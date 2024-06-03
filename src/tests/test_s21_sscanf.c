#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "../s21_string.h"

START_TEST(testSscanfC1) {
  char str[] = "a";
  char resS21 = ' ';
  char resStd = ' ';
  int rcS21 = s21_sscanf(str, "%c", &resS21);
  int rcStd = sscanf(str, "%c", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfC2) {
  char str[] = " A ";
  char resS21 = ' ';
  char resStd = ' ';
  int rcS21 = s21_sscanf(str, "%c", &resS21);
  int rcStd = sscanf(str, "%c", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfC3) {
  char str[] = "123";
  char resS21 = ' ';
  char resStd = ' ';
  int rcS21 = s21_sscanf(str, "%c", &resS21);
  int rcStd = sscanf(str, "%c", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfC4) {
  char str[] = "";
  char resS21 = ' ';
  char resStd = ' ';
  int rcS21 = s21_sscanf(str, "%c", &resS21);
  int rcStd = sscanf(str, "%c", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfC5) {
  char str[] = "abc";
  char resS21 = ' ';
  char resStd = ' ';
  int rcS21 = s21_sscanf(str, "%c", &resS21);
  int rcStd = sscanf(str, "%c", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfC6) {
  char str[] = "\ta";
  char resS21 = ' ';
  char resStd = ' ';
  int rcS21 = s21_sscanf(str, "%c", &resS21);
  int rcStd = sscanf(str, "%c", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfC7) {
  char str[] = "\na";
  char resS21 = ' ';
  char resStd = ' ';
  int rcS21 = s21_sscanf(str, "%c", &resS21);
  int rcStd = sscanf(str, "%c", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfC8) {
  char str[] = "\0";
  char resS21 = ' ';
  char resStd = ' ';
  int rcS21 = s21_sscanf(str, "%c", &resS21);
  int rcStd = sscanf(str, "%c", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfC9) {
  char str[] = "abc";
  char resS21 = ' ';
  char resStd = ' ';
  int rcS21 = s21_sscanf(str, "%c", &resS21);
  int rcStd = sscanf(str, "%c", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfC10) {
  char str[] = "abc";
  char resS21 = ' ';
  char resStd = ' ';
  int rcS21 = s21_sscanf(str, "%1c", &resS21);
  int rcStd = sscanf(str, "%1c", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfC11) {
  char str[] = "abc";
  char resS21 = ' ';
  char resStd = ' ';
  int rcS21 = s21_sscanf(str, "%*c%c", &resS21);
  int rcStd = sscanf(str, "%*c%c", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

/////////////////////////////

START_TEST(testSscanfD1) {
  char str[] = "123";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%d", &resS21);
  int rcStd = sscanf(str, "%d", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfD2) {
  char str[] = "-123";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%d", &resS21);
  int rcStd = sscanf(str, "%d", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfD3) {
  char str[] = "0";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%d", &resS21);
  int rcStd = sscanf(str, "%d", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfD4) {
  char str[] = "+123";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%d", &resS21);
  int rcStd = sscanf(str, "%d", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfD5) {
  char str[] = " 123 ";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%d", &resS21);
  int rcStd = sscanf(str, "%d", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfD6) {
  char str[] = "123 345";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%d", &resS21);
  int rcStd = sscanf(str, "%d", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfD7) {
  char str[] = "abc";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%d", &resS21);
  int rcStd = sscanf(str, "%d", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfD8) {
  char str[] = "123.45";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%d", &resS21);
  int rcStd = sscanf(str, "%d", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfD9) {
  char str[] = "123a";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%d", &resS21);
  int rcStd = sscanf(str, "%d", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfD10) {
  char str[] = "+123abc";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%d", &resS21);
  int rcStd = sscanf(str, "%d", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfD11) {
  char str[] = "1234567890";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%3d", &resS21);
  int rcStd = sscanf(str, "%3d", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfD12) {
  char str[] = "+1234567890";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%5d", &resS21);
  int rcStd = sscanf(str, "%5d", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfD13) {
  char str[] = "-1234567890";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%7d", &resS21);
  int rcStd = sscanf(str, "%7d", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfD14) {
  char str[] = "123 456";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%d%*d", &resS21);
  int rcStd = sscanf(str, "%d%*d", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfD15) {
  char str[] = "123 456";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%*d%d", &resS21);
  int rcStd = sscanf(str, "%*d%d", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfD16) {
  char str[] = "123 456 789";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%d%*d%*d", &resS21);
  int rcStd = sscanf(str, "%d%*d%*d", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

///////////////////////////////
START_TEST(testSscanfI1) {
  char str[] = "123";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%i", &resS21);
  int rcStd = sscanf(str, "%i", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfI2) {
  char str[] = "-123";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%i", &resS21);
  int rcStd = sscanf(str, "%i", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfI3) {
  char str[] = "+123";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%i", &resS21);
  int rcStd = sscanf(str, "%i", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfI4) {
  char str[] = "0";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%i", &resS21);
  int rcStd = sscanf(str, "%i", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfI5) {
  char str[] = "123   123";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%i", &resS21);
  int rcStd = sscanf(str, "%i", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfI6) {
  char str[] = "20";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%i", &resS21);
  int rcStd = sscanf(str, "%i", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfI7) {
  char str[] = "123.45";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%i", &resS21);
  int rcStd = sscanf(str, "%i", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfI8) {
  char str[] = "123a";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%i", &resS21);
  int rcStd = sscanf(str, "%i", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfI9) {
  char str[] = "+123abc";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%i", &resS21);
  int rcStd = sscanf(str, "%i", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfI10) {
  char str[] = "1234567890";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%3i", &resS21);
  int rcStd = sscanf(str, "%3i", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfI11) {
  char str[] = "-1234567890";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%5i", &resS21);
  int rcStd = sscanf(str, "%5i", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfI12) {
  char str[] = "123 456";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%i%*i", &resS21);
  int rcStd = sscanf(str, "%i%*i", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfI13) {
  char str[] = "123 456";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%*i%i", &resS21);
  int rcStd = sscanf(str, "%*i%i", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfI14) {
  char str[] = "123 456 789";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%i%*i%*i", &resS21);
  int rcStd = sscanf(str, "%i%*i%*i", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfI17) {
  char str[] = "0123";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%i", &resS21);
  int rcStd = sscanf(str, "%i", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfI18) {
  char str[] = "0x123";
  int resS21 = 0;
  int resStd = 0;
  int rcS21 = s21_sscanf(str, "%i", &resS21);
  int rcStd = sscanf(str, "%i", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST
//////////////////////
START_TEST(testSscanfE1) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("1.234e+5", "%e", &resS21);
  int rcStd = sscanf("1.234e+5", "%e", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfE2) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("-1.234e-5", "%e", &resS21);
  int rcStd = sscanf("-1.234e-5", "%e", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfE3) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("123.45e+0", "%e", &resS21);
  int rcStd = sscanf("123.45e+0", "%e", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfE4) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("1e10", "%e", &resS21);
  int rcStd = sscanf("1e10", "%e", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfE5) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("1.e-10", "%e", &resS21);
  int rcStd = sscanf("1.e-10", "%e", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfE6) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("1.234E+5", "%E", &resS21);
  int rcStd = sscanf("1.234E+5", "%E", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfE7) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("-1.234E-5", "%E", &resS21);
  int rcStd = sscanf("-1.234E-5", "%E", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfE8) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("123.45E+0", "%E", &resS21);
  int rcStd = sscanf("123.45E+0", "%E", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfE9) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("1E10", "%E", &resS21);
  int rcStd = sscanf("1E10", "%E", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfE10) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("1.E-10", "%E", &resS21);
  int rcStd = sscanf("1.E-10", "%E", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfE11) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("abc", "%e", &resS21);
  int rcStd = sscanf("abc", "%e", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfE12) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("1.234e+", "%e", &resS21);
  int rcStd = sscanf("1.234e+", "%e", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfE13) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("1.234e-abc", "%e", &resS21);
  int rcStd = sscanf("1.234e-abc", "%e", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfE14) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("1.234e abc", "%e", &resS21);
  int rcStd = sscanf("1.234e abc", "%e", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfE15) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("1.23456789e+10", "%5e", &resS21);
  int rcStd = sscanf("1.23456789e+10", "%5e", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfE16) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("1.234e+5 5.678e+9", "%e%*e", &resS21);
  int rcStd = sscanf("1.234e+5 5.678e+9", "%e%*e", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfE17) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("1.234e+5 5.678e+9", "%*e%e", &resS21);
  int rcStd = sscanf("1.234e+5 5.678e+9", "%*e%e", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfE18) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("1.234e+3", "%e", &resS21);
  int rcStd = sscanf("1.234e+3", "%e", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfE19) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("1.234e-308", "%e", &resS21);
  int rcStd = sscanf("1.234e-308", "%e", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST
///////////////////////////
START_TEST(testSscanfF1) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("123.456", "%f", &resS21);
  int rcStd = sscanf("123.456", "%f", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfF2) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("-123.456", "%f", &resS21);
  int rcStd = sscanf("-123.456", "%f", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfF3) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("0.123456", "%f", &resS21);
  int rcStd = sscanf("0.123456", "%f", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfF4) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("123.", "%f", &resS21);
  int rcStd = sscanf("123.", "%f", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfF5) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf(".123456", "%f", &resS21);
  int rcStd = sscanf(".123456", "%f", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfF6) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("abc", "%f", &resS21);
  int rcStd = sscanf("abc", "%f", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfF7) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("123.456.789", "%f", &resS21);
  int rcStd = sscanf("123.456.789", "%f", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfF8) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("123,456", "%f", &resS21);
  int rcStd = sscanf("123,456", "%f", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfF9) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("123.456e+5", "%f", &resS21);
  int rcStd = sscanf("123.456e+5", "%f", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfF10) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("123.456789", "%5f", &resS21);
  int rcStd = sscanf("123.456789", "%5f", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfF11) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("123.456789", "%10f", &resS21);
  int rcStd = sscanf("123.456789", "%10f", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfF12) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("123.456 567.890", "%f%*f", &resS21);
  int rcStd = sscanf("123.456 567.890", "%f%*f", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfF13) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("123.456 567.890", "%*f%f", &resS21);
  int rcStd = sscanf("123.456 567.890", "%*f%f", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfF14) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("3.402823466e+38", "%f", &resS21);
  int rcStd = sscanf("3.402823466e+38", "%f", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfF15) {
  float resS21 = 0.0;
  float resStd = 0.0;
  int rcS21 = s21_sscanf("1.175494351e-38", "%f", &resS21);
  int rcStd = sscanf("1.175494351e-38", "%f", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST
/////////////////////////
START_TEST(testSscanfGg1) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("123.456", "%g", &resS21);
  int rcStd = sscanf("123.456", "%g", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfGg2) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("0.123456", "%g", &resS21);
  int rcStd = sscanf("0.123456", "%g", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfGg3) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("123", "%g", &resS21);
  int rcStd = sscanf("123", "%g", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfGg4) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("1.23e+4", "%g", &resS21);
  int rcStd = sscanf("1.23e+4", "%g", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfGg5) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("1.23E+4", "%G", &resS21);
  int rcStd = sscanf("1.23E+4", "%G", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfGg6) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("1.23e-4", "%g", &resS21);
  int rcStd = sscanf("1.23e-4", "%g", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfGg7) {
  float resS21 = 0.0, resStd = 0.0;  // тип переменных остаётся double
  int rcS21 = s21_sscanf("1.23E-4", "%G", &resS21);
  int rcStd = sscanf("1.23E-4", "%G", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd,
                          1e-6);  //  используем ck_assert_double_eq_tol
}
END_TEST

START_TEST(testSscanfGg8) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf(" 123.456 ", "%g", &resS21);
  int rcStd = sscanf(" 123.456 ", "%g", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfGg9) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("abc", "%g", &resS21);
  int rcStd = sscanf("abc", "%g", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfGg10) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("123.456.789", "%g", &resS21);
  int rcStd = sscanf("123.456.789", "%g", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfGg11) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("123,456", "%g", &resS21);
  int rcStd = sscanf("123,456", "%g", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfGg12) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("123.456789", "%5g", &resS21);
  int rcStd = sscanf("123.456789", "%5g", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfGg13) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("123.456789", "%10G", &resS21);
  int rcStd = sscanf("123.456789", "%10G", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfGg14) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("123.456 567.890", "%g%*g", &resS21);
  int rcStd = sscanf("123.456 567.890", "%g%*g", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfGg15) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("123.456 567.890", "%*G%G", &resS21);
  int rcStd = sscanf("123.456 567.890", "%*G%G", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfGg16) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("3.402823466e+38", "%g", &resS21);
  int rcStd = sscanf("3.402823466e+38", "%g", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfGg17) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("1.175494351e-38", "%g", &resS21);
  int rcStd = sscanf("1.175494351e-38", "%g", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST
////////////////////
START_TEST(testSscanfO1) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("0123", "%o", &resS21);
  int rcStd = sscanf("0123", "%o", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfO2) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("00123", "%o", &resS21);
  int rcStd = sscanf("00123", "%o", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfO3) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("0", "%o", &resS21);
  int rcStd = sscanf("0", "%o", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfO4) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("123", "%o", &resS21);
  int rcStd = sscanf("123", "%o", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfO5) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("7", "%o", &resS21);
  int rcStd = sscanf("7", "%o", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfO6) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("4", "%o", &resS21);
  int rcStd = sscanf("4", "%o", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfO7) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("0123a", "%o", &resS21);
  int rcStd = sscanf("0123a", "%o", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfO8) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("01234567", "%3o", &resS21);
  int rcStd = sscanf("01234567", "%3o", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfO9) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("01234567", "%5o", &resS21);
  int rcStd = sscanf("01234567", "%5o", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfO10) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("01234567", "%7o", &resS21);
  int rcStd = sscanf("01234567", "%7o", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfO11) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("0123 0456", "%o%*o", &resS21);
  int rcStd = sscanf("0123 0456", "%o%*o", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfO12) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("0123 0456", "%*o%o", &resS21);
  int rcStd = sscanf("0123 0456", "%*o%o", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST
///////////////////
START_TEST(testSscanfS1) {
  char strS21[100] = {0};
  char strStd[100] = {0};
  int rcS21 = s21_sscanf("Hello world", "%s", strS21);
  int rcStd = sscanf("Hello world", "%s", strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfS2) {
  char strS21[100] = {0};
  char strStd[100] = {0};
  int rcS21 = s21_sscanf("12345", "%s", strS21);
  int rcStd = sscanf("12345", "%s", strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfS3) {
  char strS21[100] = {0};
  char strStd[100] = {0};
  int rcS21 = s21_sscanf("k", "%s", strS21);
  int rcStd = sscanf("k", "%s", strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfS4) {
  char strS21[100] = {0};
  char strStd[100] = {0};
  int rcS21 = s21_sscanf("gad", "%s", strS21);
  int rcStd = sscanf("gad", "%s", strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfS5) {
  char strS21[100] = {0};
  char strStd[100] = {0};
  int rcS21 = s21_sscanf("Hello, world!", "%s", strS21);
  int rcStd = sscanf("Hello, world!", "%s", strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfS6) {
  char strS21[100] = {0};
  char strStd[100] = {0};
  int rcS21 = s21_sscanf("Hello", "%5s", strS21);
  int rcStd = sscanf("Hello", "%5s", strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfS7) {
  char strS21[100] = {0};
  char strStd[100] = {0};
  int rcS21 = s21_sscanf("Hello world", "%10s", strS21);
  int rcStd = sscanf("Hello world", "%10s", strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfS8) {
  char strS21[100] = {0};
  char strStd[100] = {0};
  int rcS21 = s21_sscanf("Hello world", "%2s", strS21);
  int rcStd = sscanf("Hello world", "%2s", strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfS9) {
  char strS21[100] = {0};
  char strStd[100] = {0};
  char strS212[100] = {0};
  char strStd2[100] = {0};
  int rcS21 =
      s21_sscanf("Hello world, this is a test!", "%s%s", strS21, strS212);
  int rcStd = sscanf("Hello world, this is a test!", "%s%s", strStd, strStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
  ck_assert_str_eq(strS212, strStd2);
}
END_TEST

START_TEST(testSscanfS10) {
  char strS21[100] = {0};
  char strStd[100] = {0};
  char strS212[100] = {0};
  char strStd2[100] = {0};
  int rcS21 =
      s21_sscanf("Hello world, this is a test!", "%s%*s%s", strS21, strS212);
  int rcStd =
      sscanf("Hello world, this is a test!", "%s%*s%s", strStd, strStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
  ck_assert_str_eq(strS212, strStd2);
}
END_TEST

START_TEST(testSscanfS11) {
  char strS21[100] = {0};
  char strStd[100] = {0};
  char strS212[100] = {0};
  char strStd2[100] = {0};
  int rcS21 = s21_sscanf("Hello world, this is a test!", "%*s%s%*s%*s%*s%s",
                         strS21, strS212);
  int rcStd = sscanf("Hello world, this is a test!", "%*s%s%*s%*s%*s%s", strStd,
                     strStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
  ck_assert_str_eq(strS212, strStd2);
}
END_TEST
///////////////////////////
START_TEST(testSscanfU1) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("0", "%u", &resS21);
  int rcStd = sscanf("0", "%u", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfU2) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("123", "%u", &resS21);
  int rcStd = sscanf("123", "%u", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfU3) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("4294967295", "%u", &resS21);
  int rcStd = sscanf("4294967295", "%u", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfU4) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("123 456", "%u", &resS21);
  int rcStd = sscanf("123 456", "%u", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfU5) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("123 456", "%u%*u", &resS21);
  int rcStd = sscanf("123 456", "%u%*u", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfU6) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("123 456", "%*u%u", &resS21);
  int rcStd = sscanf("123 456", "%*u%u", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfU7) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("123 456 789", "%u%*u%*u", &resS21);
  int rcStd = sscanf("123 456 789", "%u%*u%*u", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfU8) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("abc", "%u", &resS21);
  int rcStd = sscanf("abc", "%u", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfU9) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("-123", "%u", &resS21);
  int rcStd = sscanf("-123", "%u", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfU10) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("123.456", "%u", &resS21);
  int rcStd = sscanf("123.456", "%u", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfU11) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("123a", "%u", &resS21);
  int rcStd = sscanf("123a", "%u", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfU12) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("+123", "%u", &resS21);
  int rcStd = sscanf("+123", "%u", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfU13) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("+123abc", "%u", &resS21);
  int rcStd = sscanf("+123abc", "%u", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfU14) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("1234567890", "%3u", &resS21);
  int rcStd = sscanf("1234567890", "%3u", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfU15) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("1234567890", "%5u", &resS21);
  int rcStd = sscanf("1234567890", "%5u", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfU16) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("1234567890", "%7u", &resS21);
  int rcStd = sscanf("1234567890", "%7u", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST
//////////////////////
START_TEST(testSscanfx1) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("0x0", "%x", &resS21);
  int rcStd = sscanf("0x0", "%x", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfx2) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("0x123", "%x", &resS21);
  int rcStd = sscanf("0x123", "%x", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfx3) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("0x12345678", "%x", &resS21);
  int rcStd = sscanf("0x12345678", "%x", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfx4) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("0x123 0x456", "%x", &resS21);
  int rcStd = sscanf("0x123 0x456", "%x", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfx5) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("0x123 0x456", "%x%*x", &resS21);
  int rcStd = sscanf("0x123 0x456", "%x%*x", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfx6) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("0x123 0x456", "%*x%x", &resS21);
  int rcStd = sscanf("0x123 0x456", "%*x%x", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfx7) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("0x123 0x456 0x789", "%x%*x%*x", &resS21);
  int rcStd = sscanf("0x123 0x456 0x789", "%x%*x%*x", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfx8) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("abc", "%x", &resS21);
  int rcStd = sscanf("abc", "%x", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfx9) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("-123", "%x", &resS21);
  int rcStd = sscanf("-123", "%x", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfx10) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("123.456", "%x", &resS21);
  int rcStd = sscanf("123.456", "%x", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfx11) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("123a", "%x", &resS21);
  int rcStd = sscanf("123a", "%x", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfx12) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("+123", "%x", &resS21);
  int rcStd = sscanf("+123", "%x", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfx13) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("+123abc", "%x", &resS21);
  int rcStd = sscanf("+123abc", "%x", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfx14) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("1234567890", "%3x", &resS21);
  int rcStd = sscanf("1234567890", "%3x", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfx15) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("1234567890", "%5x", &resS21);
  int rcStd = sscanf("1234567890", "%5x", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfx16) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("1234567890", "%7x", &resS21);
  int rcStd = sscanf("1234567890", "%7x", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfx17) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("0x123 0x456", "%x%*x", &resS21);
  int rcStd = sscanf("0x123 0x456", "%x%*x", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfx18) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("0x123 0x456", "%*x%x", &resS21);
  int rcStd = sscanf("0x123 0x456", "%*x%x", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfx19) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("0x123 0x456 0x789", "%x%*x%*x", &resS21);
  int rcStd = sscanf("0x123 0x456 0x789", "%x%*x%*x", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

// Тесты для спецификатора X
START_TEST(testSscanfX1) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("0X0", "%X", &resS21);
  int rcStd = sscanf("0X0", "%X", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfX2) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("0X123", "%X", &resS21);
  int rcStd = sscanf("0X123", "%X", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfX3) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("0X12345678", "%X", &resS21);
  int rcStd = sscanf("0X12345678", "%X", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfX4) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("0X123 0X456", "%X", &resS21);
  int rcStd = sscanf("0X123 0X456", "%X", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfX5) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("0X123 0X456", "%X%*X", &resS21);
  int rcStd = sscanf("0X123 0X456", "%X%*X", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfX6) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("0X123 0X456", "%*X%X", &resS21);
  int rcStd = sscanf("0X123 0X456", "%*X%X", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfX7) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("0X123 0X456 0X789", "%X%*X%*X", &resS21);
  int rcStd = sscanf("0X123 0X456 0X789", "%X%*X%*X", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfX8) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("abc", "%X", &resS21);
  int rcStd = sscanf("abc", "%X", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfX9) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("-123", "%X", &resS21);
  int rcStd = sscanf("-123", "%X", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfX10) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("123.456", "%X", &resS21);
  int rcStd = sscanf("123.456", "%X", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfX11) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("123a", "%X", &resS21);
  int rcStd = sscanf("123a", "%X", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfX12) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("+123", "%X", &resS21);
  int rcStd = sscanf("+123", "%X", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfX13) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("+123abc", "%X", &resS21);
  int rcStd = sscanf("+123abc", "%X", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfX14) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("1234567890", "%3X", &resS21);
  int rcStd = sscanf("1234567890", "%3X", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfX15) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("1234567890", "%5X", &resS21);
  int rcStd = sscanf("1234567890", "%5X", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfX16) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("1234567890", "%7X", &resS21);
  int rcStd = sscanf("1234567890", "%7X", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfX17) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("0X123 0X456", "%X%*X", &resS21);
  int rcStd = sscanf("0X123 0X456", "%X%*X", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfX18) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("0X123 0X456", "%*X%X", &resS21);
  int rcStd = sscanf("0X123 0X456", "%*X%X", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfX19) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("0X123 0X456 0X789", "%X%*X%*X", &resS21);
  int rcStd = sscanf("0X123 0X456 0X789", "%X%*X%*X", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfX20) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("0x0", "%x", &resS21);
  int rcStd = sscanf("0x0", "%x", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfX21) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("-0x123", "%x", &resS21);
  int rcStd = sscanf("-0x123", "%x", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfX22) {
  unsigned int resS21 = 0;
  unsigned int resStd = 0;
  int rcS21 = s21_sscanf("+0x123", "%x", &resS21);
  int rcStd = sscanf("+0x123", "%x", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST
///////////////////
START_TEST(testSscanfP1) {
  void *ptr = (void *)0x1234;
  char str[20] = {0};
  sprintf(str, "%p", ptr);
  void *resS21 = NULL;
  void *resStd = NULL;
  int rcS21 = s21_sscanf(str, "%p", &resS21);
  int rcStd = sscanf(str, "%p", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ptr_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfP2) {
  void *ptr = (void *)0x12345678;
  char str[20] = {0};
  sprintf(str, "%p", ptr);
  void *resS21 = NULL;
  void *resStd = NULL;
  int rcS21 = s21_sscanf(str, "%p", &resS21);
  int rcStd = sscanf(str, "%p", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ptr_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfP3) {
  void *ptr = (void *)0x123456789ABCDEF0;
  char str[20] = {0};
  sprintf(str, "%p", ptr);
  void *resS21 = NULL;
  void *resStd = NULL;
  int rcS21 = s21_sscanf(str, "%p", &resS21);
  int rcStd = sscanf(str, "%p", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ptr_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfP4) {
  void *resS21 = NULL;
  void *resStd = NULL;
  int rcS21 = s21_sscanf("0x1234", "%p", &resS21);
  int rcStd = sscanf("0x1234", "%p", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ptr_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfP5) {
  void *resS21 = NULL;
  void *resStd = NULL;
  int rcS21 = s21_sscanf("0x12345678", "%p", &resS21);
  int rcStd = sscanf("0x12345678", "%p", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ptr_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfP6) {
  void *resS21 = NULL;
  void *resStd = NULL;
  int rcS21 = s21_sscanf("0x123456789ABCDEF0", "%p", &resS21);
  int rcStd = sscanf("0x123456789ABCDEF0", "%p", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ptr_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfP7) {
  void *resS21 = NULL;
  void *resStd = NULL;
  int rcS21 = s21_sscanf("1234", "%p", &resS21);
  int rcStd = sscanf("1234", "%p", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfP8) {
  void *resS21 = NULL;
  void *resStd = NULL;
  int rcS21 = s21_sscanf("12345678", "%p", &resS21);
  int rcStd = sscanf("12345678", "%p", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfP9) {
  void *resS21 = NULL;
  void *resStd = NULL;
  int rcS21 = s21_sscanf("123456789ABCDEF0", "%p", &resS21);
  int rcStd = sscanf("123456789ABCDEF0", "%p", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfP10) {
  void *resS21 = NULL;
  void *resStd = NULL;
  int rcS21 = s21_sscanf("abc", "%p", &resS21);
  int rcStd = sscanf("abc", "%p", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfP11) {
  void *resS21 = NULL;
  void *resStd = NULL;
  int rcS21 = s21_sscanf("123.456", "%p", &resS21);
  int rcStd = sscanf("123.456", "%p", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfP12) {
  void *resS21 = NULL;
  void *resStd = NULL;
  int rcS21 = s21_sscanf("123a", "%p", &resS21);
  int rcStd = sscanf("123a", "%p", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfP13) {
  void *resS21 = NULL;
  void *resStd = NULL;
  int rcS21 = s21_sscanf("+123", "%p", &resS21);
  int rcStd = sscanf("+123", "%p", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfP14) {
  void *resS21 = NULL;
  void *resStd = NULL;
  int rcS21 = s21_sscanf("+123abc", "%p", &resS21);
  int rcStd = sscanf("+123abc", "%p", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfP15) {
  void *resS21 = NULL;
  void *resStd = NULL;
  int rcS21 = s21_sscanf("1234567890", "%p", &resS21);
  int rcStd = sscanf("1234567890", "%p", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST
///////////////////////
START_TEST(testSscanfN1) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("12345", "%d%n", &resS21, &countS21);
  int rcStd = sscanf("12345", "%d%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN2) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0, resS212 = 0,
      resStd2 = 0;
  int rcS21 = s21_sscanf("12345 67890", "%d%n%d", &resS21, &countS21, &resS212);
  int rcStd = sscanf("12345 67890", "%d%n%d", &resStd, &countStd, &resStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(resS212, resStd2);

  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN3) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc", "%d%n%s", &resS21, &countS21, strS21);
  int rcStd = sscanf("12345abc", "%d%n%s", &resStd, &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfN5) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("12345.6789", "%d%n", &resS21, &countS21);
  int rcStd = sscanf("12345.6789", "%d%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN6) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("12345", "%3d%n", &resS21, &countS21);
  int rcStd = sscanf("12345", "%3d%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN7) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0, resS212 = 0,
      resStd2 = 0;
  int rcS21 =
      s21_sscanf("12345 67890", "%3d%n%5d", &resS21, &countS21, &resS212);
  int rcStd = sscanf("12345 67890", "%3d%n%5d", &resStd, &countStd, &resStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(resS212, resStd2);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN8) {
  int countS21 = 0, countStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc", "%*d%n%s", &countS21, strS21);
  int rcStd = sscanf("12345abc", "%*d%n%s", &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfN9) {
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("abc12345", "%*d%n", &countS21);
  int rcStd = sscanf("abc12345", "%*d%n", &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN11) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("12345abc", "%d%n", &resS21, &countS21);
  int rcStd = sscanf("12345abc", "%d%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN12) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("12345.6789", "%3d%n", &resS21, &countS21);
  int rcStd = sscanf("12345.6789", "%3d%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN13) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("12345", "%u%n", &resS21, &countS21);
  int rcStd = sscanf("12345", "%u%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN14) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0, resS212 = 0,
      resStd2 = 0;
  int rcS21 = s21_sscanf("12345 67890", "%u%n%u", &resS21, &countS21, &resS212);
  int rcStd = sscanf("12345 67890", "%u%n%u", &resStd, &countStd, &resStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS212, resStd2);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN15) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc", "%u%n%s", &resS21, &countS21, strS21);
  int rcStd = sscanf("12345abc", "%u%n%s", &resStd, &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfN17) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("12345", "%3u%n", &resS21, &countS21);
  int rcStd = sscanf("12345", "%3u%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN18) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0, resS212 = 0,
      resStd2 = 0;
  int rcS21 =
      s21_sscanf("12345 67890", "%3u%n%5u", &resS21, &countS21, &resS212);
  int rcStd = sscanf("12345 67890", "%3u%n%5u", &resStd, &countStd, &resStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS212, resStd2);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN19) {
  int countS21 = 0, countStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc", "%*u%n%s", &countS21, strS21);
  int rcStd = sscanf("12345abc", "%*u%n%s", &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfN20) {
  int countS21 = 0, countStd = 0, resS21 = 0, resStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc", "%u%n%s", &resS21, &countS21, strS21);
  int rcStd = sscanf("12345abc", "%u%n%s", &resStd, &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfN21) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("-12345", "%u%n", &resS21, &countS21);
  int rcStd = sscanf("-12345", "%u%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN22) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("12345abc", "%u%n", &resS21, &countS21);
  int rcStd = sscanf("12345abc", "%u%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN23) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("12345", "%3u%n", &resS21, &countS21);
  int rcStd = sscanf("12345", "%3u%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN24) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("12345", "%x%n", &resS21, &countS21);
  int rcStd = sscanf("12345", "%x%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN25) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0, resS212 = 0,
      resStd2 = 0;
  int rcS21 = s21_sscanf("12345 67890", "%x%n%x", &resS21, &countS21, &resS212);
  int rcStd = sscanf("12345 67890", "%x%n%x", &resStd, &countStd, &resStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS212, resStd2);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN26) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc", "%x%n%s", &resS21, &countS21, strS21);
  int rcStd = sscanf("12345abc", "%x%n%s", &resStd, &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfN27) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("abc12345", "%x%n%s", &resS21, &countS21, strS21);
  int rcStd = sscanf("abc12345", "%x%n%s", &resStd, &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfN28) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("12345", "%X%n", &resS21, &countS21);
  int rcStd = sscanf("12345", "%X%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN29) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0, resS212 = 0,
      resStd2 = 0;
  int rcS21 = s21_sscanf("12345 67890", "%X%n%X", &resS21, &countS21, &resS212);
  int rcStd = sscanf("12345 67890", "%X%n%X", &resStd, &countStd, &resStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS212, resStd2);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN30) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc", "%X%n%s", &resS21, &countS21, strS21);
  int rcStd = sscanf("12345abc", "%X%n%s", &resStd, &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfN31) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("abc12345", "%X%n%s", &resS21, &countS21, strS21);
  int rcStd = sscanf("abc12345", "%X%n%s", &resStd, &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfN32) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("12345", "%3x%n", &resS21, &countS21);
  int rcStd = sscanf("12345", "%3x%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN33) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0, resS212 = 0,
      resStd2 = 0;
  int rcS21 =
      s21_sscanf("12345 67890", "%3x%n%5x", &resS21, &countS21, &resS212);
  int rcStd = sscanf("12345 67890", "%3x%n%5x", &resStd, &countStd, &resStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS212, resStd2);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN34) {
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("12345abc", "%*x%n", &countS21);
  int rcStd = sscanf("12345abc", "%*x%n", &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN35) {
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("abc12345", "%*x%n", &countS21);
  int rcStd = sscanf("abc12345", "%*x%n", &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN36) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("12345", "%3X%n", &resS21, &countS21);
  int rcStd = sscanf("12345", "%3X%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN37) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0, resS212 = 0,
      resStd2 = 0;
  int rcS21 =
      s21_sscanf("12345 67890", "%3X%n%5X", &resS21, &countS21, &resS212);
  int rcStd = sscanf("12345 67890", "%3X%n%5X", &resStd, &countStd, &resStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS212, resStd2);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN38) {
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("12345abc", "%*X%n", &countS21);
  int rcStd = sscanf("12345abc", "%*X%n", &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN39) {
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("abc12345", "%*X%n", &countS21);
  int rcStd = sscanf("abc12345", "%*X%n", &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN40) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("abc", "%x%n", &resS21, &countS21);
  int rcStd = sscanf("abc", "%x%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN41) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("12345abc", "%x%n", &resS21, &countS21);
  int rcStd = sscanf("12345abc", "%x%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN42) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("12345", "%3x%n", &resS21, &countS21);
  int rcStd = sscanf("12345", "%3x%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN43) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("abc", "%X%n", &resS21, &countS21);
  int rcStd = sscanf("abc", "%X%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN44) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("12345abc", "%X%n", &resS21, &countS21);
  int rcStd = sscanf("12345abc", "%X%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN45) {
  int resS21 = 0, resStd = 0, countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("12345", "%3X%n", &resS21, &countS21);
  int rcStd = sscanf("12345", "%3X%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN46) {
  float resS21 = 0.0, resStd = 0.0;
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("123.456", "%f%n", &resS21, &countS21);
  int rcStd = sscanf("123.456", "%f%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN47) {
  float resS21 = 0.0, resStd = 0.0, resS212 = 0.0, resStd2 = 0.0;
  int countS21 = 0, countStd = 0;
  int rcS21 =
      s21_sscanf("123.456 678.90", "%f%n%f", &resS21, &countS21, &resS212);
  int rcStd = sscanf("123.456 678.90", "%f%n%f", &resStd, &countStd, &resStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
  ck_assert_double_eq_tol(resS212, resStd2, 1e-6);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN48) {
  float resS21 = 0.0, resStd = 0.0;
  int countS21 = 0, countStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("123.456abc", "%f%n%s", &resS21, &countS21, strS21);
  int rcStd = sscanf("123.456abc", "%f%n%s", &resStd, &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfN50) {
  float resS21 = 0.0, resStd = 0.0;
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("1.23e+4", "%e%n", &resS21, &countS21);
  int rcStd = sscanf("1.23e+4", "%e%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN51) {
  float resS21 = 0.0, resStd = 0.0, resS212 = 0.0, resStd2 = 0.0;
  int countS21 = 0, countStd = 0;
  int rcS21 =
      s21_sscanf("1.23e+4 4.56e-7", "%e%n%e", &resS21, &countS21, &resS212);
  int rcStd = sscanf("1.23e+4 4.56e-7", "%e%n%e", &resStd, &countStd, &resStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
  ck_assert_double_eq_tol(resS212, resStd2, 1e-6);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN52) {
  float resS21 = 0.0, resStd = 0.0;
  int countS21 = 0, countStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("1.23e+4abc", "%e%n%s", &resS21, &countS21, strS21);
  int rcStd = sscanf("1.23e+4abc", "%e%n%s", &resStd, &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfN54) {
  float resS21 = 0.0, resStd = 0.0;
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("123.456", "%g%n", &resS21, &countS21);
  int rcStd = sscanf("123.456", "%g%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN55) {
  float resS21 = 0.0, resStd = 0.0, resS212 = 0.0, resStd2 = 0.0;
  int countS21 = 0, countStd = 0;
  int rcS21 =
      s21_sscanf("123.456 678.90", "%g%n%g", &resS21, &countS21, &resS212);
  int rcStd = sscanf("123.456 678.90", "%g%n%g", &resStd, &countStd, &resStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
  ck_assert_double_eq_tol(resS212, resStd2, 1e-6);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN56) {
  float resS21 = 0.0, resStd = 0.0;
  int countS21 = 0, countStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("123.456abc", "%g%n%s", &resS21, &countS21, strS21);
  int rcStd = sscanf("123.456abc", "%g%n%s", &resStd, &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfN58) {
  float resS21 = 0.0, resStd = 0.0;
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("123.456", "%5f%n", &resS21, &countS21);
  int rcStd = sscanf("123.456", "%5f%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN59) {
  float resS21 = 0.0, resStd = 0.0, resS212 = 0.0, resStd2 = 0.0;
  int countS21 = 0, countStd = 0;
  int rcS21 =
      s21_sscanf("123.456 678.90", "%5f%n%8f", &resS21, &countS21, &resS212);
  int rcStd =
      sscanf("123.456 678.90", "%5f%n%8f", &resStd, &countStd, &resStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
  ck_assert_double_eq_tol(resS212, resStd2, 1e-6);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN60) {
  int countS21 = 0, countStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("123.456abc", "%*f%n%s", &countS21, strS21);
  int rcStd = sscanf("123.456abc", "%*f%n%s", &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfN61) {
  int countS21 = 0.0, countStd = 0.0;
  int rcS21 = s21_sscanf("abc123.456", "%*f%n", &countS21);
  int rcStd = sscanf("abc123.456", "%*f%n", &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN62) {
  float resS21 = 0.0, resStd = 0.0;
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("1.23e+4", "%5e%n", &resS21, &countS21);
  int rcStd = sscanf("1.23e+4", "%5e%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN63) {
  float resS21 = 0.0, resStd = 0.0, resS212 = 0.0, resStd2 = 0.0;
  int countS21 = 0, countStd = 0;
  int rcS21 =
      s21_sscanf("1.23e+4 4.56e-7", "%5e%n%8e", &resS21, &countS21, &resS212);
  int rcStd =
      sscanf("1.23e+4 4.56e-7", "%5e%n%8e", &resStd, &countStd, &resStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
  ck_assert_double_eq_tol(resS212, resStd2, 1e-6);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN64) {
  int countS21 = 0, countStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("1.23e+4abc", "%*e%n%s", &countS21, strS21);
  int rcStd = sscanf("1.23e+4abc", "%*e%n%s", &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfN65) {
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("abc1.23e+4", "%*e%n", &countS21);
  int rcStd = sscanf("abc1.23e+4", "%*e%n", &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN66) {
  float resS21 = 0.0, resStd = 0.0;
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("123.456", "%5g%n", &resS21, &countS21);
  int rcStd = sscanf("123.456", "%5g%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN67) {
  float resS21 = 0.0, resStd = 0.0, resS212 = 0.0, resStd2 = 0.0;
  int countS21 = 0, countStd = 0;
  int rcS21 =
      s21_sscanf("123.456 678.90", "%5g%n%8g", &resS21, &countS21, &resS212);
  int rcStd =
      sscanf("123.456 678.90", "%5g%n%8g", &resStd, &countStd, &resStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
  ck_assert_float_eq_tol(resS212, resStd2, 1e-6);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN68) {
  int countS21 = 0, countStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("123.456abc", "%*g%n%s", &countS21, strS21);
  int rcStd = sscanf("123.456abc", "%*g%n%s", &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfN69) {
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("abc123.456", "%*g%n", &countS21);
  int rcStd = sscanf("abc123.456", "%*g%n", &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN71) {
  float resS21 = 0.0, resStd = 0.0;
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("123.456abc", "%f%n", &resS21, &countS21);
  int rcStd = sscanf("123.456abc", "%f%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_float_eq_tol(resS21, resStd, 1e-6);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN72) {
  float resS21 = 0.0, resStd = 0.0;
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("123.456", "%5f%n", &resS21, &countS21);
  int rcStd = sscanf("123.456", "%5f%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_float_eq_tol(resS21, resStd, 1e-6);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN74) {
  float resS21 = 0.0, resStd = 0.0;
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("1.23e+4abc", "%e%n", &resS21, &countS21);
  int rcStd = sscanf("1.23e+4abc", "%e%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_float_eq_tol(resS21, resStd, 1e-6);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN75) {
  float resS21 = 0.0, resStd = 0.0;
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("1.23e+4", "%5e%n", &resS21, &countS21);
  int rcStd = sscanf("1.23e+4", "%5e%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_float_eq_tol(resS21, resStd, 1e-6);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN77) {
  float resS21 = 0.0, resStd = 0.0;
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("123.456abc", "%g%n", &resS21, &countS21);
  int rcStd = sscanf("123.456abc", "%g%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_float_eq_tol(resS21, resStd, 1e-6);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN78) {
  float resS21 = 0.0, resStd = 0.0;
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("123.456", "%5g%n", &resS21, &countS21);
  int rcStd = sscanf("123.456", "%5g%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_float_eq_tol(resS21, resStd, 1e-6);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN79) {
  char resS21 = ' ', resStd = ' ';
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("12345c", "%c%n", &resS21, &countS21);
  int rcStd = sscanf("12345c", "%c%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN80) {
  char resS21 = ' ', resStd = ' ', resS212 = ' ', resStd2 = ' ';
  int countS21 = 0, countStd = 0;
  int rcS21 =
      s21_sscanf("12345 67890c", "%c%n%c", &resS21, &countS21, &resS212);
  int rcStd = sscanf("12345 67890c", "%c%n%c", &resStd, &countStd, &resStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(resS212, resStd2);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN81) {
  char resS21 = ' ', resStd = ' ';
  int countS21 = 0, countStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc", "%c%n%s", &resS21, &countS21, strS21);
  int rcStd = sscanf("12345abc", "%c%n%s", &resStd, &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfN82) {
  char resS21 = ' ', resStd = ' ';
  int countS21 = 0, countStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("abc12345", "%c%n%s", &resS21, &countS21, strS21);
  int rcStd = sscanf("abc12345", "%c%n%s", &resStd, &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfN85) {
  int countS21 = 0, countStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc", "%*c%n%s", &countS21, strS21);
  int rcStd = sscanf("12345abc", "%*c%n%s", &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfN86) {
  int countS21 = 0, countStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("abc12345", "%*c%n%s", &countS21, strS21);
  int rcStd = sscanf("abc12345", "%*c%n%s", &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfN87) {
  char resS21 = ' ', resStd = ' ';
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("12345", "%c%n", &resS21, &countS21);
  int rcStd = sscanf("12345", "%c%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfN89) {
  int countS21 = 0, countStd = 0;
  char resS21[10] = {0}, resStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc", "%s%n", resS21, &countS21);
  int rcStd = sscanf("12345abc", "%s%n", resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfN90) {
  int countS21 = 0, countStd = 0;
  char strS21[10] = {0}, strStd[10] = {0}, resS21[10] = {0}, resStd[10] = {0};
  int rcS21 =
      s21_sscanf("12345 abc 67890", "%s%n%s", resS21, &countS21, strS21);
  int rcStd = sscanf("12345 abc 67890", "%s%n%s", resStd, &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
  ck_assert_str_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfN91) {
  int countS21 = 0, countStd = 0;
  char strS21[10] = {0}, strStd[10] = {0}, resS21[10] = {0}, resStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc 67890", "%s%n%s", resS21, &countS21, strS21);
  int rcStd = sscanf("12345abc 67890", "%s%n%s", resStd, &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
  ck_assert_str_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfN92) {
  int countS21 = 0, countStd = 0;
  char resS21[10] = {0}, resStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc", "%5s%n", resS21, &countS21);
  int rcStd = sscanf("12345abc", "%5s%n", resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfN93) {
  int countS21 = 0, countStd = 0;
  char strS21[10] = {0}, strStd[10] = {0}, resS21[10] = {0}, resStd[10] = {0};
  int rcS21 =
      s21_sscanf("12345 abc 67890", "%5s%n%8s", resS21, &countS21, strS21);
  int rcStd = sscanf("12345 abc 67890", "%5s%n%8s", resStd, &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
  ck_assert_str_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfN94) {
  int countS21 = 0, countStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc 67890", "%*s%n%s", &countS21, strS21);
  int rcStd = sscanf("12345abc 67890", "%*s%n%s", &countStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfN95) {
  void *resS21 = NULL;
  void *resStd = NULL;
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("0x12345678", "%p%n", &resS21, &countS21);
  int rcStd = sscanf("0x12345678", "%p%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ptr_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN96) {
  void *resS21 = NULL;
  void *resStd = NULL;
  void *resS212 = NULL;
  void *resStd2 = NULL;
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("0x12345678 0x9abcdef0", "%p%n%p", &resS21, &countS21,
                         &resS212);
  int rcStd =
      sscanf("0x12345678 0x9abcdef0", "%p%n%p", &resStd, &countStd, &resStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ptr_eq(resS212, resStd2);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN97) {
  void *resS21 = NULL;
  void *resStd = NULL;
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("0x12345678", "%10p%n", &resS21, &countS21);
  int rcStd = sscanf("0x12345678", "%10p%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ptr_eq(resS21, resStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN98) {
  void *resS21 = NULL;
  void *resStd = NULL;
  void *resS212 = NULL;
  void *resStd2 = NULL;
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("0x12345678 0x9abcdef0", "%10p%n%12p", &resS21,
                         &countS21, &resS212);
  int rcStd = sscanf("0x12345678 0x9abcdef0", "%10p%n%12p", &resStd, &countStd,
                     &resStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ptr_eq(resS212, resStd2);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN99) {
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("0x12345678", "%*p%n", &countS21);
  int rcStd = sscanf("0x12345678", "%*p%n", &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN101) {
  void *resS21 = NULL;
  void *resStd = NULL;
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("abc", "%p%n", &resS21, &countS21);
  int rcStd = sscanf("abc", "%p%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN102) {
  void *resS21 = NULL;
  void *resStd = NULL;
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("12345", "%p%n", &resS21, &countS21);
  int rcStd = sscanf("12345", "%p%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfN103) {
  void *resS21 = NULL;
  void *resStd = NULL;
  int countS21 = 0, countStd = 0;
  int rcS21 = s21_sscanf("0x7fff5a07a000", "%10p%n", &resS21, &countS21);
  int rcStd = sscanf("0x7fff5a07a000", "%10p%n", &resStd, &countStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(countS21, countStd);
}
END_TEST

START_TEST(testSscanfPercent01) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345%", "%d%%", &resS21);
  int rcStd = sscanf("12345%", "%d%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent02) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345 67890%", "%d%%%d", &resS21, &resStd);
  int rcStd = sscanf("12345 67890%", "%d%%%d", &resStd, &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent03) {
  int resS21 = 0, resStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc%", "%d%%%s", &resS21, strS21);
  int rcStd = sscanf("12345abc%", "%d%%%s", &resStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent04) {
  int resS21 = 0, resStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("abc12345%", "%d%%%s", &resS21, strS21);
  int rcStd = sscanf("abc12345%", "%d%%%s", &resStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent05) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345%", "%3d%%", &resS21);
  int rcStd = sscanf("12345%", "%3d%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent06) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345 67890%", "%3d%%%5d", &resS21, &resStd);
  int rcStd = sscanf("12345 67890%", "%3d%%%5d", &resStd, &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent07) {
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc%", "%*d%%%s", strS21);
  int rcStd = sscanf("12345abc%", "%*d%%%s", strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent08) {
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("abc12345%", "%*d%%%s", strS21);
  int rcStd = sscanf("abc12345%", "%*d%%%s", strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent10) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345abc%", "%d%%", &resS21);
  int rcStd = sscanf("12345abc%", "%d%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent11) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345%", "%3d%%", &resS21);
  int rcStd = sscanf("12345%", "%3d%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent12) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345%", "%u%%", &resS21);
  int rcStd = sscanf("12345%", "%u%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent13) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345 67890%", "%u%%%u", &resS21, &resStd);
  int rcStd = sscanf("12345 67890%", "%u%%%u", &resStd, &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent14) {
  int resS21 = 0, resStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc%", "%u%%%s", &resS21, strS21);
  int rcStd = sscanf("12345abc%", "%u%%%s", &resStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent15) {
  int resS21 = 0, resStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("abc12345%", "%u%%%s", &resS21, strS21);
  int rcStd = sscanf("abc12345%", "%u%%%s", &resStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent16) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345%", "%3u%%", &resS21);
  int rcStd = sscanf("12345%", "%3u%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent17) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345 67890%", "%3u%%%5u", &resS21, &resStd);
  int rcStd = sscanf("12345 67890%", "%3u%%%5u", &resStd, &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent18) {
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc%", "%*u%%%s", strS21);
  int rcStd = sscanf("12345abc%", "%*u%%%s", strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent19) {
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("abc12345%", "%*u%%%s", strS21);
  int rcStd = sscanf("abc12345%", "%*u%%%s", strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent20) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("-12345%", "%u%%", &resS21);
  int rcStd = sscanf("-12345%", "%u%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent21) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345abc%", "%u%%", &resS21);
  int rcStd = sscanf("12345abc%", "%u%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent22) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345%", "%3u%%", &resS21);
  int rcStd = sscanf("12345%", "%3u%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent23) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345%", "%x%%", &resS21);
  int rcStd = sscanf("12345%", "%x%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent24) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345 67890%", "%x%%%x", &resS21, &resStd);
  int rcStd = sscanf("12345 67890%", "%x%%%x", &resStd, &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent25) {
  int resS21 = 0, resStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc%", "%x%%%s", &resS21, strS21);
  int rcStd = sscanf("12345abc%", "%x%%%s", &resStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent26) {
  int resS21 = 0, resStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("abc12345%", "%x%%%s", &resS21, strS21);
  int rcStd = sscanf("abc12345%", "%x%%%s", &resStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent27) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345%", "%3x%%", &resS21);
  int rcStd = sscanf("12345%", "%3x%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent28) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345 67890%", "%3x%%%5x", &resS21, &resStd);
  int rcStd = sscanf("12345 67890%", "%3x%%%5x", &resStd, &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent29) {
  int rcS21 = s21_sscanf("12345abc%", "%*x%%");
  int rcStd = sscanf("12345abc%", "%*x%%");
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfPercent30) {
  int rcS21 = s21_sscanf("abc12345%", "%*x%%");
  int rcStd = sscanf("abc12345%", "%*x%%");
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfPercent31) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("abc%", "%x%%", &resS21);
  int rcStd = sscanf("abc%", "%x%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent32) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345abc%", "%x%%", &resS21);
  int rcStd = sscanf("12345abc%", "%x%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent33) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345%", "%3x%%", &resS21);
  int rcStd = sscanf("12345%", "%3x%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent34) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345%", "%X%%", &resS21);
  int rcStd = sscanf("12345%", "%X%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent35) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345 67890%", "%X%%%X", &resS21, &resStd);
  int rcStd = sscanf("12345 67890%", "%X%%%X", &resStd, &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent36) {
  int resS21 = 0, resStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc%", "%X%%%s", &resS21, strS21);
  int rcStd = sscanf("12345abc%", "%X%%%s", &resStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent37) {
  int resS21 = 0, resStd = 0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("abc12345%", "%X%%%s", &resS21, strS21);
  int rcStd = sscanf("abc12345%", "%X%%%s", &resStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent38) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345%", "%3X%%", &resS21);
  int rcStd = sscanf("12345%", "%3X%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent39) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345 67890%", "%3X%%%5X", &resS21, &resStd);
  int rcStd = sscanf("12345 67890%", "%3X%%%5X", &resStd, &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent40) {
  int rcS21 = s21_sscanf("12345abc%", "%*X%%");
  int rcStd = sscanf("12345abc%", "%*X%%");
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfPercent41) {
  int rcS21 = s21_sscanf("abc12345%", "%*X%%");
  int rcStd = sscanf("abc12345%", "%*X%%");
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfPercent42) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("abc%", "%X%%", &resS21);
  int rcStd = sscanf("abc%", "%X%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent43) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345abc%", "%X%%", &resS21);
  int rcStd = sscanf("12345abc%", "%X%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent44) {
  int resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345%", "%3X%%", &resS21);
  int rcStd = sscanf("12345%", "%3X%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent45) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("123.456%", "%f%%", &resS21);
  int rcStd = sscanf("123.456%", "%f%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfPercent46) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("123.456 678.90%", "%f%%%f", &resS21, &resStd);
  int rcStd = sscanf("123.456 678.90%", "%f%%%f", &resStd, &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfPercent47) {
  float resS21 = 0.0, resStd = 0.0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("123.456abc%", "%f%%%s", &resS21, strS21);
  int rcStd = sscanf("123.456abc%", "%f%%%s", &resStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent48) {
  float resS21 = 0.0, resStd = 0.0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("abc123.456%", "%f%%%s", &resS21, strS21);
  int rcStd = sscanf("abc123.456%", "%f%%%s", &resStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent49) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("123.456%", "%5f%%", &resS21);
  int rcStd = sscanf("123.456%", "%5f%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfPercent51) {
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("123.456abc%", "%*f%%%s", strS21);
  int rcStd = sscanf("123.456abc%", "%*f%%%s", strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent52) {
  float resS21 = 0.0, resStd = 0.0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("abc123.456%", "%f%%%s", &resS21, strS21);
  int rcStd = sscanf("abc123.456%", "%f%%%s", &resStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent53) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("1.23e+4%", "%e%%", &resS21);
  int rcStd = sscanf("1.23e+4%", "%e%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfPercent54) {
  float resS211 = 0.0, resStd1 = 0.0;
  float resS212 = 0.0, resStd2 = 0.0;
  int rcS21 = s21_sscanf("1.23e+4 4.56e-7%", "%e%%%e", &resS211, &resS212);
  int rcStd = sscanf("1.23e+4 4.56e-7%", "%e%%%e", &resStd1, &resStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS211, resStd1, 1e-6);
  ck_assert_double_eq_tol(resS212, resStd2, 1e-6);
}
END_TEST

START_TEST(testSscanfPercent55) {
  float resS21 = 0.0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("1.23e+4abc%", "%e%%%s", &resS21, strS21);
  int rcStd = sscanf("1.23e+4abc%", "%e%%%s", &resS21, strS21);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resS21, 1e-6);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent56) {
  float resS21 = 0.0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("abc1.23e+4%", "%e%%%s", &resS21, strS21);
  int rcStd = sscanf("abc1.23e+4%", "%e%%%s", &resS21, strS21);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resS21, 1e-6);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent57) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("123.456%", "%g%%", &resS21);
  int rcStd = sscanf("123.456%", "%g%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfPercent59) {
  float resS21 = 0.0, resStd = 0.0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("123.456abc%", "%g%%%s", &resS21, strS21);
  int rcStd = sscanf("123.456abc%", "%g%%%s", &resStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent60) {
  float resS21 = 0.0, resStd = 0.0;
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("abc123.456%", "%g%%%s", &resS21, strS21);
  int rcStd = sscanf("abc123.456%", "%g%%%s", &resStd, strS21);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent61) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("123.456%", "%5f%%", &resS21);
  int rcStd = sscanf("123.456%", "%5f%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfPercent63) {
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("123.456abc%", "%*f%%%s", strS21);
  int rcStd = sscanf("123.456abc%", "%*f%%%s", strS21);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent64) {
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("abc123.456%", "%*f%%%s", strS21);
  int rcStd = sscanf("abc123.456%", "%*f%%%s", strS21);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent65) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("1.23e+4%", "%5e%%", &resS21);
  int rcStd = sscanf("1.23e+4%", "%5e%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfPercent67) {
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("1.23e+4abc%", "%*e%%%s", strS21);
  int rcStd = sscanf("1.23e+4abc%", "%*e%%%s", strS21);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent68) {
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("abc1.23e+4%", "%*e%%%s", strS21);
  int rcStd = sscanf("abc1.23e+4%", "%*e%%%s", strS21);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent69) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("123.456%", "%5g%%", &resS21);
  int rcStd = sscanf("123.456%", "%5g%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfPercent71) {
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("123.456abc%", "%*g%%%s", strS21);
  int rcStd = sscanf("123.456abc%", "%*g%%%s", strS21);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent72) {
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("abc123.456%", "%*g%%%s", strS21);
  int rcStd = sscanf("abc123.456%", "%*g%%%s", strS21);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent73) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("abc%", "%f%%", &resS21);
  int rcStd = sscanf("abc%", "%f%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfPercent74) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("123.456abc%", "%f%%", &resS21);
  int rcStd = sscanf("123.456abc%", "%f%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfPercent75) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("123.456%", "%5f%%", &resS21);
  int rcStd = sscanf("123.456%", "%5f%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfPercent76) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("abc%", "%e%%", &resS21);
  int rcStd = sscanf("abc%", "%e%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfPercent77) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("1.23e+4abc%", "%e%%", &resS21);
  int rcStd = sscanf("1.23e+4abc%", "%e%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfPercent78) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("1.23e+4%", "%5e%%", &resS21);
  int rcStd = sscanf("1.23e+4%", "%5e%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfPercent79) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("abc%", "%g%%", &resS21);
  int rcStd = sscanf("abc%", "%g%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfPercent80) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("123.456abc%", "%g%%", &resS21);
  int rcStd = sscanf("123.456abc%", "%g%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfPercent81) {
  float resS21 = 0.0, resStd = 0.0;
  int rcS21 = s21_sscanf("123.456%", "%5g%%", &resS21);
  int rcStd = sscanf("123.456%", "%5g%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_double_eq_tol(resS21, resStd, 1e-6);
}
END_TEST

START_TEST(testSscanfPercent82) {
  char resS21 = ' ', resStd = ' ';
  int rcS21 = s21_sscanf("12345c%", "%c%%", &resS21);
  int rcStd = sscanf("12345c%", "%c%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent83) {
  char resS211 = ' ', resStd1 = ' ';
  int rcS21 = s21_sscanf("12345 67890c%", "%c%%", &resS211);
  int rcStd = sscanf("12345 67890c%", "%c%%", &resStd1);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS211, resStd1);
}
END_TEST

START_TEST(testSscanfPercent84) {
  char resS21 = ' ', resStd = ' ';
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc%", "%c%%%s", &resS21, strS21);
  int rcStd = sscanf("12345abc%", "%c%%%s", &resStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent85) {
  char resS21 = ' ', resStd = ' ';
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("abc12345%", "%c%%%s", &resS21, strS21);
  int rcStd = sscanf("abc12345%", "%c%%%s", &resStd, strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent86) {
  char resS21 = ' ', resStd = ' ';
  int rcS21 = s21_sscanf("12345c%", "%c%%", &resS21);
  int rcStd = sscanf("12345c%", "%c%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent88) {
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc%", "%*c%%%s", strS21);
  int rcStd = sscanf("12345abc%", "%*c%%%s", strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent89) {
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("abc12345%", "%*c%%%s", strS21);
  int rcStd = sscanf("abc12345%", "%*c%%%s", strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent90) {
  char resS21 = ' ', resStd = ' ';
  int rcS21 = s21_sscanf("12345%", "%c%%", &resS21);
  int rcStd = sscanf("12345%", "%c%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent91) {
  char resS21 = ' ', resStd = ' ';
  int rcS21 = s21_sscanf("12345%", "%c%%", &resS21);
  int rcStd = sscanf("12345%", "%c%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent92) {
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc%", "%s%%", strS21);
  int rcStd = sscanf("12345abc%", "%s%%", strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent93) {
  char strS21[10] = {0}, strStd[10] = {0};
  char strS212[10] = {0}, strStd2[10] = {0};
  int rcS21 = s21_sscanf("12345 abc 67890%", "%s%%%s", strS21, strS212);
  int rcStd = sscanf("12345 abc 67890%", "%s%%%s", strStd, strStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
  ck_assert_str_eq(strS212, strStd2);
}
END_TEST

START_TEST(testSscanfPercent94) {
  char strS21[10] = {0}, strStd[10] = {0};
  char strS212[10] = {0}, strStd2[10] = {0};
  int rcS21 = s21_sscanf("12345abc 67890%", "%s%%%s", strS21, strS212);
  int rcStd = sscanf("12345abc 67890%", "%s%%%s", strStd, strStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
  ck_assert_str_eq(strS212, strStd2);
}
END_TEST

START_TEST(testSscanfPercent95) {
  char strS21[10] = {0}, strStd[10] = {0};
  int rcS21 = s21_sscanf("12345abc%", "%5s%%", strS21);
  int rcStd = sscanf("12345abc%", "%5s%%", strStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
}
END_TEST

START_TEST(testSscanfPercent96) {
  char strS21[10] = {0}, strStd[10] = {0};
  char strS212[10] = {0}, strStd2[10] = {0};
  int rcS21 = s21_sscanf("12345 abc 67890%", "%5s%%%8s", strS21, strS212);
  int rcStd = sscanf("12345 abc 67890%", "%5s%%%8s", strStd, strStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS21, strStd);
  ck_assert_str_eq(strS212, strStd2);
}
END_TEST

START_TEST(testSscanfPercent97) {
  char strS212[10] = {0}, strStd2[10] = {0};
  int rcS21 = s21_sscanf("12345abc 67890%", "%*s%%%s", strS212);
  int rcStd = sscanf("12345abc 67890%", "%*s%%%s", strStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_str_eq(strS212, strStd2);
}
END_TEST

START_TEST(testSscanfPercent98) {
  void *resS21 = NULL, *resStd = NULL;
  int rcS21 = s21_sscanf("0x12345678%", "%p%%", &resS21);
  int rcStd = sscanf("0x12345678%", "%p%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ptr_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent99) {
  void *resS211 = NULL, *resStd1 = NULL;
  void *resS212 = NULL, *resStd2 = NULL;
  int rcS21 =
      s21_sscanf("0x12345678 0x9abcdef0%", "%p%%%p", &resS211, &resS212);
  int rcStd = sscanf("0x12345678 0x9abcdef0%", "%p%%%p", &resStd1, &resStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ptr_eq(resS211, resStd1);
  ck_assert_ptr_eq(resS212, resStd2);
}
END_TEST

START_TEST(testSscanfPercent100) {
  void *resS21 = NULL, *resStd = NULL;
  int rcS21 = s21_sscanf("0x12345678%", "%10p%%", &resS21);
  int rcStd = sscanf("0x12345678%", "%10p%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ptr_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent101) {
  void *resS211 = NULL, *resStd1 = NULL;
  void *resS212 = NULL, *resStd2 = NULL;
  int rcS21 =
      s21_sscanf("0x12345678 0x9abcdef0%", "%10p%%%12p", &resS211, &resS212);
  int rcStd =
      sscanf("0x12345678 0x9abcdef0%", "%10p%%%12p", &resStd1, &resStd2);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ptr_eq(resS211, resStd1);
  ck_assert_ptr_eq(resS212, resStd2);
}
END_TEST

START_TEST(testSscanfPercent102) {
  int rcS21 = s21_sscanf("0x12345678%", "%*p%%");
  int rcStd = sscanf("0x12345678%", "%*p%%");
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfPercent104) {
  void *resS21 = NULL, *resStd = NULL;
  int rcS21 = s21_sscanf("abc%", "%p%%", &resS21);
  int rcStd = sscanf("abc%", "%p%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ptr_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent105) {
  void *resS21 = NULL, *resStd = NULL;
  int rcS21 = s21_sscanf("12345%", "%p%%", &resS21);
  int rcStd = sscanf("12345%", "%p%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ptr_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercent106) {
  void *resS21 = NULL, *resStd = NULL;
  int rcS21 = s21_sscanf("0x12345678%", "%10p%%", &resS21);
  int rcStd = sscanf("0x12345678%", "%10p%%", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ptr_eq(resS21, resStd);
}
//////////////////////
// Тесты для спецификатора %Le
START_TEST(testSscanfPercentLe01) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 =
      s21_sscanf("12345678901234567890.12345678901234567890Le", "%Le", &resS21);
  int rcStd =
      sscanf("12345678901234567890.12345678901234567890Le", "%Le", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

START_TEST(testSscanfPercentLe02) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 = s21_sscanf("1.2345678901234567890Le", "%Le", &resS21);
  int rcStd = sscanf("1.2345678901234567890Le", "%Le", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

START_TEST(testSscanfPercentLe03) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 = s21_sscanf("-1.2345678901234567890Le", "%Le", &resS21);
  int rcStd = sscanf("-1.2345678901234567890Le", "%Le", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

START_TEST(testSscanfPercentLe04) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 = s21_sscanf("1.2345678901234567890e+100Le", "%Le", &resS21);
  int rcStd = sscanf("1.2345678901234567890e+100Le", "%Le", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

START_TEST(testSscanfPercentLe05) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 = s21_sscanf("1.2345678901234567890e-100Le", "%Le", &resS21);
  int rcStd = sscanf("1.2345678901234567890e-100Le", "%Le", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

// Тесты для спецификатора %LE
START_TEST(testSscanfPercentLE01) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 =
      s21_sscanf("12345678901234567890.12345678901234567890LE", "%LE", &resS21);
  int rcStd =
      sscanf("12345678901234567890.12345678901234567890LE", "%LE", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

START_TEST(testSscanfPercentLE02) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 = s21_sscanf("1.2345678901234567890LE", "%LE", &resS21);
  int rcStd = sscanf("1.2345678901234567890LE", "%LE", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

START_TEST(testSscanfPercentLE03) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 = s21_sscanf("-1.2345678901234567890LE", "%LE", &resS21);
  int rcStd = sscanf("-1.2345678901234567890LE", "%LE", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

START_TEST(testSscanfPercentLE04) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 = s21_sscanf("1.2345678901234567890e+100LE", "%LE", &resS21);
  int rcStd = sscanf("1.2345678901234567890e+100LE", "%LE", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

START_TEST(testSscanfPercentLE05) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 = s21_sscanf("1.2345678901234567890e-100LE", "%LE", &resS21);
  int rcStd = sscanf("1.2345678901234567890e-100LE", "%LE", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

// Тесты для спецификатора %Lf
START_TEST(testSscanfPercentLf01) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 =
      s21_sscanf("12345678901234567890.12345678901234567890Lf", "%Lf", &resS21);
  int rcStd =
      sscanf("12345678901234567890.12345678901234567890Lf", "%Lf", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

START_TEST(testSscanfPercentLf02) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 = s21_sscanf("1.2345678901234567890Lf", "%Lf", &resS21);
  int rcStd = sscanf("1.2345678901234567890Lf", "%Lf", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

START_TEST(testSscanfPercentLf03) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 = s21_sscanf("-1.2345678901234567890Lf", "%Lf", &resS21);
  int rcStd = sscanf("-1.2345678901234567890Lf", "%Lf", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

START_TEST(testSscanfPercentLf04) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 = s21_sscanf("1.2345678901234567890e+100Lf", "%Lf", &resS21);
  int rcStd = sscanf("1.2345678901234567890e+100Lf", "%Lf", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

START_TEST(testSscanfPercentLf05) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 = s21_sscanf("1.2345678901234567890e-100Lf", "%Lf", &resS21);
  int rcStd = sscanf("1.2345678901234567890e-100Lf", "%Lf", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

// Тесты для спецификатора %Lg
START_TEST(testSscanfPercentLg01) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 =
      s21_sscanf("12345678901234567890.12345678901234567890Lg", "%Lg", &resS21);
  int rcStd =
      sscanf("12345678901234567890.12345678901234567890Lg", "%Lg", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

START_TEST(testSscanfPercentLg02) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 = s21_sscanf("1.2345678901234567890Lg", "%Lg", &resS21);
  int rcStd = sscanf("1.2345678901234567890Lg", "%Lg", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

START_TEST(testSscanfPercentLg03) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 = s21_sscanf("-1.2345678901234567890Lg", "%Lg", &resS21);
  int rcStd = sscanf("-1.2345678901234567890Lg", "%Lg", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

START_TEST(testSscanfPercentLg04) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 = s21_sscanf("1.2345678901234567890e+100Lg", "%Lg", &resS21);
  int rcStd = sscanf("1.2345678901234567890e+100Lg", "%Lg", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

START_TEST(testSscanfPercentLg05) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 = s21_sscanf("1.2345678901234567890e-100Lg", "%Lg", &resS21);
  int rcStd = sscanf("1.2345678901234567890e-100Lg", "%Lg", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

// Тесты для спецификатора %LG
START_TEST(testSscanfPercentLG01) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 =
      s21_sscanf("12345678901234567890.12345678901234567890LG", "%LG", &resS21);
  int rcStd =
      sscanf("12345678901234567890.12345678901234567890LG", "%LG", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

START_TEST(testSscanfPercentLG02) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 = s21_sscanf("1.2345678901234567890LG", "%LG", &resS21);
  int rcStd = sscanf("1.2345678901234567890LG", "%LG", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

START_TEST(testSscanfPercentLG03) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 = s21_sscanf("-1.2345678901234567890LG", "%LG", &resS21);
  int rcStd = sscanf("-1.2345678901234567890LG", "%LG", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

START_TEST(testSscanfPercentLG04) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 = s21_sscanf("1.2345678901234567890e+100LG", "%LG", &resS21);
  int rcStd = sscanf("1.2345678901234567890e+100LG", "%LG", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

START_TEST(testSscanfPercentLG05) {
  long double resS21 = 0.0L, resStd = 0.0L;
  int rcS21 = s21_sscanf("1.2345678901234567890e-100LG", "%LG", &resS21);
  int rcStd = sscanf("1.2345678901234567890e-100LG", "%LG", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_ldouble_eq_tol(resS21, resStd, 1e-9);
}
END_TEST

// Тесты для спецификатора %li
START_TEST(testSscanfPercentli01) {
  long resS21 = 0L, resStd = 0L;
  int rcS21 = s21_sscanf("1234567890li", "%li", &resS21);
  int rcStd = sscanf("1234567890li", "%li", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercentli02) {
  long resS21 = 0L, resStd = 0L;
  int rcS21 = s21_sscanf("-1234567890li", "%li", &resS21);
  int rcStd = sscanf("-1234567890li", "%li", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercentli03) {
  long resS21 = 0L, resStd = 0L;
  int rcS21 = s21_sscanf("0li", "%li", &resS21);
  int rcStd = sscanf("0li", "%li", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

// Тесты для спецификатора %ld
START_TEST(testSscanfPercentld01) {
  long resS21 = 0L, resStd = 0L;
  int rcS21 = s21_sscanf("1234567890ld", "%ld", &resS21);
  int rcStd = sscanf("1234567890ld", "%ld", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercentld02) {
  long resS21 = 0L, resStd = 0L;
  int rcS21 = s21_sscanf("-1234567890ld", "%ld", &resS21);
  int rcStd = sscanf("-1234567890ld", "%ld", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercentld03) {
  long resS21 = 0L, resStd = 0L;
  int rcS21 = s21_sscanf("0ld", "%ld", &resS21);
  int rcStd = sscanf("0ld", "%ld", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

// Тесты для спецификатора %lo
START_TEST(testSscanfPercentlo01) {
  long resS21 = 0L, resStd = 0L;
  int rcS21 = s21_sscanf("1234567890lo", "%lo", &resS21);
  int rcStd = sscanf("1234567890lo", "%lo", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercentlo02) {
  long resS21 = 0L, resStd = 0L;
  int rcS21 = s21_sscanf("17777777777lo", "%lo", &resS21);
  int rcStd = sscanf("17777777777lo", "%lo", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercentlo03) {
  long resS21 = 0L, resStd = 0L;
  int rcS21 = s21_sscanf("0lo", "%lo", &resS21);
  int rcStd = sscanf("0lo", "%lo", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

// Тесты для спецификатора %lu
START_TEST(testSscanfPercentlu01) {
  unsigned long resS21 = 0L, resStd = 0L;
  int rcS21 = s21_sscanf("1234567890lu", "%lu", &resS21);
  int rcStd = sscanf("1234567890lu", "%lu", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_uint_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercentlu02) {
  unsigned long resS21 = 0L, resStd = 0L;
  int rcS21 = s21_sscanf("18446744073709551615lu", "%lu", &resS21);
  int rcStd = sscanf("18446744073709551615lu", "%lu", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_uint_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercentlu03) {
  unsigned long resS21 = 0L, resStd = 0L;
  int rcS21 = s21_sscanf("0lu", "%lu", &resS21);
  int rcStd = sscanf("0lu", "%lu", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_uint_eq(resS21, resStd);
}
END_TEST

// Тесты для спецификатора %lx
START_TEST(testSscanfPercentlx01) {
  unsigned long resS21 = 0L, resStd = 0L;
  int rcS21 = s21_sscanf("1234567890lx", "%lx", &resS21);
  int rcStd = sscanf("1234567890lx", "%lx", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_uint_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercentlx02) {
  unsigned long resS21 = 0L, resStd = 0L;
  int rcS21 = s21_sscanf("fffffffffffflx", "%lx", &resS21);
  int rcStd = sscanf("fffffffffffflx", "%lx", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_uint_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercentlx03) {
  unsigned long resS21 = 0L, resStd = 0L;
  int rcS21 = s21_sscanf("0lx", "%lx", &resS21);
  int rcStd = sscanf("0lx", "%lx", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_uint_eq(resS21, resStd);
}
END_TEST

// Тесты для спецификатора %lX
START_TEST(testSscanfPercentlX01) {
  unsigned long resS21 = 0L, resStd = 0L;
  int rcS21 = s21_sscanf("1234567890lX", "%lX", &resS21);
  int rcStd = sscanf("1234567890lX", "%lX", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_uint_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercentlX02) {
  unsigned long resS21 = 0L, resStd = 0L;
  int rcS21 = s21_sscanf("FFFFFFFFFFFFlX", "%lX", &resS21);
  int rcStd = sscanf("FFFFFFFFFFFFlX", "%lX", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_uint_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercentlX03) {
  unsigned long resS21 = 0L, resStd = 0L;
  int rcS21 = s21_sscanf("0lX", "%lX", &resS21);
  int rcStd = sscanf("0lX", "%lX", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_uint_eq(resS21, resStd);
}
END_TEST

// Тесты для спецификатора %lc
START_TEST(testSscanfPercentlc01) {
  wchar_t resS21 = L'\0', resStd = L'\0';
  int rcS21 = s21_sscanf("1lc", "%lc", &resS21);
  int rcStd = sscanf("1lc", "%lc", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfPercentlc02) {
  wchar_t resS21 = L'\0', resStd = L'\0';
  int rcS21 = s21_sscanf("Alic", "%lc", &resS21);
  int rcStd = sscanf("Alic", "%lc", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfPercentlc03) {
  wchar_t resS21 = L'\0', resStd = L'\0';
  int rcS21 = s21_sscanf("alic", "%lc", &resS21);
  int rcStd = sscanf("alic", "%lc", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

// Тесты для спецификатора %ls
START_TEST(testSscanfPercentls01) {
  wchar_t resS21[10] = {L'\0'}, resStd[10] = {L'\0'};
  int rcS21 = s21_sscanf("Hellols", "%ls", resS21);
  int rcStd = sscanf("Hellols", "%ls", resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfPercentls02) {
  wchar_t resS21[10] = {L'\0'}, resStd[10] = {L'\0'};
  int rcS21 = s21_sscanf("worldls", "%ls", resS21);
  int rcStd = sscanf("worldls", "%ls", resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfPercentls03) {
  wchar_t resS21[10] = {L'\0'}, resStd[10] = {L'\0'};
  int rcS21 = s21_sscanf("12345ls", "%ls", resS21);
  int rcStd = sscanf("12345ls", "%ls", resStd);
  ck_assert_int_eq(rcS21, rcStd);
}
END_TEST

START_TEST(testSscanfPercenthi01) {
  short resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345hi", "%hi", &resS21);
  int rcStd = sscanf("12345hi", "%hi", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercenthi02) {
  short resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("-12345hi", "%hi", &resS21);
  int rcStd = sscanf("-12345hi", "%hi", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercenthi03) {
  short resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("0hi", "%hi", &resS21);
  int rcStd = sscanf("0hi", "%hi", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

// Тесты для спецификатора %hd
START_TEST(testSscanfPercenthd01) {
  short resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345hd", "%hd", &resS21);
  int rcStd = sscanf("12345hd", "%hd", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercenthd02) {
  short resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("-12345hd", "%hd", &resS21);
  int rcStd = sscanf("-12345hd", "%hd", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercenthd03) {
  short resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("0hd", "%hd", &resS21);
  int rcStd = sscanf("0hd", "%hd", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

// Тесты для спецификатора %ho
START_TEST(testSscanfPercentho01) {
  short resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345ho", "%ho", &resS21);
  int rcStd = sscanf("12345ho", "%ho", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercentho02) {
  short resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("17777ho", "%ho", &resS21);
  int rcStd = sscanf("17777ho", "%ho", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercentho03) {
  short resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("0ho", "%ho", &resS21);
  int rcStd = sscanf("0ho", "%ho", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_int_eq(resS21, resStd);
}
END_TEST

// Тесты для спецификатора %hu
START_TEST(testSscanfPercenthu01) {
  unsigned short resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345hu", "%hu", &resS21);
  int rcStd = sscanf("12345hu", "%hu", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_uint_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercenthu02) {
  unsigned short resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("65535hu", "%hu", &resS21);
  int rcStd = sscanf("65535hu", "%hu", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_uint_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercenthu03) {
  unsigned short resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("0hu", "%hu", &resS21);
  int rcStd = sscanf("0hu", "%hu", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_uint_eq(resS21, resStd);
}
END_TEST

// Тесты для спецификатора %hx
START_TEST(testSscanfPercenthx01) {
  unsigned short resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345hx", "%hx", &resS21);
  int rcStd = sscanf("12345hx", "%hx", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_uint_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercenthx02) {
  unsigned short resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("ffffhx", "%hx", &resS21);
  int rcStd = sscanf("ffffhx", "%hx", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_uint_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercenthx03) {
  unsigned short resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("0hx", "%hx", &resS21);
  int rcStd = sscanf("0hx", "%hx", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_uint_eq(resS21, resStd);
}
END_TEST

// Тесты для спецификатора %hX
START_TEST(testSscanfPercenthX01) {
  unsigned short resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("12345hX", "%hX", &resS21);
  int rcStd = sscanf("12345hX", "%hX", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_uint_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercenthX02) {
  unsigned short resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("FFFFhX", "%hX", &resS21);
  int rcStd = sscanf("FFFFhX", "%hX", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_uint_eq(resS21, resStd);
}
END_TEST

START_TEST(testSscanfPercenthX03) {
  unsigned short resS21 = 0, resStd = 0;
  int rcS21 = s21_sscanf("0hX", "%hX", &resS21);
  int rcStd = sscanf("0hX", "%hX", &resStd);
  ck_assert_int_eq(rcS21, rcStd);
  ck_assert_uint_eq(resS21, resStd);
}
END_TEST

// Функция для добавления тестов для спецификатора %c
static void add_c_tests(TCase *tcase) {
  tcase_add_test(tcase, testSscanfC1);
  tcase_add_test(tcase, testSscanfC2);
  tcase_add_test(tcase, testSscanfC3);
  tcase_add_test(tcase, testSscanfC4);
  tcase_add_test(tcase, testSscanfC5);
  tcase_add_test(tcase, testSscanfC6);
  tcase_add_test(tcase, testSscanfC7);
  tcase_add_test(tcase, testSscanfC8);
  tcase_add_test(tcase, testSscanfC9);
  tcase_add_test(tcase, testSscanfC10);
  tcase_add_test(tcase, testSscanfC11);
}

// Функция для добавления тестов для спецификатора %d
static void add_d_tests(TCase *tcase) {
  tcase_add_test(tcase, testSscanfD1);
  tcase_add_test(tcase, testSscanfD2);
  tcase_add_test(tcase, testSscanfD3);
  tcase_add_test(tcase, testSscanfD4);
  tcase_add_test(tcase, testSscanfD5);
  tcase_add_test(tcase, testSscanfD6);
  tcase_add_test(tcase, testSscanfD7);
  tcase_add_test(tcase, testSscanfD8);
  tcase_add_test(tcase, testSscanfD9);
  tcase_add_test(tcase, testSscanfD10);
  tcase_add_test(tcase, testSscanfD11);
  tcase_add_test(tcase, testSscanfD12);
  tcase_add_test(tcase, testSscanfD13);
  tcase_add_test(tcase, testSscanfD14);
  tcase_add_test(tcase, testSscanfD15);
  tcase_add_test(tcase, testSscanfD16);
}

// Функция для добавления тестов для спецификатора %i
static void add_i_tests(TCase *tcase) {
  tcase_add_test(tcase, testSscanfI1);
  tcase_add_test(tcase, testSscanfI2);
  tcase_add_test(tcase, testSscanfI3);
  tcase_add_test(tcase, testSscanfI4);
  tcase_add_test(tcase, testSscanfI5);
  tcase_add_test(tcase, testSscanfI6);
  tcase_add_test(tcase, testSscanfI7);
  tcase_add_test(tcase, testSscanfI8);
  tcase_add_test(tcase, testSscanfI9);
  tcase_add_test(tcase, testSscanfI10);
  tcase_add_test(tcase, testSscanfI11);
  tcase_add_test(tcase, testSscanfI12);
  tcase_add_test(tcase, testSscanfI13);
  tcase_add_test(tcase, testSscanfI14);
  tcase_add_test(tcase, testSscanfI17);
  tcase_add_test(tcase, testSscanfI18);
}

// Функция для добавления тестов для спецификаторов %e и %E
static void add_e_tests(TCase *tcase) {
  tcase_add_test(tcase, testSscanfE1);
  tcase_add_test(tcase, testSscanfE2);
  tcase_add_test(tcase, testSscanfE3);
  tcase_add_test(tcase, testSscanfE4);
  tcase_add_test(tcase, testSscanfE5);
  tcase_add_test(tcase, testSscanfE6);
  tcase_add_test(tcase, testSscanfE7);
  tcase_add_test(tcase, testSscanfE8);
  tcase_add_test(tcase, testSscanfE9);
  tcase_add_test(tcase, testSscanfE10);
  tcase_add_test(tcase, testSscanfE11);
  tcase_add_test(tcase, testSscanfE12);
  tcase_add_test(tcase, testSscanfE13);
  tcase_add_test(tcase, testSscanfE14);
  tcase_add_test(tcase, testSscanfE15);
  tcase_add_test(tcase, testSscanfE16);
  tcase_add_test(tcase, testSscanfE17);
  tcase_add_test(tcase, testSscanfE18);
  tcase_add_test(tcase, testSscanfE19);
}

// Функция для добавления тестов для спецификаторов %f
static void add_f_tests(TCase *tcase) {
  tcase_add_test(tcase, testSscanfF1);
  tcase_add_test(tcase, testSscanfF2);
  tcase_add_test(tcase, testSscanfF3);
  tcase_add_test(tcase, testSscanfF4);
  tcase_add_test(tcase, testSscanfF5);
  tcase_add_test(tcase, testSscanfF6);
  tcase_add_test(tcase, testSscanfF7);
  tcase_add_test(tcase, testSscanfF8);
  tcase_add_test(tcase, testSscanfF9);
  tcase_add_test(tcase, testSscanfF10);
  tcase_add_test(tcase, testSscanfF11);
  tcase_add_test(tcase, testSscanfF12);
  tcase_add_test(tcase, testSscanfF13);
  tcase_add_test(tcase, testSscanfF14);
  tcase_add_test(tcase, testSscanfF15);
}

// Функция для добавления тестов для спецификаторов %f
static void add_g_G_tests(TCase *tcase) {
  tcase_add_test(tcase, testSscanfGg1);
  tcase_add_test(tcase, testSscanfGg2);
  tcase_add_test(tcase, testSscanfGg3);
  tcase_add_test(tcase, testSscanfGg4);
  tcase_add_test(tcase, testSscanfGg5);
  tcase_add_test(tcase, testSscanfGg6);
  tcase_add_test(tcase, testSscanfGg7);
  tcase_add_test(tcase, testSscanfGg8);
  tcase_add_test(tcase, testSscanfGg9);
  tcase_add_test(tcase, testSscanfGg10);
  tcase_add_test(tcase, testSscanfGg11);
  tcase_add_test(tcase, testSscanfGg12);
  tcase_add_test(tcase, testSscanfGg13);
  tcase_add_test(tcase, testSscanfGg14);
  tcase_add_test(tcase, testSscanfGg15);
  tcase_add_test(tcase, testSscanfGg16);
  tcase_add_test(tcase, testSscanfGg17);
}

// Функция для добавления тестов для спецификаторов %o
static void add_o_tests(TCase *tcase) {
  tcase_add_test(tcase, testSscanfO1);
  tcase_add_test(tcase, testSscanfO2);
  tcase_add_test(tcase, testSscanfO3);
  tcase_add_test(tcase, testSscanfO4);
  tcase_add_test(tcase, testSscanfO5);
  tcase_add_test(tcase, testSscanfO6);
  tcase_add_test(tcase, testSscanfO7);
  tcase_add_test(tcase, testSscanfO8);
  tcase_add_test(tcase, testSscanfO9);
  tcase_add_test(tcase, testSscanfO10);
  tcase_add_test(tcase, testSscanfO11);
  tcase_add_test(tcase, testSscanfO12);
}

// Функция для добавления тестов для спецификаторов %s
static void add_s_tests(TCase *tcase) {
  tcase_add_test(tcase, testSscanfS1);
  tcase_add_test(tcase, testSscanfS2);
  tcase_add_test(tcase, testSscanfS3);
  tcase_add_test(tcase, testSscanfS4);
  tcase_add_test(tcase, testSscanfS5);
  tcase_add_test(tcase, testSscanfS6);
  tcase_add_test(tcase, testSscanfS7);
  tcase_add_test(tcase, testSscanfS8);
  tcase_add_test(tcase, testSscanfS9);
  tcase_add_test(tcase, testSscanfS10);
  tcase_add_test(tcase, testSscanfS11);
}

// Функция для добавления тестов для спецификаторов %s
static void add_u_tests(TCase *tcase) {
  tcase_add_test(tcase, testSscanfU1);
  tcase_add_test(tcase, testSscanfU2);
  tcase_add_test(tcase, testSscanfU3);
  tcase_add_test(tcase, testSscanfU4);
  tcase_add_test(tcase, testSscanfU5);
  tcase_add_test(tcase, testSscanfU6);
  tcase_add_test(tcase, testSscanfU7);
  tcase_add_test(tcase, testSscanfU8);
  tcase_add_test(tcase, testSscanfU9);
  tcase_add_test(tcase, testSscanfU10);
  tcase_add_test(tcase, testSscanfU11);
  tcase_add_test(tcase, testSscanfU12);
  tcase_add_test(tcase, testSscanfU13);
  tcase_add_test(tcase, testSscanfU14);
  tcase_add_test(tcase, testSscanfU15);
  tcase_add_test(tcase, testSscanfU16);
}

// Функция для добавления тестов для спецификаторов %X и %x
static void add_x_X_tests(TCase *tcase) {
  tcase_add_test(tcase, testSscanfX1);
  tcase_add_test(tcase, testSscanfX2);
  tcase_add_test(tcase, testSscanfX3);
  tcase_add_test(tcase, testSscanfX4);
  tcase_add_test(tcase, testSscanfX5);
  tcase_add_test(tcase, testSscanfX6);
  tcase_add_test(tcase, testSscanfX7);
  tcase_add_test(tcase, testSscanfX8);
  tcase_add_test(tcase, testSscanfX9);
  tcase_add_test(tcase, testSscanfX10);
  tcase_add_test(tcase, testSscanfX11);
  tcase_add_test(tcase, testSscanfX12);
  tcase_add_test(tcase, testSscanfX13);
  tcase_add_test(tcase, testSscanfX14);
  tcase_add_test(tcase, testSscanfX15);
  tcase_add_test(tcase, testSscanfX16);
  tcase_add_test(tcase, testSscanfX17);
  tcase_add_test(tcase, testSscanfX18);
  tcase_add_test(tcase, testSscanfX19);
  tcase_add_test(tcase, testSscanfX20);
  tcase_add_test(tcase, testSscanfX21);
  tcase_add_test(tcase, testSscanfX22);
  tcase_add_test(tcase, testSscanfx1);
  tcase_add_test(tcase, testSscanfx2);
  tcase_add_test(tcase, testSscanfx3);
  tcase_add_test(tcase, testSscanfx4);
  tcase_add_test(tcase, testSscanfx5);
  tcase_add_test(tcase, testSscanfx6);
  tcase_add_test(tcase, testSscanfx7);
  tcase_add_test(tcase, testSscanfx8);
  tcase_add_test(tcase, testSscanfx9);
  tcase_add_test(tcase, testSscanfx10);
  tcase_add_test(tcase, testSscanfx11);
  tcase_add_test(tcase, testSscanfx12);
  tcase_add_test(tcase, testSscanfx13);
  tcase_add_test(tcase, testSscanfx14);
  tcase_add_test(tcase, testSscanfx15);
  tcase_add_test(tcase, testSscanfx16);
  tcase_add_test(tcase, testSscanfx17);
  tcase_add_test(tcase, testSscanfx18);
  tcase_add_test(tcase, testSscanfx19);
}

// Функция для добавления тестов для спецификаторов %p
static void add_p_tests(TCase *tcase) {
  tcase_add_test(tcase, testSscanfP1);
  tcase_add_test(tcase, testSscanfP2);
  tcase_add_test(tcase, testSscanfP3);
  tcase_add_test(tcase, testSscanfP4);
  tcase_add_test(tcase, testSscanfP5);
  tcase_add_test(tcase, testSscanfP6);
  tcase_add_test(tcase, testSscanfP7);
  tcase_add_test(tcase, testSscanfP8);
  tcase_add_test(tcase, testSscanfP9);
  tcase_add_test(tcase, testSscanfP10);
  tcase_add_test(tcase, testSscanfP11);
  tcase_add_test(tcase, testSscanfP12);
  tcase_add_test(tcase, testSscanfP13);
  tcase_add_test(tcase, testSscanfP14);
  tcase_add_test(tcase, testSscanfP15);
}

// Функция для добавления тестов для спецификаторов %n
static void add_n1_tests(TCase *tcase) {
  tcase_add_test(tcase, testSscanfN1);
  tcase_add_test(tcase, testSscanfN2);
  tcase_add_test(tcase, testSscanfN3);
  tcase_add_test(tcase, testSscanfN5);
  tcase_add_test(tcase, testSscanfN6);
  tcase_add_test(tcase, testSscanfN7);
  tcase_add_test(tcase, testSscanfN8);
  tcase_add_test(tcase, testSscanfN9);
  tcase_add_test(tcase, testSscanfN11);
  tcase_add_test(tcase, testSscanfN12);
  tcase_add_test(tcase, testSscanfN13);
  tcase_add_test(tcase, testSscanfN14);
  tcase_add_test(tcase, testSscanfN15);
  tcase_add_test(tcase, testSscanfN17);
  tcase_add_test(tcase, testSscanfN18);
  tcase_add_test(tcase, testSscanfN19);
  tcase_add_test(tcase, testSscanfN20);
  tcase_add_test(tcase, testSscanfN21);
  tcase_add_test(tcase, testSscanfN22);
  tcase_add_test(tcase, testSscanfN23);
  tcase_add_test(tcase, testSscanfN24);
  tcase_add_test(tcase, testSscanfN25);
  tcase_add_test(tcase, testSscanfN26);
  tcase_add_test(tcase, testSscanfN27);
  tcase_add_test(tcase, testSscanfN28);
  tcase_add_test(tcase, testSscanfN29);
  tcase_add_test(tcase, testSscanfN30);
}

static void add_n2_tests(TCase *tcase) {
  tcase_add_test(tcase, testSscanfN31);
  tcase_add_test(tcase, testSscanfN32);
  tcase_add_test(tcase, testSscanfN33);
  tcase_add_test(tcase, testSscanfN34);
  tcase_add_test(tcase, testSscanfN35);
  tcase_add_test(tcase, testSscanfN36);
  tcase_add_test(tcase, testSscanfN37);
  tcase_add_test(tcase, testSscanfN38);
  tcase_add_test(tcase, testSscanfN39);
  tcase_add_test(tcase, testSscanfN40);
  tcase_add_test(tcase, testSscanfN41);
  tcase_add_test(tcase, testSscanfN42);
  tcase_add_test(tcase, testSscanfN43);
  tcase_add_test(tcase, testSscanfN44);
  tcase_add_test(tcase, testSscanfN45);
  tcase_add_test(tcase, testSscanfN46);
  tcase_add_test(tcase, testSscanfN47);
  tcase_add_test(tcase, testSscanfN48);
  tcase_add_test(tcase, testSscanfN50);
  tcase_add_test(tcase, testSscanfN51);
  tcase_add_test(tcase, testSscanfN52);
  tcase_add_test(tcase, testSscanfN54);
  tcase_add_test(tcase, testSscanfN55);
  tcase_add_test(tcase, testSscanfN56);
  tcase_add_test(tcase, testSscanfN58);
  tcase_add_test(tcase, testSscanfN59);
  tcase_add_test(tcase, testSscanfN60);
}

static void add_n3_tests(TCase *tcase) {
  tcase_add_test(tcase, testSscanfN61);
  tcase_add_test(tcase, testSscanfN62);
  tcase_add_test(tcase, testSscanfN63);
  tcase_add_test(tcase, testSscanfN64);
  tcase_add_test(tcase, testSscanfN65);
  tcase_add_test(tcase, testSscanfN66);
  tcase_add_test(tcase, testSscanfN67);
  tcase_add_test(tcase, testSscanfN68);
  tcase_add_test(tcase, testSscanfN69);
  tcase_add_test(tcase, testSscanfN71);
  tcase_add_test(tcase, testSscanfN72);
  tcase_add_test(tcase, testSscanfN74);
  tcase_add_test(tcase, testSscanfN75);
  tcase_add_test(tcase, testSscanfN77);
  tcase_add_test(tcase, testSscanfN78);
  tcase_add_test(tcase, testSscanfN79);
  tcase_add_test(tcase, testSscanfN80);
  tcase_add_test(tcase, testSscanfN81);
  tcase_add_test(tcase, testSscanfN82);
  tcase_add_test(tcase, testSscanfN85);
  tcase_add_test(tcase, testSscanfN86);
  tcase_add_test(tcase, testSscanfN87);
  tcase_add_test(tcase, testSscanfN89);
  tcase_add_test(tcase, testSscanfN90);
}

static void add_n4_tests(TCase *tcase) {
  tcase_add_test(tcase, testSscanfN91);
  tcase_add_test(tcase, testSscanfN92);
  tcase_add_test(tcase, testSscanfN93);
  tcase_add_test(tcase, testSscanfN94);
  tcase_add_test(tcase, testSscanfN95);
  tcase_add_test(tcase, testSscanfN96);
  tcase_add_test(tcase, testSscanfN97);
  tcase_add_test(tcase, testSscanfN98);
  tcase_add_test(tcase, testSscanfN99);
  tcase_add_test(tcase, testSscanfN101);
  tcase_add_test(tcase, testSscanfN102);
  tcase_add_test(tcase, testSscanfN103);
}

// Функция для добавления тестов для спецификаторов %%
static void add_proz1_tests(TCase *tcase) {
  tcase_add_test(tcase, testSscanfPercent01);
  tcase_add_test(tcase, testSscanfPercent02);
  tcase_add_test(tcase, testSscanfPercent03);
  tcase_add_test(tcase, testSscanfPercent04);
  tcase_add_test(tcase, testSscanfPercent05);
  tcase_add_test(tcase, testSscanfPercent06);
  tcase_add_test(tcase, testSscanfPercent07);
  tcase_add_test(tcase, testSscanfPercent08);
  tcase_add_test(tcase, testSscanfPercent10);
  tcase_add_test(tcase, testSscanfPercent11);
  tcase_add_test(tcase, testSscanfPercent12);
  tcase_add_test(tcase, testSscanfPercent13);
  tcase_add_test(tcase, testSscanfPercent14);
  tcase_add_test(tcase, testSscanfPercent15);
  tcase_add_test(tcase, testSscanfPercent16);
  tcase_add_test(tcase, testSscanfPercent17);
  tcase_add_test(tcase, testSscanfPercent18);
  tcase_add_test(tcase, testSscanfPercent19);
  tcase_add_test(tcase, testSscanfPercent20);
  tcase_add_test(tcase, testSscanfPercent21);
  tcase_add_test(tcase, testSscanfPercent22);
  tcase_add_test(tcase, testSscanfPercent23);
  tcase_add_test(tcase, testSscanfPercent24);
  tcase_add_test(tcase, testSscanfPercent25);
  tcase_add_test(tcase, testSscanfPercent26);
  tcase_add_test(tcase, testSscanfPercent27);
  tcase_add_test(tcase, testSscanfPercent28);
  tcase_add_test(tcase, testSscanfPercent29);
  tcase_add_test(tcase, testSscanfPercent30);
  tcase_add_test(tcase, testSscanfPercent31);
  tcase_add_test(tcase, testSscanfPercent32);
  tcase_add_test(tcase, testSscanfPercent33);
  tcase_add_test(tcase, testSscanfPercent34);
  tcase_add_test(tcase, testSscanfPercent35);
  tcase_add_test(tcase, testSscanfPercent36);
  tcase_add_test(tcase, testSscanfPercent37);
  tcase_add_test(tcase, testSscanfPercent38);
  tcase_add_test(tcase, testSscanfPercent39);
  tcase_add_test(tcase, testSscanfPercent40);
}

static void add_proz2_tests(TCase *tcase) {
  tcase_add_test(tcase, testSscanfPercent41);
  tcase_add_test(tcase, testSscanfPercent42);
  tcase_add_test(tcase, testSscanfPercent43);
  tcase_add_test(tcase, testSscanfPercent44);
  tcase_add_test(tcase, testSscanfPercent45);
  tcase_add_test(tcase, testSscanfPercent46);
  tcase_add_test(tcase, testSscanfPercent47);
  tcase_add_test(tcase, testSscanfPercent48);
  tcase_add_test(tcase, testSscanfPercent49);
  tcase_add_test(tcase, testSscanfPercent51);
  tcase_add_test(tcase, testSscanfPercent52);
  tcase_add_test(tcase, testSscanfPercent53);
  tcase_add_test(tcase, testSscanfPercent54);
  tcase_add_test(tcase, testSscanfPercent55);
  tcase_add_test(tcase, testSscanfPercent56);
  tcase_add_test(tcase, testSscanfPercent57);
  tcase_add_test(tcase, testSscanfPercent59);
  tcase_add_test(tcase, testSscanfPercent60);
  tcase_add_test(tcase, testSscanfPercent61);
  tcase_add_test(tcase, testSscanfPercent63);
  tcase_add_test(tcase, testSscanfPercent64);
  tcase_add_test(tcase, testSscanfPercent65);
  tcase_add_test(tcase, testSscanfPercent67);
  tcase_add_test(tcase, testSscanfPercent68);
  tcase_add_test(tcase, testSscanfPercent69);
  tcase_add_test(tcase, testSscanfPercent71);
  tcase_add_test(tcase, testSscanfPercent72);
  tcase_add_test(tcase, testSscanfPercent73);
  tcase_add_test(tcase, testSscanfPercent74);
  tcase_add_test(tcase, testSscanfPercent75);
  tcase_add_test(tcase, testSscanfPercent76);
  tcase_add_test(tcase, testSscanfPercent77);
  tcase_add_test(tcase, testSscanfPercent78);
  tcase_add_test(tcase, testSscanfPercent79);
  tcase_add_test(tcase, testSscanfPercent80);
}

static void add_proz3_tests(TCase *tcase) {
  tcase_add_test(tcase, testSscanfPercent81);
  tcase_add_test(tcase, testSscanfPercent82);
  tcase_add_test(tcase, testSscanfPercent83);
  tcase_add_test(tcase, testSscanfPercent84);
  tcase_add_test(tcase, testSscanfPercent85);
  tcase_add_test(tcase, testSscanfPercent86);
  tcase_add_test(tcase, testSscanfPercent88);
  tcase_add_test(tcase, testSscanfPercent89);
  tcase_add_test(tcase, testSscanfPercent90);
  tcase_add_test(tcase, testSscanfPercent91);
  tcase_add_test(tcase, testSscanfPercent92);
  tcase_add_test(tcase, testSscanfPercent93);
  tcase_add_test(tcase, testSscanfPercent94);
  tcase_add_test(tcase, testSscanfPercent95);
  tcase_add_test(tcase, testSscanfPercent96);
  tcase_add_test(tcase, testSscanfPercent97);
  tcase_add_test(tcase, testSscanfPercent98);
  tcase_add_test(tcase, testSscanfPercent99);
  tcase_add_test(tcase, testSscanfPercent100);
  tcase_add_test(tcase, testSscanfPercent101);
  tcase_add_test(tcase, testSscanfPercent102);
  tcase_add_test(tcase, testSscanfPercent104);
  tcase_add_test(tcase, testSscanfPercent105);
  tcase_add_test(tcase, testSscanfPercent106);
}

// Функция для добавления тестов с длиной
static void add_len_tests(TCase *tcase) {
  tcase_add_test(tcase, testSscanfPercentLe01);
  tcase_add_test(tcase, testSscanfPercentLe02);
  tcase_add_test(tcase, testSscanfPercentLe03);
  tcase_add_test(tcase, testSscanfPercentLe04);
  tcase_add_test(tcase, testSscanfPercentLe05);
  tcase_add_test(tcase, testSscanfPercentLE01);
  tcase_add_test(tcase, testSscanfPercentLE02);
  tcase_add_test(tcase, testSscanfPercentLE03);
  tcase_add_test(tcase, testSscanfPercentLE04);
  tcase_add_test(tcase, testSscanfPercentLE05);
  tcase_add_test(tcase, testSscanfPercentLf01);
  tcase_add_test(tcase, testSscanfPercentLf02);
  tcase_add_test(tcase, testSscanfPercentLf03);
  tcase_add_test(tcase, testSscanfPercentLf04);
  tcase_add_test(tcase, testSscanfPercentLf05);
  tcase_add_test(tcase, testSscanfPercentLg01);
  tcase_add_test(tcase, testSscanfPercentLg02);
  tcase_add_test(tcase, testSscanfPercentLg03);
  tcase_add_test(tcase, testSscanfPercentLg04);
  tcase_add_test(tcase, testSscanfPercentLg05);
  tcase_add_test(tcase, testSscanfPercentLG01);
  tcase_add_test(tcase, testSscanfPercentLG02);
  tcase_add_test(tcase, testSscanfPercentLG03);
  tcase_add_test(tcase, testSscanfPercentLG04);
  tcase_add_test(tcase, testSscanfPercentLG05);

  tcase_add_test(tcase, testSscanfPercentli01);
  tcase_add_test(tcase, testSscanfPercentli02);
  tcase_add_test(tcase, testSscanfPercentli03);

  tcase_add_test(tcase, testSscanfPercentld01);
  tcase_add_test(tcase, testSscanfPercentld02);
  tcase_add_test(tcase, testSscanfPercentld03);

  tcase_add_test(tcase, testSscanfPercentlo01);
  tcase_add_test(tcase, testSscanfPercentlo02);
  tcase_add_test(tcase, testSscanfPercentlo03);

  tcase_add_test(tcase, testSscanfPercentlu01);
  tcase_add_test(tcase, testSscanfPercentlu02);
  tcase_add_test(tcase, testSscanfPercentlu03);

  tcase_add_test(tcase, testSscanfPercentlx01);
  tcase_add_test(tcase, testSscanfPercentlx02);
  tcase_add_test(tcase, testSscanfPercentlx03);

  tcase_add_test(tcase, testSscanfPercentlX01);
  tcase_add_test(tcase, testSscanfPercentlX02);
  tcase_add_test(tcase, testSscanfPercentlX03);

  tcase_add_test(tcase, testSscanfPercentlc01);
  tcase_add_test(tcase, testSscanfPercentlc02);
  tcase_add_test(tcase, testSscanfPercentlc03);

  tcase_add_test(tcase, testSscanfPercentls01);
  tcase_add_test(tcase, testSscanfPercentls02);
  tcase_add_test(tcase, testSscanfPercentls03);

  tcase_add_test(tcase, testSscanfPercenthi01);
  tcase_add_test(tcase, testSscanfPercenthi02);
  tcase_add_test(tcase, testSscanfPercenthi03);

  tcase_add_test(tcase, testSscanfPercenthd01);
  tcase_add_test(tcase, testSscanfPercenthd02);
  tcase_add_test(tcase, testSscanfPercenthd03);

  tcase_add_test(tcase, testSscanfPercentho01);
  tcase_add_test(tcase, testSscanfPercentho02);
  tcase_add_test(tcase, testSscanfPercentho03);

  tcase_add_test(tcase, testSscanfPercenthu01);
  tcase_add_test(tcase, testSscanfPercenthu02);
  tcase_add_test(tcase, testSscanfPercenthu03);

  tcase_add_test(tcase, testSscanfPercenthx01);
  tcase_add_test(tcase, testSscanfPercenthx02);
  tcase_add_test(tcase, testSscanfPercenthx03);

  tcase_add_test(tcase, testSscanfPercenthX01);
  tcase_add_test(tcase, testSscanfPercenthX02);
  tcase_add_test(tcase, testSscanfPercenthX03);
}

// Основная функция для создания набора тестов
Suite *S21SscanfSuite(void) {
  Suite *suite = suite_create("S21SscanfSuite");

  // Создание отдельных наборов тестов для каждого спецификатора
  TCase *tcaseCoreC = tcase_create("specifierC");
  TCase *tcaseCoreD = tcase_create("specifierD");
  TCase *tcaseCoreI = tcase_create("specifierI");
  TCase *tcaseCoreE = tcase_create("specifierE");
  TCase *tcaseCoreF = tcase_create("specifierF");
  TCase *tcaseCoreG = tcase_create("specifierG");
  TCase *tcaseCoreO = tcase_create("specifierO");
  TCase *tcaseCoreS = tcase_create("specifierS");
  TCase *tcaseCoreU = tcase_create("specifierU");
  TCase *tcaseCoreX = tcase_create("specifierX");
  TCase *tcaseCoreP = tcase_create("specifierP");
  TCase *tcaseCoreN1 = tcase_create("specifierN1");
  TCase *tcaseCoreN2 = tcase_create("specifierN2");
  TCase *tcaseCoreN3 = tcase_create("specifierN3");
  TCase *tcaseCoreN4 = tcase_create("specifierN4");
  TCase *tcaseCoreProz1 = tcase_create("specifierProz1");
  TCase *tcaseCoreProz2 = tcase_create("specifierProz2");
  TCase *tcaseCoreProz3 = tcase_create("specifierProz3");
  TCase *tcaseCoreLen = tcase_create("specifierLen");

  // Добавление тестов в соответствующие наборы
  add_c_tests(tcaseCoreC);
  add_d_tests(tcaseCoreD);
  add_i_tests(tcaseCoreI);
  add_e_tests(tcaseCoreE);
  add_f_tests(tcaseCoreF);
  add_g_G_tests(tcaseCoreG);
  add_o_tests(tcaseCoreO);
  add_s_tests(tcaseCoreS);
  add_u_tests(tcaseCoreU);
  add_x_X_tests(tcaseCoreX);
  add_p_tests(tcaseCoreP);
  add_n1_tests(tcaseCoreN1);
  add_n2_tests(tcaseCoreN2);
  add_n3_tests(tcaseCoreN3);
  add_n4_tests(tcaseCoreN4);
  add_proz1_tests(tcaseCoreProz1);
  add_proz2_tests(tcaseCoreProz2);
  add_proz3_tests(tcaseCoreProz3);
  add_len_tests(tcaseCoreLen);

  // Добавление наборов тестов в общий набор
  suite_add_tcase(suite, tcaseCoreC);
  suite_add_tcase(suite, tcaseCoreD);
  suite_add_tcase(suite, tcaseCoreI);
  suite_add_tcase(suite, tcaseCoreE);
  suite_add_tcase(suite, tcaseCoreF);
  suite_add_tcase(suite, tcaseCoreG);
  suite_add_tcase(suite, tcaseCoreO);
  suite_add_tcase(suite, tcaseCoreS);
  suite_add_tcase(suite, tcaseCoreU);
  suite_add_tcase(suite, tcaseCoreX);
  suite_add_tcase(suite, tcaseCoreP);
  suite_add_tcase(suite, tcaseCoreN1);
  suite_add_tcase(suite, tcaseCoreN2);
  suite_add_tcase(suite, tcaseCoreN3);
  suite_add_tcase(suite, tcaseCoreN4);
  suite_add_tcase(suite, tcaseCoreProz1);
  suite_add_tcase(suite, tcaseCoreProz2);
  suite_add_tcase(suite, tcaseCoreProz3);
  suite_add_tcase(suite, tcaseCoreLen);
  return suite;
}

// Главная функция для запуска тестов
int main(void) {
  int failed = 0;
  Suite *suite = S21SscanfSuite();
  SRunner *runner = srunner_create(suite);

  // Запуск всех тестов с нормальным режимом
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);

  // Освобождение ресурсов и возврат результата
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}