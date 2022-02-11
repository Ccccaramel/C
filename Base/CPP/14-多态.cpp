#include <iostream>
using namespace std;
class Base
{
private:
public:
    static int i;
    Base();
    ~Base();
};
Base ::Base()
{
    i++;
}
Base ::~Base()
{
}
class Derived : public Base
{
private:
    /* data */
public:
    Derived(/* args */);
    ~Derived();
    void fun(Base &b)
    {
        cout << b.i << endl;
    }
};
Derived::Derived(/* args */)
{
}
Derived::~Derived()
{
}
class Derive1 : private Base
{
private:
    /* data */
public:
    Derive1(/* args */);
    ~Derive1();
};

Derive1::Derive1(/* args */)
{
}

Derive1::~Derive1()
{
}
class Derive2 : public Base
{
private:
    /* data */
public:
    Derive2(/* args */);
    ~Derive2();
};

Derive2::Derive2(/* args */)
{
}

Derive2::~Derive2()
{
}
int Base::i = 0;
int main()
{
    Derived d1, d2, d3;
    d1.fun(d2);

    cout << "---多态性(注意)---" << endl;
    Base b1, *b2;
    Derive1 de1;
    b2 = &b1;
    // b2=&de1; // 私有派生不可访问 'Base' is an inaccessible base of 'Derive1'

    Derive2 de2, *de3;
    // de3 = &b1; // 转换无效 invalid conversion from 'Base*' to 'Derive2*'
    de3 = &de2;
}