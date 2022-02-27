#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> obj;
    for (int i = 0; i < 5; i++)
    {
        obj.push_back(5 - i); // 添加
        cout << obj[i] << ",";
    }
    for (int i = 5; i < 10; i++)
    {
        obj.push_back(-1 * i); // 添加
        cout << obj[i] << ",";
    }

    obj.pop_back(); // 移除

    cout << "\n";

    for (int i = 0; i < obj.size(); i++)
    {
        cout << obj[i] << ",";
    }

    cout << "\n";

    sort(obj.begin(), obj.end()); // 从小到大
    for (int i = 0; i < obj.size(); i++)
    {
        cout << obj[i] << ",";
    }

    cout << endl;

    reverse(obj.begin(), obj.end()); // 反转数组(从大到小)
    for (int i = 0; i < obj.size(); i++)
    {
        cout << obj[i] << ",";
    }

    return 0;
}