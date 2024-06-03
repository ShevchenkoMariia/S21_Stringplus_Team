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

START_TEST(test_1) {
  const char *str_1 = "Hello";
  const char *str_2 = "Hello ";
  ck_assert_int_eq(s21_strncmp(str_1, str_2, 5), strncmp(str_1, str_2, 5));
}
END_TEST

START_TEST(test_2) {
  const char *str1 = "Hello";
  const char *str2 = "Hella";
  ck_assert_int_eq(s21_strncmp(str1, str2, 4), strncmp(str1, str2, 4));
}
END_TEST

START_TEST(test_3) {
  const char *str1 = "Helloaaaa";
  const char *str2 = "Hella";
  ck_assert_int_eq(s21_strncmp(str1, str2, 7), strncmp(str1, str2, 7));
}
END_TEST

START_TEST(test_4) {
  const char *str1 = "Hello";
  const char *str2 = "Hellapipapupa";
  ck_assert_int_eq(s21_strncmp(str1, str2, 7), strncmp(str1, str2, 7));
}
END_TEST

START_TEST(test_5) {
  const char *str1 = "Hel\0lo";
  const char *str2 = "Hel\0lo";
  ck_assert_int_eq(s21_strncmp(str1, str2, 7), strncmp(str1, str2, 7));
}
END_TEST

//--------------------------------------------------------------------------

Suite *strncmpSuite(void) {
  Suite *s = suite_create("Strncmp tests");
  TCase *tcCore = tcase_create("Tests");
  tcase_add_test(tcCore, test_1);
  tcase_add_test(tcCore, test_2);
  tcase_add_test(tcCore, test_3);
  tcase_add_test(tcCore, test_4);
  tcase_add_test(tcCore, test_5);

  suite_add_tcase(s, tcCore);

  return s;
}

int main() {
  int failed = 0;
  Suite *s = strncmpSuite();
  SRunner *sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return failed == 0 ? 0 : 1;
}
