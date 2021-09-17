#include "stdio.h"
/**
 * 字符常量
 * 转义字符
 * */
void printf_1();
void printf_2();
int main()
{
    printf_1();
    printf_2(); // a
}
void printf_1() {
    printf("1 \\ 2 \a 3 \b 4 \f 5 \n  66666  \r 7 \t 8 \v 9"); // 6 去哪儿了?
    printf("\n***\n"); // b
    printf("111\r2");
    printf("\n");
}
void printf_2() {
    printf("1\t1\t1\t1\t1\t1\t\n");
    printf("1234567\t1\t1\t1\t1\t1\t\n");
    printf("12345678\t1\t1\t1\t1\t1\t\n");
    printf("123456789012345\t1\t1\t1\t1\t1\t\n");

    printf("1\v1\v1\v1\v1\v1\v*\n");
}
/**
 *  注释掉 a 处
 *  执行结果是什么?
 *  将 b 处 换成 printf("\r***\n"); 
 *  运行观察结果又是什么?
 **/