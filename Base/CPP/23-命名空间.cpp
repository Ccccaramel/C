#include <iostream>
namespace University
{
    int grade = 3;
}
namespace Highschool
{
    int grade = 4;
}
int main()
{
    std::cout << "The university's grade is:" << University::grade << std::endl;
    std::cout << "The highschool's grade is:" << Highschool::grade << std::endl;
}