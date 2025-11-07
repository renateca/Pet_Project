CC= gcc
FLAGS= -Wall -Werror -Wextra
LIBS= -lcheck -lsubunit -lm -lgcov
FILE_C= *.c
FILE_O= *.o
CHECK_FLAGS= $(shell pkg-config --cflags --libs check)
GCOV_FLAGS = -fprofile-arcs -ftest-coverage -fprofile-exclude-files=test.c
LIB_NAME= s21_matrix.a
G_FLAGS= --coverage

all: s21_matrix.a

build_object_file:
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(G_FLAGS) -c $(FILE_C)

build_lib:
	ar rcs $(LIB_NAME) $(FILE_O)

s21_matrix.a:
	$(CC) $(FLAGS) -c $(FILE_C)
	make  build_lib
	rm -f *.o

test: clean s21_matrix.a 
	$(CC) unit_test/test.c -L. $(LIB_NAME) $(CHECK_FLAGS) $(G_FLAGS) $(GCOV_FLAGS) -o test
	make start_test

start_test:
	./test

gcov_report: clean build_object_file build_lib test
	/usr/bin/gcovr -r . --html --html-details -o s21_decimal.html
	/usr/bin/gcov-11 $(FILE_C)

gcov_open: gcov_report
	xdg-open s21_decimal.html

val:
	valgrind --leak-check=full --track-origins=yes --trace-children=yes -s ./test

cpp:
	cppcheck *.c *.h

clang_check:
	cp ../materials/linters/.clang-format ../src/.clang-format
	clang-format -style=Google -n *.c *.h
	clang-format -style=Google -n unit_test/*.c 
	rm .clang-format

clang:
	cp ../materials/linters/.clang-format ../src/.clang-format
	clang-format -style=Google -i *.c *.h
	clang-format -style=Google -i unit_test/*.c 
	rm .clang-format

clean:
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcov
	rm -rf *.gcda
	rm -rf *.a
	rm -rf *.html
	rm -rf *.css
	rm -rf ./test

