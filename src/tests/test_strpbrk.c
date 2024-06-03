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

#include "../s21_string.h"  // Подключение статической библиотеки

START_TEST(TestEmptyStrings) {
  char *str1 = "";
  char *str2 = "";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(TestNoMatches) {
  char *str1 = "abcdef";
  char *str2 = "ghijkl";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(TestSingleMatch) {
  char *str1 = "abcdef";
  char *str2 = "c";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(TestMultipleMatches) {
  char *str1 = "abcdef";
  char *str2 = "ae";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(TestAllMatches) {
  char *str1 = "abcdef";
  char *str2 = "abcdef";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(TestNullStr1) {
  char *str1 = "NULL";
  char *str2 = "abcdef";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(TestNullBoth) {
  char *str1 = "NULL";
  char *str2 = "NULL";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(TestNullStr2) {
  char *str1 = "abcdef";
  char *str2 = "NULL";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(TestNoAsciiChars) {
  char *str1 = "Привет мир";
  char *str2 = " ";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(TestSpecialChars) {
  char *str1 = "Hello\tWorld\n";
  char *str2 = "\t\n";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(TestEmptyStr2) {
  char *str1 = "abcdef";
  char *str2 = "";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(TestRepeating) {
  char *str1 = "aaabbbccc";
  char *str2 = "a";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(TestLargeString) {
  char largeStr[10000];
  memset(largeStr, 'a', sizeof(largeStr) - 1);
  largeStr[sizeof(largeStr) - 1] = '\0';
  char *str2 = "a";
  ck_assert_ptr_eq(s21_strpbrk(largeStr, str2), strpbrk(largeStr, str2));
}
END_TEST

START_TEST(TestNegativeIndex) {
  char *str1 = "abcdef";
  char *str2 = "-a";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(TestNotInStr2) {
  char *str1 = "1234567890";
  char *str2 = "a";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(TestLastMatch) {
  char *str1 = "abcdef";
  char *str2 = "f";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(TestFirstMatch) {
  char *str1 = "abcdef";
  char *str2 = "a";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

// Создание набора тестов для функции s21_strpbrk
Suite *S21StrpbrkSuite(void) {
  Suite *suite = suite_create("S21StrpbrkTests");
  TCase *tcaseCore = tcase_create("Core");

  // Добавление теста в набор тестов
  tcase_add_test(tcaseCore, TestEmptyStrings);
  tcase_add_test(tcaseCore, TestNoMatches);
  tcase_add_test(tcaseCore, TestSingleMatch);
  tcase_add_test(tcaseCore, TestMultipleMatches);
  tcase_add_test(tcaseCore, TestAllMatches);
  tcase_add_test(tcaseCore, TestNullStr1);
  tcase_add_test(tcaseCore, TestNullBoth);
  tcase_add_test(tcaseCore, TestNullStr2);
  tcase_add_test(tcaseCore, TestNoAsciiChars);
  tcase_add_test(tcaseCore, TestSpecialChars);
  tcase_add_test(tcaseCore, TestEmptyStr2);
  tcase_add_test(tcaseCore, TestRepeating);
  tcase_add_test(tcaseCore, TestLargeString);
  tcase_add_test(tcaseCore, TestNegativeIndex);
  tcase_add_test(tcaseCore, TestNotInStr2);
  tcase_add_test(tcaseCore, TestLastMatch);
  tcase_add_test(tcaseCore, TestFirstMatch);

  // Добавление набора тестов в общий набор
  suite_add_tcase(suite, tcaseCore);
  return suite;
}

// Главная функция для запуска тестов
int main(void) {
  int failed = 0;
  Suite *suite = S21StrpbrkSuite();
  SRunner *runner = srunner_create(suite);

  // Запуск всех тестов с нормальным режимом
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);

  // Освобождение ресурсов и возврат результата
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}