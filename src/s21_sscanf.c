#include "s21_string.h"

double s21_atof(const char *str) {
  double result = 0.0;
  double fraction = 1.0;
  int sign = 1;
  int exponent = 0;
  int exp_sign = 1;
  while (isspace(*str)) str++;
  if (*str == '-') {
    sign = -1;
    str++;
  } else if (*str == '+') {
    str++;
  }
  while (isdigit(*str)) {
    result = result * 10.0 + (*str - '0');
    str++;
  }
  if (*str == '.') {
    str++;
    while (isdigit(*str)) {
      result = result * 10.0 + (*str - '0');
      fraction *= 10.0;
      str++;
    }
  }
  if (*str == 'e' || *str == 'E') {
    str++;
    if (*str == '-') {
      exp_sign = -1;
      str++;
    } else if (*str == '+') {
      str++;
    }
    while (isdigit(*str)) {
      exponent = exponent * 10 + (*str - '0');
      str++;
    }
  }
  result = sign * result / fraction;
  if (exponent) {
    result *= pow(10.0, exp_sign * exponent);
  }

  return result;
}

int s21_sscanf_specifier_float(const char *str, va_list *args) {
  double *num = va_arg(*args, double *);
  *num = s21_atof(str);
  return 1;
}

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);

  int read = 0;
  while (*format) {
    if (*format == '%') {
      format++;
      char specifier = *format;
      if (specifier == 'e' || specifier == 'E' || specifier == 'f' ||
          specifier == 'g' || specifier == 'G') {
        read += s21_sscanf_specifier_float(str, &args);
      } else {
        // pass
      }
      format++;
    } else {
      format++;
    }
  }

  va_end(args);
  return read;
}
