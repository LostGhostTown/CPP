#include<iostream>
using namespace std;
class MyInteger {
	friend ostream& operator<<(ostream& cout, MyInteger num);
public:
	MyInteger() {
		num = 0;
	}
	//前置++运算符
	MyInteger & operator++() {//需要自身 不然++myint变成了void类型
		++num;
		return *this;
	}
	//后置++运算符
	MyInteger operator++(int) {
		MyInteger temp = *this;
		num++;
		return temp;
	}
private:
	int num;
};
ostream& operator<<(ostream& cout, MyInteger num) {
	cout << num.num;
	return cout;
}
void test01() {
	MyInteger myint;
	cout << myint << endl;
	cout << ++myint << endl;
	cout << ++myint << endl;
	cout << myint++ << endl;
	cout << ++myint << endl;
}
void main() {
	test01();
	return;
}