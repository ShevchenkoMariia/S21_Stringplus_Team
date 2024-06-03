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

START_TEST(TestInsertInEmptyStr) {
  char *str = "Hello";
  char *src = s21_NULL;
  s21_size_t startIndex = 3;
  char *result = s21_insert(src, str, startIndex);
  ck_assert_pstr_eq(result, s21_NULL);
  free(result);
}
END_TEST

START_TEST(TestInsertAtEndOfSrc) {
  char *str = "World";
  char *src = "Hello";
  s21_size_t startIndex = s21_strlen(src);
  char *result = s21_insert(src, str, startIndex);
  ck_assert_pstr_eq(result, "HelloWorld");
  free(result);
}
END_TEST

START_TEST(TestInsertAtStartOfSrc) {
  char *str = "World";
  char *src = "Hello";
  s21_size_t startIndex = 0;
  char *result = s21_insert(src, str, startIndex);
  ck_assert_pstr_eq(result, "WorldHello");
  free(result);
}
END_TEST

START_TEST(TestInsertInMiddleOfSrc) {
  char *str = " World!";
  char *src = "Hello";
  s21_size_t startIndex = 5;
  char *result = s21_insert(src, str, startIndex);
  ck_assert_pstr_eq(result, "Hello World!");
  free(result);
}
END_TEST

START_TEST(TestInsertWithNullSrc) {
  char *str = "World";
  char *src = s21_NULL;
  s21_size_t startIndex = 0;
  char *result = s21_insert(src, str, startIndex);
  ck_assert_pstr_eq(result, s21_NULL);
  free(result);
}
END_TEST

START_TEST(TestInsertEmptyString) {
  char *str = "";
  char *src = "Hello";
  s21_size_t startIndex = 3;
  char *result = s21_insert(src, str, startIndex);
  ck_assert_pstr_eq(result, "Hello");
  free(result);
}
END_TEST

// Создание набора тестов для функции
Suite *S21InsertSuite(void) {
  Suite *suite = suite_create("S21InsertTests");
  TCase *tcaseCore = tcase_create("Core");

  // Добавление теста в набор тестов
  tcase_add_test(tcaseCore, TestInsertInEmptyStr);
  tcase_add_test(tcaseCore, TestInsertAtEndOfSrc);
  tcase_add_test(tcaseCore, TestInsertAtStartOfSrc);
  tcase_add_test(tcaseCore, TestInsertInMiddleOfSrc);
  tcase_add_test(tcaseCore, TestInsertWithNullSrc);
  tcase_add_test(tcaseCore, TestInsertEmptyString);

  // Добавление набора тестов в общий набор
  suite_add_tcase(suite, tcaseCore);
  return suite;
}

// Главная функция для запуска тестов
int main(void) {
  int failed = 0;
  Suite *suite = S21InsertSuite();
  SRunner *runner = srunner_create(suite);

  // Запуск всех тестов с нормальным режимом
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);

  // Освобождение ресурсов и возврат результата
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}