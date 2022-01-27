#include "stdio.h"
/**
 * 数组
 *   数组名是常量,不可赋值
 */
int main()
{

    int arr1[5] = {0, 1, 2, 3, 4};
    for (int i = 0; i < 5; i++)
    {
        printf("arr1[%d]=%d\n", i, arr1[i]);
    }

    // 初始化
    int arr2[3] = {1};            // 缺省部分自动赋 0 值
    int arr3[] = {1, 3, 5, 7, 9}; // 系统自动定义数组 arr3 长度为 5
    int arr4[3];                  // 数组未初始化,将由系统分配给数组各个元素内存单元的原始值决定
    printf("arr2:");
    for (int i = 0; i < 3; i++)
        printf("%6d  ", arr2[i]);
    printf("\narr3:");

    for (int i = 0; i < 5; i++)
        printf("%6d  ", arr3[i]);
    printf("\narr4:");

    for (int i = 0; i < 3; i++)
        printf("%6d  ", arr4[i]);
    printf("\n");
    printf("arr4:%s\n",arr4);

    // 二维数组,三维数组,...
    int arr5[3][3] = {0, 1, 2, 3, 4, 5};
    int arr6[][3] = {0, 1, 2, 3, 4, 5}; // 第一维可不指定大小
    int arr7[3][3] = {{0, 1, 2}, {3, 4, 5}};
    int arr8[2][2][2] = {0, 1, 2, 3, 4, 5, 6, 7};
    int arr9[][2][2] = {0, 1, 2, 3, 4, 5, 6, 7};
    printf("arr5:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%6d", arr5[i][j]);
        }
        printf("\n");
    }
    printf("arr7:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%6d", arr7[i][j]);
        }
        printf("\n");
    }
    printf("arr8:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                printf("arr8[%d][%d][%d]=%d  ", i, j, k, arr8[i][j][k]);
            }
            printf("\n");
        }
    }

    /**
     * 即使你输入的字符串长度超过3,程序也可能"正常"执行
     * C/C++不检查数组越界,不报错只是运气好
    */
    char arr10[3],arr11[3];
    scanf("%s",&arr10);
    printf("%s\n",arr10);
    // arr11=arr10; // 这是错误的,arr11和arr10都是常量,常量不能在等号左边
    printf("arr11:%s\n",arr11);

    // char arr11[];  //不允许使用不完整的类型
}