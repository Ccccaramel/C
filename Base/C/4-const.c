#include<stdio.h>
/**
 * 您可以使用 const 前缀声明指定类型的常量
 */
int main() {
    const int CONST_I_1; // 未初始化的常量后续将无法赋值,所以必须声明时赋值
    const int CONST_I_2 = 1; // 常量名大写
    printf("CONST_I_1=%d\n", CONST_I_1); // 未初始化的常量为随机值
    printf("CONST_I_2=%d\n", CONST_I_2);
}