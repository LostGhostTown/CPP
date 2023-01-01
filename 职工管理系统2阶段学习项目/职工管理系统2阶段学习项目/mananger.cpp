#include"mananger.h"
Manager::Manager(int id, string name, int did) {
	this->ID = id;
	this->Name = name;
	this->DeptID = did;
}
void Manager::showInfo() {
	cout << "职工编号：" << this->ID
		<< "\t职工姓名：" << this->Name
		<< "\t岗位：" << this->getDeptID() << endl;
}
string Manager::getDeptID() {
	return string("经理");
}