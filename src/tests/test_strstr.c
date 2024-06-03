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

START_TEST(TestEmptyStrings) {
  char *haystack = "";
  char *needle = "";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(TestEmptyStringHaystack) {
  char *haystack = "";
  char *needle = "example";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(TestEmptyStringNeedle) {
  char *haystack = "hello";
  char *needle = "";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(TestStringWithoutSubstring) {
  char *haystack = "hello";
  char *needle = "goodbye";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(TestSubstringAtBeginning) {
  char *haystack = "hello world";
  char *needle = "hello";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(TestSubstringInMiddle) {
  char *haystack = "hello world";
  char *needle = "world";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(TestSubstringAtEnd) {
  char *haystack = "hello world";
  char *needle = "orld";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(TestSubstringExactlyOnce) {
  char *haystack = "hello hello";
  char *needle = "hello";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(TestNullHaystack) {
  char *haystack = "";
  char *needle = "hello";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(TestNullNeedle) {
  char *haystack = "hello";
  char *needle = "";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(TestNullBoth) {
  char *haystack = "";
  char *needle = "";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(TestNonAsciiChars) {
  char *haystack = "Привет мир";
  char *needle = "мир";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(TestSpacesAndSpecialSymb) {
  char *haystack = "Hello, World! ?";
  char *needle = ", World!";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// Создание набора тестов для функции s21_strstr
Suite *S21StrstrSuite(void) {
  Suite *suite = suite_create("S21StrstrTests");
  TCase *tcaseCore = tcase_create("Core");

  // Добавление теста в набор тестов
  tcase_add_test(tcaseCore, TestEmptyStrings);
  tcase_add_test(tcaseCore, TestEmptyStringHaystack);
  tcase_add_test(tcaseCore, TestEmptyStringNeedle);
  tcase_add_test(tcaseCore, TestStringWithoutSubstring);
  tcase_add_test(tcaseCore, TestSubstringAtBeginning);
  tcase_add_test(tcaseCore, TestSubstringInMiddle);
  tcase_add_test(tcaseCore, TestSubstringAtEnd);
  tcase_add_test(tcaseCore, TestSubstringExactlyOnce);
  tcase_add_test(tcaseCore, TestNullHaystack);
  tcase_add_test(tcaseCore, TestNullNeedle);
  tcase_add_test(tcaseCore, TestNullBoth);
  tcase_add_test(tcaseCore, TestNonAsciiChars);
  tcase_add_test(tcaseCore, TestSpacesAndSpecialSymb);

  // Добавление набора тестов в общий набор
  suite_add_tcase(suite, tcaseCore);
  return suite;
}

// Главная функция для запуска тестов
int main(void) {
  int failed = 0;
  Suite *suite = S21StrstrSuite();
  SRunner *runner = srunner_create(suite);

  // Запуск всех тестов с нормальным режимом
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);

  // Освобождение ресурсов и возврат результата
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}