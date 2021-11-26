#include <stdio.h>
/**
 * 函数
 * 
 * 形参(形式参数)
 *   在函数定义时函数首部形式参数表中的变量是形式参数
 * 
 * 实参(实际参数)
 *   在函数调用中的实际参数表中的参数
 * 
 * 当数组名作为函数参数时,对形参数组元素内容所做的改变就是对实参数组元素内容的改变
 *  
 */
int add(int a, int b)
{
    return a + b;
}

void add1(int a, int b, int *c)
{
    *c = a + b;
}

char *strcat(char *s1, char *s2)
{
    char *p = s1;
    while (*p != '\0')
    {
        p++;
    }
    while ((*p++ = *s2++) != '\0');
    return (s1);
}

int main()
{
    printf("12+3=%d\n", add(12, 3));
    int subtraction(int a, int b); // 若函数在 mian 后定义则需要在使用前声明
    printf("45-6=%d\n", subtraction(45, 6));

    int a1 = 10, b1 = 2, c1;
    add1(a1, b1, &c1);
    printf("a1+b1=%d\n", c1);

    /**
     * 函数的返回值为指针
     * 
     */
    char str1[30]="I learn ",str2[30]="C language.";
    char *s;
    s=strcat(str1,str2);
    printf("s=%s,str1=%s\n",s,str1);

    return (0);
}
int subtraction(int a, int b)
{
    return (a - b);
}