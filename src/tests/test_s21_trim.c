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

START_TEST(TestNull) {
  char *src = "Hello";
  char *trimChars = s21_NULL;
  char *result = s21_trim(src, trimChars);
  ck_assert_pstr_eq(result, s21_NULL);
  free(result);
}
END_TEST

START_TEST(TestInStart) {
  char *src = "  Hello";
  char *trimChars = " ";
  char *result = s21_trim(src, trimChars);
  ck_assert_pstr_eq(result, "Hello");
  free(result);
}
END_TEST

START_TEST(TestInEnd) {
  char *src = "Hello    ";
  char *trimChars = " ";
  char *result = s21_trim(src, trimChars);
  ck_assert_pstr_eq(result, "Hello");
  free(result);
}
END_TEST

START_TEST(TestInStartAndEnd) {
  char *src = "  Hello    ";
  char *trimChars = " ";
  char *result = s21_trim(src, trimChars);
  ck_assert_pstr_eq(result, "Hello");
  free(result);
}
END_TEST

START_TEST(TestSimpleTrim) {
  char *src = "Hello World";
  char *trimChars = "Hel";
  char *result = s21_trim(src, trimChars);
  ck_assert_pstr_eq(result, "o World");
  free(result);
}
END_TEST

START_TEST(TestTrimAll) {
  char *src = "Hello";
  char *trimChars = "Hello";
  char *result = s21_trim(src, trimChars);
  ck_assert_pstr_eq(result, "");
  free(result);
}
END_TEST

START_TEST(TestTrimInNull) {
  char *src = s21_NULL;
  char *trimChars = " ";
  char *result = s21_trim(src, trimChars);
  ck_assert_pstr_eq(result, s21_NULL);
  free(result);
}
END_TEST

START_TEST(TestTrimFailure) {
  char *src = "Hello";
  char *trimChars = "l";
  char *result = s21_trim(src, trimChars);
  ck_assert_pstr_eq(result, "Hello");
  free(result);
}
END_TEST

START_TEST(TestNonExistentTrim) {
  char *src = "Hello";
  char *trimChars = "m";
  char *result = s21_trim(src, trimChars);
  ck_assert_pstr_eq(result, "Hello");
  free(result);
}
END_TEST

// Создание набора тестов для функции
Suite *S21TrimSuite(void) {
  Suite *suite = suite_create("S21TrimTests");
  TCase *tcaseCore = tcase_create("Core");

  // Добавление теста в набор тестов
  tcase_add_test(tcaseCore, TestNull);
  tcase_add_test(tcaseCore, TestInStart);
  tcase_add_test(tcaseCore, TestInEnd);
  tcase_add_test(tcaseCore, TestInStartAndEnd);
  tcase_add_test(tcaseCore, TestSimpleTrim);
  tcase_add_test(tcaseCore, TestTrimAll);
  tcase_add_test(tcaseCore, TestTrimInNull);
  tcase_add_test(tcaseCore, TestTrimFailure);
  tcase_add_test(tcaseCore, TestNonExistentTrim);

  // Добавление набора тестов в общий набор
  suite_add_tcase(suite, tcaseCore);
  return suite;
}

// Главная функция для запуска тестов
int main(void) {
  int failed = 0;
  Suite *suite = S21TrimSuite();
  SRunner *runner = srunner_create(suite);

  // Запуск всех тестов с нормальным режимом
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);

  // Освобождение ресурсов и возврат результата
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}