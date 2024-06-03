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

// Тест с корректными данными
START_TEST(TestCorrectData) {
  char arr1[20] = {0};
  char arr2[20] = {0};
  char value = 'a';
  size_t size1 = 10;
  s21_size_t size2 = 10;

  memset(&arr1, value, size1);
  char *result2 = s21_memset(&arr2, value, size2);

  // сравниваем массивы на идентичность заполнения в битах
  for (size_t i = 0; i < size1; ++i) {
    ck_assert_int_eq(arr1[i], arr2[i]);
  }

  // сравниваем массивы на идентичность заполнения в смволах
  ck_assert_msg(strcmp(arr1, arr2) == 0, "Strings are not equal");

  // проверяем возвращаемый указатель
  ck_assert_ptr_eq(result2, &arr2);
}
END_TEST

// Тест с нулевым значением
START_TEST(TestZeroValue) {
  char arr1[20] = {0};
  char arr2[20] = {0};
  char value = '\0';
  size_t size1 = 10;
  s21_size_t size2 = 10;

  memset(&arr1, value, size1);
  char *result2 = s21_memset(&arr2, value, size2);

  // сравниваем массивы на идентичность заполнения в битах
  for (size_t i = 0; i < size1; ++i) {
    ck_assert_int_eq(arr1[i], arr2[i]);
  }

  // сравниваем массивы на идентичность заполнения в смволах
  ck_assert_msg(strcmp(arr1, arr2) == 0, "Strings are not equal");

  // проверяем возвращаемый указатель
  ck_assert_ptr_eq(result2, &arr2);
}
END_TEST

// Тест с размером, равным нулю
START_TEST(TestZeroSize) {
  char arr1[20] = {0};
  char arr2[20] = {0};
  char value = 'a';
  size_t size1 = 0;
  s21_size_t size2 = 0;

  memset(&arr1, value, size1);
  char *result2 = s21_memset(&arr2, value, size2);

  // сравниваем массивы на идентичность заполнения в символах
  ck_assert_msg(strcmp(arr1, arr2) == 0, "Strings are not equal");

  // проверяем возвращаемый указатель
  ck_assert_ptr_eq(result2, &arr2);
}
END_TEST

// Тест с размером, равным размеру массива
START_TEST(TestSizeIsEqualToTheSizeOfTheArray) {
  char arr1[20] = {0};
  char arr2[20] = {0};
  char value = 'a';
  size_t size1 = 20;
  s21_size_t size2 = 20;

  memset(&arr1, value, size1);
  char *result2 = s21_memset(&arr2, value, size2);

  // сравниваем массивы на идентичность заполнения в битах
  for (size_t i = 0; i < size1; ++i) {
    ck_assert_int_eq(arr1[i], arr2[i]);
  }

  // проверяем возвращаемый указатель
  ck_assert_ptr_eq(result2, &arr2);
}
END_TEST

// Тест с размером, равным размеру массива минус 1
START_TEST(TestSizeMinusOne) {
  char arr1[20] = {0};
  char arr2[20] = {0};
  char value = 'a';
  size_t size1 = 19;
  s21_size_t size2 = 19;

  memset(&arr1, value, size1);
  char *result2 = s21_memset(&arr2, value, size2);

  // сравниваем массивы на идентичность заполнения в битах
  for (size_t i = 0; i < size1; ++i) {
    ck_assert_int_eq(arr1[i], arr2[i]);
  }

  // сравниваем массивы на идентичность заполнения в смволах
  ck_assert_msg(strcmp(arr1, arr2) == 0, "Strings are not equal");

  // проверяем возвращаемый указатель
  ck_assert_ptr_eq(result2, &arr2);
}
END_TEST

// Создание набора тестов для функции s21_memset
Suite *S21MemsetSuite(void) {
  Suite *suite = suite_create("S21MemsetTests");
  TCase *tcaseCore = tcase_create("Core");

  // Добавление теста в набор тестов
  tcase_add_test(tcaseCore, TestCorrectData);
  tcase_add_test(tcaseCore, TestZeroValue);
  tcase_add_test(tcaseCore, TestZeroSize);
  tcase_add_test(tcaseCore, TestSizeIsEqualToTheSizeOfTheArray);
  tcase_add_test(tcaseCore, TestSizeMinusOne);

  // Добавление набора тестов в общий набор
  suite_add_tcase(suite, tcaseCore);
  return suite;
}

// Главная функция для запуска тестов
int main(void) {
  int failed;
  Suite *suite = S21MemsetSuite();
  SRunner *runner = srunner_create(suite);

  // Запуск всех тестов с нормальным режимом
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);

  // Освобождение ресурсов и возврат результата
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}