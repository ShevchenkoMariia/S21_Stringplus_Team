#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

#include "s21_string.h"

#define SPECS "cdifsugGeExXop"
#define FLAGS "+- 0#"
#define LENGTH "hlL"
#define NUMS "1234567890*"
#define DOT '.'
#define VALID "cdifsugGeExXop+- 0#hlL1234567890*."
#define STAR '*'
typedef struct flag {
  int plus;
  int minus;
  int space;
  int zero;
  int jail;
} flag;
typedef struct format {
  char spec;
  flag flag;
  int wid;
  int prec;
  char len;
} format;

enum Types { INT, UNSIGNED, FLOAT, SCIENCE, H_FLOAT, CHAR, STR, PTR };
void formating(char *, va_list *, format *);

void strToStr(char *, va_list *);
void lstrToStr(char *, va_list *);

void charToStr(char *, va_list *);
void lcharToStr(char *, va_list *);

void pToStr(char *, va_list *, char);

int getBase(char, int);
char getFlag(format *);

int setPrefixSign(char *, long double, char);
int setWidth(char *, char *, int, char);

int newInt(char *, void *, char, char, int, char);
void newIntU(char *, va_list *, char, int, int, char, char);
int newFloat(char *, void *, char, int, char, int);
long double newE(char *, va_list *, char, char, int, char, int);
void newG(char *, va_list *, char, char, int, char, int);
void cut(char *);

int gTrim(long double, int);
void trimFloat(long double *, int);
int sharpFlagProc(char *, char);
void addBuffers(char *, char *, int, int, char);
char getSpaces(int);
enum Types getType(char);

// int s21_sprintf(char *dest, char *src, ...);
void flagProcess(format *format, char *cur, int *ind);
void widthProcess(format *format, char *cur, int *ind, va_list *args);
int getNumber(char *cur, int *ind);

void precisionProcess(format *format, char *cur, int *ind, va_list *args);

void lengthProcess(format *format, char *cur, int *ind);

void specifierProcess(format *format, char *cur, int *ind);

int formatProcess(format *format, char *cur, int *ind, va_list *args);
int isDigit(char c);

long int intA(long int);
long double doubleA(long double);
long double mpow(long double, int);

#endif
