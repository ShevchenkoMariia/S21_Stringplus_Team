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
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_1) {
  for (int i = -1; i < 6; i++) {
    char *str1 = s21_strerror(i);
    char *str2 = strerror(i);
    ck_assert_str_eq(str1, str2);
  }
}
END_TEST

//-----------------------------------------------------------------

Suite *strerrorSuite(void) {
  Suite *s = suite_create("Strerror tests");
  TCase *tcCore = tcase_create("Tests");
  tcase_add_test(tcCore, test_1);
  suite_add_tcase(s, tcCore);

  return s;
}

int main() {
  int failed;
  Suite *s = strerrorSuite();
  SRunner *sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return failed == 0 ? 0 : 1;
}