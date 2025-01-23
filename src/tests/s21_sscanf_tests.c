#include "../s21_tests.h"

START_TEST(test_s21_sscanf_f) {
  double num;
  int result = s21_sscanf("123.456", "%f", &num);
  ck_assert_int_eq(result, 1);
  ck_assert_double_eq(num, 123.456);
}
END_TEST

START_TEST(test_s21_sscanf_e) {
  double num;
  int result = s21_sscanf("1.23e+02", "%e", &num);
  ck_assert_int_eq(result, 1);
  ck_assert_double_eq(num, 123.0);
}
END_TEST

START_TEST(test_s21_sscanf_E) {
  double num;
  int result = s21_sscanf("1.23E+02", "%E", &num);
  ck_assert_int_eq(result, 1);
  ck_assert_double_eq(num, 123.0);
}
END_TEST

START_TEST(test_s21_sscanf_g) {
  double num;
  int result = s21_sscanf("0.001", "%g", &num);
  ck_assert_int_eq(result, 1);
  ck_assert_double_eq(num, 0.001);
}
END_TEST

START_TEST(test_s21_sscanf_G) {
  double num;
  int result = s21_sscanf("-4.56E-03", "%G", &num);
  ck_assert_int_eq(result, 1);
  ck_assert_double_eq(num, -0.00456);
}
END_TEST

Suite *s21_sscanf_test(void) {
  Suite *s = suite_create("s21_sscanf");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_sscanf_f);
  tcase_add_test(tc, test_s21_sscanf_e);
  tcase_add_test(tc, test_s21_sscanf_E);
  tcase_add_test(tc, test_s21_sscanf_g);
  tcase_add_test(tc, test_s21_sscanf_G);

  suite_add_tcase(s, tc);
  return s;
}