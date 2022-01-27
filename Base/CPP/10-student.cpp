#include <string.h>
#include "10-student.h"
// Student::Student(char *name1, char *stu_no1, float score1)
// {

//     this->name = new char[strlen(name1) + 1];
//     strcpy(this->name, name1);
//     this->stu_no = new char[strlen(stu_no1) + 1];
//     strcpy(this->stu_no, stu_no1);
//     this->score = score1;
// }
Student::Student(int name1, int stu_no1, float score1)
{

    this->name = name1;
    this->stu_no = stu_no1;
    this->score = score1;
}
Student::~Student()
{
    cout <<"run ~Student()" << endl;
}
void Student::modify(float score1)
{
    this->score = score1;
}
void Student::disp()
{
    cout << "student:" << this->name << "," << this->stu_no << "," << this->score << endl;
}
