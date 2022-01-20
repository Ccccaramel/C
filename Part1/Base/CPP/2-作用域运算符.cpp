#include <iostream>
#include <iomanip>
using namespace std;
double pi = 3;
int main()
{
    const double pi = 3.14;
    ::pi = 3.1415926;
    cout << pi << endl;
    cout << setprecision(8) << ::pi << std::endl; // C++ 默认输出6位有效数字
    return 0;
}