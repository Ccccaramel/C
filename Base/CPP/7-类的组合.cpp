#include <iostream>
#include <string>
using namespace std;
class Score
{
public:
    Score(double c = 0, double e = 0, double m = 0);
    void show();

private:
    double computer, english, mathemaics;
};
Score::Score(double c, double e, double m)
{
    this->computer = c;
    this->english = e;
    this->mathemaics = m;
}
void Score::show()
{
    cout << "score:" << this->computer << "," << this->english << "," << this->mathemaics << endl;
}
class Student
{
public:
    Student(string n, double s1, double s2, double s3);
    void show();

private:
    string name;
    Score score;
};
Student::Student(string n, double s1, double s2, double s3) : score(s1, s2, s3)
{
    this->name = n;
}
void Student::show()
{
    cout << "student:" << this->name << endl;
    this->score.show();
}
int main()
{
    Student s1("Tim", 11, 22, 33);
    s1.show();
}