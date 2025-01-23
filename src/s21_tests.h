#ifndef S21_TESTS_H_
#define S21_TESTS_H_

#include <assert.h>
#include <check.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "s21_string.h"

// string functions tests
Suite *test_to_strlen(void);
Suite *test_to_memchr(void);
Suite *test_to_memcmp(void);
Suite *test_to_memcpy(void);
Suite *test_to_memset(void);
Suite *test_to_strncat(void);
Suite *test_to_strchr(void);
Suite *test_to_strncmp(void);
Suite *test_to_strncpy(void);
Suite *test_to_strcspn(void);
Suite *test_to_strerror(void);
Suite *test_to_strpbrk(void);
Suite *test_to_strrchr(void);
Suite *test_to_strstr(void);
Suite *test_to_strtok(void);

// sharp functions tests
Suite *s21_sharp_test_to_upper(void);
Suite *s21_sharp_test_to_lower(void);
Suite *s21_sharp_test_insert(void);
Suite *s21_sharp_test_trim(void);

// sscanf functions tests
Suite *s21_sscanf_test(void);

// sprintf functions tests
Suite *s21_sprintf_test(void);

#endif