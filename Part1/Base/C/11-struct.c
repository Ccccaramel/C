#include<stdio.h>
#include<stdlib.h>
struct Student {
    int number;
    struct {
        int year;
        int month;
        int day;
    }birthday;
    int age;
    char name[9];
};
struct Employee {
    int number;
    char *name;
};
void add(struct Student *s);
int main(){

    struct Student s1={1001,2001,10,11,3,"Tom"},*s2=&s1,s3,s4[2]={{1002,2002,12,12,2,"A"},{1004,2004,4,14,4,"B"}};
    struct Employee e1={2,"qqq"},e2;
    // s3={1002,2002,12,12,2,"Mark"}; 错误
    // scanf("%d %s",&s4[0].number,&s4[0].name);
    printf("s1:%d,%d\n",s1.number,s1.birthday.day);
    printf("s2:%d,%d\n",s2->age,s2->birthday.day);
    // printf("s4:%d,%s\n",s4[0].number,s4[0].name);
    printf("%d %s\n",e1.number,e1.name);
    e2.name=(char*)calloc(21,sizeof(char));
    scanf("%s",e2.name);
    printf("%s\n",e2.name);

    printf("***add***\n");
    add(s2);
    printf("age,s1:%d,s2:%d\n",s1.age,s2->age);
    add(&s1);
    printf("age,s1:%d,s2:%d\n",s1.age,s2->age);

}
void add(struct Student *s){
    s->age++;
}