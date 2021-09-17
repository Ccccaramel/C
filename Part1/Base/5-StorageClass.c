#include<stdio.h>
/**
 * 存储类
 *   定义 C 程序中变量/函数的范围(可见性)和生命周期
 * 
 * auto
 *   局部变量默认的存储类
 * 
 * register
 *   定义存储在寄存器中而不是 RAM 中的局部变量
 *   这意味着变量的最大尺寸等于寄存器的大小(一个字)
 *   且不能对它应用一元的 & 运算符(因为它没有内存位置)
 *   寄存器只用于需要快速访问的变量,比如计数器
 *   此外,定义 register 并不意味着变量将被存储在寄存器中
 *   它意味着变量可能存储在寄存器中,这取决于硬件和实现的限制
 * 
 * static
 *   static 存储类指示编译器在程序的生命周期内保持局部变量的存在
 *   而不需要在每次进入和离开作用域时进行创建和销毁
 *   因此使用 static 修饰局部变量可以在函数调用之间保持局部变量的值
 *   static 修饰符也可以应用于全局变量
 *   当 static 修饰全局变量时,会使变量的作用域限制在声明它的文件内
 *   全局声明的一个 static 变量或方法可以被任何函数或方法调用
 *   只要这些方法出现在跟 static  变量或方法同一个文件中
 * 
 * extern
 *   用于提供一个全局变量的引用
 *   全局变量对所有的程序文件都是可见的
 *   当你使用 extern 时
 *   对于无法初始化的变量
 *   会把变量名指向一个之前定义过的存储位置
 *
 */
static int count = 10;
int add() {
    static int thingy  = -4;
    thingy ++;
}
int main() {
    int mount;
    auto int month;

    register int miles;

    while (count--) {
        printf("thingy:%d,count:%d\n", add(), count);
    }
}