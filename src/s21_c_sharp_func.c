#include "s21_string.h"

/* Возвращает копию строки (str), преобразованной в верхний регистр */
/* В случае какой-либо ошибки следует вернуть значение NULL */

void *s21_to_upper(const char *str) {
  char *cpStr = s21_NULL;
  if (!str || *str == '\0') return s21_NULL;
  s21_size_t len = s21_strlen(str);
  cpStr = (char *)calloc(len + 1, sizeof(char));
  if (!cpStr) return s21_NULL;
  for (s21_size_t i = 0; str[i] != '\0'; ++i) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      cpStr[i] = str[i] - 32;  // ('a' - 'A');
    } else {
      cpStr[i] = str[i];
    }
  }
  return cpStr;
}

/* Возвращает копию строки (str), преобразованной в нижний регистр */
/* В случае какой-либо ошибки следует вернуть значение NULL */

void *s21_to_lower(const char *str) {
  char *cpStr = s21_NULL;
  if (!str || *str == '\0') return s21_NULL;
  s21_size_t len = s21_strlen(str);
  cpStr = (char *)calloc(len + 1, sizeof(char));
  if (!cpStr) return s21_NULL;
  for (s21_size_t i = 0; str[i] != '\0'; ++i) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      cpStr[i] = str[i] + 32;
    } else {
      cpStr[i] = str[i];
    }
  }
  return cpStr;
}

/* Возвращает новую строку, в которой указанная строка (str) */
/* вставлена в указанную позицию (startIndex) в данной строке (src). */
/* В случае какой-либо ошибки следует вернуть значение NULL */
void *s21_insert(const char *src, const char *str, size_t startIndex) {
  char *result = s21_NULL;
  if (src != s21_NULL && str != s21_NULL) {
    s21_size_t srcLen = s21_strlen(src);
    s21_size_t strLen = s21_strlen(str);
    s21_size_t new = srcLen + strLen;
    result = (char *)calloc(new + 1, sizeof(char));
    if (result) {
      for (s21_size_t i = 0, j = 0, k = 0; i < new; i++) {
        if (i < startIndex || !str[k]) {
          result[i] = src[j++];
        } else {
          result[i] = str[k++];
        }
      }
      result[new] = '\0';
    }
  } else if (str == s21_NULL && src != s21_NULL) {
    result = (char *)calloc(s21_strlen(src) + 1, sizeof(char));
    if (result) {
      for (s21_size_t i = 0; src[i] != '\0'; i++) {
        result[i] = src[i];
      }
      result[s21_strlen(src)] = '\0';
    }
  }
  return result;
}

/* Возвращает новую строку, в которой удаляются все начальные и конечные
 * вхождения */
/* набора заданных символов (trimChars) из данной строки (src) */
/* В случае какой-либо ошибки следует вернуть значение NULL */

void *s21_trim(const char *src, const char *trimChars) {
  char *res = s21_NULL;
  if (src && trimChars) {
    char *start = (char *)src;
    char *end = (char *)src + s21_strlen(src);
    for (; *start && s21_strchr(trimChars, *start); start++)
      ;
    for (; end != start && s21_strchr(trimChars, *(end - 1)); end--)
      ;
    res = (char *)malloc((end - start + 1) * sizeof(char));
    if (res) {
      s21_strncpy(res, start, end - start);
      *(res + (end - start)) = '\0';
    }
  }
  return res;
}