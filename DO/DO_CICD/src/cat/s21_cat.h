#ifndef S21_CAT_H
#define S21_CAT_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int b;
  int e;
  int n;
  int s;
  int t;
  int T;
  int E;
  int v;
  int line;
  int prev;
  int gob;
} options;

void get_options(int argc, char *argv[], options *opts);
void raw_cat(FILE *file);
void get_files(int argc, char *argv[], char **files, int *count_file);
void output(options *opts, FILE *file);

#endif /*S21_CAT_H*/
