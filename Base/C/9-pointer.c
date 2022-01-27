#include <stdio.h>
#include <string.h>
/**
 * 指针
 *   内存存储器是用来存放程序和数据的装置
 *   其基本职能是正确存放和读取一个数据
 *   它由一系列存储单元构成
 *   每一个存储单元一般可存放一个字节的二进制数
 *   为了正确地访问这些内存单元
 *   必须为每个内存单元编上号
 *   内存单元的编号就叫作单元地址,即指针
 * 
 * & 运算符
 *   单目运算符,取出操作对象在内存单元的地址
 * 
 * * 运算符
 *   访问操作对象所指向的变量
 */
int main()
{
    int *i1;
    int i2 = 10;
    int i3;
    i1 = &i2;
    printf("i1=%d,&i1=%d\n", *i1, i1);
    printf("i2=%d,&i2=%d\n", i2, &i2);
    if (i3 == 0)
    {
        printf("i3=0\n");
    }
    else
    {
        printf("i3!=0\n");
    }

    // 数组与指针
    int i4[3] = {1, 2, 3};
    printf("i4[2]=%d\n", *(i4 + 2));
    printf("*i4=%d\n", *i4);
    printf("i4的地址:%d\n", &i4);
    printf("i4:%d\n", i4);

    // 指向二维数组的指针
    int i5[2][2] = {{1, 2}, {3, 4}};
    int *i6;
    i6 = i5[0] + 2; // 或 i6=&i5[0][0]+2
    printf("i5[0][1]=%d,i5[1][1]=%d,i6:%d\n", *(i5[0] + 1), *(i5[0] + 3), *i6);
    printf("i5[1][1]=%d\n", *(*(i5 + 1) + 1));
    printf("i5的地址:%d\n", *i5);
    printf("i5的地址:%d\n", &i5);
    printf("i5:%d\n", i5);

    // 指向行数组的指针变量
    int(*i7)[2];
    i7 = i5;
    printf("i7:%d\n", *(*(i7 + 1) + 1));

    // 字符串与指针
    /**
     * 字符'A'与字符串"A"在内存中的存储是不一样的
     * 前者只占用1个字节
     * 后者占用2个字节
     * C语言在存储字符串时规定在最后一个字符后附加存储一个空字符
     * 空字符指 ASCII 码值为 0 的字符,可用转义符表示为'\0'
     * 它不引起任何控制操作,也不是一个可显示的字符
     * 当然,'\0'字符不作为字符串的成员
     * 对于存储由n个字符构成的字符串,在内存中必须占用n+1个单元(字节)
     */
    char ch1[3] = {'1', '2', '\0'};
    char ch2[3] = {'1'};
    for (int i = 0; i < 3; i++)
    {
        if (ch2[i] == 0)
        {
            printf("NULL ");
        }
        printf("%c ", ch2[i]);
    }
    printf("\n");
    if (NULL == 0)
    {
        printf("0==NULL\n");
    }
    if ("" == NULL)
    {
        printf("\"\"==NULL\n");
    }
    if (" " == NULL)
    {
        printf("\" \"==NULL\n");
    }
    printf("\n");
    // 下列输出覆盖了 \0
    // 为了保证与字符串存储格式的一致性
    // 提倡至少留出一个数组元素用于存放'\0'
    char ch3[3] = {'\0'};
    // for(int i=0;i<2;i++){
    //     scanf("%c",&ch3[i]);
    // }
    // for(int i=0;i<3;i++){
    //     printf("%c",ch3[i]);
    // }
    // printf("\n");
    /**
     * 一次性输入输出
     *   注意数组越界问题
     *   即使输入的字符串长度大于数组定义的长度也能正常输出但不建议这么做
     */
    // scanf("%s",ch3);
    // printf("%s",ch3);
    char ch4[4] = "abc";
    puts(ch4);

    /**
     * 初始化未指定大小的字符数组其长度为字符串长度+1
     */
    char ch5[] = "123456";
    printf("ch5总空间大小:%d,ch5已占空间大小:%d\n", sizeof(ch5), strlen(ch5));
    printf("ch5:%s\n", ch5);

    /**
     * 指向字符串常量的指针变量
     * 
     * 系统先分配一块长度为字符串字符个数加上1('\o',即4)的连续内存空间
     * 以存储字符串"hi!"
     * 然后将连续内存空间的首地址赋给字指针 str1
     * 故 str1 的值是一个字符串常量的首地址,即指向该字符串的第一个字符
     * 
     * putchar(int char)
     *   把参数 char 指定的(无符号)字符写入到标准输出 stdout 中
     *   它每次只输出一个字符
     */
    char *str1;
    str1 = "hi!";
    printf("str1=%s\n", str1);
    printf("str1:");
    while (*str1)
    {
        putchar(str1[0]);
        str1++;
    }
    printf("\n");

    /**
     * 指向字符数组的指针变量
     */
    char arr3[] = "hello";
    char *s1;
    s1 = arr3;
    printf("%s\n", arr3);
    printf("%s\n", s1);
    s1 += 1;
    while (*s1)
    {
        putchar(s1[0]);
        s1++;
    }
    printf("\n");

    /**
     * gets(str)
     *   从键盘读入字符串直到读入换行符为止
     *   用 \0 代替换行符并把读入的字符串存入以 str 为首地址的存储区中
     * puts(str)
     *   把首地址为 str 的字符串显示在屏幕上,直到空字符但不包括空字符,输出时用'\n'代替'\0'
     * strcpy(str1,str3)
     *   把 str1 复制到 str3 中
     * strcmp(str1,str2)
     *   比较 str1 与 str2 的大小关系决定返回值
     *   比较规则:
     *     从第一个字符开始,依次比较两个字符串同一位置的一对字符
     *     通过 ASCII 码比较字符大小
     *     ASCII 码值大的字符所在的字符串较大
     *     若所有字符均相同则两字符串相等
     *     若一个字符串的长度m大于另一个字符串的长度n且前n个字符相同,则长度m的字符串大
     *    在 Turbo C 中返回的函数值是最后一次比较的两个字符的 ASCII 码值的差
     *    在 Visual C++ 中则是1,0或-1
     * strcat(str1,str2)
     *   把 str2 连接到 str1 末尾
     * strlen(str)
     *   字符个数
     * strlwr(str)
     *   将所有大写字母改为小写
     * strupr(str)
     *   将所有小写字母改为大写
     */
    char arr1[20], arr2[20] = "how\nare\nyou.";
    // gets(arr1);
    printf("arr1:");
    puts(arr1);
    printf("arr2:");
    puts(arr2);
    char arr5[4] = "hi.", arr4[6];
    strcpy(arr4, arr5); // 如果字符串大于数组空间则会导致内存越界!
    printf("***\n");
    puts(arr4);
    printf("strcmp(\"abc\",\"ac\")=%d\n", strcmp("abc", "ac"));
    char arr6[10] = "123", arr7[10] = "asd";
    printf("strcat(arr6,arr7)=%s\n", strcat(arr6, arr7));
    printf("strlen(arr6)=%d\n", strlen(arr6));
    char arr8[10] = "qWeR";
    strlwr(arr8);
    printf("arr8=%s\n", arr8);
    strupr(arr8);
    printf("arr9=%s\n", arr8);

    char s[80] = "qwe 123 []=\0", *p1, *p2;
    p1 = p2 = s;
    while (*p1)
    {
        if (*p1 == ' ')
            p1++;
        else
            *p2++ = *p1++;
    }
    *p2 = '\0';
    printf("%s\n", s);

    /**
     * 指针数组
     *   指向同一类型数据的指针变量构成的数组
     *   int pa[5]; // 表示定义一个由5个指针变量构成的指针数组
     *                 数组中每一个元素都是指向一个整数的指针
     *   int a[3][4]; // a[i]由a[i][0]~a[i][3]构成的一维数组名
     *                   是一个指向一维数组的指针,它是一个常量
     *                   可以通过pi[i]=a[i];语句赋值给pa[i](pa[i]是变量)
     *                   这样pa[i]+j便指向a[i][j],通过*(pa[i]+j)就可以间接访问a[i][j]
     */

    /**
     * 通过指针数组表示多个字符串
     *   节约内存
     *   处理更方便,各个字符串不必存放到连续的地址空间,有利于充分利用内存中的"碎片"
     */
    printf("指针数组\n");
    char *ps[6]={"FORTRAN","PASCAL","BASIC","COBOL","C","C++"};
    int i,j,k;
    for(i=0;i<6;i++){
        puts(ps[i]);
    }

    /**
     * 将多个字符串从小到大排序
     */
    printf("排序:\n");
    char *temp;
    for(i=0;i<5;i++){
        k=i;
        for(j=i+1;j<6;j++){
            if(strcmp(ps[k],ps[j])>0){
                k=j;
            }
        }
        if(k!=i){
            temp=ps[i];
            ps[i]=ps[k];
            ps[k]=temp;
        }
    }
    for(i=0;i<6;i++){
        puts(ps[i]);
    }

    /**
     * 指向指针的指针变量
     *   int a;
     *   我们可以定义一个指针变量 int *pa; 使之指向变量 a
     *   pa可称为一级指针
     *   假设定义一指针变量 ppa 使之指向一级指针变量 pa
     *   则 ppa 就是二级指针变量
     *   若有另一指针变量使之指向 ppa
     *   则称其为三级指针
     *   以此类推,二级以上的指针统称为多级指针
     */

    /**
     * 二级指针主要用于二维数组,指针数组,多字符串处理和函数参数传递等应用场合
     *   类型名 **指针变量名;
     */
    int a;
    int *pa;
    int **ppa;
    a=100;
    pa=&a;
    ppa=&pa;
    printf("%d,%u,%u\n",a,pa,ppa);
    printf("%d,%d,%d\n",a,*pa,**ppa);
    printf("%u,%u,%u\n",&a,pa,*ppa);

    // 二级指针与二维数组
    printf("二级指针与二维数组\n");
    int a1[3][4]={{0,1,2,3},{4,5,6,7},{8,9,3,6}};
    int *b1[3]={a1[0],a1[1],a1[2]};
    int **pa1 = b1;
    int *pa2 = a1;
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            printf("%d,%d,%d,%d,%d\n",a1[i][j],*(*(a1+i)+j),*(b1[i]+j),*(*(pa1+i)+j),*(pa2+i*4+j));
        }
    }

    // 使用二级指针引用字符串
    printf("使用二级指针引用字符串\n");
    int **pp;
    pp=ps;
    for(i=0;i<6;i++){
        puts(*pp++);
    }
}