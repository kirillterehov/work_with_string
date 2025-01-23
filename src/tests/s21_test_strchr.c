#include "../s21_tests.h"

START_TEST(test_strchr_1) {
  char s[] = "gkgkhjkghjgsfada";
  int ch = 'k';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_strchr_2) {
  char s[] = "gkgkhjkghjgsfada";
  int ch = '\0';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_strchr_3) {
  char s[] = "gkgkhjkghjgsfada,segse";
  int ch = ',';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_strchr_4) {
  char s[] = "gkgkhjkghjgsfada";
  int ch = 33;
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_strchr_5) {
  char s[] = "gkgkhjkghjgsfadaH";
  int ch = 'H';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_strchr_6) {
  char s[] = "gkgkhjkghjgsfada ddsad";
  int ch = 'd';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_strchr_7) {
  char s[] = "gkgkhjkghjgsfada";
  int ch = '0';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_strchr_8) {
  char s[] = "gkgkhjkghjgsfada";
  int ch = 'q';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

Suite *test_to_strchr(void) {
  Suite *s = suite_create("\033[45m-=S21_STRCHR=-\033[0m");
  TCase *tc = tcase_create("strchr_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_strchr_1);
  tcase_add_test(tc, test_strchr_2);
  tcase_add_test(tc, test_strchr_3);
  tcase_add_test(tc, test_strchr_4);
  tcase_add_test(tc, test_strchr_5);
  tcase_add_test(tc, test_strchr_6);
  tcase_add_test(tc, test_strchr_7);
  tcase_add_test(tc, test_strchr_8);

  suite_add_tcase(s, tc);
  return s;
}
