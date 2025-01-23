#include "../s21_tests.h"

int main(void) {
  int number_failed = 0;
  // sprintf functions test
  Suite *s_sprintf = s21_sprintf_test();

  // sscanf functions test
  Suite *s_sscanf = s21_sscanf_test();

  // string functions tests
  Suite *s_to_strlen = test_to_strlen();
  Suite *s_to_memchr = test_to_memchr();
  Suite *s_to_memcmp = test_to_memcmp();
  Suite *s_to_memcpy = test_to_memcpy();
  Suite *s_to_memset = test_to_memset();
  Suite *s_to_strncat = test_to_strncat();
  Suite *s_to_strchr = test_to_strchr();
  Suite *s_to_strncmp = test_to_strncmp();
  Suite *s_to_strncpy = test_to_strncpy();
  Suite *s_to_strcspn = test_to_strcspn();
  Suite *s_to_strerror = test_to_strerror();
  Suite *s_to_strpbrk = test_to_strpbrk();
  Suite *s_to_strrchr = test_to_strrchr();
  Suite *s_to_strstr = test_to_strstr();
  Suite *s_to_strtok = test_to_strtok();

  // sharp functions tests
  Suite *s_to_upper = s21_sharp_test_to_upper();
  Suite *s_to_lower = s21_sharp_test_to_lower();
  Suite *s_insert = s21_sharp_test_insert();
  Suite *s_trim = s21_sharp_test_trim();

  // create SRunner and add string functions suits
  SRunner *sr = srunner_create(s_to_strlen);
  srunner_add_suite(sr, s_to_memchr);
  srunner_add_suite(sr, s_to_memcmp);
  srunner_add_suite(sr, s_to_memcpy);
  srunner_add_suite(sr, s_to_memset);
  srunner_add_suite(sr, s_to_strncat);
  srunner_add_suite(sr, s_to_strchr);
  srunner_add_suite(sr, s_to_strncmp);
  srunner_add_suite(sr, s_to_strncpy);
  srunner_add_suite(sr, s_to_strcspn);
  srunner_add_suite(sr, s_to_strerror);
  srunner_add_suite(sr, s_to_strpbrk);
  srunner_add_suite(sr, s_to_strrchr);
  srunner_add_suite(sr, s_to_strstr);
  srunner_add_suite(sr, s_to_strtok);

  // add sharp functions suits
  srunner_add_suite(sr, s_to_upper);
  srunner_add_suite(sr, s_to_lower);
  srunner_add_suite(sr, s_insert);
  srunner_add_suite(sr, s_trim);

  // add sscanf function suits
  srunner_add_suite(sr, s_sscanf);

  // add sprintf function suits
  srunner_add_suite(sr, s_sprintf);

  // run all tests
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
