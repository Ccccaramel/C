#include <iostream>
using namespace std;
class A
{
private:
    int pri_a;
    void showAPri()
    {
        cout << "showAPri()" << endl;
    };

protected:
    int pro_a;
    void showAPro()
    {
        cout << "showAPro()" << endl;
    };

public:
    int pub_a;
    A(int x, int y, int z)
    {
        pri_a = x;
        pro_a = y;
        pub_a = z;
    };
    void showAPub()
    {
        cout << "showAPub()" << endl;
    };
    void hi()
    {
        cout << "hi!A." << endl;
    }
};
class B : private A
{
private:
    int pri_b;
    void showBPri()
    {
        cout << "showBPri()" << endl;
    };

protected:
    int pro_b;
    void showBPro()
    {
        cout << "showBPro()" << endl;
    };

public:
    int pub_b;
    B(int n, int p, int q, int x, int y, int z) : A(x, y, z)
    {
        pri_b = n;
        pro_b = p;
        pub_b = q;
    };
    void showBPub()
    {
        cout << "--内部访问--" << endl;
        // cout << pri_a << endl; // 不可访问
        cout << "pro_a:" << pro_a << ",pub_a:" << pub_a << endl;
        showAPro();
        showAPub();
        cout << "----" << endl;
        cout << "showBPub()" << endl;
    };
};
class C : protected A
{
private:
    int pri_c;
    void showCPri()
    {
        cout << "showCPri()" << endl;
    };

protected:
    int pro_c;
    void showCPro()
    {
        cout << "showCPro()" << endl;
    };

public:
    int pub_c;
    C(int n, int p, int q, int x, int y, int z) : A(x, y, z)
    {
        pri_c = n;
        pro_c = p;
        pub_c = q;
    };
    void showCPub()
    {
        cout << "--内部访问--" << endl;
        // cout << pri_a << endl; // 不可访问
        cout << "pro_a:" << pro_a << ",pub_a:" << pub_a << endl;
        showAPro();
        showAPub();
        cout << "----" << endl;
        cout << "showCPub()" << endl;
    };
};
class D : public A
{
private:
    int pri_d;
    void showDPri()
    {
        cout << "showDPri()" << endl;
    };

protected:
    int pro_d;
    void showDPro()
    {
        cout << "showDPro()" << endl;
    };

public:
    int pub_d;
    D(int n, int p, int q, int x, int y, int z) : A(x, y, z)
    {
        pri_d = n;
        pro_d = p;
        pub_d = q;
    };
    void hi()
    {
        cout << "在派生类中调用基类成员:";
        A::hi();
        cout << "hi!D." << endl;
    }
    void showDPub()
    {
        cout << "--内部访问--" << endl;
        // cout << pri_a << endl; // 不可访问
        cout << "pro_a:" << pro_a << ",pub_a:" << pub_a << endl;
        showAPro();
        showAPub();
        cout << "----" << endl;
        cout << "showDPub()" << endl;
    };
};
int main()
{
    cout << "---A---" << endl;
    A a1(10, 11, 12);
    cout << "pub_a:" << a1.pub_a << endl;
    a1.showAPub();

    cout << "---B--- private:只可访问自己的数据成员和成员函数" << endl;
    B b1(20, 21, 22, 23, 24, 25);
    // cout << b1.pub_a; // 报错:'int A::pub_a' is inaccessible within this context 无法访问
    cout << "pub_b:" << b1.pub_b << endl;
    // b1.showAPub(); // 无法访问
    b1.showBPub();

    cout << "---C--- protected:只可访问自己的数据成员和成员函数" << endl;
    C c1(30, 31, 32, 33, 34, 35);
    // cout << c1.pub_a; // 无法访问
    cout << "pub_c:" << c1.pub_c << endl;
    // c1.showAPub(); // 无法访问
    c1.showCPub();

    cout << "---D--- public:可访问父类的公有数据成员和公有成员函数" << endl;
    D d1(40, 41, 42, 43, 44, 45);
    cout << "pub_a:" << d1.pub_a << ",pub_d:" << d1.pub_d << endl;
    d1.showAPub();
    d1.showDPub();

    // 重新声明
    d1.hi();
    cout << "通过派生类的对象调用基类成员:";
    d1.A::hi();
}