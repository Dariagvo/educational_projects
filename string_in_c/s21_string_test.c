#include <stdio.h>
#include <stdlib.h>
#include "s21_string.h"

#define TEST_1 "Hello!"
#define TEST_2 "kjsdbfh\0  "
#define TEST_3 ""
#define TEST_4 " abc"

#define res_1_l 6
#define res_2_l 9
#define res_3_l 0

#define res_cmp1 1
#define res_cmp2 1
#define res_cmp3 0

void s21_strlen_test(const char * test, size_t res);
void s21_strcmp_test(const char * test_st_1_1, const char * test_st_1_2, int res_cmp);
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();

int main() {
#ifdef QUEST1
    s21_strlen_test(TEST_1, res_1_l);
    s21_strlen_test(TEST_2, res_2_l);
    s21_strlen_test(TEST_3, res_3_l);
#endif  // QUEST1

#ifdef QUEST2
    s21_strcmp_test(TEST_1, TEST_3, res_cmp1);
    s21_strcmp_test(TEST_2, TEST_2, res_cmp2);
    s21_strcmp_test(TEST_1, TEST_1, res_cmp3);
#endif  // QUEST2

#ifdef QUEST3
    s21_strcpy_test();
#endif  // QUEST3

#ifdef QUEST4
    s21_strcat_test();
#endif  // QUEST4

#ifdef QUEST5
    s21_strchr_test();
#endif  // QUEST5

    return 0;
}

void s21_strlen_test(const char * test, size_t res) {
    size_t k;
    k = s21_strlen(test);
    printf("%s : %ld : ", test, k);
    if (k == res)
        printf("SUCCESS \n");
    else
        printf("FAIL \n");
}

void s21_strcmp_test(const char * test_st_1_1, const char * test_st_1_2, int res_cmp) {
    int k;
    k = s21_strcmp(test_st_1_1, test_st_1_2);
    printf("%s : %s : %d : ", test_st_1_1, test_st_1_2, k);
    if (k == res_cmp)
        printf("SUCCESS \n");
    else
        printf("FAIL \n");
}

void s21_strcpy_test() {
    char s1[] = "hello", s2[] = "no";
    char * ans = s21_strcpy(s1, s2);
    printf("hello, no : %s : ", ans);
    if (0 == s21_strcmp(ans, s2))
        printf("SUCCESS \n");
    else
        printf("FAIL \n");

    char s12[] = "hello", s22[] = " ";
    printf("hello, _ : %s : ", s21_strcpy(s12, s22));
    if (0 == s21_strcmp(s21_strcpy(s12, s22), s22))
        printf("SUCCESS \n");
    else
        printf("FAIL \n");

    char s13[] = "hello", s23[] = "buddy";
    printf("hello, buddy : %s : ", s21_strcpy(s13, s23));
    if (0 == s21_strcmp(s21_strcpy(s13, s23), s23))
        printf("SUCCESS \n");
    else
        printf("FAIL \n");
}

void s21_strcat_test() {
    char s1_1[] = "first ", s1_2[] = "second";
    s21_strcat(s1_1, s1_2);
    printf("first , second : %s :", s1_1);
    if (s21_strlen(s1_1) == 12)
        printf("SUCCESS \n");
    else
        printf("FAIL \n");

    char s2_1[] = "first ", s2_2[] = "\n";
    s21_strcat(s2_1, s2_2);
    printf("first ,\n : %s :", s2_1);
    if (s21_strlen(s2_1) == 6)
        printf("SUCCESS \n");
    else
        printf("FAIL \n");

    char s3_1[] = "first", s3_2[] = "first";
    s21_strcat(s3_1, s3_2);
    printf("first , first : %s :", s3_1);
    if (s21_strlen(s3_1) == 10)
        printf("SUCCESS \n");
    else
        printf("FAIL \n");
}

void s21_strchr_test() {
    char st[] = "You can do this";
    char symb = 'o';
    int res = s21_strchr(st, symb);
    printf("You can do this, o : %d :", res);
    if (res != -1)
        printf("SUCCESS \n");
    else
        printf("FAIL \n");

    char st2[] = "You can do this";
    char symb3 = 'i';
    int res2 = s21_strchr(st2, symb3);
    printf("You can do this, p : %d :", res2);
    if (res2 != -1)
        printf("SUCCESS \n");
    else
        printf("FAIL \n");

    char st3[] = "You can do this";
    char symb2 = ' ';
    int res3 = s21_strchr(st3, symb2);
    printf("You can do this, p : %d :", res3);
    if (res3 != -1)
        printf("SUCCESS \n");
    else
        printf("FAIL \n");
}
