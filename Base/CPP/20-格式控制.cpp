#include <iostream>
#include <iomanip>
using namespace std;
ostream &output(ostream &stream);
istream &input(istream &in);
int main()
{
    cout << "---用流成员函数进行输入输出格式控制---" << endl;
    cout.setf(ios::showpos | ios::scientific);
    cout << 567 << " " << 567.89 << endl;

    cout.unsetf(ios::showpos | ios::scientific); // 移除状态标志

    double d1 = -5.1;
    cout.setf(ios::internal);
    cout.width(10);
    cout.fill('*');
    cout << d1 << endl;

    cout.unsetf(ios::internal); // 移除状态标志

    cout.fill('&');
    cout.width(10);
    cout.setf(ios::left);
    cout << 123 << endl;

    cout.unsetf(ios::left); // 移除状态标志

    int i1 = 21;
    cout.unsetf(ios::dec);               // 需要终止十进制的格式设置
    cout.setf(ios::showbase | ios::hex); // 显示基数符号并以十六进制输出格式
    cout << i1 << endl;

    cout.unsetf(ios::showbase | ios::hex); // 移除状态标志

    cout << "---使用预定义的操纵符进行输入输出格式控制---" << endl;
    double d2 = 45.3, d3 = -5.1;
    cout << setiosflags(ios::scientific | ios::left | ios::showpos);
    cout << d2 << endl;

    cout.unsetf(ios::scientific | ios::left | ios::showpos); // 移除状态标志

    cout << setw(10);
    cout << setfill('*');
    cout << internal << d3 << endl;

    cout.unsetf(ios::internal); // 移除状态标志

    cout << setiosflags(ios::scientific) << setw(20) << 123.456789 << endl; // 默认保留6位小数

    cout << resetiosflags(ios::scientific); // 移除状态标志

    cout << setiosflags(ios::left) << setfill('#') << setw(8) << 123 << endl;
    cout << resetiosflags(ios::left) << setfill('$') << setw(8) << 123 << endl;

    cout << "---使用用户自定义的操纵符进行输入输出格式控制---" << endl;
    cout << 666 << endl;
    cout << output << 666 << endl;

    int i2;
    cin >> input >> i2;
    cout << "hex:" << i2 << "------dec:" << dec << i2 << endl;
}
ostream &output(ostream &stream)
{
    stream.setf(ios::left);
    stream << setw(10) << hex << setfill('&');
    return stream;
}
istream &input(istream &in)
{
    in >> hex;
    cout << "Enter number using hex format:";
    return in;
}