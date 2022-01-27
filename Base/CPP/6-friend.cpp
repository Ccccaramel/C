#include <iostream>
using namespace std;
class Date; // 对 Date 类的提前引用声明
class Time
{
public:
    Time(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }
    void showDateTime(Date &); // 声明为成员函数

private:
    int hour, minute, second;
};
class Date
{
public:
    Date(int y, int m, int d){
        year = y;
        month = m;
        day = d;
    }
    friend void showDate(Date &);           // 声明函数 showDate 为类 Date 的友元函数
    friend void Time::showDateTime(Date &); // 将 Time 的成员函数声明为 Date 的友元函数

private:
    int year;
    int month;
    int day;
};
// 友元类
void Time::showDateTime(Date &d)
{
    cout << "date:" << d.year << "," << d.month << "," << d.day << endl;
    cout << "time:" << hour << ":" << minute << ":" << second << endl;
}
class Date1;
class Time1
{
public:
    Time1(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }
    void showDateTime(Date1 &);

private:
    int hour, minute, second;
};
class Date1
{
public:
    Date1(int y, int m, int d)
    {
        this->year = y;
        this->month = m;
        this->day = d;
    }
    void showDate()
    {
        cout << "date:" << year << "," << month << "," << day << endl;
    }
    friend Time1;

private:
    int year, month, day;
};
void Time1::showDateTime(Date1 &d)
{
    cout << "date:" << d.year << "," << d.month << "," << d.day << endl;
    cout << "time:" << hour << ":" << minute << ":" << second << endl;
}
int main()
{
    Date date1(2022, 1, 25);
    Time time1(17, 20, 0);
    time1.showDateTime(date1);

    Date1 date2(2000,1,25);
    Time1 time2(11,22,33);
    time2.showDateTime(date2);
}