#include <iostream>
using namespace std;
class Student
{
public:
    Student(int name1, int stu_no1, float score1);
    // Student(char *name1, char *stu_no1, float score1);
    ~Student();
    void modify(float score1);
    void disp();

private:
    int name;
    int stu_no;
    // char *name;
    // char *stu_no;
    float score;
};