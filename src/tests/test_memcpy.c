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
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

typedef struct {
  int id;
  char name[50];
} Person;

START_TEST(testIntArray) {
  int arr1[5] = {1, 2, 3, 4, 5};
  int arr2[5] = {0};
  int arr3[5] = {0};
  s21_memcpy(arr2, arr1, 3 * sizeof(int));
  memcpy(arr3, arr1, 3 * sizeof(int));
  char *arr22 = (char *)arr2;
  char *arr33 = (char *)arr3;
  ck_assert_str_eq(arr22, arr33);
}
END_TEST

START_TEST(testCharArray) {
  char arr1[5] = {'a', 'b', 'c', 'd', 'e'};
  char arr2[5] = {0};
  char arr3[5] = {0};
  s21_memcpy(arr2, arr1, 3 * sizeof(char));
  memcpy(arr3, arr1, 3 * sizeof(char));
  ck_assert_str_eq(arr2, arr3);
}
END_TEST

START_TEST(testStruct) {
  Person person1 = {1, "John Doe"};
  Person person2;
  Person person3;
  s21_memcpy(&person2, &person1, sizeof(Person));
  memcpy(&person3, &person1, sizeof(Person));

  int condition =
      (person2.id == person3.id && !strcmp(person2.name, person3.name));
  ck_assert_msg(condition, "Structs are not equal");
}
END_TEST

START_TEST(testCopiingNothing) {
  char arr1[5] = {'a', 'b', 'c', 'd', 'e'};
  char arr2[5] = {0};
  char arr3[5] = {0};
  s21_memcpy(arr2, arr1, 0);
  memcpy(arr3, arr1, 0);
  ck_assert_str_eq(arr2, arr3);
}
END_TEST

START_TEST(testCopiingOneByte) {
  char arr1 = 'a';
  char arr2 = 0;
  char arr3 = 0;
  s21_memcpy(&arr2, &arr1, 1);
  memcpy(&arr3, &arr1, 1);
  ck_assert_int_eq(arr2, arr3);
}
END_TEST

Suite *suiteMemcpyTests() {
  Suite *suite = suite_create("memcpyTests");
  TCase *tcase = tcase_create("memcpyTests");
  tcase_add_test(tcase, testIntArray);
  tcase_add_test(tcase, testCharArray);
  tcase_add_test(tcase, testStruct);
  tcase_add_test(tcase, testCopiingNothing);
  tcase_add_test(tcase, testCopiingOneByte);
  suite_add_tcase(suite, tcase);
  return suite;
}

int main() {
  int failed = 0;
  Suite *suite = suiteMemcpyTests();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
