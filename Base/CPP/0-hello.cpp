#include <iostream>
using namespace std;
int main()
{
    char s[10],*p;
    p=s;
    cin >> s;
    cout << "hello," << p << "!\n";
    cout << __cplusplus << endl;
    std::cout << __GNUC__ << std::endl;
    cout << __VERSION__ << endl;
}