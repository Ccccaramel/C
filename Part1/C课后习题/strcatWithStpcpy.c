#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str1[10] = "123";
    char str2[10] = "456";
    strcat(str1, str2);
    printf("str1=%s\n", str1);

    // 在 linux 上测试
    // char str3[10] = "151515";
    // char str4[10] = "2";
    // stpcpy(str3, str4);
    // printf("str3=%s\n", str3);

    // char str5[10] = "567890";
    // char str6[10] = "2134";
    // stpncpy(str5, str6, 1);
    // printf("str5=%s\n", str5);

    char str7[10] = "qqq";
    char str8[10] = "zzzz";
    strcpy(str7, str8);
    printf("str7=%s\n", str7);
}