#include<iostream>
using namespace std;
/*对于整型
* short占用2个字节 最大值32768
* int&long占用4个字节   最大值2,147,483,648
* long long占用8个字节
* 
* 对于递增和递减
* a=10
* cout<<++a =11
* cout<<a=11
* 
* cout<<a++=10
* cout<<a=11
*/
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
也可以使用静态变量 static 将函数中的变量返回  可以让函数中定义的静态变量只定义一次而不会在多次调用中反复定义

使用指针可以节约内存

默认参数
 可以在函数定义中直接给参数定义一个值，如果调用时没有数自动使用定义的值
 如果函数定义中使用默认参数，那从有默认参数的地方开始到最后必须都是默认参数
 声明和实现中只能有其中一项有默认参数

占位参数
 返回值类型 函数名（数据类型）{} 既没有变量名只有数据类型 
 调用时一定要传递一个相应的值 
 可以加默认参数

 函数重载
 在函数名相同的情况下，参数不同。
使用引用时
void func(int &a)
void func(const int &a)
func(10)
 10在int&a是不合法的 所以会调用第二个函数
使用默认参数时
如果不同的参数只有默认参数时可能发生混淆
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
* 
* *p=&a
* 在a也是指针的情况下  p和a都是指针  指向同一个值
* 在参数中（type *& point)//既在函数中以point指代传入的指针
* 
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
/*常量用const修饰 
* 不可以修改
* 静态变量用 static修饰
* 静态变量由全局修改*/
/* new可以把值从函数返回到全局
* new是把值存到堆区
* 例如 new int(10)
* int *p=new int(10);new返回的是地址   接受也要指针  注意数据类型一致
* return p; 
* 类似于全局变量但我可以操作的只是地址
* 使用delete 释放内存
* delete p;
* new int[10] 创建一个有10个元素的数组并返回地址 
* 用 int*arr接收  注意数据类型
* 用delete[] arr 释放 要加“[]”
* 最好在delete后加一个 指针=NULL;*/ 
/*引用
* 引用=指针常量
* 引用在初始化后不可以更改
* 
* 数据类型 &别名=原名
* int a=10
* int &b=a
* 别名=原名
* b和a都是int变量 操作同一个值
* 把引用用在函数中 和使用指针进行地址传递产生的效果一致
* 例int func(int &a){a = 10}
* 如果想要防止这个a被修改 可以改成 const int &a
* 
* 如果把函数引用例如 int& func(){return a;}
* 等同于返回的是a的地址
* 用 int &b=func()来接收  注意变量格式一致
* 这时的函数可以作为左值 例如 func()=1000 运行后a会等于1000 所以b也会是1000   a和b都指向同一个地址
* 只有在需要函数作为左值时才使用这个“引用函数”
* 
* 常量引用
* int &ref=10是不行的
* const int & ref=10是可以的
* =int temp//一个随机的变量名 = 10; int &ref = temp;
* 这个ref是不可修改的*/
/*对象 和类
* 所以事物都是对象
* 具有相同性质的对象在一起就是类
* 当一个对象是另一个类的成员时 称为对象成员
* 会先构造被包含的类再构造包含类 并先析构包含类再析构被包含类
* 例 class A{}
* class B{A a;}
* A先构造B再构造 B先析构A再析构
* 
* 尽量在函数中调用类  而不是main
* 
* 面向对象的编程指 封装 继承和多态
*/
/*封装
* 每个对象都有属性和行为并施加一些限制
* class 类名{访问权限：属性/行为}
* 属性是 成员变量
* 行为是 成员函数
*  权限
* public 公共权限
*  成员 类内可以访问 类外也可以访问
* protected 保护权限
*  成员 类内可以访问 类外不可以访问 子类可以访问
* private 私有权限
*  成员 类内可以访问 类外不可以访问 子类不可以访问
* 一个类中可以有多个权限
* 
* 静态成员变量 
* 前加 static
* 作用是 所以对象共享一份数据 共同读写
* 这个变量必须在类外初始化
* 可以使用 类名::静态变量名 进行访问
* 
* 
* class 类似 struct
* class默认私有  struct默认公共
* 
* class 权限设置
* 例 class Person{
public:
//需要让名字可读可写  年龄只读   爱人 只写
void setName(string name){
name=name;
}
string getName(){
return name;
}
string getAge(){
return name;
}
void setLover(string name){
name=name;
}
private:
string name
int age
string lover
}
先将变量私有
这样可以具体规划权限

初始化列表语法：类 （变量类型 变量名,变量类型 变量名,……）：变量类型 变量名,变量类型 变量名,……
类似于构造函数，就是在类中进行初始化。

静态成员函数
在成员函数前加 static
静态成员函数只能访问静态成员变量
能使用 类名::静态函数名(); 调用

const可以修饰成员函数
称为常函数
语法： 返回类型 函数名（……）const{}

这个函数不能修改成员属性
当成员属性被mutable修饰后 在常函数可以修改
语法 mutable 变量类型 变量名;

常对象只能调用常函数
不能修改成员属性 只能修改mutable修饰的成员属性
语法 const 类名 变量名;

*/
/*构造和析构函数
* 用于初始化和清理
* 构造函数 用于赋值
* 析构函数 用于销毁和清理
* 
* 构造函数
* 类名（）{}
* 没有返回值
* 可以有参数
* 使用 类名 变量名;调用无参构造函数
* 使用 类名 变量名（参数）; 调用有参构造函数
* 显示法
* 类名 变量名=类名（参数）;
* 隐试转化法
* 类名 变量名=参数；
* 
* 拷贝构造函数
* 类名（const 类名 &变量名）{}
* 复制一份
* 使用 类名 变量名（一个已经初始化的同类变量名）：调用拷贝函数
* 系统默认的拷贝函数都是浅拷贝
* 浅拷贝会导致堆区的内存重复释放
* 如果要使用深拷贝需要用new 变量类型（变量名(值)）在堆区创建一个值并返回地址  （new需要用指针接收返回）必须的**
* 在拷贝构造函数中使用new进行拷贝
* 如果使用了深拷贝 需要在析构函数中销毁 用delete
* 
* 析构函数
* ~类名（）{}
* 没有返回值
* 不可以有参数
*
* 类外定义内部函数可以使用 类名::函数名(){}  类内需要有声明*/
/*
* this 指针指向被调用的成员所属的对象
* 可以用来区分名称重复
* 可以使用 return *this 返回对象本身
* 需要使用时 使用引用就是数据继承的 函数需要是 类名& 函数名(……
* 使用数据形式 类名 函数名(……  就是创建一个新数据 新数据只在函数中有效  最后的值会有区别
*/
/*空指针是可以调用成员函数的
* 但涉及到变量时会报错
* 可以在成员函数中加一个
* if(this ==NULL){return;}
* 来阻止报错*/
/*友元
* 用来访问私有的成员变量或者成员函数
* 全局函数  类  成员函数 可以做友元
* 
* 全局函数友元
* 将函数前加 friend 并在类的开头声明（权限前）
* 
* 类友元
* 在类中加一个需要访问的类的指针的成员
* 并在构造函数中用new访问
* 访问构造函数(){
* 指针=new 被访问类名；}
* 在被访问的类中最前面（权限前）加一个声明 friend class 访问类名;
* 
* 成员函数友元
* 在类中加一个需要访问的类的指针的成员
* 并在构造函数中用new访问
* 在被访问的类中最前面（权限前）加一个声明 friend 返回类型 访问类名::函数名(……);*/
/*运算符重载
* 加法运算符重载“+” 为了自定义对类中数据的加法运算
* 左移运算符重载“<<” 为了自定义输出 为了和自带的<<同步 需要返回cout 
* 递增递减运算符重载“++/--” 为了对数据进行自定义递增或递减              //由于是类内部函数 左侧的不需要调用 
* 赋值运算符重载“=" 为了对类的数据复制 可以回避浅拷贝问题 //和拷贝构造不同的是 需要先判断左侧变量是否已经有数据，先释放
* 关系运算符重载“!=/==” 系统没办法对比 自定义这个对比
* 函数调用运算符重载“（）” 访函数
*/
/*继承
* 子类继承父类的共性 并且有自己的特点 作用是减少重复代码
* 语法
* class 子类名: 继承方式 父类名{}     //继承方式只规则 public、private、private  子类=派生类  父类=基类
* 需要继承多个父类用“,”分割
* 
* 父类的指针和引用可以直接指向子类对象 
* 
* 继承方式：
* class A{
public：
int a;
protected:
int b;
private:
int c; //private部分无论如何都不会被子类访问
}
class B：public A{
public:
int a
protected:
int b;
}//权限不变 访问不到C
class B：protected A{
protected:
int a
int b;
}//共用权限变成保护权限
class B：private A{
private:
int a
int b;
}//共用权限和保护权限变成私有权限
*
* 父类中的所以非静态成员属性都会被继承   静态是全局的不需要继承
* 父类先构造 子类先析构
* 
* 如果继承中有同名成员无论是否是静态，在子类中可以直接访问子类的成员  在子类中访问父类的同名成员需要前加一个“父类名::”
* 和参数是否有区别无关 只要是同名就必须用作用域：“父类名::”
* 
* 菱形继承/钻石继承
* 有两个子类继承同一个父类
* 又有一个子类同时继承前面的两个子类
* 这样会继承两份最初的父类信息  利用虚继承可以解决
* 在 两个子类继承第一个父类的时候 添加virtual关键字  
* class 子类名: virtual 继承规则 父类名{}
* 作用是将父类的成员变成虚基类指针来进行继承*/
/*多态
* 静态多态： 函数重载  运算符重载 编译阶段确定函数地址
* 动态多态： 派生类和虚函数 运行才确定函数地址
* 
* 让地址在运行阶段进行绑定  //地址晚绑定
* 在父类的同名函数中添加 virtual  则优先执行子类的同名函数
* 
* 动态多态怎么产生？
* 有继承关系
* 子类需要重写父类的虚函数//重写是返回类型，函数名和参数都一致 **
* 用父类的引用或指针 执行子类的对象 //有实例 多态计算器  // new 或者 &  父类名 * 变量名=new 子类名  
//或者是函数参数中用引用父类 并在调用函数时将子类传入
* 父类中是最终执行代码 子类是改变过程
* 
* 提倡扩展 不提倡修改
* 多态的优势就是扩展
* 
* 由于使用多态时 父类的 虚函数是不重要的  为了方便可以写纯虚函数 语法：
* virtual 返回类型 函数名（参数）=0;
* 整个类称为抽象类 无法进行实例化并且子类必须重写纯虚函数
* 
* 虚析构和纯虚析构
* 父类不会调用子类的虚构 程序无法析构子类属性开辟的堆区数据  所以需要使用虚析构来让子类析构代码被运行
* virtual ~类名（）{}//虚析构
* virtual~类名（）=0; //纯虚析构 在父类使用纯虚析构的时候需要在类外实现
*/
/*文件操作
* 头文件 #include<fstream>
* 
* 打开方式：
* ios::in //为读文件而打开文件
* ios::out //为写文件而打开文件
* iod::ate //初始位置：文件尾部
* ios::app  //追加方式写文件
* ios::trunc //如果文件存在先删除再创建一个新的
* ios::binary //二进制方式
* 
* 写文件
* 文本文件
* 语法:
* ofstream ofs; //创建流对象
* ofs.open("文件路径",打开方式); //打开文件   可以使用if(!ofs.is_open()) 来判断是否打开成功
* ofs<<"想写的数据";
* ofs.close; //关闭文件
* 二进制文件
* 语法：
* ofstream ofs; //创建流对象
* ofs.open("文件路径",打开方式|ios::binary);
* ofs.write((const char *)数据变量，数据大小) //写入文件 //可以使用class读取和写入
* ofs.close; //关闭文件
* 
* 读文件
* 文本文件
* 语法：
* ifstream ifs; //创建流对象
* ifs.open("文件路径",打开方式)://打开文件
* 
* char buf[1024]={0} //用char数组读数据
while(ifs>>buf){
cout<<buf<<endl;
}

* char buf[1024]={0} //用char数组读数据
while(ifs.getline(buf,sizeof(buf))){
cout<<buf<<endl;
}

* string buf;
while(getline(ifs,buf)){//用string读数据
cout<<buf<<endl;
}
* char c;//一个个字符读 而不是一行
while((c = ifs.get())!= EOF){// 判断是为了判断是否判断到文件尾  EOF= end of file
cout<<c
}//不推荐 速度慢
* 
* ifs.close();//关闭文件
* 
* 二进制文件
* 语法：
* ifstream ifs; //创建流对象
* ifs.open("文件路径",打开方式|ios::binary)://打开文件
* ifs.read((char*)&接收数据的变量名,数据大小);  //可以使用class读取和写入
* ifs.close();//关闭文件
* */
/*模板
* 语法：
* template<typename 模板名，……>
* 函数声明或定义
* 
* template<class 模板名，……>
* 函数声明或定义、类 //由于不确定成员的数据类型所以才使用
* 
* 调用
* 函数名或类名<参数类型，参数类型，……>变量名(参数，参数，……);
* 
* 在把模板类作为参数传入时语法：
* 返回类型 函数名（<类名<变量类型，……> & 类变量名）{} //<>中的参数类型能直接用 模板变量 代替 需要在一行写template
* 
*  相当于把模板名作为一个自定义的数据类型 作为具体数据类型的替代品 以减少编程量  //作用于多次使用同一种函数但数据类型不同
* 在一个函数内 T代替的数据类型只有一个  所以必须一致
* 模板必须要接受一个数据类型给模板名  不能为空
* 模板在被调用时才创建
* 
*  在重载的情况下
* 前加template<> 函数名（参数）来重载函数模板
* 普通函数比函数模板优先级高 
* 使用函数名<>（参数）能确定调用模板
* 如果参数在模板中更合适 会调用模板
* 当数据类型是class时（既数据类型是自定义时）可以使用具体的参数和代码来重载 编译器会优先调用
* 
* 在继承的情况下
* 如果父类是模板
* 子类需要声明父类的类型或者 子类也是模板
* 语法：
* class 子类名：继承类型 父类名<父类类型>
* 
* template<class T1,class T2>
* class son:public Base<T2>{T1 A;}//子类也是模板 通过T2获取父类的参数  通过T1自定义子类的参数
* 
* 构造函数类外实现语法：//类外很复杂 尽量类内
* 注意类外声明时类内类外一定要一致 如果类外需要template 类内需要在函数名后加"<>"
* template<class T1,class T2>
* 类名<T1,T2>：函数名（T1 变量名,T2 变量名){}
* 
* 分文件编写
* 主程序直接包含.cpp而不是h 或者把声明和实现写到同一个文件中*/
/*STL 基本模板库
* 所有STL都要头文件
* 容器 算法和迭代器 仿函数 配接器 空间配置器
* 变量方法for_each(开头指针，结束指针，print函数)//不需要括号  函数有参数 用于打印
*/
/*iterator 一种迭代器 用于遍历容器
* 指示位置的时候需要用
* 容器名<数据类型>::iterator 变量名=指向的位置//变量是指针
* 例子:
* for（容器名<类型名>::iterator it=从哪开始比如.begin();it!=到哪结束比如.end();it++）//可以用于打印 cout<<*it<<endl;
* 
* 迭代器套迭代器
* for (map<string, string>::iterator mit = (*it).second.begin(); mit != it->second.end(); mit++) {、
* //(*it). == it->
*/
/* vector
* 需要头文件
* 语法：
* vector<变量类型>变量名;
* 
* pushback()//尾部插入
* 
* 访问：
* vector<数据类型>::iterator 变量名=vector变量名.begin();//变量指向第一个元素
* vector<数据类型>::iterator 变量名=vector变量名.end();//变量指向最后一个元素的下一个位置
* 
* vector可以嵌套vector*/
/*string
* 是一个容器一个类
* 注意下面是函数 调用用“.”
* 
* 构造函数
* string(const char* 变量名)//使用char*赋值
* string(const string& 变量名)//拷贝构造
* string(int n,char 变量名)//使用n个char变量初始化
* 赋值函数
* string& operator=（）//可以把char* char string 赋值给当前字符串
* string& assign（）//可以把char* char string 赋值给当前字符串
* string& assign（const char *变量名, int n）//将char*中的前n个字符 赋值给当前字符串
* string& assign（ int n，const char 变量名）//把n个char赋值给当前字符串
* 字符串拼接 在字符串后加其他字符串
* string& operator+=（）//char* char string添加到原本字符串之后
* string& append（）char* char string添加到原本字符串之后
* string& append（const char*变量名,int n）//把字符串的前n个字符拼接
* string& append（const char*变量名,int pos ,int n）//把字符串的从pos开始的前n个字符拼接
* 查找和替换函数
* int find（const string&变量名，int pos）const;//查找变量第一次出现的位置，从pos开始查找   变量可替换成char* char
* int rfind（const string&变量名，int pos）const;//查找变量最后一次出现的位置，从pos开始查找 变量可替换成char* char
* string& replace(int pos,int n,const char* 变量名)替换从pos开始的n个字符串变为变量  会保留完整的变量 而不是替换掉的位数
* 比较
* int conpare（const char*变量名）=返回0  >返回1  <返回-1
* 读写单个字符
* char& operator[]（int n）
* char& at(int n)
* 插入和删除
* string& insert(int pos,const char*s);在pos的位置插入
* string& erase(int pos,int n=npos)删除从pos开始的n个字符
* 截取
* string substr(int pos,int n=npos)const; 从pos开始截取几个字符；*/
/*vector
* 头文件
* vector=单端数组 类似于动态数组
* 将原因数据复制到一个更大的空间 并在后面添加数据
* .begin()指向第一个元素   .end()指向最后一个元素的后一个位置
* .rbegin()指向最后一个元素  .rend()指向第一个元素的前一个位置
* .push_back() .pop_back 增删
* .insert(const_iterator pos,变量)在迭代器指向的位置插入
* .erase(const_iterator pos)删除指向的元素
* =等于assign(等号右边的变量名.begin(),等号右边的变量名.end());
* empty()//是否为空
* capacity()//返回容量
* size()//返回元素个数
* resize(int num)//重新指定容器长度
* resize(int num,elem)//重新指定容器长度并用elem填充新增的位置
* .clear()//清空
* at()等于operator[]返回所指的数据
* front()返回第一个元素
* back()返回最后一个元素
* swap()互换所有元素
* reserve(int len)预留len个元素长度*/
/*deque
* 由中控器保存每一组数据的地址   每组数据的地址本身没有联系
* 双端数组 可对头尾进行插入和删除
* push_front();pop_front() 头部插入删除
* puch_back();pop_back()  尾部插入删除
* begin（）；end（） 指向头部和尾部后一位
* insert(pos,elem);insert(pos,n,elem);insert(pos,begin(),end())//在pos位置插入1个或多个elem  将beg到end部分赋值到pos位置
* erase(begin(),end())删除区间并返回下一个数据的位置 erase(const_iterator pos)删除pos位置并返回下一个数据的位置  clear()清楚
* 构造
* deque<t>变量名；
* deque(begin,end)拷贝
* deque(n.elem)拷贝n个elem
* deque(const deque&deq)
* 赋值
* deque& operator=（const deque&deq）
* assign(begin,end);assign(n,elem)
* 大小
* .empty() 是否为空
* .size()元素个数
* .resize(num);resize(num,elem)；改变大小并填充
* 返回
* .at(int idx)返回idx所指的元素
* operator[]返回所指元素
* .front（）；.back（）返回第一个或最后一个元素
* 排序
* 需要头文件 algorithm
* sort(iterator beg,iterator end)
sort(.begin(),.end())
需要头文件 algorithm  全局函数 不需要“.”
在beg和end之间进行排序 从小到大*/
/*stack
* 栈容器
* 没有遍历只能访问顶端数据
* 先进后出  //数据按顺序反向记录
* .push();.pop()
* .top()//访问顶端数据
* .empty()//返回是否为空
* .size()//返回元素个数
* 构造函数
* stack<T> stk;//或者 stack<数据类型> 变量名;
* stack(const stack &stk)拷贝构造
* 赋值用 =号*/
/*queue
* 队列容器
* 先进先出
* push();pop();
* back();front()
* //没有遍历只能访问对头和队尾
* back端只接受push   front端只接受pop
* 构造函数
* queue<T> stk;//或者 stack<数据类型> 变量名;
* queue(const stack &stk)//拷贝构造
* 赋值用 =号
* .empty()//返回是否为空
* .size()//返回元素个数*/
/*list
* 链表
* 数据储存不连续 由一系列节点组成
* 每一个节点都储存前后两个节点的地址
* 方便插入删除并且不会有浪费但速度慢且占用大
* 最后一个结点的后一个指向第一个；第一个结点的前一个指向最后一个结点
* 构造
* list<T> 变量名//或者list<变量类型>变量名
* list（n,elem);list(const list&变量名);list(begin(),end());
* 赋值
* assign(begin(),end())
* assign(n,elem)
* 用等号
* .swap（）//交换
* 
* .empty()//返回是否为空
* .size()//返回元素个数
* resize(num);resize(num,elem)；改变大小并填充
* 插入删除
* push_front();pop_front() 头部插入删除
* puch_back();pop_back()  尾部插入删除
* insert(pos,elem);insert(pos,n,elem);insert(pos,begin(),end())//在pos位置插入1个或多个elem  将beg到end部分赋值到pos位置
* erase(begin(),end())删除区间并返回下一个数据的位置 erase(const_iterator pos)删除pos位置并返回下一个数据的位置  clear()清楚
* remove(elem)删除容器中所以等于elem的元素
* 
* front（）；back（）返回第一个或最后一个元素
* 
* reverse()反转链表首尾对调
* .sort()排序 从小到大*/
/*set/multiset
* 集合容器
* 所有元素会自动被排序 从小到大
* set不允许重复元素  multiset允许重复元素
* set插入时会返回是否成功
* pair<set<变量类型>::iterator,bool>变量名=s.insert(数据)
* if(ret.second){插入成功}else{插入失败}// bool返回是否成功
* 构造赋值
* set<变量类型>变量名； set(const set &变量名)
* =直接赋值
* .swap（）//交换
* 
* .empty()//返回是否为空
* .size()//返回元素个数
* 插入删除
* insert(elem);
* erase(begin(),end())删除区间并返回下一个数据的位置 erase(const_iterator pos)删除pos位置并返回下一个数据的位置  clear()清楚
* erase(elem)//删除容器中值为elem的元素
* 查找和统计
* find（elem)//查找是否存在返回位置  若不存在返回.end()
* count(elem)//统计elem的元素个数
* 
* 让set从大到小打印
* 在构造时 使用仿函数
* class MyCompare{
public:
bool operator()(数据类型 v1,数据类型 v2){//比如int
		return v1>v2
	}
}
set<数据类型,MyCompare>变量名;

当set的数据是自定义的时候 //既class
我们必须指定排序规则
需要用类似的仿函数*/
/*pair
* 对组
* 创建对组变量：
* pair<数据类型，数据类型>变量名(初始值，初始值)
* pair<数据类型，数据类型>变量名=make_pair(初始值，初始值)
* 用变量名.first &  变量名.second 调用数据*/
/*map/multimap
* map中所有元素都是pair
* 第一个元素是key键值  第二个元素为value 实值
* 元素会根据key排序
* 可以快速使用key值找到value
* map不允许重复key  multimap允许重复key
* 构造赋值
* map<键值变量类型，实值变量类型>变量名；
* map(const map &变量名)
* 使用=赋值
* .swap（）//交换
* 
* .empty()//返回是否为空
* .size()//返回元素个数
* .insert(map<键值变量类型，实值变量类型>::value_type(参数,参数));
* .insert(pair<键值变量类型，实值变量类型>（参数，参数）)//插入
* .insert(make_pair(参数，参数))
* erase(begin(),end())删除区间并返回下一个数据的位置 erase(const_iterator pos)删除pos位置并返回下一个数据的位置  clear()清楚
* erase(key)//删除容器中键值为key的元素
* 查找统计
* find(key);cout(key);//按照key查找和统计
* 排序
* 用仿函数修改规则
* class MyCompare{
public:
bool operator()(数据类型 v1,数据类型 v2){//比如int
		return v1>v2
	}
}
map<数据类型,数据类型,MyCompare>变量名;// 只需要修改key的比较方式*/
/*函数对象
* 重载函数调用操作符的类
* 就是仿函数
* 这是一个类 就是重载()
* 
* 在类中写一个成员函数
* 返回类型 operator()(参数，……){}
* 调用时直接 类名(参数，……);
* 
* 因为是类 所以内部可以保存一些自己的数据和状态  即有自己的成员和成员函数
* 
* 可以作为参数
* 
* 匿名函数对象 不创建直接使用
* 类名(参数)
* 
* 谓词
* 返回bool类型的仿函数称为谓词
* 通常用于自定义判断
* bool operator（）（参数）{
return 参数和什么比较之类的    既成立返回真  不成立返回假
}
* 
* STL自带的函数对象 有些是仿函数有些是谓词
* 头文件functional
* 
* 算术仿函数
* template<class T>T plus<T>      //加法
* template<class T>T minus<T>   //减法
* template<class T>T multiplies<T> //乘法
* template<class T>T divides<T>  //除法
* template<class T>T mpdulus<T>  //取模
* template<class T>T negate<T>   //取反
* 调用
*	函数名<参数类型>变量名
* 变量名(参数)
* 
* 关系仿函数
* template<class T>bool euqal_to<T>//等于
* template<class T>bool not_equal_tp<T> //不等于
* template<class T>bool greater<T> //大于
* template<class T>bool greater_equal<T> //大于等于
* template<class T>bool less<T> //小于
* template<class T>bool less_equal<T> //小于等于
* 调用
* 函数名<参数类型>()
* 
* 逻辑仿函数
* template<class T>bool logical_and<T>   //and
* template<class T>bool logical_or<T>   //or
* template<class T>bool logical_not<T>   //not
* 调用
* 函数名<参数类型>()*/
/*常用算法
* 头文件 algorithm numeric functional
* 
* 遍历算法  可用于打印
* for_each(iterator begin,iterator end, _func)// 开始迭代器  结束迭代器  函数或函数对象就是你的遍历要做什么
* 普通函数不需要(）  仿函数需要()
* 
* transform(iterator begin,iterator end,iterator beg2, _func)//用于搬运数据  原容器开始迭代器 原容器结束迭代器 目标容器开始迭代器   需要进行的运算比如逻辑运算 //可以直接返回数据
* 注意搬运时需要先开辟需要的空间
* 
* 查找算法
* find（iterator begin,iterator end, value)//开始迭代器 结束迭代器 需要找的元素
* find 会返回迭代器  返回元素位置或找不到返回end()
* 如果数据是自定义的既class  需要在类中重载operator==
* 
* find_if(iterator begin,iterator end, _pred）//开始迭代器 结束迭代器  谓词  既按照你的要求去找
* 会返回迭代器  返回元素位置或找不到返回end()
* 如果数据是自定义的既class  谓词部分的参数是（类名 &变量名）并自定义返回的需求  不需要在类中重载
* 
* adjacent_find(iterator beg,iterator end)
* 找到就返回第一个元素的迭代器  没找到返回end()
* 就是找有没有相邻的元素有没有一样的
* 
* binary_search(iterator begin,iterator end, value)
* 找到返回true 没找到返回false 
* 只能在有序序列中使用
* 如果是无序的序列 结果未知
* 
* count(iterator begin,iterator end, value)
* 统计元素value个数  返回int
* 如果数据是自定义的既class  需要在类中重载operator==
* 
* count_if(iterator begin,iterator end, _pred）
* 按条件统计元素个数  返回int
* 如果数据是自定义的既class  谓词部分的参数是（类名 &变量名）并自定义返回的需求  不需要在类中重载
* 
* 排序算法
* sort(iterator begin,iterator end, _pred）//第三个参数不填默认从小到大  或者自定义
* 
* random_shuffle(iterator begin,iterator end)//打乱数据 和随机一样是伪随机
* 需要种子 srand((unsigned int)time(NULL));//需要头文件ctime
* 
* merge(iterator beg1,iterator end1,iterator beg2, iterator end2,iterator dest);//容器1开始结束  容器2开始结束 目标容器开始迭代器
* 合并两个容器并储存到第三个容器里
* 两个容器必须是有序的 合并后他们也会是有序的
* 注意目标容器需要提前分配空间
* 
* reverse(iterator beg,iterator end)
* 反转范围内元素  前后对调
* 
* 拷贝和替换算法
* copy(iterator beg, iterator end,iterator dest)//将指定范围的元素拷贝到另一个容器  容器开始结束  目标容器开始迭代器
* 注意目标容器需要提前分配空间
* 
* replace(iterator beg, iterator end,oldvalue,newvalue);//容器开始结束 将范围内所有旧数据都替换成新数据
* 
* replace(iterator beg, iterator end,_pred,newvalue);//容器开始结束 将范围内所有满足谓词的数据都替换成新数据
* 
* swap（container1.container2);呼唤两个容器的元素  比如同种容器
* 
* 算术生成算法
* 头文件 numeric
* accumulate(iterator beg,iterator end, value)://计算区间内所以元素的总和  value是初始值既计算 总和 + value = 返回值
* 
* fill(iterator beg,iterator end, value)//将value无限次填充到区间内
* 
* 集合算法
* set_intersection(iterator beg1,iterator end1,iterator beg2, iterator end2,iterator dest);//容器1开始结束  容器2开始结束 目标容器开始迭代器
* 求两个容器的交集 //n  一样的部分
* 并放到目标容器中
* 目标容器要先分配空间
* 它会返回交集结束的位置 因为数量未知 它不一定能填充满目标容器 
* 所以遍历目标容器变成
* (.begin(),……iterator itend=set_intersection……)
* 
* set_union(iterator beg1,iterator end1,iterator beg2, iterator end2,iterator dest);//容器1开始结束  容器2开始结束 目标容器开始迭代器
* 求两个容器的并集//U 加起来不重复
* 并放到目标容器中
* 目标容器要先分配空间
* 两个集合必须是有序序列
* 它会返回并集结束的位置 因为数量未知 它不一定能填充满目标容器 
* 所以遍历目标容器变成
* (.begin(),……iterator itend=set_union……)
* 
* set_difference(iterator beg1,iterator end1,iterator beg2, iterator end2,iterator dest);//容器1开始结束  容器2开始结束 目标容器开始迭代器)
* 求两个集合的差集// 1容器和2容器中不同的部分
* 例子：容器1{1，2，3} 容器2{3，4,5}
* set_difference(容器1……容器2……）得出 {1,2}
*  set_difference(容器2……容器1……）得出 {4,5}
* 并放到目标容器中
* 目标容器要先分配空间
* 它会返回差集结束的位置 因为数量未知 它不一定能填充满目标容器 
* 所以遍历目标容器变成
* (.begin(),……iterator itend=set_difference……)*/