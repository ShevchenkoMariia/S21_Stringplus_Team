#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(testBeginOfString) {
  const char *str = "Hello World";
  ck_assert_str_eq(s21_strrchr(str, 'H'), strrchr(str, 'H'));
}
END_TEST

START_TEST(testMiddleOfString) {
  const char *str = "Hello World";
  ck_assert_str_eq(s21_strrchr(str, 'W'), strrchr(str, 'W'));
}
END_TEST

START_TEST(testEndOfString) {
  const char *str = "Hello World";
  ck_assert_str_eq(s21_strrchr(str, 'd'), strrchr(str, 'd'));
}
END_TEST

START_TEST(testNotExist) {
  const char *str = "Hello World";
  ck_assert_ptr_null(s21_strrchr(str, 't'));
}
END_TEST

Suite *strrchrSuite(void) {
  Suite *s;
  TCase *tcCore;
  s = suite_create("StrrchrTestsSuite");
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

  s = strrchrSuite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  numberFailed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (numberFailed == 0) ? 0 : 1;
}