#ifndef S21_SSCANF_H
#define S21_SSCANF_H

#include <stdarg.h>

#include "s21_string.h"

#define SIZE 4096
typedef struct token {
  int width;
  int precision;
  int length;
  int specifier;
  int description;
  int spaces;
} tokens;

extern tokens token;

void processingFormat(tokens *token, char *format, char *string, va_list arg,
                      int *argCount);

s21_size_t processingToken(tokens *token, s21_size_t position, char *format);
void processingBuffer(tokens *token, char *String, s21_size_t size);
int myAtoi(const char *str);

void processSpecifier(va_list arg, char *string, int *index, tokens *token,
                      int *argCount, int *spaces);
void processingDecimal(va_list arg, char *string, int *index, tokens *token,
                       int *argCount);
void processingInteger(va_list arg, char *string, int *index, tokens *token,
                       int *argCount);
void processingFloat(va_list arg, char *string, int *index, tokens *token,
                     int *argCount);
void processingString(va_list arg, char *string, int *index, tokens *token,
                      int *argCount);
void processUnsigned(va_list arg, char *string, int *index, tokens *token,
                     int *argCount);
void processPointer(va_list arg, char *string, int *index, tokens *token,
                    int *argCount);
void processingChar(va_list arg, char *string, int *index, tokens *token,
                    int *argCount);
void processingCount(va_list arg, int *spaces, int *index, tokens *token);

void processingLengthForInt(va_list arg, char buffer[], tokens *token,
                            int base);
void processingLengthForUnsigned(va_list arg, char buffer[], tokens *token);

#endif  // S21_SSCANF_H
