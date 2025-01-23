#include "../s21_tests.h"

START_TEST(test_s21_to_upper) {
  char *str = "hello, world!";
  char *result = s21_to_upper(str);

  // Ожидаемый результат
  char expected[100];
  for (int i = 0; str[i] != '\0'; i++) {
    expected[i] = toupper((unsigned char)str[i]);
  }
  expected[strlen(str)] = '\0';

  // Проверяем результат
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

Suite *s21_sharp_test_to_upper(void) {
  Suite *s = suite_create("s21_to_upper");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_to_upper);
  suite_add_tcase(s, tc);

  return s;
}