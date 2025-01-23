#include "../s21_tests.h"

START_TEST(test_s21_trim) {
  char *src = "  Hello, world!  ";
  char *trim_chars = " ";
  char *result = s21_trim(src, trim_chars);

  // Ожидаемый результат
  char *expected = "Hello, world!";

  // Проверяем результат
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

Suite *s21_sharp_test_trim(void) {
  Suite *s = suite_create("s21_trim");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_trim);
  suite_add_tcase(s, tc);

  return s;
}