#include <stdio.h>
#include<float.h>
/**
 * 数据类型
 */
int main()
{
    printf("---char---\n");
    char c1 = 'a';
    char c2 = -128; // -128~255
    char c3 = '\t'; // 转义字符
    unsigned char uc1 = 'b';
    signed char sc1 = 'c';
    printf("%c,%d,%d,%d\n", c1, c1, &c1, sizeof(c1));
    printf("%c,%d,%d,%d\n", c2, c2, &c2, sizeof(c2));
    printf("%c,%d,%d,%d\n", c3, c3, &c3, sizeof(c3));
    printf("%c,%d,%d,%d\n", uc1, uc1, &uc1, sizeof(uc1));
    printf("%c,%d,%d,%d\n", sc1, sc1, &sc1, sizeof(sc1));

    printf("---int---\n");
    int i1 = 2147483647;
    int i2 = 2147483648;
    unsigned int i3 = 0;
    printf("%d,%d\n", i1, sizeof(i1));
    printf("%d,%d\n", i2, sizeof(i2));
    printf("%d,%d\n", i3, sizeof(i3));

    printf("---short---\n");
    short s1 = 32767;
    short s2 = 2147483647L;
    unsigned short us2 = 1;
    printf("%d,%d\n", s1, sizeof(s1));
    printf("%d,%d\n", s2, sizeof(s2));
    printf("%d,%d\n", us2, sizeof(us2));

    printf("---long---\n");
    long l1 = 2147483647l;
    unsigned long l2 = 1L;
    printf("%d,%d\n", l1, sizeof(l1));
    printf("%d,%d\n", l2, sizeof(l2));

    printf("---float---\n");
    float f1 = 1;
    float f2 = -3;
    printf("f1=%f,%lu\n",f1, sizeof(f1));
    printf("f2=%f\n", f2);
    printf("%E\n",FLT_MIN);  // 以指数形式输出单/双精度实数
    printf("%E\n",FLT_MAX);
    printf("%E\n",FLT_MANT_DIG);

    printf("---double---\n");
    double d1 = 1;
    long double ld1 = 1;
    printf("%f\n", d1);
    printf("%E\n", DBL_MIN);
    printf("%E\n", DBL_MAX);
    printf("%f\n", ld1);
    printf("%E\n", LDBL_MIN);
    printf("%E\n", LDBL_MAX);
}