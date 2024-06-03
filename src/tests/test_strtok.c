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

START_TEST(TestSimpleTokenString) {
  char s21_str[] = "hello++hello_*_!hello hello=======hello";
  char str[] = "hello++hello_*_!hello hello=======hello";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(strlen(s21), strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(TestHard_TokenString) {
  char s21_str[] = "      hello++hello__! A !hello _hello=======hello ";
  char str[] = "      hello++hello__! A !hello _hello=======hello ";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(strlen(s21), strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(TestNotAllDelims) {
  char s21_str[] = "hello++hello__!A!hello_hello=======hello";
  char str[] = "hello++hello__!A!hello_hello=======hello";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(strlen(s21), strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(TestNoDelims) {
  char s21_str[] = "HelloHelloHelloHello";
  char str[] = "HelloHelloHelloHello";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(strlen(s21), strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(TestDelimsStr) {
  char s21_str[] = "++!!= _";
  char str[] = "++!!= _";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_pstr_eq(s21, system);
}
END_TEST

START_TEST(TestDelimsInWord) {
  char s21_str[] = "Hello+*+aaaaa    !bbbbb     aba=aaaaa___aaaaa";
  char str[] = "Hello+*+aaaaa    !bbbbb     aba=aaaaa___aaaaa";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(strlen(s21), strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(TestHardWord) {
  char s21_str[] = "!A+*+A***A A=A_A_A*A";
  char str[] = "!A+*+A***A A=A_A_A*A";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(strlen(s21), strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(TestHardString) {
  char s21_str[] =
      "        !          hello+*+aaaaa***bbb    !aaaaaa     "
      "aba=hello_a__hello*** *** *** hi";
  char str[] =
      "        !          hello+*+aaaaa***bbb    !aaaaaa     "
      "aba=hello_a__hello*** *** *** hi";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(strlen(s21), strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

// Создание набора тестов для функции s21_strtok
Suite *S21StrtokSuite(void) {
  Suite *suite = suite_create("S21StrtokTests");
  TCase *tcaseCore = tcase_create("Core");

  // Добавление теста в набор тестов
  tcase_add_test(tcaseCore, TestSimpleTokenString);
  tcase_add_test(tcaseCore, TestHard_TokenString);
  tcase_add_test(tcaseCore, TestNotAllDelims);
  tcase_add_test(tcaseCore, TestNoDelims);
  tcase_add_test(tcaseCore, TestDelimsStr);
  tcase_add_test(tcaseCore, TestDelimsInWord);
  tcase_add_test(tcaseCore, TestHardWord);
  tcase_add_test(tcaseCore, TestHardString);

  // Добавление набора тестов в общий набор
  suite_add_tcase(suite, tcaseCore);
  return suite;
}

// Главная функция для запуска тестов
int main(void) {
  int failed = 0;
  Suite *suite = S21StrtokSuite();
  SRunner *runner = srunner_create(suite);

  // Запуск всех тестов с нормальным режимом
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);

  // Освобождение ресурсов и возврат результата
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
