#include <stdio.h>
int main()
{
    enum Week
    {
        Sunday,
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday
    } weekDays1 = Monday;
    if (weekDays1 == Monday)
    {
        printf("weekDays1==Monday\n");
    }
    else
    {
        printf("weekDays1!=Monday\n");
    }

    enum Week weekDays2 = Sunday;
    if (weekDays2 == Sunday)
    {
        printf("weekDays2==Sunday\n");
    }
    else
    {
        printf("weekDays2!=Sunday\n");
    }

    enum Week weekDays3 = (enum Week)1;
    if (weekDays3 == Monday)
    {
        printf("weekDays3==Monday\n");
    }
    else
    {
        printf("weekDays3!=Monday\n");
    }

    printf("枚举的值域是整数的集合,Friday=%d\n",Friday);
}