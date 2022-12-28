#include <iostream>
using namespace std;
class Person {
	
public:
	Person(int age) {
		this->age = new int(age);
	}
	~Person(){
		if (age != NULL) {
			delete age;
			age = NULL;
		}
}
	Person &operator= (Person& p) {
		if (age != NULL) {//先释放原来的数据 如果有
			delete age;
			age = NULL;
		}
		age = new int(*p.age);
		return *this;//为了连=
	}
	int* age;
	
};
void test01() {
	Person p1(15);
	cout << *p1.age << endl;
	Person p2(12);
	cout << *p2.age << endl;
	p2 = p1;
	cout << *p2.age << endl;
	Person p3(30);
	p3 = p2 = p1;
	cout << *p3.age << endl;
}
void main() {
	test01();
	int a = 10;
	int b = 20;
	int c = 30;
	c = b = a;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	return;
}