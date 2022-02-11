#include <iostream>
#include <fstream>
using namespace std;
struct List
{
    char course[15];
    int score;
};

int main()
{
    // 文本文件写入
    ofstream fout1("testA.txt", ios::out);
    // ofstream fout("testA.txt"); // 与上等价
    if (!fout1)
    {
        cout << "Connot open this file.\n"
             << hex << 100;
        exit(1);
    }
    fout1 << "\"I am a student.\"";
    fout1.close();

    // 文本文件读取
    ifstream fin1("testA.txt", ios::in);
    // ifstream fin("testA.txt"); // 与上等价
    if (!fin1)
    {
        cout << "Cannot open this file.\n";
        exit(1);
    }

    char str[80];
    fin1.getline(str, 80);

    cout << str << endl;
    fin1.close();

    // 二进制文件写入
    ofstream fout2("testB.dat", ios::binary);
    if (!fout2)
    {
        cout << "Connot open this file.\n";
        exit(1);
    }
    char ch = 'a';
    for (int i = 0; i < 26; i++)
    {
        fout2.put(ch);
        ch++;
    }
    fout2.close();

    // 二进制文件读取
    ifstream fin2("testB.dat", ios::binary);
    if (!fin2)
    {
        cout << "Cannot open this file.\n";
        exit(1);
    }
    while (fin2.get(ch))
        cout << ch;

    fin2.close();

    cout << "\n---用 read 函数和 write 函数读写二进制文件---" << endl;

    // 数据块二进制写入
    List lis[3] = {"Computer", 90, "Mathematics", 80, "English", 84}, l1;
    ofstream out("testC.dat", ios::binary);
    if (!out)
    {
        cout << "Connot open output file.\n";
        abort(); // 推出程序,作用与 exit 相同
    }
    for (int i = 0; i < 2; i++)
    {
        out.write((char *)&lis[i], sizeof(lis[i]));
    }
    out.close();

    // 数据块二进制读取
    ifstream in("testC.dat", ios::binary);
    if (!in)
    {
        cout << "Connot open input file.\n";
        abort();
    }
    for (int i = 0; i < 3; i++)
    {
        in.read((char *)&lis[i], sizeof(lis[i]));
        cout << lis[i].course << "," << lis[i].score << endl;
    }
    in.close();

    cout << "---随机访问二进制文件---" << endl;
    fstream fst("testC.dat", ios::out | ios::in | ios::binary); // ios::out 会清除原有数据
    if (!fst)
    {
        cout << "open testC.dat error!" << endl;
        abort();
    }
    for (int i = 0; i < 3; i++) // 重新写入
    {
        fst.write((char *)&lis[i], sizeof(lis[i]));
    }

    fst.seekp(sizeof(List) * 2); // 将文件指针定位到第三门课程
    fst.read((char *)&l1, sizeof(List));
    cout << l1.course << "," << l1.score << endl;

    fst.seekp(0); // 将文件指针定位到第一门课程
    fst.read((char *)&l1, sizeof(List));
    cout << l1.course << "," << l1.score << endl;

    fst.close();
}