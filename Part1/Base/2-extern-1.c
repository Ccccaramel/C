#include <stdio.h>
/**
 * 变量
 */
int x, y;
int add()
{
    extern int x;
    extern int y; // 函数内声明变量 x y 为外部变量
    x = 1;
    y = 2;
    return x + y;
}
int main()
{
    printf("x+y=%d\n", add());
}