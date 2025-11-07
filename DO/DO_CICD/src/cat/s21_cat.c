#include "s21_cat.h"

int main(int argc, char *argv[]) {
  options opts = {0};
  FILE *file;
  char *files[argc];
  int count_files = 0;
  get_options(argc, argv, &opts);
  get_files(argc, argv, files, &count_files);

  for (int i = 0; i < count_files; i++) {
    file = fopen(files[i], "r");
    if (!file) {
      perror(argv[i]);
    } else {
      if (opts.b || opts.e || opts.n || opts.s || opts.t || opts.v)
        output(&opts, file);
      else
        raw_cat(file);

      fclose(file);
    }
  }
  return 0;
}

void get_options(int argc, char *argv[], options *opts) {
  int opt;
  opts->line = 0;
  opts->gob = 0;
  opts->prev = '\n';
  int options_index;
  static struct option long_options[] = {{"number-nonblank", 0, 0, 'b'},
                                         {"number", 0, 0, 'n'},
                                         {"squeeze-blank", 0, 0, 's'},
                                         {0, 0, 0, 0}};

  while ((opt = getopt_long(argc, argv, "benstvTE", long_options,
                            &options_index)) != -1) {
    switch (opt) {
      case 'b':
        opts->b = opts->n = 1;
        break;
      case 'e':
        opts->e = 1;
        opts->v = 1;
        break;
      case 'n':
        opts->n = 1;
        break;
      case 's':
        opts->s = 1;
        break;
      case 't':
        opts->t = opts->v = 1;
        break;
      case 'T':
        opts->t = 1;
        break;
      case 'E':
        opts->e = 1;
        break;
      case 'v':
        opts->v = 1;
        break;
      default:
        printf("usage: ./s21_cat [benstv][file...]\n");
        exit(1);
        break;
    }
  }
}

void get_files(int argc, char *argv[], char **files, int *count_files) {
  for (int i = optind; i < argc; i++) {
    files[*count_files] = argv[i];
    *count_files += 1;
  }
}

void raw_cat(FILE *file) {
  int ch;
  while ((ch = getc(file)) != EOF) {
    putchar(ch);
  }
  if (ferror(file)) {
    perror("File read error");
  }
}

void output(options *opts, FILE *file) {
  int c;
  for (opts->prev = '\n'; (c = getc(file)) != EOF; opts->prev = c) {
    if (opts->prev == '\n') {
      if (opts->s) {
        if (c == '\n') {
          if (opts->gob) continue;
          opts->gob = 1;
        } else
          opts->gob = 0;
      }
      if (opts->n && (!opts->b || c != '\n')) {
        printf("%6d\t", ++(opts->line));
      }
    }
    if (c == '\n') {
      if (opts->e && putchar('$') == EOF) break;
    } else if (c == '\t') {
      if (opts->t) {
        if (putchar('^') == EOF || putchar('I') == EOF) break;
        continue;
      }
    } else if (opts->v) {
      if (!(c >= 0 && c < 128) && !(c >= ' ' && c <= '~')) {
        if (putchar('M') == EOF || putchar('-') == EOF) break;
        c = (c & 0x7F);
      }
      if ((c >= 0 && c < 32) || c == 127) {
        if (putchar('^') == EOF || putchar(c == '\177' ? '?' : c | 0100) == EOF)
          break;
        continue;
      }
    }
    if (putchar(c) == EOF) break;
  }
  if (ferror(file)) {
    perror("File read error");
  }
}

/*//char temp[2] = {-1, -1};
int count_enter = 0;
int moment_s = 0;
int c;
int line_number = 1;

while ((c = getc(file)) != EOF) {
  //temp[0] = temp[1];
  //temp[1] = c;
  if (opts.s) {
    if (temp[0] == -1 && temp[1] == '\n' && count_enter == 0)
      moment_s = 1;
    else if (temp[0] == '\n' && temp[1] == '\n' && moment_s == 0)
      moment_s = 1;
    else if (temp[0] == '\n' && temp[1] != '\n')
      moment_s = 0;
    else if (temp[0] == '\n' && temp[1] == '\n' && moment_s == 1)
      continue;
  }
  if (opts.b) {
    if (count_enter == 0 && line_number == 1 && c != '\n') {
      printf("%6d\t", line_number);
      line_number += 1;
    } else if (c != '\n' && temp[0] == '\n') {
      printf("%6d\t", line_number);
      line_number += 1;
    } else if (opts.n) {
      if (count_enter == 0 && line_number == 1) {
        printf("%6d\t", line_number);
        line_number += 1;
      }
      if (temp[0] == '\n') {
        printf("%6d\t", line_number);
        line_number += 1;
      }
    }
  }
  if (opts.v) {
    if ((c >= 0 && c < 32 && c != 10 && c != 9) || c == 127) {
      if (c == 127) {
        printf("^?");
        continue;
      } else {
        printf("^%c", (c + 64));
        continue;
      }
    }
  }
  if (opts.e) {
    if (c == '\n') printf("$");
  }
  if (opts.t) {
    if (c == '\t') {
      printf("^I");
      continue;
    }
  }
  printf("%c", c);
}*/
