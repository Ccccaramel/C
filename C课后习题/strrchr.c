#include <stdio.h>
#include <string.h>
int main()
{
    char *str1 = "qwerty";
    char c = 'e';
    char *str2 = strrchr(str1, c);
    printf("%s\n", str2);
}