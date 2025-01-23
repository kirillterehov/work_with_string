CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror
LIB_NAME = s21_string.a
TEST_EXEC = test_s21_string


UNAME := $(shell uname -s)
ifeq ($(UNAME), Linux)
  OPEN_CMD = xdg-open
  TEST_FLAGS = -lcheck -lsubunit -lm -lrt -lpthread
else ifeq ($(UNAME), Darwin)
  OPEN_CMD = open
  TEST_FLAGS = -lcheck -lm -lpthread
endif

SRC_FILES = s21_string_functions.c s21_sharp_functions.c s21_sprintf.c s21_sscanf.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# Тестовые файлы
TEST_FILES = tests/test_main.c \
             tests/s21_sharp_test_insert.c \
             tests/s21_sharp_test_to_lower.c \
             tests/s21_sharp_test_to_upper.c \
             tests/s21_sharp_test_trim.c \
             tests/s21_sprintf_tests.c \
             tests/s21_sscanf_tests.c \
             tests/s21_test_memchr.c \
             tests/s21_test_memcmp.c \
             tests/s21_test_memcpy.c \
             tests/s21_test_memset.c \
             tests/s21_test_strchr.c \
             tests/s21_test_strcspn.c \
             tests/s21_test_strerror.c \
             tests/s21_test_strlen.c \
             tests/s21_test_strncat.c \
             tests/s21_test_strncmp.c \
             tests/s21_test_strncpy.c \
             tests/s21_test_strpbrk.c \
             tests/s21_test_strrchr.c \
             tests/s21_test_strstr.c \
             tests/s21_test_strtok.c

$(LIB_NAME): $(OBJ_FILES)
	ar rcs $(LIB_NAME) $(OBJ_FILES)

%.o: %.c s21_string.h s21_strerror.h s21_tests.h
	$(CC) $(CFLAGS) -c $< -o $@

test: $(LIB_NAME) $(TEST_FILES)
	$(CC) $(CFLAGS) $(TEST_FILES) $(LIB_NAME) $(TEST_FLAGS) -o $(TEST_EXEC)
	./$(TEST_EXEC)

gcov_report: CFLAGS += -fprofile-arcs -ftest-coverage
gcov_report: clean $(LIB_NAME) $(TEST_FILES)
	$(CC) $(CFLAGS) $(TEST_FILES) $(SRC_FILES) $(TEST_FLAGS) -o $(TEST_EXEC)
	./$(TEST_EXEC)
	gcov $(SRC_FILES)
	lcov -t "s21_string" -o s21_string.info -c -d . --exclude "*/tests/*"
	genhtml -o report s21_string.info
	$(OPEN_CMD) report/index.html

.PHONY: all test clean gcov_report

clean:
	rm -rf *.o $(LIB_NAME) $(TEST_EXEC) *.gcno *.gcda *.info report *.gcov

rebuild: clean $(LIB_NAME)