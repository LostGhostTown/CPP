#include<iostream>
using namespace std;
class Person {
public:
	int A;
	int B;
	/*Person operator+(Person& p) {//成员函数实现
		Person temp;
		temp.A = this->A + p.A;
		temp.B = this->B + p.B;
		return temp;
	}*/
};
Person operator+(Person& p1, Person& p2) {//全局函数实现
	Person temp;
	temp.A = p1.A + p2.A;
	temp.B = p1.B + p2.B;
	return temp;
}
Person operator+(Person &p, int num) {//不同的需求不同的重载实现
	Person temp;
	
	temp.A = num + p.A;
	temp.B = num + p.B;
	
	return temp;
}

void main() {
	Person p1;
	p1.A = 10;
	p1.B = 10;
	Person p2;
	p2.A = 5;
	p2.B = 5;
	Person p3;
	p3 = p1 + p2;
	cout << p3.A << p3.B << endl;
	Person p4 = p1 + 10;
	cout << p4.A << p4.B << endl;
	return;
}