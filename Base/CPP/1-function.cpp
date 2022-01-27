#include <iostream>
using namespace std;
int add1(int a, int b = 6); // 函数原型声明
double add1(double a, double b);
int main()
{
    cout << "add1:" << add1(1) << endl;
    cout << "add1(重载):" << add1(6.6, 3.3) << endl;
    return 0;
}
int add1(int a, int b) // 带有默认参数的函数
{
    return a + b;
}
double add1(double a, double b)
{
    return a + b + 0.1;
}