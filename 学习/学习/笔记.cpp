#include<iostream>
using namespace std;
/*对于整型
* short占用2个字节 最大值32768
* int&long占用4个字节   最大值2,147,483,648
* long long占用8个字节*/
/*对于浮点型
* float 7位有效数字  需要在最后加f
* double 16位有效数字
* 默认输出6位有效数字
* 3e2=3*10^2
* 3e-2=3*0.1^2*/
/*对于转义字符
* \n 换行
* \t tab
* \\  输出 “\”*/
/*对于字符串
* 用string需要头文件<string>*/
/*if
* else if
* else*/
/*三目运算符
* 表达式1?表达式2:表达式3
* 等于 if(表达式1)表达式2;
* else 表达式3;
* a和b做比较 将变量大的值赋值给c
* c=(a>b?a:b);
* a和b做比较 将变量大的值变成100
* (a>b?a:b)=100*/
/*随机数 
#include <ctime>
srand((unsigned int)time(NULL)) 
rand()%100
生成随机数 范围0-99*/
/* continue
* 跳过本次循环并继续下一次循环*/
/*goto
* 跳转代码
* goto ThisWay;
* ……
* ThisWay:*/
/*数组
* sizeof(arr)/sizeof(arr[0]) 获取元素个数
*/
/*冒泡排序
* for(int i=0;i<数组的元素数-1;i++){
* for(int j=0;i<元素数-i-1;j++){
}
}*/
/*函数声明的作用是让main部分更简洁直接
定义可以放在后面

函数内的变量变动是独立的
除非用return或者指针

当函数的（）内是变量时 变量在函数内部修改
当函数的（）内是指针时 指针所对应的地址和值是全局修改

使用指针可以节约内存
*/
/*头文件的作用是让他简洁
* 调用 #include "头文件名"
* #include部分可以写在头文件中
*/
/*int *p, a;
* p= &a
* 将p指向变量a
* p储存a的地址
* 空指针 *p=NULL;
* 为了初始化
* 野指针 *p=(int *)0X1100 
* 直接指定一个内存地址
* 没用 避免它
* 常量指针：
* const int *p = &a
* 指针的指向可以改 但变量的值不能改
* 指针常量：
* int * const p = &a
* 指针的指向不可以改 但变量的值可以改
* const int * const p = &a 
* 都不能改*/
/*结构体
* 结构体等于自定义的数据类型、
* 结构体数组 struct NAME arr[]
* 值是变量用.访问  指针用->访问
* 通常使用const防止结构体的值被修改 例如函数（）中const struct Name */