#include "s21_sscanf.h"

int s21_sscanf(const char *inputString, const char *inputFormat, ...) {
  tokens token = {0};
  va_list arg;
  int argCount = 0;
  char *string = (char *)inputString;
  char *format = (char *)inputFormat;
  if (format != s21_NULL) {
    {
      va_start(arg, inputFormat);
      processingFormat(&token, format, string, arg, &argCount);
      va_end(arg);
    }
  }
  return argCount;
}

void processingFormat(tokens *token, char *format, char *string, va_list arg,
                      int *argCount) {
  int stringIndex = 0;
  int spaces = 0;

  for (s21_size_t formatIndex = 0; formatIndex < s21_strlen(format);
       formatIndex++) {
    if (format[formatIndex] == '%') {
      formatIndex++;
      if (format[formatIndex] == '%') {
        while (string[stringIndex] != '%') {
          stringIndex++;
          if (stringIndex == (int)s21_strlen(string)) {
            string[stringIndex] = '\0';
            break;
          }
        }
        if (string[stringIndex] == '%') stringIndex++;
        formatIndex++;
      }

      s21_memset(token, 0, sizeof(tokens));

      formatIndex = processingToken(token, formatIndex, format);
      if (format[formatIndex] == '%') formatIndex = formatIndex - 1;
      while (string[stringIndex] == ' ' && !(token->specifier == 'c')) {
        stringIndex++;
        spaces++;
      }
      if ((string[stringIndex] != '\0' ||
           (string[stringIndex] == '\0' && token->specifier == 'n')) ||
          token->specifier == 'c')
        processSpecifier(arg, string, &stringIndex, token, argCount, &spaces);
    }
  }
}

s21_size_t processingToken(tokens *token, s21_size_t formatIndex,
                           char *format) {
  char buffer[SIZE] = {0};
  s21_size_t bufferIndex = 0;

  if (format[formatIndex] == '*') {
    token->description = 1;
    formatIndex++;
  }

  while ((format[formatIndex] >= '0' && format[formatIndex] <= '9') ||
         (format[formatIndex] == '.')) {
    buffer[bufferIndex++] = format[formatIndex];
    formatIndex++;
  }

  if (bufferIndex > 0) processingBuffer(token, buffer, bufferIndex);

  if (s21_strchr("hlL", format[formatIndex])) {
    token->length = format[formatIndex];
    formatIndex++;
  }
  if (s21_strchr("cdieEfgGosuxXpn", format[formatIndex])) {
    token->specifier = format[formatIndex];
    formatIndex++;
  }

  return formatIndex;
}

void processingBuffer(tokens *token, char *String, s21_size_t size) {
  char buffer[SIZE] = {0};
  s21_size_t index = 0;
  s21_size_t bufIndex = 0;
  while (index < size) {
    buffer[bufIndex] = String[index];
    bufIndex++;
    index++;
  }

  buffer[bufIndex] = '\0';
  token->width = myAtoi(buffer);
}

int myAtoi(const char *str) {
  int sign = 1;
  int result = 0;
  if (*str == '-') {
    sign = -1;
    str++;
  } else if (*str == '+') {
    sign = 1;
    str++;
  }
  while (*str >= '0' && *str <= '9' && *str != '\0') {
    result = result * 10 + (*str - '0');
    str++;
  }
  return result * sign;
}

void processSpecifier(va_list arg, char *string, int *index, tokens *token,
                      int *argCount, int *spaces) {
  if (token->specifier == 'c')
    processingChar(arg, string, index, token, argCount);

  else if (token->specifier == 'd')
    processingDecimal(arg, string, index, token, argCount);

  else if (token->specifier == 'i' || token->specifier == 'x' ||
           token->specifier == 'X' || token->specifier == 'o')
    processingInteger(arg, string, index, token, argCount);

  else if (token->specifier == 'f' || token->specifier == 'e' ||
           token->specifier == 'E' || token->specifier == 'g' ||
           token->specifier == 'G')
    processingFloat(arg, string, index, token, argCount);

  else if (token->specifier == 's')
    processingString(arg, string, index, token, argCount);

  else if (token->specifier == 'u')
    processUnsigned(arg, string, index, token, argCount);

  else if (token->specifier == 'p')
    processPointer(arg, string, index, token, argCount);

  else if (token->specifier == 'n')
    processingCount(arg, spaces, index, token);
}

void processingCount(va_list arg, int *spaces, int *index, tokens *token) {
  if (token->description != 1) {
    int *count = va_arg(arg, int *);
    if (count) *count = *index - *spaces;
  }
}

void processingChar(va_list arg, char *string, int *index, tokens *token,
                    int *argCount) {
  if (string == s21_NULL || string[*index] == '\0')
    *argCount = -1;
  else if (token->description != 1) {
    if (token->length != 'l') {
      char *charPtr = va_arg(arg, char *);
      *charPtr = string[*index];
    } else if (token->length == 'l') {
      wchar_t *charPtr = va_arg(arg, wchar_t *);
      *charPtr = string[*index];
    }
    (*argCount)++;
  }
  if (token->width > 0) *index = *index + token->width - 1;

  *index = *index + 1;
}

void processingDecimal(va_list arg, char *string, int *index, tokens *token,
                       int *argCount) {
  char buffer[SIZE] = {0};
  int bufferIndex = 0;
  while (((string[*index] >= '0' && string[*index] <= '9') ||
          string[*index] == '-' || string[*index] == '+')) {
    if (bufferIndex == token->width && token->width > 0) break;
    buffer[bufferIndex++] = string[*index];
    *index = *index + 1;
  }
  if (token->description != 1) {
    processingLengthForInt(arg, buffer, token, 10);
    if (bufferIndex != 0) (*argCount)++;
  }
}

void processingInteger(va_list arg, char *string, int *index, tokens *token,
                       int *argCount) {
  int bufferIndex = 0;
  char buffer[SIZE] = {0};
  int numberSystem = 10;
  int x0 = 0;
  if (string[*index] == '+') *index = *index + 1;
  if (token->specifier == 'X' || token->specifier == 'x' ||
      (token->specifier == 'i' &&
       (string[*index] == '0' &&
        (string[*index + 1] == 'x' || string[*index + 1] == 'X')))) {
    if (string[*index] == '0' &&
        (string[*index + 1] == 'x' || string[*index + 1] == 'X')) {
      *index = *index + 2;
      x0 = 1;
    }
    numberSystem = 16;
    while ((string[*index] >= '0' && string[*index] <= '9') ||
           (string[*index] >= 'A' && string[*index] <= 'F') ||
           (string[*index] >= 'a' && string[*index] <= 'f')) {
      if (x0 && bufferIndex == token->width - 2 && token->width > 0) break;
      if (bufferIndex == token->width && token->width > 0) break;
      buffer[bufferIndex++] = string[(*index)++];
    }
  } else if (token->specifier == 'o' ||
             (token->specifier == 'i' && string[*index] == '0')) {
    if (string[*index] >= '0' && string[*index] <= '7') {
      numberSystem = 8;
      while (string[*index] >= '0' && string[*index] <= '7') {
        if (bufferIndex == token->width && token->width > 0) break;
        buffer[bufferIndex++] = string[(*index)++];
      }
    }
  } else {
    if (string[*index] == '+') *index = *index + 1;
    while ((string[*index] >= '0' && string[*index] <= '9') ||
           string[*index] == '-') {
      if (bufferIndex == token->width && token->width > 0) break;
      buffer[bufferIndex++] = string[(*index)++];
    }
  }
  buffer[bufferIndex] = '\0';
  if (token->description != 1) {
    processingLengthForInt(arg, buffer, token, numberSystem);
    (*argCount)++;
  }
}

void processingFloat(va_list arg, char *string, int *index, tokens *token,
                     int *argCount) {
  char buffer[SIZE] = {0};
  int bufferIndex = 0;
  if (token->specifier == 'f' && token->length == 'L') token->specifier = 'e';
  while ((string[*index] >= '0' && string[*index] <= '9') ||
         string[*index] == '.' ||
         (string[*index] == 'e' || string[*index] == 'E') ||
         string[*index] == '+' || string[*index] == '-') {
    if (bufferIndex == token->width && token->width > 0) break;
    if ((token->specifier == 'g' || token->specifier == 'G') &&
        string[*index] == 'e' && string[*index + 1] == '.')
      break;
    buffer[bufferIndex++] = string[(*index)++];
  }
  if (token->description != 1) {
    if (token->length == 'L') {
      long double *floatPtr = va_arg(arg, long double *);
      char *endptr;
      long double val = strtold(buffer, &endptr);
      *floatPtr = val;
    } else {
      float *floatPtr = va_arg(arg, float *);
      char *endptr;
      float val = strtod(buffer, &endptr);
      *floatPtr = val;
    }
    if (bufferIndex != 0) (*argCount)++;
  }
}

void processUnsigned(va_list arg, char *string, int *index, tokens *token,
                     int *argCount) {
  char buffer[SIZE] = {0};
  int bufferIndex = 0;
  if (string[*index] == '+') *index = *index + 1;
  while ((string[*index] >= '0' && string[*index] <= '9') ||
         string[*index] == '-') {
    if (bufferIndex == token->width && token->width > 0) break;
    buffer[bufferIndex++] = string[*index];
    *index = *index + 1;
  }
  if (token->description != 1) {
    processingLengthForUnsigned(arg, buffer, token);
    if (bufferIndex != 0) (*argCount)++;
  }
}

void processPointer(va_list arg, char *string, int *index, tokens *token,
                    int *argCount) {
  if (string[*index] == '+') *index = *index + 1;
  char buffer[SIZE] = {0};
  int bufferIndex = 0;
  if (string[*index] == '0' && bufferIndex == 0) {
    *index = *index + 1;
    if (string[*index] == 'x' || string[*index] == 'X') *index = *index + 1;
  }
  while ((string[*index] >= '0' && string[*index] <= '9') ||
         (string[*index] >= 'A' && string[*index] <= 'F') ||
         (string[*index] >= 'a' && string[*index] <= 'f')) {
    if (token->width > 0 && bufferIndex == token->width - 2) break;
    buffer[bufferIndex++] = string[*index];
    *index = *index + 1;
  }
  long long num = strtol(buffer, s21_NULL, 16);
  if (token->description != 1) {
    void **ptr = va_arg(arg, void **);
    *ptr = (void *)num;
    if (bufferIndex != 0) (*argCount)++;
  }
}

void processingString(va_list arg, char *string, int *index, tokens *token,
                      int *argCount) {
  char buffer[SIZE] = {0};
  int bufferIndex = 0;
  while (string[*index] != ' ') {
    if (bufferIndex == (int)s21_strlen(string)) {
      buffer[bufferIndex++] = '\0';
      break;
    }
    if (bufferIndex == token->width && token->width > 0) break;
    buffer[bufferIndex++] = string[*index];
    *index = *index + 1;
  }
  buffer[bufferIndex++] = '\0';
  s21_size_t len = s21_strlen(buffer);

  if (!token->description) {
    if (token->length != 'l') {
      char *strPtr = va_arg(arg, char *);
      for (s21_size_t i = 0; i < len; i++) {
        strPtr[i] = buffer[i];
        if (i == len - 1) strPtr[i + 1] = '\0';
      }
    } else if (token->length == 'l') {
      wchar_t *strPtr = va_arg(arg, wchar_t *);
      mbstowcs(strPtr, buffer, len);
    }
    if (bufferIndex != 0) (*argCount)++;
  }
}

void processingLengthForUnsigned(va_list arg, char buffer[], tokens *token) {
  char *endptr;
  unsigned long val = strtoul(buffer, &endptr, 10);
  if (!token->length) {
    unsigned int *unsignedPtr = va_arg(arg, unsigned int *);
    *unsignedPtr = (unsigned int)val;
  } else if (token->length == 'h') {
    unsigned short *unsignedPtr = va_arg(arg, unsigned short *);
    *unsignedPtr = (unsigned short)val;
  } else if (token->length == 'l') {
    unsigned long *unsignedPtr = va_arg(arg, unsigned long *);
    *unsignedPtr = (unsigned long)val;
  }
}

void processingLengthForInt(va_list arg, char buffer[], tokens *token,
                            int base) {
  if (!token->length) {
    int *num = va_arg(arg, int *);
    *num = strtol(buffer, s21_NULL, base);
  } else if (token->length == 'h' && base == 16) {
    unsigned short *num = va_arg(arg, unsigned short *);
    *num = (unsigned short)strtol(buffer, s21_NULL, base);
  } else if (token->length == 'h' && base != 16) {
    short *num = va_arg(arg, short *);
    *num = (short)strtol(buffer, s21_NULL, base);
  } else if (token->length == 'l') {
    long *num = va_arg(arg, long *);
    *num = strtol(buffer, s21_NULL, base);
  }
}