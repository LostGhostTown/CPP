#include"employee.h"
Employee::Employee(int id, string name, int did) {
	this->ID = id;
	this->Name = name;
	this->DeptID = did;
}
void Employee::showInfo() {
	cout << "职工编号：" << this->ID
		<< "\t职工姓名：" << this->Name
		<< "\t岗位：" << this->getDeptID() << endl;
}
string Employee::getDeptID() {
	return string("员工");
}