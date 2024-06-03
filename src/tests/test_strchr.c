#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(testBeginOfString) {
  const char *str = "Hello World";
  ck_assert_str_eq(s21_strchr(str, 'H'), strchr(str, 'H'));
}
END_TEST

START_TEST(testMiddleOfString) {
  const char *str = "Hello World";
  ck_assert_str_eq(s21_strchr(str, 'W'), strchr(str, 'W'));
}
END_TEST

START_TEST(testEndOfString) {
  const char *str = "Hello World";
  ck_assert_str_eq(s21_strchr(str, 'd'), strchr(str, 'd'));
}
END_TEST

START_TEST(testNotExist) {
  const char *str = "Hello World";
  ck_assert_ptr_null(s21_strchr(str, 't'));
}
END_TEST

Suite *strchrSuite(void) {
  Suite *s;
  TCase *tcCore;
  s = suite_create("StrchrTestsSuite");
  tcCore = tcase_create("Tests");

  tcase_add_test(tcCore, testBeginOfString);
  tcase_add_test(tcCore, testMiddleOfString);
  tcase_add_test(tcCore, testEndOfString);
  tcase_add_test(tcCore, testNotExist);

  suite_add_tcase(s, tcCore);

  return s;
}

int main(void) {
  int numberFailed;
  Suite *s;
  SRunner *sr;

  s = strchrSuite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  numberFailed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (numberFailed == 0) ? 0 : 1;
}
