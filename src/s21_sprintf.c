#include "s21_string.h"

int s21_sprintf(char dest[], const char format_string[], ...) {
  va_list args;
  va_start(args, format_string);
  int cnt_before_n;
  int indx = 0;
  for (int i = 0; format_string[i] != '\0'; i++) {
    if (format_string[i] == '%') {
      frmt_spec spec = {0};
      fill_struct_by_parse_frmt_str(&format_string[i + 1], &spec, &args);
      if (spec.specifier == 'n') {
        cnt_before_n = s21_strlen(dest);
        *va_arg(args, int *) = cnt_before_n;
      }
      if (spec.specifier == '%') i++;
      process_specifier(dest, &indx, &spec, &args);
      while (format_string[i] != spec.specifier && format_string[i] != '\0')
        i++;
    } else {
      dest[indx++] = format_string[i];
    }
  }
  dest[indx] = '\0';
  va_end(args);
  return s21_strlen(dest);
}

void fill_struct_by_parse_frmt_str(const char *frmt_str, frmt_spec *spec,
                                   va_list *args) {
  while (*frmt_str && !s21_strchr("cdieEfgGosuxXpn%", *frmt_str)) {
    if (*frmt_str == '-') {
      frmt_str++;
      spec->minus_flag = 1;
      spec->zero_flag = 0;
    } else if (*frmt_str == '+') {
      frmt_str++;
      spec->plus_flag = 1;
      spec->space_flag = 0;
    } else if (*frmt_str == ' ') {
      frmt_str++;
      spec->space_flag = spec->plus_flag ? 0 : 1;
    } else if (*frmt_str == '#') {
      frmt_str++;
      spec->sharp_flag = 1;
    } else if (*frmt_str == '0') {
      spec->zero_flag = (!spec->minus_flag && !spec->precision_set) ? 1 : 0;
      frmt_str++;
    } else if (*frmt_str == '*') {
      spec->width = va_arg(*args, int);
      spec->width_set = 1;
      frmt_str++;
    } else if (!spec->width_set && *frmt_str >= '0' && *frmt_str <= '9') {
      while (*frmt_str >= '0' && *frmt_str <= '9') {
        spec->width = spec->width * 10 + (*frmt_str - '0');
        frmt_str++;
      }
      spec->width_set = 1;
    } else if (*frmt_str == '.') {
      frmt_str++;
      spec->precision_set = 1;
      spec->zero_flag = 0;
      if (*frmt_str == '*') {
        spec->precision = va_arg(*args, int);
        frmt_str++;
      } else {
        while (*frmt_str >= '0' && *frmt_str <= '9') {
          spec->precision = spec->precision * 10 + (*frmt_str - '0');
          frmt_str++;
        }
      }
    } else if (*frmt_str == 'h' || *frmt_str == 'l') {
      spec->length = (*frmt_str == 'h') ? 'h' : 'l';
      frmt_str++;
    } else {
      frmt_str++;
    }
  }
  if (*frmt_str) {
    spec->specifier = *frmt_str;
  }
}
void process_specifier(char dest[], int *indx, frmt_spec *spec, va_list *args) {
  if (spec->specifier == 'd' || spec->specifier == 'i') {
    long long int value = va_arg(*args, long long int);
    value = (spec->length == 'h') ? (short)value : value;
    spec_int_handler(dest, indx, value, spec);
  } else if (spec->specifier == 'u') {
    int value = va_arg(*args, int);
    value = (spec->length == 'h') ? (short)value : value;
    spec_int_handler(dest, indx, value, spec);
  } else if (spec->specifier == 'c') {
    char ch = (char)va_arg(*args, int);
    char value[2] = {ch, '\0'};
    add_string(dest, indx, value, spec);
  } else if (spec->specifier == 's') {
    char *value = va_arg(*args, char *);
    add_string(dest, indx, value, spec);
  } else if (spec->specifier == 'x' || spec->specifier == 'X') {
    int num = va_arg(*args, int);
    if (num) {
      char tmp[S_BUF_SIZE];
      int_to_hex(tmp, num, indx, spec);
      add_string(dest, indx, tmp, spec);
    } else {
      add_char(dest, indx, '0');
    }
  } else if (spec->specifier == '%') {
    add_char(dest, indx, '%');
  } else if (spec->specifier == 'p') {
    int value = va_arg(*args, int);
    unsigned long long num = get_ptr_adress(&value);
    char tmp[S_BUF_SIZE];
    int_to_hex(tmp, num, indx, spec);
    add_string(dest, indx, tmp, spec);
  }
}

void spec_int_handler(char dest[], int *indx, int val, frmt_spec *spec) {
  int len = get_num_len(val);
  int neg_flag = is_negative_num(&val, spec);

  if (neg_flag || spec->plus_flag || spec->space_flag) {
    put_sign(dest, indx, neg_flag, spec);
  }

  if (spec->width > len) {
    int padding = spec->width - len;
    char filler = (spec->zero_flag && !spec->minus_flag) ? '0' : ' ';
    for (int i = 0; i < padding; i++) {
      add_char(dest, indx, filler);
    }
  }

  int_to_str(dest, indx, val, spec);

  if (spec->minus_flag && spec->width > len) {
    int padding = spec->width - len;
    for (int i = 0; i < padding; i++) {
      add_char(dest, indx, ' ');
    }
  }
}

void add_char(char dest[], int *indx, char ch) { dest[(*indx)++] = ch; }

void add_string(char dest[], int *indx, const char *str, frmt_spec *spec) {
  int len = s21_strlen(str);
  if (spec->precision_set && spec->precision < len) {
    len = spec->precision;
  }

  if (!spec->minus_flag && spec->width > len) {
    for (int i = 0; i < spec->width - len; i++) {
      add_char(dest, indx, ' ');
    }
  }

  for (int i = 0; i < len; i++) {
    add_char(dest, indx, str[i]);
  }

  if (spec->minus_flag && spec->width > len) {
    for (int i = 0; i < spec->width - len; i++) {
      add_char(dest, indx, ' ');
    }
  }
}

int get_num_len(long long int num) {
  int len = 0;
  while (num != 0) {
    num /= 10;
    len++;
  }
  return len;
}

void int_to_hex(char dest[], unsigned long long num, int *indx,
                frmt_spec *spec) {
  char specifier = (spec->specifier == 'X') ? 'X' : 'x';
  const char *digits =
      (specifier == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
  char buffer[S_BUF_SIZE];
  int ind = 0;

  if (num == 0) {
    buffer[ind++] = '0';
  } else {
    while (num > 0) {
      buffer[ind++] = digits[num % 16];
      num /= 16;
    }
  }

  if (spec->sharp_flag && ind > 0) {
    buffer[ind++] = (specifier == 'X') ? 'X' : 'x';
    buffer[ind++] = '0';
  }

  for (int i = 0; i < ind / 2; i++) {
    char temp = buffer[i];
    buffer[i] = buffer[ind - i - 1];
    buffer[ind - i - 1] = temp;
  }

  add_string(dest, indx, buffer, spec);
}

void int_to_str(char dest[], int *indx, long long int num, frmt_spec *spec) {
  char buffer[32];
  int i = 0;

  do {
    buffer[i++] = (num % 10) + '0';
    num /= 10;
  } while (num > 0);
  if (spec->precision_set && spec->precision > i) {
    for (int j = 0; j < spec->precision - i; j++) {
      add_char(dest, indx, '0');
    }
  }

  while (i > 0) {
    add_char(dest, indx, buffer[--i]);
  }
}

char get_prefix_char(int is_neg, char filler, frmt_spec *spec) {
  char res = filler;
  if (!spec->minus_flag) {
    if (is_neg)
      res = '-';
    else if (spec->plus_flag)
      res = '+';
    else if (spec->space_flag)
      res = ' ';
  }
  return res;
}

void put_sign(char dest[], int *indx, int is_neg, frmt_spec *spec) {
  if (is_neg)
    add_char(dest, indx, '-');
  else if (spec->plus_flag)
    add_char(dest, indx, '+');
  else if (spec->space_flag)
    add_char(dest, indx, ' ');
}

int is_negative_num(int *val, frmt_spec *spec) {
  int is_neg = (*val < 0) ? 1 : 0;
  if (is_neg) {
    *val = -(*val);
    spec->plus_flag = 0;
    spec->space_flag = 0;
  }
  return is_neg;
}

unsigned long long get_ptr_adress(int *num) {
  int *ptr = num;
  unsigned long long adress = (unsigned long long)ptr;
  return adress;
}
