#include <iostream>
using namespace std;
class Date
{
public:
    Date();
    Date(int y, int m, int d); // 默认值既可以在声明时加上,也可以在实现时加上
    void setDate(int, int, int); // 参数名称可省略,但类型不可省略
    void showDate();
    int num;

private:
    int year;
    int month;
    int day;
};
inline void Date::setDate(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}
inline void Date::showDate()
{
    cout << year << "." << month << "." << day << endl;
}
Date::Date() {}
Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}
class Time
{
public:
    Time();
    Time(int h, int m, int s);
    void showDate();
    void display()
    {
        cout << this << "," << hour << ":" << minute << ":" << second << endl;
    }

private:
    int hour, minute, second;
};
Time::Time() {}
Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) // 成员初始化列表
{
}
void Time::showDate()
{
    cout << hour << ":" << minute << ":" << second << endl;
}
class Exam1
{
public:
    static int count;
    static void add_count(){
        count++;
    }
    static int get_count(){
        return count;
    }
    static void show_x(Exam1 &e){
        cout << "show_x=" << e.x << endl;
    }
    Exam1()
    {
        x = 100;
    }
    Exam1(int n)
    {
        x = n;
    }
    void set_x(int n)
    {
        x = n;
    }
    int get_x()
    {
        return x;
    }

private:
    int x = 1;
};
class Exam2
{
public:
    Exam2()
    {
        x = 100;
        y = 200;
    }
    Exam2(int m,int n)
    {
        x = m;
        y = n;
    }
    int get_x()
    {
        return x;
    }
    int get_y()
    {
        return y;
    }
private:
    int x,y;
};
void twofold(Exam1 *e){
    e->set_x(e->get_x()*2);
}
void twofold(Exam1 &e){
    e.set_x(e.get_x()*2);
}
int Exam1::count=100; // 初始化静态数据成员
int main()
{
    // 内联函数,对象的定义,成员的访问
    Date date1, *p1;
    date1.num = 10;
    date1.setDate(2022, 1, 22);
    cout << "date1.num=" << date1.num << endl;
    p1 = &date1;
    cout << "p1->num=" << p1->num << ",(*p1).num=" << (*p1).num << endl;
    p1->setDate(2022, 1, 1);
    date1.showDate();
    p1->showDate();
    (*p1).showDate();

    // 构造函数
    Date date2(2022, 1, 23); // 在定义对象时被系统自动调用
    date2.showDate();
    Date *p2 = new Date(2000, 1, 23);
    // Date *p2;
    // p2 = new Date(2000,1,23);
    p2->showDate();
    delete p2;

    // 第二种初始化方法
    Time time1(15, 43, 0);
    time1.showDate();

    cout << "---关于 this ---" << endl;
    Time time2(17, 29, 0);
    time1.display();
    time2.display();

    cout << "---对象数组---" << endl;
    Exam1 e_arr_1[5] = {1, 2, 3, 4};
    cout << "e_arr_1:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << e_arr_1[i].get_x() << endl;
    }
    Exam2 e_arr_2[3] ={
        Exam2(1,10),
        Exam2(2,20),
        Exam2(3,30)
    };
    cout << "e_arr_2:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << e_arr_2[i].get_x() << "," << e_arr_2[i].get_y() << endl;
    }

    cout << "---对象数组---" << endl;
    cout << "before:" << e_arr_1[0].get_x() << endl;
    twofold(&e_arr_1[0]);
    cout << "after:" << e_arr_1[0].get_x() << endl;
    cout << "before:" << e_arr_1[2].get_x() << endl;
    twofold(e_arr_1[2]);
    cout << "after:" << e_arr_1[2].get_x() << endl;

    cout << "---静态数据成员与静态成员函数---" << endl;
    e_arr_1[0].add_count();
    cout << "count=" << e_arr_1[0].get_count() << endl;
    Exam1::show_x(e_arr_1[0]);
    e_arr_1[1].add_count();
    cout << "count=" << e_arr_1[1].get_count() << endl;
    Exam1::show_x(e_arr_1[1]);
    cout << "Exam1 count=" << Exam1::count << endl;

    return 0;
}