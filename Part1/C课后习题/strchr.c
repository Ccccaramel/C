#include <stdio.h>
#include <string.h>
int main()
{
        char *str1 = "1234";
        char c = '2';
        char *c1 = strchr(str1, '1');
        char *c2 = strchr(str1, '2');
        char *c3 = strchr(str1, '3');
        char *c4 = strchr(str1, '4');
        printf("%s,%d\n", c1, &c1);
        printf("%s,%d\n", c2, &c2);
        printf("%s,%d\n", c3, &c3);
        printf("%s,%d\n", c4, &c4);
}