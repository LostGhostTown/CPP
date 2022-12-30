#include<iostream>
#include<string>
using namespace std;
class Calculator {//非多态计算器
public:
	int getResult(string oper) {
		if (oper == "+") {
			return num1 + num2;
		}
		else if (oper == "-") {
			return num1 - num2;
		}
		else if (oper == "*") {
			return num1 * num2;
		}
	}
	int num1, num2;
};
void test01() {
	Calculator c;
	c.num1 = 10;
	c.num2 = 10;
	cout << c.num1 << "+" << c.num2 << "=" << c.getResult("+") << endl;
	cout << c.num1 << "-" << c.num2 << "=" << c.getResult("-") << endl;
	cout << c.num1 << "*" << c.num2 << " = " << c.getResult("*") << endl;
}

class AbstractaCalculator {
public:
	virtual int getResult() {
		return 0;
	}
	int num1, num2;
};
class Add :public AbstractaCalculator {
public:
	int getResult(){
		return num1 + num2;
	}
};
class Sub :public AbstractaCalculator {
public:
	int getResult() {
		return num1 - num2;
	}
};
class Mul :public AbstractaCalculator {
public:
	int getResult() {
		return num1 * num2;
	}
};
void test02() {
	AbstractaCalculator* m;
	m = new Add;//使用指针使用多态
	m->num1 = 10;
	m->num2 = 10;
	cout << m->num1 << "+" << m->num2 << "=" << m->getResult() << endl;
	delete m;
}
int Cal(AbstractaCalculator &cal) {//使用引用使用多态
	int ret;
	ret = cal.getResult();
	return ret;
}
void test03() {
	int ret;
	Sub s;
	s.num1 = 10;
	s.num2 = 10;
	ret = Cal(s);
	cout << s.num1 << "-" << s.num2 << "=" << ret << endl;
}
int main() {
	test01();
	test02();
	test03();
	return 0;
}