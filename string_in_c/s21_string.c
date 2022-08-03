#include <stdio.h>
#include <stdlib.h>
#include "s21_string.h"

size_t s21_strlen(const char * str) {
    size_t length = 0;
    for (; *(str + length); length++) {}
    return length;
}

int s21_strcmp(const char * str1, const char * str2) {
    int ans = 0;
    for (; *str1 && *str1 == *str2; str1++, str2++) {}
    if (*str1 - *str2 < 0)
        ans = -1;
    else if (*str1 - *str2 > 0)
        ans = 1;
    else
        ans = 0;
    return ans;
}

char * s21_strcpy(char * str1, const char * str2) {
    char * addres = str1;
    int i = 0;
    while (*str2 != '\0') {
        *str1++ = *str2++;
        i++;
    }
    *addres = '\0';
    addres -= i + 1;
    return addres;
}

char * s21_strcat(char * s1, const char * s2) {
    int k = s21_strlen(s1);
    char * res = s1 + k;
    int i = 0;
    for (; *s2; res++, s2++, i++) {
        *res = *s2;
    }
    *res = '\0';
    res -= i + k +1;
    return res;
}

int s21_strchr(const char * str, int c) {
    int ans = -1;
    while (*str) {
        if (*str == c) {
            break;
        } else {
            str++;
            ans++;
        }
    }
    return ans;
}
