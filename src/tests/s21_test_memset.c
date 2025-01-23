#include "../s21_tests.h"

START_TEST(test_memset_1) {
  char str1[] = "asdasdasd awsdsadas";
  char str2[] = "asdasdasd awsdsadas";
  int ch = ' ';
  s21_size_t n = strlen(str1);
  ck_assert_str_eq(memset(str1, ch, n), s21_memset(str2, ch, n));
}
END_TEST

START_TEST(test_memset_2) {
  char str1[] = "asdasdasd awsdsadas";
  char str2[] = "asdasdasd awsdsadas";
  int ch = ' ';
  s21_size_t n = 3;
  ck_assert_str_eq(memset(str1, ch, n), s21_memset(str2, ch, n));
}
END_TEST

START_TEST(test_memset_3) {
  char str1[] = "asdasdasd awsdsadas";
  char str2[] = "asdasdasd awsdsadas";
  int ch = ' ';
  s21_size_t n = 0;
  ck_assert_str_eq(memset(str1, ch, n), s21_memset(str2, ch, n));
}
END_TEST

START_TEST(test_memset_4) {
  char str1[] = "";
  char str2[] = "";
  int ch = '\0';
  s21_size_t n = 0;
  ck_assert_str_eq(memset(str1, ch, n), s21_memset(str2, ch, n));
}
END_TEST

START_TEST(test_memset_5) {
  char str1[] = "asdasdasd awsdsadas";
  char str2[] = "asdasdasd awsdsadas";
  int ch = '\0';
  s21_size_t n = 0;
  ck_assert_str_eq(memset(str1, ch, n), s21_memset(str2, ch, n));
}
END_TEST

START_TEST(test_memset_6) {
  char str1[] = "asdasdasd awsdsadas";
  char str2[] = "asdasdasd awsdsadas";
  int ch = 80;
  s21_size_t n = 7;
  ck_assert_str_eq(memset(str1, ch, n), s21_memset(str2, ch, n));
}
END_TEST

Suite *test_to_memset(void) {
  Suite *s = suite_create("\033[45m-=S21_memset=-\033[0m");
  TCase *tc = tcase_create("memset_tc");

  tcase_add_test(tc, test_memset_1);
  tcase_add_test(tc, test_memset_2);
  tcase_add_test(tc, test_memset_3);
  tcase_add_test(tc, test_memset_4);
  tcase_add_test(tc, test_memset_5);
  tcase_add_test(tc, test_memset_6);
  suite_add_tcase(s, tc);
  return s;
}