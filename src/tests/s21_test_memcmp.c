#include "../s21_tests.h"

START_TEST(test_memcmp_1) {
  char str1[] = "hello";
  char str2[] = "hello";
  ck_assert_int_eq(memcmp(str1, str2, 5), s21_memcmp(str1, str2, 5));
}
END_TEST

START_TEST(test_memcmp_2) {
  char str1[] = "hello";
  char str2[] = "hello";
  ck_assert_int_eq(memcmp(str1, str2, 0), s21_memcmp(str1, str2, 0));
}
END_TEST

START_TEST(test_memcmp_3) {
  char str1[100] = "hello";
  char str2[100] = "hello";
  ck_assert_int_eq(memcmp(str1, str2, 14), s21_memcmp(str1, str2, 14));
}
END_TEST

START_TEST(test_memcmp_4) {
  char str1[] = "hello123";
  char str2[] = "hello456";
  ck_assert_int_eq(memcmp(str1, str2, 4), s21_memcmp(str1, str2, 4));
}
END_TEST

START_TEST(test_memcmp_5) {
  char str1[] = "hello123";
  char str2[] = "hello456";
  ck_assert_int_eq(memcmp(str1, str2, 6), s21_memcmp(str1, str2, 6));
}
END_TEST

START_TEST(test_memcmp_6) {
  char str1[100] = "hello123";
  char str2[100] = "hello456";
  ck_assert_int_eq(memcmp(str1, str2, 10), s21_memcmp(str1, str2, 10));
}
END_TEST

START_TEST(test_memcmp_7) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_int_eq(memcmp(str1, str2, 0), s21_memcmp(str1, str2, 0));
}
END_TEST

START_TEST(test_memcmp_8) {
  char str1[] = "adsadada";
  char str2[] = "aad";
  ck_assert_int_eq(memcmp(str1, str2, 3), s21_memcmp(str1, str2, 3));
}
END_TEST

Suite *test_to_memcmp(void) {
  Suite *s = suite_create("\033[45m-=S21_memcmp=-\033[0m");
  TCase *tc = tcase_create("memcmp_tc");

  tcase_add_test(tc, test_memcmp_1);
  tcase_add_test(tc, test_memcmp_2);
  tcase_add_test(tc, test_memcmp_3);
  tcase_add_test(tc, test_memcmp_4);
  tcase_add_test(tc, test_memcmp_5);
  tcase_add_test(tc, test_memcmp_6);
  tcase_add_test(tc, test_memcmp_7);
  tcase_add_test(tc, test_memcmp_8);
  suite_add_tcase(s, tc);
  return s;
}
