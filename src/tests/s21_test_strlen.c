#include "../s21_tests.h"

START_TEST(test_strlen_1) {
  char str[] = "sgsddsgassrgdsrgdrgrdgdrg";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_strlen_2) {
  char str[] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_strlen_3) {
  char str[] = "sffsdfsdf\0sdfsdfds";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_strlen_4) {
  char str[] = "    fewfesf  sfgewsfe      ";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_strlen_5) {
  char str[] = "dghdrdgr";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_strlen_6) {
  char str[] = "\n";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

Suite *test_to_strlen(void) {
  Suite *s = suite_create("\033[45m-=S21_strlen=-\033[0m");
  TCase *tc = tcase_create("strlen_tc");

  tcase_add_test(tc, test_strlen_1);
  tcase_add_test(tc, test_strlen_2);
  tcase_add_test(tc, test_strlen_3);
  tcase_add_test(tc, test_strlen_4);
  tcase_add_test(tc, test_strlen_5);
  tcase_add_test(tc, test_strlen_6);
  suite_add_tcase(s, tc);
  return s;
}