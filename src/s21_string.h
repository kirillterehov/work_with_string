#ifndef S21_STRING_H_
#define S21_STRING_H_

#define S21_NULL ((void *)0)
typedef long unsigned s21_size_t;

#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define S_BUF_SIZE 256
#define S21_NAN 0.0 / 0.0
#define S21_POS_INF 1.0 / 0.0
#define S21_NEG_INF -1.0 / 0.0

#if defined(__APPLE__) || defined(__MACH__)
#define STR_NULL "0x0\0"

#elif defined(__linux__)
#define STR_NULL "(nil)\0"

#endif

typedef struct format_specifier {
  int minus_flag;
  int plus_flag;
  int space_flag;
  int sharp_flag;
  int zero_flag;
  int width;
  int width_set;
  int precision;
  int precision_set;
  char length;
  char specifier;
} frmt_spec;

char *s21_strcpy(char *dest, const char *src);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

int s21_sprintf(char dest[], const char format_string[], ...);
void add_char(char dest[], int *indx, char ch);
void add_string(char dest[], int *indx, const char *str, frmt_spec *spec);
int get_num_len(long long int num);
void int_to_hex(char dest[], unsigned long long num, int *indx,
                frmt_spec *spec);
void int_to_str(char dest[], int *indx, long long int num, frmt_spec *spec);
char get_prefix_char(int is_neg, char filler, frmt_spec *spec);
void put_sign(char dest[], int *indx, int is_neg, frmt_spec *spec);
int is_negative_num(int *val, frmt_spec *spec);
unsigned long long get_ptr_adress(int *num);
void spec_int_handler(char dest[], int *indx, int val, frmt_spec *spec);
void process_specifier(char dest[], int *indx, frmt_spec *spec, va_list *args);
void fill_struct_by_parse_frmt_str(const char *frmt_str, frmt_spec *spec,
                                   va_list *args);

int s21_sscanf(const char *str, const char *format, ...);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

#endif
