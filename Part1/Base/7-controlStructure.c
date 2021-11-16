#include"stdio.h"
/**
 * 程序控制结构
 * 1.选择结构
 *   if
 *   switch
 * 2.循环结构
 *   while
 *   do-while
 *   for
 *   continue 与 break
 */
int main() {
    int a = 1;
    switch (a)
    {
    case 0:
        printf("0\n");
        break;
    case 1:
        printf("1\n"); // 如果不在后面添加 break 则会将之后的所有语句执行
    case 2:
        printf("2\n");
    default:
        printf("default\n");
        break;
    }

    do{
        a++;
    }while(a<10);
    printf("a=%d\n", a);
}