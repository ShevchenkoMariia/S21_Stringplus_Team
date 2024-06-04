#include <check.h>
#include <string.h>
#define BUFFER 1000
#include "../s21_sprintf.h"

START_TEST(testInt) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  int value = 5;
  s21_sprintf(dest1, "%d", value);
  sprintf(dest2, "%d", value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testChar) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  char value = '5';
  s21_sprintf(dest1, "%c", value);
  sprintf(dest2, "%c", value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testFloat) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  double value = 5.55555;
  s21_sprintf(dest1, "%f", value);
  sprintf(dest2, "%f", value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testString) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  char value[10] = "5.55555";
  s21_sprintf(dest1, "%s", value);
  sprintf(dest2, "%s", value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testUnsigned) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  unsigned int value = -10;
  s21_sprintf(dest1, "%u", value);
  sprintf(dest2, "%u", value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testPercent) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  s21_sprintf(dest1, "%%");
  sprintf(dest2, "%%");
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testSmallG) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  float value = 25.3123;
  s21_sprintf(dest1, "%g", value);
  sprintf(dest2, "%g", value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testBigG) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  float value = 25.3123;
  s21_sprintf(dest1, "%G", value);
  sprintf(dest2, "%G", value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testSmallE) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  float value = 25.32971537;
  s21_sprintf(dest1, "%e", value);
  sprintf(dest2, "%e", value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testBigE) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  float value = 25.32971537;
  s21_sprintf(dest1, "%E", value);
  sprintf(dest2, "%E", value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testSmallX) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  unsigned int value = 25;
  s21_sprintf(dest1, "%x", value);
  sprintf(dest2, "%x", value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testBigX) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  unsigned int value = 25;
  s21_sprintf(dest1, "%X", value);
  sprintf(dest2, "%X", value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testO) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  unsigned int value = 25;
  s21_sprintf(dest1, "%o", value);
  sprintf(dest2, "%o", value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testPointer) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  char *value = dest1;
  s21_sprintf(dest1, "%p", value);
  sprintf(dest2, "%p", value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testMinus) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  int value = 25;
  s21_sprintf(dest1, "%-5d", value);
  sprintf(dest2, "%-5d", value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testPlus) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  int value = 25;
  s21_sprintf(dest1, "%+d", value);
  sprintf(dest2, "%+d", value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testSpacePositive) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  int value = 25;
  s21_sprintf(dest1, "% d", value);
  sprintf(dest2, "% d", value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testSpaceNegative) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  int value = -25;
  s21_sprintf(dest1, "% d", value);
  sprintf(dest2, "% d", value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST
START_TEST(testJailNonDecimal) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  int value = 25;
  double value2 = 25.123;
  s21_sprintf(dest1, "%#x %#e %#g", value, value2, value2);
  sprintf(dest2, "%#x %#e %#g", value, value2, value2);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testJailDecimal) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  float value = 25.1345;
  s21_sprintf(dest1, "%#e", value);
  sprintf(dest2, "%#e", value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testZeroInt) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  int value = 25;
  s21_sprintf(dest1, "%05d", value);
  sprintf(dest2, "%05d", value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testPrecision) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  float value = 25.123456;
  int value2 = 25;
  unsigned int value3 = 25;
  s21_sprintf(dest1, "%.5f %.5d %.5i %.5o %.5x", value, value2, value2, value3,
              value3);
  sprintf(dest2, "%.5f %.5d %.5i %.5o %.5x", value, value2, value2, value3,
          value3);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testWidth) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  float value = 25.123456;
  int value2 = 25;
  char value3 = 'c';
  s21_sprintf(dest1, "%10.5f %10d %10c %10p", value, value2, value3, dest1);
  sprintf(dest2, "%10.5f %10d %10c %10p", value, value2, value3, dest1);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testPrecisionStar) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  float value = 25.123456;
  s21_sprintf(dest1, "%.*f", 5, value);
  sprintf(dest2, "%.*f", 5, value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testWidthStar) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  float value = 25.123456;
  s21_sprintf(dest1, "%*.5f", 10, value);
  sprintf(dest2, "%*.5f", 10, value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testLengthH) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  short int value1 = 25;
  short unsigned int value2 = 25;
  s21_sprintf(dest1, "%hd %hi %ho %hu %hx %hX", value1, value1, value2, value2,
              value2, value2);
  sprintf(dest2, "%hd %hi %ho %hu %hx %hX", value1, value1, value2, value2,
          value2, value2);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testLengthSmallL) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  long int value1 = 25;
  long unsigned int value2 = 25;
  s21_sprintf(dest1, "%ld %li %lo %lu %lx %lX", value1, value1, value2, value2,
              value2, value2);
  sprintf(dest2, "%ld %li %lo %lu %lx %lX", value1, value1, value2, value2,
          value2, value2);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testLengthBigL) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  long double value = 25.23456789876754465;
  s21_sprintf(dest1, "%Lf %Le %Lg", value, value, value);
  sprintf(dest2, "%Lf %Le %Lg", value, value, value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testNothing) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};

  s21_sprintf(dest1, "NULL");
  sprintf(dest2, "NULL");
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testSomething) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  s21_sprintf(dest1, "1234");
  sprintf(dest2, "1234");
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testSomethingAndFormat) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  int value = 123;
  s21_sprintf(dest1, "123 = %d", value);
  sprintf(dest2, "123 = %d", value);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(testEveryThing) {
  char dest1[BUFFER] = {0};
  char dest2[BUFFER] = {0};
  short int value = 12;
  long double value2 = 12;
  s21_sprintf(dest1, "12 = %0*hd = %+10.5Lf", 10, value, value2);
  sprintf(dest2, "12 = %0*hd = %+10.5Lf", 10, value, value2);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

Suite *sprintfSuite(void) {
  Suite *s;
  TCase *tcCore;
  s = suite_create("sprintfTestsSuite");
  tcCore = tcase_create("Core");
  tcase_add_test(tcCore, testInt);
  tcase_add_test(tcCore, testInt);
  tcase_add_test(tcCore, testChar);
  tcase_add_test(tcCore, testFloat);
  tcase_add_test(tcCore, testString);
  tcase_add_test(tcCore, testUnsigned);
  tcase_add_test(tcCore, testPercent);
  tcase_add_test(tcCore, testSmallG);
  tcase_add_test(tcCore, testBigG);
  tcase_add_test(tcCore, testSmallE);
  tcase_add_test(tcCore, testBigE);
  tcase_add_test(tcCore, testSmallX);
  tcase_add_test(tcCore, testBigX);
  tcase_add_test(tcCore, testO);
  tcase_add_test(tcCore, testPointer);
  tcase_add_test(tcCore, testMinus);
  tcase_add_test(tcCore, testPlus);
  tcase_add_test(tcCore, testSpacePositive);
  tcase_add_test(tcCore, testSpaceNegative);
  tcase_add_test(tcCore, testJailNonDecimal);
  tcase_add_test(tcCore, testJailDecimal);
  tcase_add_test(tcCore, testZeroInt);
  tcase_add_test(tcCore, testPrecision);
  tcase_add_test(tcCore, testWidth);
  tcase_add_test(tcCore, testPrecisionStar);
  tcase_add_test(tcCore, testWidthStar);
  tcase_add_test(tcCore, testLengthH);
  tcase_add_test(tcCore, testLengthSmallL);
  tcase_add_test(tcCore, testLengthBigL);
  tcase_add_test(tcCore, testNothing);
  tcase_add_test(tcCore, testSomething);
  tcase_add_test(tcCore, testSomethingAndFormat);
  tcase_add_test(tcCore, testEveryThing);

  suite_add_tcase(s, tcCore);

  return s;
}

int main(void) {
  int numberFailed = 0;
  Suite *s;
  SRunner *sr;

  s = sprintfSuite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  numberFailed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (numberFailed == 0) ? 0 : 1;
}
