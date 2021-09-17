#include <stdio.h>
#include"2-extern-2-2.h"
/**
 * 变量
 */
int x=6, y=4;
extern int a, b;
int main()
{
    printf("x+y=%d\n", result());
    printf("x+y=%d\n", add());
    return 0;
}
int mult() {
    return a+b;
}