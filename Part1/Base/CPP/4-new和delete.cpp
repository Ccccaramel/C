#include <iostream>
using namespace std;
int main()
{
    int *pi = new int[10];  // 必须提供所有维的大小
    delete []pi; // 无论几维数组,都只需要一对方括号 delete []指针变量名;
    cout << "123" << endl;
}