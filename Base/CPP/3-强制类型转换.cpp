#include <iostream>
using namespace std;
int main()
{
    // C 中的强制类型转换
    int m = 5;
    double n = (double)m;
    cout << "n:" << n << endl;

    // C++ 的扩充,使得强制类型转换执行起来像是调用了函数(推荐使用该方法)
    int i = 10;
    double j = double(i);
    cout << "j:" << j << endl;
}