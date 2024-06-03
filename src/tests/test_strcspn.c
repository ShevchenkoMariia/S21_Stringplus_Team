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

// Тест на пустую исходную строку и пустой набор символов
START_TEST(TestEmptyLines) {
  char *str1 = "";
  char *str2 = "";
  size_t result1 = strcspn(str1, str2);
  s21_size_t result2 = s21_strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест на пустую исходную строку и непустой набор символов
START_TEST(TestEmptySourceString) {
  char *str1 = "";
  char *str2 = "aaa";
  size_t result1 = strcspn(str1, str2);
  s21_size_t result2 = s21_strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест на непустую исходную строку и пустой набор символов
START_TEST(TestAnEmptySet) {
  char *str1 = "aaa";
  char *str2 = "";
  size_t result1 = strcspn(str1, str2);
  s21_size_t result2 = s21_strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест, где все символы входят в набор
START_TEST(TestAllCharactersOfTheSet) {
  char *str1 = "Hi, my dear!";
  char *str2 = "Hi, my dear!";
  size_t result1 = strcspn(str1, str2);
  s21_size_t result2 = s21_strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест, где все многобайтовые символы входят в набор
START_TEST(TestMultibyteCharacters) {
  char *str1 = "Привет!";
  char *str2 = "Привет!";
  size_t result1 = strcspn(str1, str2);
  s21_size_t result2 = s21_strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест, где не все многобайтовые символы входят в набор
START_TEST(TestNotAllMultibyteCharacters) {
  char *str1 = "Привет!";
  char *str2 = "и?";
  size_t result1 = strcspn(str1, str2);
  s21_size_t result2 = s21_strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест, где не все символы входят в набор
START_TEST(TestNotAllCharactersInTheSet) {
  char *str1 = "Hi, my dear!";
  char *str2 = "my dear";
  size_t result1 = strcspn(str1, str2);
  s21_size_t result2 = s21_strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест на строку из специальных символов
START_TEST(TestStringOfSpecialCharacter1) {
  char *str1 = "Hi\n\tMy";
  char *str2 = "\n\tMy";
  size_t result1 = strcspn(str1, str2);
  s21_size_t result2 = s21_strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест на строку из специальных символов
START_TEST(TestStringOfSpecialCharacter2) {
  char *str1 = "\n\tMy";
  char *str2 = "Hi\n\tMy";
  size_t result1 = strcspn(str1, str2);
  s21_size_t result2 = s21_strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест на строку, содержащую только \0 не в исходной строке
START_TEST(TestLineZero1) {
  char *str1 = "Hi, my \0dear!";
  char *str2 = "\0";
  size_t result1 = strcspn(str1, str2);
  s21_size_t result2 = s21_strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест на строку, содержащую \0 в середине исходной строки
START_TEST(TestLineZero2) {
  char *str1 = "Hi, my \0dear!";
  char *str2 = "d";
  size_t result1 = strcspn(str1, str2);
  s21_size_t result2 = s21_strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест на строку, содержащую \0 в начале исходной строки
START_TEST(TestLineZero3) {
  char *str1 = "\0Hi, my dear!";
  char *str2 = "m";
  size_t result1 = strcspn(str1, str2);
  s21_size_t result2 = s21_strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест на строку, содержащую цифры
START_TEST(TestaStringWithNumbers) {
  char *str1 = "1234567890";
  char *str2 = "5";
  size_t result1 = strcspn(str1, str2);
  s21_size_t result2 = s21_strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест на исходную строку из символов, не входящих в набор
START_TEST(TestDifferentCharacters) {
  char *str1 = "asdfgh";
  char *str2 = "zxcvbn";
  size_t result1 = strcspn(str1, str2);
  s21_size_t result2 = s21_strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Создание набора тестов для функции s21_strcspn
Suite *S21StrcspnSuite(void) {
  Suite *suite = suite_create("S21StrcspnTests");
  TCase *tcaseCore = tcase_create("Core");

  // Добавление теста в набор тестов
  tcase_add_test(tcaseCore, TestEmptyLines);
  tcase_add_test(tcaseCore, TestEmptySourceString);
  tcase_add_test(tcaseCore, TestAnEmptySet);
  tcase_add_test(tcaseCore, TestAllCharactersOfTheSet);
  tcase_add_test(tcaseCore, TestMultibyteCharacters);
  tcase_add_test(tcaseCore, TestNotAllMultibyteCharacters);
  tcase_add_test(tcaseCore, TestNotAllCharactersInTheSet);
  tcase_add_test(tcaseCore, TestStringOfSpecialCharacter1);
  tcase_add_test(tcaseCore, TestStringOfSpecialCharacter2);
  tcase_add_test(tcaseCore, TestLineZero1);
  tcase_add_test(tcaseCore, TestLineZero2);
  tcase_add_test(tcaseCore, TestLineZero3);
  tcase_add_test(tcaseCore, TestaStringWithNumbers);
  tcase_add_test(tcaseCore, TestDifferentCharacters);

  // Добавление набора тестов в общий набор
  suite_add_tcase(suite, tcaseCore);
  return suite;
}

// Главная функция для запуска тестов
int main(void) {
  int failed = 0;
  Suite *suite = S21StrcspnSuite();
  SRunner *runner = srunner_create(suite);

  // Запуск всех тестов с нормальным режимом
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);

  // Освобождение ресурсов и возврат результата
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
