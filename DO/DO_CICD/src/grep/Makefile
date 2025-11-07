GCC = gcc -Wall -Werror -Wextra -std=c11

all: s21_grep clang

s21_grep: s21_grep.c
	$(GCC) s21_grep.c -o s21_grep 

clean:
	rm -f *.o
	rm -f s21_grep

clang:
	clang-format -i *.c
	clang-format -i *.h

clang_n:
	clang-format -n *.c
	clang-format -n *.h

prov:
	valgrind --tool=memcheck --leak-check=yes ./s21_grep 
	
test:
	chmod u=rwx tests.sh
	bash tests.sh
cpp:
	cppcheck s21_grep.c s21_grep.h

clear:
	clear

rebuild: 
	clean