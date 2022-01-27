#include <stdio.h>
/**
 * 变量
 */
extern int x, y; // 只是声明并未定义,如果不声明会报错-未声明(首次在此函数中使用)
int a=3, b=13;
extern int mult();
int add()
{
    printf("a+b=%d\n", mult());
    return x + y;
}
int result(){
    return 1;
}