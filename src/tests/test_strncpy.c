/*
Тесты в гугл стиле. Если не знаешь как это, то
https://gpt-open.ru/chat-gpt-besplatno/gpt-open
зайди в чат gpt, скинь ему свой код с фразой "перепиши в гугл стиле".
Каждая функция не длиннее 40 строк.
Для тестов используется библиотека Check.
В тестах сравнивать свою фукцию с оригиналом.
Прочитай "Справка по тестам", там быстрая инструкция
для установки библиотеки и другие подсказки
*/

#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(testNormalCopy) {
  char str1[50] = "Hello";
  char str2[50] = "";
  char str3[50] = "";
  s21_strncpy(str2, str1, 4);
  strncpy(str3, str1, 4);
  ck_assert_str_eq(str3, str2);
}
END_TEST

START_TEST(testNullCopy) {
  char str1[50] = "";
  char str2[50] = "";
  char str3[50] = "";
  s21_strncpy(str2, str1, 1);
  strncpy(str3, str1, 1);
  ck_assert_str_eq(str3, str2);
}
END_TEST

START_TEST(testOneCharCopy) {
  char str1[50] = "Hello";
  char str2[50] = "";
  char str3[50] = "";
  s21_strncpy(str2, str1, 1);
  strncpy(str3, str1, 1);
  ck_assert_str_eq(str3, str2);
}
END_TEST

START_TEST(testNullToANonEmptyString) {
  char str1[50] = "";
  char str2[50] = "HELLO";
  char str3[50] = "HELLO";
  s21_strncpy(str2, str1, 1);
  strncpy(str3, str1, 1);
  ck_assert_str_eq(str3, str2);
}
END_TEST

START_TEST(testCopiingToANonEmtptyString) {
  char str1[50] = "Hello";
  char str2[50] = "University";
  char str3[50] = "University";
  s21_strncpy(str2, str1, 5);
  strncpy(str3, str1, 5);
  ck_assert_str_eq(str3, str2);
}
END_TEST

Suite *suiteMemcpyTests() {
  Suite *suite = suite_create("memcpyTests");
  TCase *tcase = tcase_create("memcpyTests");
  tcase_add_test(tcase, testNormalCopy);
  tcase_add_test(tcase, testNullCopy);
  tcase_add_test(tcase, testOneCharCopy);
  tcase_add_test(tcase, testNullToANonEmptyString);
  tcase_add_test(tcase, testCopiingToANonEmtptyString);
  suite_add_tcase(suite, tcase);
  return suite;
}

int main() {
  int failed = 0;
  Suite *suite = suiteMemcpyTests();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
