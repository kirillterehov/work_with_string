#include "../s21_tests.h"

START_TEST(test_s21_insert) {
  char *src = "Hello, !";
  char *str = "world";
  char *result = s21_insert(src, str, 7);

  // Ожидаемый результат
  char *expected = "Hello, world!";

  // Проверяем результат
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

Suite *s21_sharp_test_insert(void) {
  Suite *s = suite_create("s21_insert");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_insert);
  suite_add_tcase(s, tc);

  return s;
}