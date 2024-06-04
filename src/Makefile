T_PATH := tests/

CC = gcc
C_FLAGS = -Wall -Werror -Wextra -std=c11
LC = lcov -c -d . -o

LIB_CMD = ar rc
TESTS_FLAGS = -lcheck -lsubunit -lm -lrt -lpthread
GCOV_FLAGS = --coverage -fprofile-arcs -ftest-coverage

ifeq ($(shell uname -s), Linux)
OPEN_CMD = xdg-open
endif
ifeq ($(shell uname -s), Darwin)
OPEN_CMD = open
endif

SRC = $(wildcard *.c)
SRC_O = $(patsubst %.c, %.o, $(SRC))
GCOV_SRC_O = $(patsubst %, gcov_%, $(SRC_O))

TESTS = $(wildcard $(T_PATH)test_*.c)
TESTS_EXE = $(notdir $(patsubst %.c, %, $(TESTS)))

#-------------------------------------------------------

.PHONY: all test clean

info:
	@echo $(GCOV_SRC_O)

all: s21_string.a test

s21_string.a: $(SRC_O) 
	$(LIB_CMD) $@ $(SRC_O)
	ranlib $@
	rm -f $(SRC_O)

%.o: %.c 
	$(CC) $(C_FLAGS) -c $<

gcov_lib.a: $(GCOV_SRC_O)
	$(LIB_CMD) $@ $(GCOV_SRC_O)
	ranlib $@
	rm -f $(GCOV_SRC_O)

gcov_%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@ $(GCOV_FLAGS) -lm

test: $(TESTS_EXE) gcov_report

test_%: $(T_PATH)test_%.c gcov_lib.a
	@$(CC) $(C_FLAGS) $< -L. gcov_lib.a -o $@  $(GCOV_FLAGS) $(TESTS_FLAGS) 
	@./$@

gcov_report:
	rm -f gcov_lib.a
	$(LC) report.info
	genhtml -o report report.info
	$(OPEN_CMD) report/index.html


check_style:
	@cp ../materials/linters/.clang-format .
	@clang-format -n *.c *.h $(T_PATH)*.c
	@rm .clang-format

style:
	@cp ../materials/linters/.clang-format .
	@clang-format -i *.c *.h $(T_PATH)*.c
	@rm .clang-format

g_style:
	@clang-format --style=Google -n $(S_PATH)*.c $(H_PATH)*.h $(T_PATH)*.c

#valgrind --tool=memcheck --leak-check=yes  ./$@

clean:
	@rm -f *.a *.o *.gcno $(T_PATH)*.gcno $(S_PATH)*.gcno *.gcda *.info $(TESTS_EXE)
	@rm -fr report
	@echo "Cleaning is finished :)"
