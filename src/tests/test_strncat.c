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

START_TEST(testNormalCat) {
  char str1[50] = "Hello ";
  char str2[50] = "Hello ";
  char str3[50] = "World";
  s21_strncat(str1, str3, 3);
  strncat(str2, str3, 3);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(testCattingANullString) {
  char str1[50] = "";
  char str2[50] = "";
  char str3[50] = "World";
  s21_strncat(str1, str3, 1);
  strncat(str2, str3, 1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(testCattingToANullString) {
  char str1[50] = "Hello ";
  char str2[50] = "Hello ";
  char str3[50] = "";
  s21_strncat(str1, str3, 4);
  strncat(str2, str3, 4);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(testCattingNothing) {
  char str1[50] = "Hello";
  char str2[50] = "Hello";
  char str3[50] = "123";
  s21_strncat(str1, str3, 0);
  strncat(str2, str3, 0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(testCattingOneSymbol) {
  char str1[50] = "Hello ";
  char str2[50] = "Hello ";
  char str3[50] = "Friend";
  s21_strncat(str1, str3, 1);
  strncat(str2, str3, 1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *suiteMemcpyTests() {
  Suite *suite = suite_create("memcpyTests");
  TCase *tcase = tcase_create("memcpyTests");
  tcase_add_test(tcase, testNormalCat);
  tcase_add_test(tcase, testCattingANullString);
  tcase_add_test(tcase, testCattingToANullString);
  tcase_add_test(tcase, testCattingNothing);
  tcase_add_test(tcase, testCattingOneSymbol);
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
