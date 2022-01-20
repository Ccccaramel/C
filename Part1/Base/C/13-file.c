#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void fun1(FILE *fp, char ch, char str[128], char fileName[80])
{
    printf("---fputc与fgetc---\n");
    // 写 --- fputc
    if ((fp = fopen(fileName, "w")) == NULL)
    {
        printf("can not open this file.\n");
        exit(0);
    }
    printf("请输入文本,以\"*\"结尾:");
    for (int i = 0; (ch = getchar()) != '*'; i++)
    {
        printf("i=%d\n", i);
        printf("fputc:%d\n", fputc(ch, fp));
    }
    fclose(fp);
    // 读 --- fgetc
    if ((fp = fopen(fileName, "r")) == NULL)
    {
        printf("can not open this file.\n");
        exit(0);
    }
    for (; (ch = fgetc(fp)) != EOF;)
    {
        putchar(ch);
    }
    fclose(fp);
    printf("\n");
    getchar(); // 缓冲区还有一个回车字符,如果注销此行,那么该回车直接被43行获取
}
void fun2(FILE *fp, char ch, char str[128], char fileName[80])
{
    printf("---fputs与fgets---\n");
    // 写 --- fputs
    if ((fp = fopen(fileName, "w")) == NULL)
    {
        printf("can not open this file.\n");
        exit(0);
    }
    printf("请输入文本,以\"*\"单独为一行作表示结束:");
    for (; strcmp(gets(str), "*") != 0;)
    {
        printf("str:%s,out:%d\n", str, fputs(str, fp));
    }
    fclose(fp);
    // 读 --- fgets
    if ((fp = fopen(fileName, "r")) == NULL)
    {
        printf("can not open this file.\n");
        exit(0);
    }
    fgets(str, 128, fp);
    printf("Output the str:");
    puts(str);
    printf("str:%s\n", str);
    fclose(fp);
}
struct Student
{
    char name[16];
    int age;
} stu, stu1[2], stu2[2], *pp, *qq;
void fun3(FILE *fp, char ch, char str[128], char fileName[80])
{
    pp = stu1;
    qq = stu2;
    if ((fp = fopen(fileName, "wb+")) == NULL)
    {
        printf("can not open this file.\n");
        exit(0);
    }
    printf("input data:\n");
    for (int i = 0; i < 2; i++, pp++)
    {
        scanf("%s%d", pp->name, &pp->age);
    }
    pp = stu1;
    // 写 --- fwrite
    fwrite(pp, sizeof(struct Student), 2, fp); // 将数据写入文件
    rewind(fp);                                // 文件指针重新定位到文件头
    // 读 --- fread
    fread(qq, sizeof(struct Student), 2, fp); // 从文件中对取数据并赋值给变量
    printf("output data:\n");
    for (int i = 0; i < 2; i++, qq++)
    {
        printf("%s %d\n", qq->name, qq->age);
    }
    fclose(fp);
}
void fun4(FILE *fp, char ch, char str[128], char fileName[80])
{
    pp = stu1;
    qq = stu2;
    if ((fp = fopen(fileName, "wb+")) == NULL)
    {
        printf("can not open this file.\n");
        exit(0);
    }
    printf("input data:\n");
    for (int i = 0; i < 2; i++, pp++)
    {
        scanf("%s%d", pp->name, &pp->age); // 从键盘输入数据,存储到数组
    }
    pp = stu1;
    for (int i = 0; i < 2; i++, pp++)
    {
        fprintf(fp, "%s %d\n", pp->name, pp->age); // 把数组中的数据写入文件中
    }
    rewind(fp); // 文件指针重新定位到文件头
    for (int i = 0; i < 2; i++, qq++)
    {
        fscanf(fp, "%s%d\n", qq->name, &qq->age); // 从文件中读取数据存储到数组
    }
    qq = stu2;
    printf("output data:\n");
    for (int i = 0; i < 2; i++, qq++)
    {
        printf("%s^%d*\n", qq->name, qq->age); // 打印到控制台
    }
    fclose(fp);
}
void fun5(FILE *fp, char ch, char str[128], char fileName[80])
{
    if ((fp = fopen(fileName, "wb")) == NULL)
    {
        printf("can not open this file.\n");
        exit(0);
    }
    printf("Enter student number(1 to 5,0 to end input):");
    scanf("%d", &stu.age);
    while (stu.age != 0)
    {
        printf("Enter name:");
        scanf("%s", stu.name);
        fseek(fp, stu.age * sizeof(struct Student), 0); // 根据年龄确定写入哪一行
        fwrite(&stu, sizeof(struct Student), 1, fp); // 写入文件
        printf("Enter student age:");
        scanf("%d", &stu.age);
    }
    fclose(fp);

    int i=1;
    pp=&stu;
    if ((fp=fopen(fileName, "rb"))==NULL)
    {
        printf("can not open this file.\n");
        exit(0);
    }
    fseek(fp, 5*sizeof(struct Student), 0); // 定位到第5行
    fread(pp,sizeof(struct Student),1,fp); // 读取数据并存储到变量中
    printf("age:%d,name:%s\n",pp->age,pp->name);
}
int main()
{
    FILE *fp;
    char ch, str[128];
    char fileName[80] = "D:/GitHub/C/Part1/Base/C/C-13.txt";

    // fun1(fp, ch, str, fileName); // fputc与fgetc
    // fun2(fp, ch, str, fileName); // fputs与fgets
    // fun3(fp, ch,str,fileName); // fread与fwrite
    // fun4(fp, ch, str, fileName); // fscanf与fprintf
    fun5(fp, ch, str, fileName); // 文件的随机读写

    return 0;
}