#include <stdio.h>
int main()
{
    enum Month
    {
        January = 1,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December
    };
    int MonthArr[12][2] = {{1, January}, {2, February}, {3, March}, {4, April}, {5, May}, {6, June}, {7, July}, {8, August}, {9, September}, {10, October}, {11, November}, {12, December}};
    for(int i=0;i<12;i++){
        printf("%d:%d,%d\n", i,MonthArr[i][0],MonthArr[i][1]);
    }
}