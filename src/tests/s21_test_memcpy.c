#include "../s21_tests.h"

START_TEST(test_memcpy_1) {
  char str1[] = "hello";
  char str2[] = "hello";
  char str3[] = "aw";
  s21_size_t n = 2;
  ck_assert_str_eq(memcpy(str1, str3, n), s21_memcpy(str2, str3, n));
}
END_TEST

START_TEST(test_memcpy_2) {
  char str1[] = "hello";
  char str2[] = "hello";
  char str3[] = "\0";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(str1, str3, n), s21_memcpy(str2, str3, n));
}
END_TEST

START_TEST(test_memcpy_3) {
  char str1[] = "hello";
  char str2[] = "hello";
  char str3[] = "f";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(str1, str3, n), s21_memcpy(str2, str3, n));
}
END_TEST

START_TEST(test_memcpy_4) {
  char str1[] = "hello";
  char str2[] = "hello";
  char str3[] = "hi";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(str1, str3, n), s21_memcpy(str2, str3, n));
}
END_TEST

START_TEST(test_memcpy_5) {
  char str1[] = "hello";
  char str2[] = "hello";
  char str3[] = "hi";
  s21_size_t n = 2;
  ck_assert_str_eq(memcpy(str1, str3, n), s21_memcpy(str2, str3, n));
}
END_TEST

START_TEST(test_memcpy_6) {
  char str1[] = "";
  char str2[] = "";
  char str3[] = "hi";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(str1, str3, n), s21_memcpy(str2, str3, n));
}
END_TEST

START_TEST(test_memcpy_7) {
  char str1[] = "drgdrg\0hjh";
  char str2[] = "gyjgyj\0ghgfg";
  char str3[] = "hi";
  s21_size_t n = 9;
  ck_assert_str_eq(memcpy(str1, str3, n), s21_memcpy(str2, str3, n));
}
END_TEST

START_TEST(test_memcpy_8) {
  char str1[] = "1111111";
  char str2[] = "1111111";
  char str3[] = "2";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(str1, str3, n), s21_memcpy(str2, str3, n));
}
END_TEST

Suite *test_to_memcpy(void) {
  Suite *s = suite_create("\033[45m-=S21_memcpy=-\033[0m");
  TCase *tc = tcase_create("memcpy_tc");

  tcase_add_test(tc, test_memcpy_1);
  tcase_add_test(tc, test_memcpy_2);
  tcase_add_test(tc, test_memcpy_3);
  tcase_add_test(tc, test_memcpy_4);
  tcase_add_test(tc, test_memcpy_5);
  tcase_add_test(tc, test_memcpy_6);
  tcase_add_test(tc, test_memcpy_7);
  tcase_add_test(tc, test_memcpy_8);
  suite_add_tcase(s, tc);
  return s;
}
