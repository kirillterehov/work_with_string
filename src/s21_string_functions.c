#include "s21_strerror.h"
#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  s21_size_t i;
  unsigned char *ptr;
  i = 0;
  ptr = (unsigned char *)str;
  while (++i <= n)
    if (*(ptr++) == (unsigned char)c) return ((void *)--ptr);
  return S21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const char *string_1 = str1;
  const char *string_2 = str2;
  int diff = 0;
  for (s21_size_t i = 0; i < n; i++) {
    diff = *string_1 - *string_2;

    if (*string_1 != *string_2) {
      break;
    }
    string_1++;
    string_2++;
  }
  return diff;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *simbol;
  const unsigned char *simbol2;
  simbol = (unsigned char *)dest;
  simbol2 = (unsigned char *)src;
  while (n-- > 0) {
    *(simbol++) = *(simbol2++);
  }
  return (dest);
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *memory = (char *)str;
  s21_size_t index = 0;
  while (index < n) {
    *(memory + index) = c;
    index++;
  }

  return str;
}

char *s21_strchr(const char *str, int c) {
  char *temp_str = (char *)str;
  char b = (char)c;
  char *res = S21_NULL;
  for (; *temp_str != '\0' && *temp_str != b; temp_str++) {
  }
  if (*temp_str == '\0' && c != '\0') {
    res = S21_NULL;
  } else {
    res = temp_str;
  }

  return res;
}

char *s21_strcpy(char *dest, const char *src) {
  s21_size_t index = 0;
  while (src[index] != '\0') {
    dest[index] = src[index];
    index++;
  }
  dest[index] = '\0';
  return (dest);
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i = 0;
  int match = 0;
  for (i = 0; str1[i] != '\0' && match == 0; i++) {
    for (s21_size_t j = 0; str2[j] != '\0' && match == 0; j++) {
      if (str1[i] == str2[j]) {
        match = 1;
      }
    }
  }
  return i - match;
}

char *s21_strerror(int errnum) {
  static char res[128] = {'\0'};
  if (errnum < 0 || errnum > ERROR_LIST_SIZE) {
    s21_sprintf(res, ERROR_ERROR, errnum);
  } else {
    s21_strcpy(res, ((char *)error_list[errnum]));
  }

  return res;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  for (; str[len]; len++);
  return len;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t index_dest = s21_strlen(dest), index_src = 0;
  while (src[index_src] != '\0' && index_src < n) {
    dest[index_dest++] = src[index_src++];
  }
  dest[index_dest + 1] = '\0';
  return dest;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int diff = 0;
  if (str1 && str2 && n > 0) {
    for (s21_size_t i = 0; i < n; i++) {
      if (str1[i] == '\0' || (str1[i] != str2[i])) {
        diff = str1[i] - str2[i];
        break;
      }
    }
  }
  return diff;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;

  for (; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  for (; i < n; i++) {
    dest[i] = '\0';
  }

  return dest;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = S21_NULL;
  char *temp_str1 = (char *)str1;
  int flag = 0;
  s21_size_t len = s21_strlen(str2);
  while (*temp_str1 != '\0' && !flag) {
    for (s21_size_t i = 0; i < len && !flag; i++) {
      if (*temp_str1 == str2[i]) {
        flag = 1;
        res = temp_str1;
      }
    }
    temp_str1++;
  }
  return res;
}

char *s21_strrchr(const char *str, int c) {
  char *ch = S21_NULL;
  for (int i = s21_strlen(str); i >= 0 && ch == S21_NULL; i--) {
    if (str[i] == c) {
      ch = (char *)&str[i];
    }
  }
  return ch;
}

char *s21_strstr(const char *haystack, const char *needle) {
  int flag = 0;
  char *ret = S21_NULL;
  for (int i = 0; haystack[i] != '\0' && ret == S21_NULL; i++) {
    if (haystack[i] == needle[0]) flag = 0;
    for (int j = 0; needle[j] != '\0'; j++) {
      if (haystack[i + j] != needle[j]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) ret = (char *)haystack + i;
  }
  return ret;
}

char *s21_strtok(char *str, const char *delim) {
  static char *result = S21_NULL;

  if (str) {
    result = str;
    while (*result != '\0' && s21_strchr(delim, *result)) {
      *result++ = '\0';
    }
  }
  if (result) {
    if (*result != '\0') {
      str = result;
      while (*result && !s21_strchr(delim, *result)) {
        ++result;
      }
      while (*result && s21_strchr(delim, *result)) {
        *result++ = '\0';
      }
    } else {
      str = S21_NULL;
    }
  } else {
    str = S21_NULL;
  }

  return str;
}
