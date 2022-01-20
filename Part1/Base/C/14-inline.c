#include <stdio.h>
inline int add(int a, int b)
{
    a *= 10;
    b *= 10;
    return a + b;
}
int main() // 无法正常运行
{
    int c = 0, i = 1;
    // for (int i = 1; i < 10; i++)
    // {
    c = add(3, 4);
    // }
    printf("c=%d\n", c);
}