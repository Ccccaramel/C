#include <iostream>
using namespace std;
template <typename T>
// 函数模板
T Max(T a, T b)
{
    return a > b ? a : b;
}
template <class H>
H Min(H a, H b)
{
    return a < b ? a : b;
}
template <typename X, class Y>
void Show(X x, Y y)
{
    cout << x << "," << y << endl;
}
void Show(int a, int b)
{
    cout << "一般函数:" << a << "," << b << endl;
}
// 类模板(类模板体内定义成员函数)
template <typename V>
class Sub
{
private:
    V a, b, c;

public:
    Sub(V a, V b, V c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    ~Sub()
    {
    }

    V difference()
    {
        return this->a - this->b - this->c;
    }
};

// 类模板(类模板体外定义成员函数)
template <typename E>
class Add
{
private:
    E a, b, c;

public:
    Add(E a, E b, E c);
    E sum();
    ~Add();
};
template <typename E>
Add<E>::Add(E a, E b, E c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}
template <typename E>
E Add<E>::sum()
{
    return this->a + this->b + this->c;
}
template <typename E>
Add<E>::~Add()
{
}

int main()
{
    int a = 5, b = 3;
    cout << Max(a, b) << endl;
    double m = 4.5, n = 3.9;
    cout << Max(m, n) << endl;

    cout << Min(4, 7) << endl;

    Show(a, m);
    Show(a, b);

    cout << "---类模板(类模板体内定义成员函数)---" << endl;
    Sub<int> s1(10, 3, 5);
    Sub<double> s2(13.7, 7.2, 5.4);
    cout << "int:" << s1.difference() << endl;
    cout << "double:" << s2.difference() << endl;

    cout << "---类模板(类模板体外定义成员函数)---" << endl;
    Add<int> a1(1, 3, 5);
    Add<double> a2(3.6, 7.2, 5.4);
    cout << "int:" << a1.sum() << endl;
    cout << "double:" << a2.sum() << endl;
}