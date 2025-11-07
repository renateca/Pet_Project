GCC= gcc -Wall -Werror -Wextra -std=c11

all: s21_cat clang test

s21_cat:
	$(GCC) s21_cat.c -o s21_cat

clear:
	clear

clean:
	rm -f *.o
	rm -f s21_cat
	clear

clang:
	clang-format -i *.c
	clang-format -i *.h

check:
	valgrind --tool=memcheck --leak-check=yes  ./s21_cat
	cppcheck s21_cat.c s21_cat.h

test:
	chmod u=rwx test_cat.sh
	bash test_cat.sh

rebuild:
	clean
	all

clang_nn:
	clang-format -n *.c
	clang-format -n *.h
