#include<iostream>
using namespace std;
class Person {
	friend ostream& operator<<(ostream& cout, Person& p);
public:
	void setA(int num) {
		A = num;
	}
	void setB(int num) {
		B = num;
	}
private:
	int A;
	int B;
};
ostream &operator<<(ostream &cout, Person &p) {//operator<<(cout,p)=cout<<p
	cout << p.A << p.B;
	return cout;
}
void test01() {
	Person p;
	p.setA(10);
	p.setB(10);
	cout << p << endl;//想要endl 需要返回cout  返回类型是 ostream &
}
void main() {
	test01();
	return;
}
