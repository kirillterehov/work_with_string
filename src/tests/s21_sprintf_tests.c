#include "../s21_tests.h"

START_TEST(test_s21_sprintf_d) {
  char buffer_custom[100];
  char buffer_original[100];

  int result_custom = s21_sprintf(buffer_custom, "%d", 123);
  int result_original = sprintf(buffer_original, "%d", 123);
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);

  result_custom = s21_sprintf(buffer_custom, "%+d", 123);
  result_original = sprintf(buffer_original, "%+d", 123);
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);

  result_custom = s21_sprintf(buffer_custom, "% d", 123);
  result_original = sprintf(buffer_original, "% d", 123);
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);

  result_custom = s21_sprintf(buffer_custom, "%010d", 123);
  result_original = sprintf(buffer_original, "%010d", 123);
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);

  result_custom = s21_sprintf(buffer_custom, "%*d", 10, 123);
  result_original = sprintf(buffer_original, "%*d", 10, 123);
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);

  result_custom = s21_sprintf(buffer_custom, "%.5d", 123);
  result_original = sprintf(buffer_original, "%.5d", 123);
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);
}
END_TEST

START_TEST(test_s21_sprintf_i) {
  char buffer_custom[100];
  char buffer_original[100];

  int result_custom = s21_sprintf(buffer_custom, "%i", -123);
  int result_original = sprintf(buffer_original, "%i", -123);
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);

  result_custom = s21_sprintf(buffer_custom, "%+i", -123);
  result_original = sprintf(buffer_original, "%+i", -123);
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);

  result_custom = s21_sprintf(buffer_custom, "% i", -123);
  result_original = sprintf(buffer_original, "% i", -123);
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);

  result_custom = s21_sprintf(buffer_custom, "%.5i", -123);
  result_original = sprintf(buffer_original, "%.5i", -123);
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);
}
END_TEST

START_TEST(test_s21_sprintf_c) {
  char buffer_custom[100];
  char buffer_original[100];

  int result_custom = s21_sprintf(buffer_custom, "%c", 'A');
  int result_original = sprintf(buffer_original, "%c", 'A');
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);

  result_custom = s21_sprintf(buffer_custom, "%-5c", 'A');
  result_original = sprintf(buffer_original, "%-5c", 'A');
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);

  result_custom = s21_sprintf(buffer_custom, "%5c", 'A');
  result_original = sprintf(buffer_original, "%5c", 'A');
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);
}
END_TEST

START_TEST(test_s21_sprintf_s) {
  char buffer_custom[100];
  char buffer_original[100];

  int result_custom = s21_sprintf(buffer_custom, "%s", "Hello");
  int result_original = sprintf(buffer_original, "%s", "Hello");
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);

  result_custom = s21_sprintf(buffer_custom, "%-10s", "Hello");
  result_original = sprintf(buffer_original, "%-10s", "Hello");
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);
  result_custom = s21_sprintf(buffer_custom, "%10s", "Hello");
  result_original = sprintf(buffer_original, "%10s", "Hello");
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);

  result_custom = s21_sprintf(buffer_custom, "%.3s", "Hello");
  result_original = sprintf(buffer_original, "%.3s", "Hello");
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);

  result_custom = s21_sprintf(buffer_custom, "%10.3s", "Hello");
  result_original = sprintf(buffer_original, "%10.3s", "Hello");
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);
}
END_TEST

START_TEST(test_s21_sprintf_u) {
  char buffer_custom[100];
  char buffer_original[100];

  int result_custom = s21_sprintf(buffer_custom, "%u", 123);
  int result_original = sprintf(buffer_original, "%u", 123);
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);

  result_custom = s21_sprintf(buffer_custom, "%010u", 123);
  result_original = sprintf(buffer_original, "%010u", (unsigned int)123);
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);

  result_custom = s21_sprintf(buffer_custom, "%*u", 10, 123);
  result_original = sprintf(buffer_original, "%*u", 10, (unsigned int)123);
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);

  result_custom = s21_sprintf(buffer_custom, "%.5u", 123);
  result_original = sprintf(buffer_original, "%.5u", (unsigned int)123);
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);
}
END_TEST

START_TEST(test_s21_sprintf_n) {
  char buffer_custom[100];
  char buffer_original[100];
  int n_custom, n_original;

  int result_custom = s21_sprintf(buffer_custom, "Hello%n", &n_custom);
  int result_original = sprintf(buffer_original, "Hello%n", &n_original);
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);
  ck_assert_int_eq(n_custom, n_original);
}
END_TEST

START_TEST(test_s21_sprintf_percent) {
  char buffer_custom[100];
  char buffer_original[100];

  int result_custom = s21_sprintf(buffer_custom, "%%");
  int result_original = sprintf(buffer_original, "%%");
  ck_assert_str_eq(buffer_custom, buffer_original);
  ck_assert_int_eq(result_custom, result_original);
}
END_TEST

Suite *s21_sprintf_test(void) {
  Suite *s = suite_create("s21_sprintf");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_sprintf_d);
  tcase_add_test(tc, test_s21_sprintf_i);
  tcase_add_test(tc, test_s21_sprintf_c);
  tcase_add_test(tc, test_s21_sprintf_s);
  tcase_add_test(tc, test_s21_sprintf_u);
  tcase_add_test(tc, test_s21_sprintf_n);
  tcase_add_test(tc, test_s21_sprintf_percent);

  suite_add_tcase(s, tc);
  return s;
}
