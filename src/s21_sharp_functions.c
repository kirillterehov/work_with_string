#include "s21_string.h"

void *s21_to_upper(const char *str) {
  if (str == S21_NULL) return S21_NULL;
  s21_size_t length = 0;
  while (str[length] != '\0') length++;
  char *result = (char *)malloc((length + 1) * sizeof(char));
  if (result == S21_NULL) return S21_NULL;
  for (s21_size_t i = 0; i < length; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      result[i] = str[i] - 32;
    } else {
      result[i] = str[i];
    }
  }
  result[length] = '\0';
  return result;
}

void *s21_to_lower(const char *str) {
  if (str == S21_NULL) return S21_NULL;
  s21_size_t length = 0;
  while (str[length] != '\0') length++;
  char *result = (char *)malloc((length + 1) * sizeof(char));
  if (result == S21_NULL) return S21_NULL;
  for (s21_size_t i = 0; i < length; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      result[i] = str[i] + 32;
    } else {
      result[i] = str[i];
    }
  }
  result[length] = '\0';
  return result;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == S21_NULL || str == S21_NULL) return S21_NULL;
  s21_size_t src_len = 0, str_len = 0;
  while (src[src_len] != '\0') src_len++;
  while (str[str_len] != '\0') str_len++;
  if (start_index > src_len) return S21_NULL;
  char *result = (char *)malloc((src_len + str_len + 1) * sizeof(char));
  if (result == S21_NULL) return S21_NULL;
  s21_size_t i = 0, j = 0;
  for (; i < start_index; i++) {
    result[i] = src[i];
  }
  for (; j < str_len; j++) {
    result[i + j] = str[j];
  }
  for (; i < src_len; i++) {
    result[i + j] = src[i];
  }
  result[src_len + str_len] = '\0';
  return result;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == S21_NULL) return S21_NULL;
  s21_size_t src_len = 0;
  while (src[src_len] != '\0') src_len++;
  s21_size_t trim_start = 0, trim_end = src_len - 1;
  while (trim_start < src_len &&
         s21_strchr(trim_chars, src[trim_start]) != S21_NULL) {
    trim_start++;
  }
  while (trim_end > trim_start &&
         s21_strchr(trim_chars, src[trim_end]) != S21_NULL) {
    trim_end--;
  }
  s21_size_t result_len = trim_end - trim_start + 1;
  char *result = (char *)malloc((result_len + 1) * sizeof(char));
  if (result == S21_NULL) return S21_NULL;
  for (s21_size_t i = 0; i < result_len; i++) {
    result[i] = src[trim_start + i];
  }
  result[result_len] = '\0';
  return result;
}