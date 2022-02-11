#include <iostream>
using namespace std;
class Complex
{
private:
    double a, b;

public:
    double real, imag;
    Complex(double r, double i, double m, double n);

    friend Complex operator-(Complex c1, Complex c2);
    Complex operator*(Complex &c1);

    // 前置运算符重载
    friend void operator++(Complex &c1);
    Complex operator--();

    //后置运算符重载
    Complex operator--(int);
    friend Complex operator++(Complex &, int);

    // <<
    friend ostream &operator<<(ostream &, Complex &);

    // >>
    friend istream &operator>>(istream &, Complex &);

    void display();
    void show();
    ~Complex();
};

Complex::Complex(double r = 0, double i = 0, double m = 0, double n = 0)
{
    this->real = r;
    this->imag = i;
    this->a = m;
    this->b = n;
}

Complex::~Complex()
{
}
// 前置运算符重载
Complex operator+(Complex c1, Complex c2)
{
    Complex c(c1.real + c2.real, c1.imag + c2.imag);
    return c; // 可读性比较好
}

Complex operator-(Complex c1, Complex c2)
{
    return Complex(0, 0, c1.a - c2.a, c1.b - c2.b); // 返回一个无名对象,效率比较高
}

void operator++(Complex &c)
{
    c.a++;
    c.b++;
}

Complex Complex::operator*(Complex &c1)
{
    Complex c(this->real * c1.real, this->imag * c1.imag);
    return c;
}
Complex Complex::operator--()
{
    // Complex c(this->real--, this->imag--, this->a, this->b);
    return Complex(--this->real, --this->imag, this->a, this->b);
}
// 后置运算符重载
Complex Complex::operator--(int) // 注意:没有参数
{
    Complex c(*this);
    this->real--;
    this->imag--;
    return c;
}
Complex operator++(Complex &c, int)
{
    c.real++;
    c.imag++;
    return c;
}

// <<
ostream &operator<<(ostream &out, Complex &com)
{
    out << com.real;
    if (com.imag > 0)
    {
        out << "+";
    }
    if (com.imag != 0)
    {
        out << com.imag << "i\n";
    }
    return out;
}
// >>
istream &operator>>(istream &in, Complex &c)
{
    cout << "Enter the real part and imaginary part of complex number:" << endl;
    cout << "real:";
    in >> c.real;
    cout << "imag:";
    in >> c.imag;
    return in;
}
void Complex::display()
{
    cout << "display():" << this->real << "," << this->imag << endl;
}
void Complex::show()
{
    cout << "show():" << this->a << "," << this->b << endl;
}

int main()
{

    cout << "---双目运算---" << endl;
    Complex c1(2, 5, 100, 200), c2(4, 7, 50, 60), c3, c4, c5, c6, c7;
    c3 = c1 + c2; // 只能访问公有成员
    cout << "c3:" << c3.real << "," << c3.imag << endl;

    cout << "***友元函数***" << endl;
    cout << "---双目运算---" << endl;
    c4 = c1 - c2; // 友元函数,可以访问私有成员(隐式调用)
    // c4 = operator(c1,c2); // 与上述等价(显式调用)
    c4.show();

    cout << "---单目运算---" << endl;
    // c4++; // 错误,自增只有前置运算符重载
    ++c4;
    c4.show();
    operator++(c4);
    c4.show();

    cout << "***成员函数***" << endl;
    // c4 = c1.operator*(c2);
    c4 = c1 * c2;
    c4.display();
    // c4.operator--();
    c5 = --c4;
    c4.display();
    c5--; // 后置运算符重载
    c5.display();
    c6 = c1 * c2;
    c6++;
    c6.display();
    c6--;
    c6.display();

    cout << "---<<---" << endl;
    cout << c6;

    cout << "--->>---" << endl;
    cin >> c7;
    c7.display();
}