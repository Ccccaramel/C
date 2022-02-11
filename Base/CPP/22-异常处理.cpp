#include <iostream>
using namespace std;
int Div(int x, int y);
int main()
{
    try
    {
        cout << "7/3=" << Div(7, 3) << endl;
        cout << "5/0=" << Div(5, 0) << endl;
    }
    catch (int)
    {
        cout << "除数为0,错误!" << endl;
    }
    cout << "end!" << endl;

    // 多个 catch 块的异常处理程序
    int i1=2;
    double d1=2.5;
    try{
        throw d1;
        throw i1; // 仅第一个异常被抛出
    }
    catch(int){
        cout<<"异常发生!整数型!"<<endl;
    }
    catch(double){
        cout<<"异常发生!双精度型!"<<endl;
    }
    cout<<"end"<<endl;
    return 0;

}
int Div(int x, int y)
{
    if (y == 0)
    {
        throw y;
    }
    return x / y;
}