#include"boss.h"
Boss::Boss(int id, string name, int did) {
	this->ID = id;
	this->Name = name;
	this->DeptID = did;
}
void Boss::showInfo() {
	cout << "职工编号：" << this->ID
		<< "\t职工姓名：" << this->Name
		<< "\t岗位：" << this->getDeptID() << endl;
}
string Boss::getDeptID() {
	return string("老板");
}