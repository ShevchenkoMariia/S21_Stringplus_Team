#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(testBeginOfString) {
  const char *str = "Hello World";
  ck_assert_str_eq(s21_memchr(str, 'H', 5), memchr(str, 'H', 5));
}
END_TEST

START_TEST(testMiddleOfString) {
  const char *str = "Hello World";
  ck_assert_str_eq(s21_memchr(str, 'W', 8), memchr(str, 'W', 8));
}
END_TEST

START_TEST(testEndOfString) {
  const char *str = "Hello World";
  ck_assert_str_eq(s21_memchr(str, 'd', 11), memchr(str, 'd', 11));
}
END_TEST

START_TEST(testNotExist) {
  const char *str = "Hello World";
  ck_assert_ptr_null(s21_memchr(str, 't', 5));
}
END_TEST

START_TEST(testToManyBytes) {
  const char *str = "Hello World";
  ck_assert_str_eq(s21_memchr(str, 'W', 10), memchr(str, 'W', 10));
}
END_TEST

START_TEST(testToFewBytes) {
  const char *str = "Hello World";
  ck_assert_ptr_null(s21_memchr(str, 'd', 5));
}
END_TEST

START_TEST(testZeroBytes) {
  const char *str = "Hello World";
  ck_assert_ptr_null(s21_memchr(str, 'e', 0));
}
END_TEST

Suite *memchrSuite(void) {
  Suite *s;
  TCase *tcCore;
  s = suite_create("MemchrTestsSuite");
  tcCore = tcase_create("Core");
  tcase_add_test(tcCore, testBeginOfString);
  tcase_add_test(tcCore, testMiddleOfString);
  tcase_add_test(tcCore, testEndOfString);
  tcase_add_test(tcCore, testNotExist);
  tcase_add_test(tcCore, testToManyBytes);
  tcase_add_test(tcCore, testToFewBytes);
  tcase_add_test(tcCore, testZeroBytes);
  suite_add_tcase(s, tcCore);

  return s;
}

int main(void) {
  int numberFailed;
  Suite *s;
  SRunner *sr;

  s = memchrSuite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  numberFailed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (numberFailed == 0) ? 0 : 1;
}
