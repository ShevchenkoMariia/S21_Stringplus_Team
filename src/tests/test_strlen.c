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

// Тест для пустой строки
START_TEST(TestEmptyString) {
  char *str = "";
  s21_size_t result1 = s21_strlen(str);
  size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Проверка для односимвольной строки
START_TEST(TestOneCharacter1) {
  char *str = "a";
  s21_size_t result1 = s21_strlen(str);
  size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Проверка для односимвольной строки
START_TEST(TestOneCharacter2) {
  char *str = "-";
  s21_size_t result1 = s21_strlen(str);
  size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Проверка для строки, в которой несколько символов
START_TEST(TestMultipleCharacters) {
  char *str = "multiple characters";
  s21_size_t result1 = s21_strlen(str);
  size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест с завершающим нулевым символом
START_TEST(TestZeroCharacter) {
  char *str = "test\0";
  s21_size_t result1 = s21_strlen(str);
  size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест с многобайтовыми символами
START_TEST(TestMultibyteCharacters) {
  char *str = "Привет";
  s21_size_t result1 = s21_strlen(str);
  size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест с буфером, который содержит только нулевые символы
START_TEST(TestBufferWithTheNullCharacters) {
  char *str = "\0\0\0\0\0\0";
  s21_size_t result1 = s21_strlen(str);
  size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест с буфером, который содержит смесь символов и нулевых символов
START_TEST(TestMixtureOfCharactersAndNullCharacters) {
  char *str = "hsrtgs\0h;gui\0";
  s21_size_t result1 = s21_strlen(str);
  size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест с буфером, который содержит только один повторяющийся символ
START_TEST(TestOneRepeatingCharacter) {
  char *str = "aaaaaaaaaaa";
  s21_size_t result1 = s21_strlen(str);
  size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест с буфером, который содержит специальные символы
START_TEST(TestSpecialCharacters) {
  char *str = "a\nb\tc";
  s21_size_t result1 = s21_strlen(str);
  size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Создание набора тестов для функции s21_strlen
Suite *S21StrlenSuite(void) {
  Suite *suite = suite_create("S21StrlenTests");
  TCase *tcaseCore = tcase_create("Core");

  // Добавление теста в набор тестов
  tcase_add_test(tcaseCore, TestEmptyString);
  tcase_add_test(tcaseCore, TestOneCharacter1);
  tcase_add_test(tcaseCore, TestOneCharacter2);
  tcase_add_test(tcaseCore, TestMultipleCharacters);
  tcase_add_test(tcaseCore, TestZeroCharacter);
  tcase_add_test(tcaseCore, TestMultibyteCharacters);
  tcase_add_test(tcaseCore, TestBufferWithTheNullCharacters);
  tcase_add_test(tcaseCore, TestMixtureOfCharactersAndNullCharacters);
  tcase_add_test(tcaseCore, TestOneRepeatingCharacter);
  tcase_add_test(tcaseCore, TestSpecialCharacters);

  // Добавление набора тестов в общий набор
  suite_add_tcase(suite, tcaseCore);
  return suite;
}

// Главная функция для запуска тестов
int main(void) {
  int failed = 0;
  Suite *suite = S21StrlenSuite();
  SRunner *runner = srunner_create(suite);

  // Запуск всех тестов с нормальным режимом
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);

  // Освобождение ресурсов и возврат результата
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}