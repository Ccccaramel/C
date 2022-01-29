#include <iostream>
using namespace std;
class A
{
public:
    A(){};
    A(int x)
    {
        a = x;
    }
    void setA(int x)
    {
        a = x;
    }
    void printA()
    {
        cout << "a:" << a << endl;
    }
    ~A()
    {
        cout << "running ~A()." << endl;
    }

private:
    int a;
};
class B
{
public:
    B(){};
    B(int x)
    {
        b = x;
    }
    void setB(int x)
    {
        b = x;
    }
    void printB()
    {
        cout << "b:" << b << endl;
    }
    ~B()
    {
        cout << "running ~B()." << endl;
    }

private:
    int b;
};
class C : public A, private B
{
public:
    C(){};
    C(int x, int y, int z) : A(y), B(z)
    {
        c = x;
    }
    void setC(int x, int y)
    {
        c = x;
        setB(y);
    }
    void printC()
    {
        printB();
        cout << "c:" << c << endl;
    }
    ~C()
    {
        cout << "running ~C()." << endl;
    }

private:
    int c;
};
int main()
{
    cout << "---多重继承---" << endl;
    C c1;
    c1.setA(10);
    c1.printA();
    // c1.setB(20); // 无法访问
    // c1.printB(); // 无法访问
    c1.setC(30, 40);
    c1.printC();

    cout << "---多重继承的构造函数与析构函数---" << endl;
    C c2(1, 2, 3);
    c2.printA();
    // c2.printB();
    c2.printC();

    return 0;
}