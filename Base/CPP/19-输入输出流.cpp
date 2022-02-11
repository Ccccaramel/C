#include <iostream>
using namespace std;
int main()
{
    cout << "---put---" << endl;
    cout.put('A');
    cout.put('\n');
    cout.put(65), cout.put('\n'), cout.put(20 + 45);

    cout << "---getline---" << endl;
    char line[20];
    cout << "输入一行字符:";
    cin.getline(line, 20, 't');
    cout << line << endl;
    getchar(); // "抵消"输入 line 时最后的回车

    cout << "---ignore---" << endl;
    char str[20];

    cin.ignore(3, 't') >> str;
    cout << str << endl;
    getchar(); // "抵消"输入 str 时最后的回车

    cout << "再依次输入字符串:";
    cin.ignore() >> str; // 等价于 cin.ignore(1,EOF);
    cout << str << endl;
    getchar();

    cout << "---get---" << endl;
    char ch;
    cout << "Input:";
    while (cin.get(ch))
        cout.put(ch); // 试试仅仅输入 Ctrl+z

    return 0;
}