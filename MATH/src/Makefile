CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBS = -lcheck -lsubunit -lm -lgcov
FUNC_FILES_C = *.c
FUNC_FILES_O = *.o
CHECKFLAGS = $(shell pkg-config --cflags --libs check)
GCOVFLAGS = -fprofile-arcs -ftest-coverage
LIBNAME =s21_math.a  s21_math.a
GLFLAGS = --coverage

all: s21_math.a

peer: 
	make clean
	make gcov_open

build_object_files:
	$(CC) $(FLAGS) $(GCOVFLAGS) $(GLFLAGS) -c $(FUNC_FILES_C)

build_library:
	ar rcs $(LIBNAME) $(FUNC_FILES_O)

s21_math.a:
	$(CC) $(FLAGS) -c $(FUNC_FILES_C)
	make build_library
	rm -rf *.o

test: s21_math.a
	$(CC) unit_tests/s21_test_abs.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_abs_test
	$(CC) unit_tests/s21_test_acos.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_acos_test
	$(CC) unit_tests/s21_test_asin.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_asin_test
	$(CC) unit_tests/s21_test_atan.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_atan_test
	$(CC) unit_tests/s21_test_ceil.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_ceil_test
	$(CC) unit_tests/s21_test_cos.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_cos_test
	$(CC) unit_tests/s21_test_exp.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_exp_test
	$(CC) unit_tests/s21_test_fabs.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_fabs_test
	$(CC) unit_tests/s21_test_floor.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_floor_test
	$(CC) unit_tests/s21_test_fmod.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_fmod_test
	$(CC) unit_tests/s21_test_log.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_log_test
	$(CC) unit_tests/s21_test_pow.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_pow_test
	$(CC) unit_tests/s21_test_sin.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_sin_test
	$(CC) unit_tests/s21_test_sqrt.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_sqrt_test
	$(CC) unit_tests/s21_test_tan.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_tan_test
	make start_tests

start_tests:
	./s21_abs_test
	./s21_acos_test
	./s21_asin_test
	./s21_atan_test
	./s21_ceil_test
	./s21_cos_test
	./s21_exp_test
	./s21_fabs_test
	./s21_floor_test
	./s21_fmod_test
	./s21_log_test
	./s21_pow_test
	./s21_sin_test
	./s21_sqrt_test
	./s21_tan_test

gcov_report: clean build_object_files build_library test
	gcov $(FUNC_FILES_C)
	~/.local/bin/gcovr -r . --html --html-details -o s21_math.html

gcov_open: 
	make gcov_report
	@echo "Opening report..."
	xdg-open s21_math.html

clean:
	rm -f *.o
	rm -f *.gcno
	rm -f *.gcov
	rm -f *.gcda
	rm -f *.a
	rm -f *.info
	rm -f *.html
	rm -f *.css
	rm -f s21_*_test

rebuild:
	make clean
	make

.PHONY: cl
cl:
	clang-format -n *.c *.h
	clang-format -n unit_tests/*.c *.h

.PHONY: cl-i
cl-i:
	clang-format -i *.c *.h
	clang-format -i unit_tests/*.c *.h

.PHONY: cpp
cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem --std=c11 *.c unit_tests/*.c

.PHONY: val
val:
	valgrind --tool=memcheck --leak-check=full ./s21_abs_test
	valgrind --tool=memcheck --leak-check=full ./s21_acos_test
	valgrind --tool=memcheck --leak-check=full ./s21_asin_test
	valgrind --tool=memcheck --leak-check=full ./s21_atan_test
	valgrind --tool=memcheck --leak-check=full ./s21_ceil_test
	valgrind --tool=memcheck --leak-check=full ./s21_cos_test
	valgrind --tool=memcheck --leak-check=full ./s21_exp_test
	valgrind --tool=memcheck --leak-check=full ./s21_fabs_test
	valgrind --tool=memcheck --leak-check=full ./s21_floor_test
	valgrind --tool=memcheck --leak-check=full ./s21_fmod_test
	valgrind --tool=memcheck --leak-check=full ./s21_log_test
	valgrind --tool=memcheck --leak-check=full ./s21_pow_test
	valgrind --tool=memcheck --leak-check=full ./s21_sqrt_test
	valgrind --tool=memcheck --leak-check=full ./s21_tan_test
	valgrind --tool=memcheck --leak-check=full ./s21_sin_test
	