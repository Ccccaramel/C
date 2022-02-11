#include <iostream>
using namespace std;
class Complex
{
private:
    double real, imag;

public:
    Complex(double r = 100, double i = 100);
    ~Complex();

    void show()
    {
        cout << "real:" << this->real << ",imag:" << this->imag << endl;
    }
    operator double()
    {
        return this->real;
    }
    operator int()
    {
        return this->real;
    }
};

Complex::Complex(double r, double i)
{
    this->real = r;
    this->imag = i;
}

Complex::~Complex()
{
}

int main()
{
    double i = 2.1, j = 3.6, k;
    int n = 1.8, x, y, z;

    x = y = z = n;
    cout << "n=" << n << endl;
    cout << "i+j=" << i + j << endl;
    x = i + j;
    cout << "x=" << x << endl;

    Complex c(1.1, 2.2);
    c.show();
    cout << double(c) << endl;
    cout << int(c) << endl;
}