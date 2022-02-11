#include <iostream>
using namespace std;
class Base
{
private:
    int a, b;

public:
    Base();
    Base(int x, int y);
    ~Base();
    void show1()
    {
        cout << "Base a=" << a << ",b=" << b << endl;
    }
    virtual void show2()
    {
        cout << "Base show2(), a=" << a << ",b=" << b << endl;
    }
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
};
Base::Base() {}
Base::Base(int x, int y)
{
    a = x;
    b = y;
}

Base::~Base()
{
}
class MyBase : public Base
{
private:
    int c;

public:
    MyBase(int x, int y, int z);
    ~MyBase();
    void show1()
    {
        cout << "MyBase>Base a+b=" << Base::getA() + Base::getB() << endl;
        cout << "MyBase c=" << c << endl;
    };
    virtual void show2()
    {
        cout << "MyBase show2(), c=" << c << endl;
    }
};

MyBase::MyBase(int x, int y, int z) : Base(x, y)
{
    c = z;
}

MyBase::~MyBase()
{
}
// 虚函数的简单应用
class Figure
{
public:
    Figure(){};
    Figure(double a, double b)
    {
        x = a;
        y = b;
    };
    virtual void area()
    {
        cout << "在基类中定义的虚函数,";
        cout << "为派生类提供一个公共接口,";
        cout << "以便派生类根据需要重新定义虚函数." << endl;
    };
    virtual void showArea() = 0;
    ~Figure()
    {
        cout << "调用 Figure 的析构函数." << endl;
    };

protected:
    double x, y;
};
class Triangle : public Figure
{
public:
    Triangle() : Figure(){};
    Triangle(double a, double b) : Figure(a, b){};
    void area()
    {
        cout << "三角形的高是" << x << ",底是" << y << ",面积是" << 0.5 * x * y << endl;
    };
    void showArea()
    {
        cout << "showArea(),三角形的高是" << x << ",底是" << y << ",面积是" << 0.5 * x * y << endl;
    };
    ~Triangle()
    {
        cout << "调用 Triangle 的析构函数." << endl;
    };
};
class Square : public Figure
{
public:
    Square(double a, double b) : Figure(a, b){};
    void area()
    {
        cout << "矩形的长是" << x << ",宽是" << y << ",面积是" << x * y << endl;
    };
    void showArea()
    {
        cout << "showArea(),矩形的长是" << x << ",宽是" << y << ",面积是" << x * y << endl;
    };
    ~Square()
    {
        cout << "调用 Square 的析构函数." << endl;
    };
};
class Circle : public Figure
{
private:
    /* data */
public:
    Circle(double a) : Figure(a, a){};
    void area()
    {
        cout << "圆的半径是" << x << ",面积是" << 3.1416 * x * x << endl;
    };
    void showArea()
    {
        cout << "showArea(),圆的半径是" << x << ",面积是" << 3.1416 * x * x << endl;
    };
    ~Circle()
    {
        cout << "调用 Circle 的析构函数." << endl;
    };
};
// 虚析构函数
class A
{
public:
    ~A()
    {
        cout << "调用基类 A 的析构函数." << endl;
    };
};
class B : public A
{
public:
    ~B()
    {
        cout << "调用基类 B 的析构函数." << endl;
    };
};
class C
{
public:
    virtual ~C()
    {
        cout << "调用基类 C 的析构函数." << endl;
    };
};
class D : public C
{
public:
    ~D()
    {
        cout << "调用基类 D 的析构函数." << endl;
    };
};
int main()
{
    Base b1(1, 2), *pb;
    pb = &b1;
    pb->show1();

    pb->show2(); // 引入虚函数,实际对象 Base

    MyBase b2(3, 4, 5);
    pb = &b2;
    pb->show1(); // 调用的是基类的方法

    pb->show2(); // 引入虚函数,实际对象 MyBase

    // 简单应用举例
    Figure *p1;
    Triangle t(10.0, 6.0);
    Square s(10.0, 6.0);
    Circle c(10.0);
    p1 = &t;
    p1->area();
    p1->showArea(); // 纯虚函数
    p1 = &s;
    p1->area();
    p1->showArea(); // 纯虚函数
    p1 = &c;
    p1->area();
    p1->showArea(); // 纯虚函数

    cout << "-虚析构函数-" << endl;
    A *p2;
    p2 = new B;
    delete p2;

    cout << "---" << endl;
    C *p3;
    p3 = new D;
    delete p3; // 动态联编,实现了运行的多态性
    cout << "^^^" << endl;
}