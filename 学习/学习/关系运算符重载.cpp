#include <iostream>
using namespace std;
class Person {
public:
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
	bool operator==(Person& p) {
		if (this->name == p.name && this->age == p.age) {
			return true;
		}
		return false;
	}
	bool operator!=(Person& p) {
		if (this->name == p.name && this->age == p.age) {
			return false;
		}
		return true;
	}
	string name;
	int age;
};
void test01(){
	Person p1("Tom", 18);
	Person p2("Tom", 18);
	Person p3("Jack", 18);
	Person p4("Tom", 18);
	if (p1 == p2) {
		cout << "p1和p2相等" << endl;
	}
	else {
		cout<< "p1和p2不相等" << endl;
	}
	if (p3 == p4) {
		cout << "p3和p4相等" << endl;
	}
	else {
		cout << "p3和p4不相等" << endl;
	}
	if (p1 != p2) {
		cout << "p1和p2不相等" << endl;
	}
	else {
		cout << "p1和p2相等" << endl;
	}
	if (p3 != p4) {
		cout << "p3和p4不相等" << endl;
	}
	else {
		cout << "p3和p4相等" << endl;
	}
}
void main() {
	test01();
	return;
}