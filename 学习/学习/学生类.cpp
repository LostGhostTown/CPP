#include<iostream>
using namespace std;
#include<string>
class Student {
public:
	//类中的属性和行为 都称为成员
	//属性   成员属性 成员变量
	string Name;
	int Id;

	//行为   成员函数  成员方法
	void showStudent() {
		cout << Name << " " << Id << endl;
	}
	//可以在行为中赋值
	void setName(string name) {
		Name = name;
	}
};
int main() {
	Student s1;//实例化
	s1.Name = "张三";
	s1.Id = 1;
	s1.showStudent();

	Student s2;
	s2.setName("李四");
	s2.Id = 2;
	s2.showStudent();
	return 0;
}