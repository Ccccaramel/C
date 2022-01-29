#include <iostream>
using namespace std;
class Base
{
public:
    Base()
    {
        a = 5;
        cout << "a=" << a << endl;
    }
    Base(int x)
    {
        a = x;
        cout << "Constructing Base." << endl;
    }
    void showBase()
    {
        cout << "Base a=" << a << endl;
    }

protected:
    int a;
};
class Base1 : public Base
{
public:
    Base1()
    {
        a = a + 10;
        cout << "a=" << a << endl;
    }
    void showBase1()
    {
        cout << "Base1 a=" << a << endl;
    }
};
class Base2 : public Base
{
public:
    Base2()
    {
        a = a + 20;
        cout << "a=" << a << endl;
    }
    void showBase2()
    {
        cout << "Base2 a=" << a << endl;
    }
};
class Derived1 : public Base1, public Base2
{
public:
    Derived1()
    {
        // cout << "Derived1 a=" << a << endl; // 错误,产生二义性,不知道指那个数据成员的 a

        cout << "Base1::a=" << Base1::a << endl;
        cout << "Base2::a=" << Base2::a << endl;
    }
};
// 虚基类
class Base3 : virtual public Base
{
public:
    Base3()
    {
        a = a + 10;
        cout << "a=" << a << endl;
    }
    Base3(int x, int y) : Base(y)
    {
        a = x;
        cout << "Constructing Base3." << endl;
    }
    void showBase3()
    {
        cout << "Base3 a=" << a << endl;
    }
};
class Base4 : virtual public Base
{
public:
    Base4()
    {
        a = a + 20;
        cout << "a=" << a << endl;
    }
    Base4(int x, int y) : Base(y)
    {
        a = x;
        cout << "Constructing Base4." << endl;
    }
    void showBase4()
    {
        cout << "Base4 a=" << a << endl;
    }
};
class Derived2 : public Base3, public Base4
{
public:
    Derived2()
    {
        cout << "Derived2 a=" << a << endl; // 错误,产生二义性,不知道指那个数据成员的 a

        // cout << "Base1::a=" << Base1::a << endl;
        // cout << "Base2::a=" << Base2::a << endl;
    }
    Derived2(int x, int y, int z, int a) : Base(x), Base3(x, y), Base4(x, z)
    {
        d = a;
        cout << "Constructing Derived2." << endl;
    }

private:
    int d;
};
int main()
{
    Derived1 obj1;
    // obj1.showBase(); // 报错,request for member 'showBase' is ambiguous,“showBase”的请求不明确
    obj1.showBase1();
    obj1.showBase2();

    cout << "---虚基类---" << endl;
    Derived2 obj2;
    obj2.showBase();
    obj2.showBase3();
    obj2.showBase4();

    cout << "---虚基类的初始化---" << endl;
    Derived2 obj3(1, 2, 3, 4);
    /**
     * 虚基类 Base 的构造函数只执行了一次
     * 当 Derived 的构造函数调用了虚基类 Base 的构造函数之后
     * 类 Base3 和 Base4 对 Base 构造函数的调用被忽略了
     * 这也是初始化虚基类和初始化非虚基类不同之处
     */

    return 0;
}