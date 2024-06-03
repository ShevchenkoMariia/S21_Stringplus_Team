#include "s21_string.h"

#include "errors.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *ptr = (const unsigned char *)str;
  unsigned char ch = (unsigned char)c;
  s21_size_t i = 0;
  void *result = s21_NULL;
  for (; i < n; i++) {
    if (ch == ptr[i]) {
      result = (void *)(ptr + i);
      break;
    }
  }
  return result;
}

char *s21_strchr(const char *str, int c) {
  char *result = s21_NULL;
  int i = 0;
  char ch = (char)c;
  for (; str[i] != '\0'; i++) {
    if (ch == str[i]) {
      result = (char *)(str + i);
      break;
    }
  }
  return result;
}

char *s21_strrchr(const char *str, int c) {
  char *result = s21_NULL;
  int i = 0;
  char ch = (char)c;
  for (; str[i] != '\0'; i++) {
    if (ch == str[i]) {
      result = (char *)(str + i);
    }
  }
  return result;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = s21_NULL;
  for (const char *a = str1; *a; a++) {
    for (const char *b = str2; *b; b++) {
      if (*a == *b) {
        res = (char *)a;
        break;
      }
    }
    if (res) {
      break;
    }
  }
  return res;
}

char *s21_strstr(const char *haystack, const char *needle) {
  if (!haystack || !needle) {
    return s21_NULL;
  }
  char *res = s21_NULL;
  if (s21_strlen(haystack) >= s21_strlen(needle)) {
    for (s21_size_t i = 0; i <= s21_strlen(haystack) - s21_strlen(needle);
         i++) {
      int found = 1;
      for (s21_size_t j = i, k = 0; needle[k]; k++, j++) {
        if (haystack[j] != needle[k]) {
          found = 0;
          break;
        }
      }
      if (found) {
        res = (char *)haystack + i;
        break;
      }
    }
  }
  return res;
}

char *s21_strtok(char *str, const char *delim) {
  static char *lastFound;
  char *temp;
  int funcWork = 1;

  if ((temp = str) == s21_NULL && (temp = lastFound) == s21_NULL) funcWork = 0;

  for (int i = 0; funcWork && *temp && delim[i]; i++) {
    if (*temp == delim[i]) {
      temp++;
      i = -1;
    }
  }

  if (funcWork && *temp == '\0') {
    temp = s21_NULL;
    lastFound = s21_NULL;
    funcWork = 0;
  }
  str = temp;

  while (funcWork && *temp) {
    for (s21_size_t i = 0; delim[i]; i++) {
      if (*temp == delim[i]) {
        funcWork = 0;
        *temp = '\0';
        temp++;
        if (*temp == '\0') temp = s21_NULL;
        lastFound = temp;
        break;
      }
    }

    if (funcWork) {
      temp++;

      if (*temp == '\0') {
        lastFound = s21_NULL;
      }
    }
  }
  return str;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *ptr = (unsigned char *)str;
  unsigned char symbol = (unsigned char)c;
  for (s21_size_t i = 0; i < n; i++) {
    ptr[i] = symbol;
  }
  return str;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t i = 0;
  while (str[i] != '\0') i++;
  return i;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  int countj = 0;
  s21_size_t len1 = s21_strlen(str1);
  s21_size_t len2 = s21_strlen(str2);

  if (s21_strlen(str2) == 0)
    count = s21_strlen(str1);
  else {
    for (s21_size_t i = 0; i < len1; i++) {
      for (s21_size_t j = 0; j < len2; j++) {
        if (str1[i] == str2[j]) {
          if (i == 0 && str1[i] == str2[j]) countj = 1;
          count = i;
          break;
        }
        if (i == len1 - 1 && j == len2 - 1 && count == 0) count = i + 1;
      }
      if (count > 0 || str1[0] == str2[0] || countj > 0) break;
    }
  }
  return count;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *cdest = (char *)dest;
  const char *csrc = (const char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    cdest[i] = csrc[i];
  }
  return dest;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    dest[i] = src[i];
  }
  return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t len = 0;
  while (dest[len++] != '\0')
    ;
  len--;
  for (s21_size_t i = 0; i < n; i++) dest[len + i] = src[i];
  return dest;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *p1 = str1;
  const unsigned char *p2 = str2;
  for (s21_size_t i = 0; i < n; i++) {
    if (*p1 != *p2) return *p1 - *p2;
    p1++;
    p2++;
  }
  return 0;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    if (str1[i] != str2[i]) return str1[i] - str2[i];
    if (str1[i] == '\0') break;
  }
  return 0;
}

char *s21_strerror(int errnum) {
  static char result[512] = {'\0'};
  if (errnum < 0 || errnum > ERRORS_DSCRPTNS) {
    s21_sprintf(result, "Unknown error %d", errnum);
  } else {
    s21_strcpy(result, ((char *)errors_dscrptns[errnum]));
  }
  return result;
}

char *s21_strcpy(char *dest, const char *src) {
  for (int i = 0; src[i]; i++) {
    dest[i] = src[i];
  }
  dest[s21_strlen(src)] = '\0';
  return dest;
}
