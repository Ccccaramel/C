#include <iostream>
#include <string>
using namespace std;
int main()
{
	/*src为源字符串即要操作的字符串，dest为目标字符串，存放操作结果*/
	string str, dest;             
	getline(cin, str);            /*从输入中读取一行赋值给str*/
	for (auto c : str)            /*对str中的每个字符*/
	{
		if (!ispunct(c))           /*如果该字符不是标点符号*/
		{
			dest.push_back(c);     /*把该字符尾插到dest中*/
		}
	}
	cout << dest << endl;          /*输出dest中的内容*/
	system("pause");
	return 0;
}