#include <iostream>
using namespace std;
// 常对象成员
class Date
{
public:
    Date(int, int, int);
    void showDate();

private:
    const int year, month, day; // 常数据成员
};
Date::Date(int y, int m, int d) : year(y), month(m), day(d) {} // 采用成员初始化列表对常数据成员赋初值
void Date::showDate()
{
    cout << "date:" << this->year << "," << this->month << "," << this->day << endl;
}
// 常成员函数
class Time
{
public:
    Time(int, int, int);
    void showTime();
    void showTime() const;

private:
    int hour, minute, second;
};
Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) {}
void Time::showTime()
{
    cout << "time:" << this->hour << ":" << this->minute << ":" << this->second << endl;
}
void Time::showTime() const
{
    cout << "time const:" << this->hour << ":" << this->minute << ":" << this->second << endl;
}
int main()
{
    Date date1(2022, 1, 26);
    date1.showDate();

    Time time1(16, 4, 0);
    time1.showTime();
    const Time time2(16, 18, 0);
    time2.showTime();
}