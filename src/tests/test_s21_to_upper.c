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

START_TEST(TestEmptyString) {
  char *str = "";
  char *result = s21_to_upper(str);
  ck_assert_ptr_null(result);
  free(result);
}
END_TEST

START_TEST(TestNullInput) {
  char *result = s21_to_upper(s21_NULL);
  ck_assert_ptr_null(result);
  free(result);
}
END_TEST

START_TEST(TestSingleChar) {
  char *str = "a";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "A");
  free(result);
}
END_TEST

START_TEST(TestSingleCharUp) {
  char *str = "A";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "A");
  free(result);
}
END_TEST

START_TEST(TestAllLower) {
  char *str = "abcdefghijklmnopqrstuvwxyz";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  free(result);
}
END_TEST

START_TEST(TestAllUpper) {
  char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, str);
  free(result);
}
END_TEST

START_TEST(TestSimpleString) {
  char *str = "This is a long string";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "THIS IS A LONG STRING");
  free(result);
}
END_TEST

START_TEST(TestLettersWithNumbers) {
  char *str = "abc1234defg";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "ABC1234DEFG");
  free(result);
}
END_TEST

START_TEST(TestMixed) {
  char *str =
      "AbCdEfGhIjKlMnOpQrStUvWxYz1234567890@#$%^&*()_+{}|:\"<>?`~-=[];\',./~`";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(
      result,
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890@#$%^&*()_+{}|:\"<>?`~-=[];',./~`");
  free(result);
}
END_TEST

// Создание набора тестов для функции
Suite *S21ToUpperSuite(void) {
  Suite *suite = suite_create("S21ToUpperTests");
  TCase *tcaseCore = tcase_create("Core");

  // Добавление теста в набор тестов
  tcase_add_test(tcaseCore, TestEmptyString);
  tcase_add_test(tcaseCore, TestNullInput);
  tcase_add_test(tcaseCore, TestSingleChar);
  tcase_add_test(tcaseCore, TestSingleCharUp);
  tcase_add_test(tcaseCore, TestAllLower);
  tcase_add_test(tcaseCore, TestAllUpper);
  tcase_add_test(tcaseCore, TestSimpleString);
  tcase_add_test(tcaseCore, TestLettersWithNumbers);
  tcase_add_test(tcaseCore, TestMixed);

  // Добавление набора тестов в общий набор
  suite_add_tcase(suite, tcaseCore);
  return suite;
}

// Главная функция для запуска тестов
int main(void) {
  int failed = 0;
  Suite *suite = S21ToUpperSuite();
  SRunner *runner = srunner_create(suite);

  // Запуск всех тестов с нормальным режимом
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);

  // Освобождение ресурсов и возврат результата
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}