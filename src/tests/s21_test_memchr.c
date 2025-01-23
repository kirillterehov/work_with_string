#include "../s21_tests.h"

START_TEST(test_memchr_1) {
  char str[] = "sdfshfbsdhfbsdhfshhjsfds";
  int ch = 'b';
  ck_assert_ptr_eq(memchr(str, ch, strlen(str)),
                   s21_memchr(str, ch, strlen(str)));
}
END_TEST

START_TEST(test_memchr_2) {
  char str[] = "sdfshfbsdhfbsdhfshhjsfds";
  int ch = 'u';
  ck_assert_ptr_eq(memchr(str, ch, strlen(str)),
                   s21_memchr(str, ch, strlen(str)));
}
END_TEST

START_TEST(test_memchr_3) {
  char str[] = "";
  int ch = 'u';
  ck_assert_ptr_eq(memchr(str, ch, strlen(str)),
                   s21_memchr(str, ch, strlen(str)));
}
END_TEST

START_TEST(test_memchr_4) {
  char str[] = "fsfsfefse\0esfesfsefffffffffffffffffff";
  int ch = '\0';
  ck_assert_ptr_eq(memchr(str, ch, strlen(str)),
                   s21_memchr(str, ch, strlen(str)));
}
END_TEST

START_TEST(test_memchr_5) {
  char str[] = "\0";
  int ch = '\0';
  ck_assert_ptr_eq(memchr(str, ch, strlen(str)),
                   s21_memchr(str, ch, strlen(str)));
}
END_TEST

Suite *test_to_memchr(void) {
  Suite *s = suite_create("\033[45m-=S21_memchr=-\033[0m");
  TCase *tc = tcase_create("memchr_tc");

  tcase_add_test(tc, test_memchr_1);
  tcase_add_test(tc, test_memchr_2);
  tcase_add_test(tc, test_memchr_3);
  tcase_add_test(tc, test_memchr_4);
  tcase_add_test(tc, test_memchr_5);
  suite_add_tcase(s, tc);
  return s;
}