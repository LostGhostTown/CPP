#include<iostream>
using namespace std;
#include<string>
//例1
class myPrint {//打印字符串
public:
	void operator()(string string) {//调用运算符只需要符合自己的需要来写
		cout << string << endl;
	}
	string mystring;
};
void test01() {
	myPrint myprint;
	myprint("hello");
}

//例2
class myAdd {
public:
	int operator()(int num1,int num2) {
		return num1 + num2;
	}
};
void test02() {
	myAdd myadd;
	int ret = myadd(100, 80);
	cout << ret << endl;
}
int main() {
	test01();
	test02();
	return 0;
}