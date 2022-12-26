#include<iostream>
using namespace std;
//通过实例化类 创建了一个对象cl
//2*π*半径
const double PI = 3.14;
class Circle {
	//访问权限
public://公共权限
	//属性
	int m_r;//半径
	//行为
	double calculate() {
		return 2 * PI * m_r;
	}
};
int main() {
	Circle cl;
	cl.m_r = 10; 
	cout << cl.calculate() << endl;
	system("pause");
	return 0;
}