#include "s21_sprintf.h"

int s21_sprintf(char *dest, char *src, ...) {
  char *cur = src;
  va_list args;
  va_start(args, src);
  int error = 0;
  int ind = 0;
  int i = 0;
  while (cur[ind] != 0) {
    if (cur[ind] == '%') {
      format format = {0};
      format.prec = -1;
      format.len = 'n';
      ind++;
      if (cur[ind] == '%') {
        dest[i++] = cur[ind++];
      } else {
        error = formatProcess(&format, cur, &ind, &args);
        if (error) break;
        char buffer[1024] = {0};
        formating(buffer, &args, &format);
        s21_strncat(dest, buffer, s21_strlen(buffer));
        i += s21_strlen(buffer);
        buffer[1024] = '\0';
      }
    } else {
      dest[i++] = cur[ind++];
    }
  }

  if (error) {
    printf("Invalid string format\n");
  }

  va_end(args);
  return i;
}

void flagProcess(format *format, char *cur, int *ind) {
  while (s21_strchr(FLAGS, cur[*ind]) != s21_NULL) {
    switch (cur[*ind]) {
      case '+':
        format->flag.plus = 1;
        break;
      case '-':
        format->flag.minus = 1;
        break;
      case ' ':
        format->flag.space = 1;
        break;
      case '0':
        format->flag.zero = 1;
        break;
      case '#':
        format->flag.jail = 1;
        break;
    }
    *ind = *ind + 1;
  }
}

void widthProcess(format *format, char *cur, int *ind, va_list *args) {
  if (s21_strchr(NUMS, cur[*ind]) != s21_NULL) {
    if (cur[*ind] == STAR) {
      format->wid = va_arg(*args, int);
      *ind = *ind + 1;
    } else {
      format->wid = getNumber(cur, ind);
    }
  }
}

int getNumber(char *cur, int *ind) {
  const char *end = cur;
  int number = 0;
  while (end[*ind] != '\0') {
    if (isDigit(end[*ind])) {
      number = number * 10 + (end[*ind] - '0');
      *ind = *ind + 1;
    } else {
      break;
    }
  }
  return number;
}

void precisionProcess(format *format, char *cur, int *ind, va_list *args) {
  if (cur[*ind] == DOT) {
    *ind = *ind + 1;
    if (s21_strchr(NUMS, cur[*ind]) != s21_NULL) {
      if (cur[*ind] == STAR) {
        format->prec = va_arg(*args, int);
        *ind = *ind + 1;
      } else
        format->prec = getNumber(cur, ind);
    } else {
      format->prec = 0;
    }
  }
}

void lengthProcess(format *format, char *cur, int *ind) {
  if (s21_strchr(LENGTH, cur[*ind]) != s21_NULL) {
    format->len = cur[*ind];
    *ind = *ind + 1;
  }
}

void specifierProcess(format *format, char *cur, int *ind) {
  if (s21_strchr(SPECS, cur[*ind]) != s21_NULL) {
    format->spec = cur[*ind];
    *ind = *ind + 1;
  }
}

int formatProcess(format *format, char *cur, int *ind, va_list *args) {
  int error = 0;
  if (s21_strchr(VALID, cur[*ind]) != s21_NULL && !error) {
    flagProcess(format, cur, ind);
  } else {
    error = 1;
  }
  if (s21_strchr(VALID, cur[*ind]) != s21_NULL && !error) {
    widthProcess(format, cur, ind, args);
  } else {
    error = 1;
  }
  if (s21_strchr(VALID, cur[*ind]) != s21_NULL && !error) {
    precisionProcess(format, cur, ind, args);
  } else {
    error = 1;
  }
  if (s21_strchr(VALID, cur[*ind]) != s21_NULL && !error) {
    lengthProcess(format, cur, ind);
  } else {
    error = 1;
  }
  if (s21_strchr(VALID, cur[*ind]) != s21_NULL && !error) {
    specifierProcess(format, cur, ind);
  } else {
    error = 1;
  }
  if (!(format->spec)) {
    error = 1;
  }

  return error;
}

int isDigit(char c) { return c >= '0' && c <= '9'; }

void formating(char *buf, va_list *args, format *optns) {
  char flag = getFlag(optns);
  int sharp = optns->flag.jail;
  char spec = optns->spec, len = optns->len;
  char spaces = ' ';
  long int valI;
  long double valF;
  int prec = optns->prec, base = getBase(spec, optns->flag.jail);
  char strValue[512] = {'\0'};
  int type = getType(spec);
  spaces = getSpaces(optns->flag.zero);

  if (type == INT) {
    if (len == 'l')
      valI = va_arg(*args, long int);
    else if (len == 'h')
      valI = (long int)va_arg(*args, int);
    else
      valI = (long int)va_arg(*args, int);
    newInt(strValue, &valI, 'l', flag, prec, 'n');
  } else if (type == FLOAT) {
    if (spec == 'e' || spec == 'E')
      newE(strValue, args, len, spec, prec, flag, sharp);
    else if (spec == 'g' || spec == 'G')
      newG(strValue, args, len, spec, prec, flag, sharp);
    else {
      if (len == 'L')
        valF = (long double)va_arg(*args, long double);
      else if (len == 'n')
        valF = (long double)(va_arg(*args, double));
      newFloat(strValue, &valF, 'L', prec, flag, sharp);
    }
  } else if (type == UNSIGNED) {
    newIntU(strValue, args, len, base, prec, spec, flag);
  } else if (type == STR) {
    if (spec != 'l')
      strToStr(strValue, args);
    else
      lstrToStr(strValue, args);
  } else if (type == CHAR) {
    if (spec != 'l')
      charToStr(strValue, args);
    else
      charToStr(strValue, args);
  } else if (type == PTR) {
    pToStr(strValue, args, flag);
  }
  addBuffers(buf, strValue, optns->flag.minus, optns->wid, spaces);
}

char getFlag(format *optns) {
  if (optns->flag.plus)
    return '+';
  else if (optns->flag.space)
    return ' ';
  else
    return '$';
}

int getBase(char spec, int sharp) {
  int base = 10;
  if (spec == 'o')
    base = 8;
  else if (spec == 'x' || spec == 'X')
    base = 16;
  if (base != 10 && sharp) base *= -1;
  return base;
}

void addBuffers(char *buf, char *value, int flagM, int len, char space) {
  char sp[128] = {'\0'};

  if (flagM) {
    setWidth(sp, value, len, ' ');
    s21_strncat(buf, value, 256);
    s21_strncat(buf, sp, 128);
  } else {
    setWidth(sp, value, len, space);
    s21_strncat(buf, sp, 128);
    s21_strncat(buf, value, 256);
  }
}

char getSpaces(int flagO) {
  char res = ' ';
  if (flagO) return '0';

  return res;
}

void cut(char *buf) {
  long int i = s21_strlen(buf) - 1;
  for (; i > 2; i--) {
    if (buf[i] == '0')
      buf[i] = '\0';
    else if (buf[i - 1] != '0')
      break;
  }
}

int gTrim(long double val, int prec) {
  int res = 0, flag = 0;
  int count = 0;
  if (doubleA(val) >= 1.0) {
    for (; val >= 1.0; val /= 10.0) {
      res--;
    }
  }
  for (val *= 10.0;; val *= 10.0) {
    int digit = ((long int)val % 10);
    if (digit != 0 && !flag) flag++;
    if (flag) count++;
    res++;
    if (count >= prec) break;
  }

  return res;
}

void newG(char *buf, va_list *args, char len, char reg, int prec, char pref,
          int sharp) {
  long double val;
  int localPrec;
  char fBuf[256] = {'\0'}, eBuf[256] = {'\0'};
  char r = reg == 'G' ? 'E' : 'e';

  val = newE(eBuf, args, len, r, 5, 'g', sharp);
  if (prec < 0) prec = 6;
  localPrec = gTrim(val, prec);
  newFloat(fBuf, &val, 'L', localPrec, 10, sharp);
  if (!sharp) cut(fBuf);

  buf += setPrefixSign(buf, val, pref);

  if (s21_strlen(fBuf) <= s21_strlen(eBuf))
    s21_strncat(buf, fBuf, 512);
  else
    s21_strncat(buf, eBuf, 512);
}

long double newE(char *buf, va_list *args, char type, char reg, int prec,
                 char pref, int sharp) {
  long double val, res;
  char sign;
  int eCount = 0;
  char *b = buf;
  switch (type) {
    case 'L':
      val = (long double)va_arg(*args, long double);
      break;
    default:
      val = (long double)va_arg(*args, double);
      break;
  }
  res = val;
  b += setPrefixSign(buf, val, pref);
  if (val < 0.0) val *= -1.0;

  sign = val > 1.0 ? '+' : '-';
  while (val < 1 || val >= 10) {
    val *= sign != '-' ? 0.1 : 10.0;
    eCount++;
  }
  b += newFloat(b, &val, 'L', prec, '$', sharp);
  if (pref == 'g') {
    if (!sharp) {
      cut(buf);
      b = buf + (int)s21_strlen(buf) - 1;
    }
  }
  b++;
  *(b++) = reg;
  *(b++) = sign;
  *(b++) = ((eCount / 10) % 10) + '0';
  *(b++) = (eCount % 10) + '0';

  return res;
}

int newFloat(char *buf, void *value, char type, int prec, char pref,
             int sharp) {
  long double val;
  long int lVal = 0;
  int res = 0;
  char *b = buf;
  if (prec < 0) prec = 6;

  switch (type) {
    case 'L':
      val = (long double)*(long double *)(value);
      break;
    default:
      val = (long double)*(double *)(value);
      break;
  }
  b += setPrefixSign(buf, val, pref);
  if (val < 0.0) val *= -1.0;

  trimFloat(&val, prec);
  lVal = (long int)val;
  res += newInt(b, &lVal, 'f', '!', 1, 'f');
  b += res;

  for (int i = 0; i < prec; i++) {
    val *= 10.0;
    *b = ((long int)val) % 10 + '0';
    b++;
    res++;
  }
  if (prec < 1 && !sharp) b--;

  return (res - 1);
}

void trimFloat(long double *value, int c) {
  long double x = mpow(10.0, c);
  *value *= x * 10.0;
  if (intA((long int)*value) % 10 >= 5) *value += *value > 0.0 ? 10.0 : -10.0;
  *value /= 10.0;
  *value = (long double)(long int)*value;
  *value /= x;
}

void newIntU(char *buf, va_list *args, char type, int base, int wid, char fSign,
             char pref) {
  long unsigned int val;
  char reverseNum[1024] = {'\0'};
  int i = 0;
  switch (type) {
    case 'h':
      val = (long unsigned int)va_arg(*args, unsigned int);
      break;
    case 'l':
      val = (long unsigned int)va_arg(*args, long unsigned int);
      break;
    default:
      val = (long unsigned int)va_arg(*args, unsigned int);
      break;
  }
  buf += setPrefixSign(buf, 20.0, pref);
  if (base < 0) {
    base *= -1;
    buf += sharpFlagProc(buf, fSign);
  }
  if (val == 0) {
    reverseNum[0] = 0 + '0';
    i++;
  } else {
    for (; val > 0; val /= base) {
      if (val % base > 9) {
        if (fSign == 'X')
          reverseNum[i] = (val % base - 10) + 'A';
        else
          reverseNum[i] = (val % base - 10) + 'a';
      } else
        reverseNum[i] = val % base + '0';
      i++;
    }
  }

  i--;
  while (i < wid - 1) {
    *(buf++) = '0';
    wid--;
  }
  for (; i >= 0; i--) {
    *buf = reverseNum[i];
    buf++;
  }
  *buf = '\0';
}

int newInt(char *buf, void *value, char type, char sign, int wid, char fSign) {
  char reverseNum[256] = {'\0'};
  int res = 0, i = 0;
  long int val;
  switch (type) {
    case 'n':
      val = (long int)*(int *)value;
      break;
    case 'h':
      val = (long int)*(short int *)value;
      break;
    default:
      val = (long int)*(long int *)value;
      break;
  }
  buf += setPrefixSign(buf, (long double)val, sign);
  if (val < 0) val *= -1;

  if (val == 0) {
    reverseNum[0] = 0 + '0';
    i++;
  } else {
    for (; val > 0; val /= 10) {
      reverseNum[i] = val % 10 + '0';
      i++;
    }
  }
  res = i;
  i--;
  while (i < wid - 1) {
    *(buf++) = '0';
    wid--;
  }
  for (; i >= 0; i--) {
    *buf = reverseNum[i];
    buf++;
  }
  *buf = fSign == 'f' ? '.' : '\0';
  return (res + 1);
}

int setWidth(char *buf, char *strValue, int width, char sign) {
  int res = 0, len = (int)s21_strlen(strValue);
  if (len < width) {
    for (int i = 0; i < width - len; i++) {
      *(buf++) = sign;
      res++;
    }
  }

  return res;
}

int setPrefixSign(char *buf, long double value, char flag) {
  int res = 1;
  if (value < 0)
    *buf = '-';
  else if (value > 0) {
    if (flag == ' ' || flag == '+')
      *buf = flag;
    else
      res -= 1;
  } else
    res--;
  return res;
}

int sharpFlagProc(char *buf, char spec) {
  int res = 0;
  switch (spec) {
    case 'o':
      *buf = '0';
      res++;
      break;
    case 'x':
    case 'X':
      *(buf++) = '0';
      *(buf) = spec;
      res += 2;
      break;
  }

  return res;
}

void lstrToStr(char *buf, va_list *args) {
  wchar_t *str = va_arg(*args, wchar_t *);
  for (; *str != '\0'; str++) {
    *buf = (char)(*str);
    buf++;
  }
}

void lcharToStr(char *buf, va_list *args) {
  char c = (char)va_arg(*args, wchar_t);
  *buf = c;
}

void strToStr(char *buf, va_list *args) {
  char *str = va_arg(*args, char *);
  for (; *str != '\0'; str++) {
    *buf = *str;
    buf++;
  }
}

void charToStr(char *buf, va_list *args) {
  char c = (char)va_arg(*args, int);
  *buf = c;
}

void pToStr(char *buf, va_list *args, char pref) {
  char reverseBuf[128] = {'\0'};
  int i = 0;
  void *p = va_arg(*args, void *);
  uintptr_t val = (uintptr_t)p;
  buf += setPrefixSign(buf, 20.0, pref);
  *(buf++) = '0';
  *(buf++) = 'x';
  for (; val > 0; val /= 16) {
    if ((val % 16) > 9)
      reverseBuf[i] = (val % 16 - 10) + 'a';
    else
      reverseBuf[i] = val % 16 + '0';
    i++;
  }
  i--;
  for (; i >= 0; i--) {
    *(buf++) = reverseBuf[i];
  }
}

enum Types getType(char spec) {
  switch (spec) {
    case 'c':
      return CHAR;

    case 'd':
      return INT;

    case 'o':
    case 'u':
    case 'x':
    case 'X':
    case 'i':
      return UNSIGNED;

    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G':
      return FLOAT;

    case 's':
      return STR;

    case 'p':
      return PTR;

    default:
      return -1;
  }
}

long int intA(long int val){
  if (val < 0) val *= -1;
  return val;
}

long double doubleA(long double val){
  if (val < 0.0) val *= -1.0;
  return val;
}

long double mpow(long double base, int exponent) {
    double result = 1.0;
    if (exponent == 0) {
        return 1.0; 
    } else if (exponent > 0) {
        for (int i = 0; i < exponent; ++i) {
            result *= base;
        }
        return result;
    } else {
        for (int i = 0; i < -exponent; ++i) {
            result *= base;
        }
        return 1.0 / result;
    }
}

