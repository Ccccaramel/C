#include<stdio.h>
#include<string.h>
struct Student {
    char no[12];
    char name[12];
    int math;
    int english;
};
int main(){
    char no[12];
    char name[12];
    int math;
    int english;
    struct Student s[5];

    for(int i=0;i<5;i++){
        scanf("%s %s %d %d",&no,&name,&math,&english);
        strcpy(s[i].no,no);
        strcpy(s[i].name,name);
        s[i].math=math;
        s[i].english=english;
    }

    int average=0,score=0,maxScore=0;
    struct Student topStu;
    for(int i=0;i<5;i++){
        score=s[i].math+s[i].english;
        average+=score;
        if(score>=maxScore){
            topStu=s[i];
        }
    }
    average/=5;

    printf("平均分:%d\n",average);
    printf("总分最高的学生信息:%s,%s,%d,%d\n",topStu.no,topStu.name,topStu.math,topStu.english);
}