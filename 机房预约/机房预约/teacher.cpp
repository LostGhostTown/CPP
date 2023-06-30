#include"teacher.h"
Teacher::Teacher() {

}
Teacher::Teacher(int id, string name, string password) {
	this->id = id;
	this->name = name;
	this->password = password;
}

void Teacher::openMenu(){
	cout << "======================欢迎" << this->name << "======================" << endl;
	cout << "--------------------------------\n";
	cout << "|                              |\n";
	cout << "|         1.查看预约           |\n";
	cout << "|                              |\n";
	cout << "|         2.审核预约           |\n";
	cout << "|                              |\n";
	cout << "|         0.注销登入           |\n";
	cout << "|                              |\n";
	cout << "--------------------------------\n";
}
void Teacher::showAllOrder() {
	OrderFile of;
	if (of.size == 0) {
		cout << "无记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.size; i++) {
		cout << "日期：" << of.orderData[i]["date"] << " 时间：" << of.orderData[i]["time"] << " 机房号：" << of.orderData[i]["id"] << "申请人学号：" << of.orderData[i]["stuid"] << " 状态为：";
		string state;
		if (of.orderData[i]["state"] == "1") {
			state = "审核中";
		}
		if (of.orderData[i]["state"] == "2") {
			state = "成功";
		}
		if (of.orderData[i]["state"] == "-1") {
			state = "失败";
		}
		if (of.orderData[i]["state"] == "0") {
			state = "已取消";
		}
		cout << state << endl;

	}
	system("pause");
	system("cls");
}
void Teacher::validOrder() {
	OrderFile of;
	if (of.size == 0) {
		cout << "无记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	int s = -1;
	for (int i = 0; i < of.size; i++) {
		if (of.orderData[i]["state"] == "1") {
			cout << "查询到记录为： " << endl;
			cout << "日期：" << of.orderData[i]["date"] << " 时间：" << of.orderData[i]["time"] << " 机房号：" << of.orderData[i]["id"] << endl;
		}
		cout << "是否同意这条预约" << endl << "1.是" << endl << "2.否" << endl;
		cin >> s;
		if (s == 1) {
			of.orderData[i]["state"] = "2";
			of.update();
			cout << "已审核" << endl;
			
		}
		else {
			of.orderData[i]["state"] = "-1";
			of.update();
			cout << "已拒绝" << endl;
			
		}

	}
	cout << "没有找到更多记录" << endl;
	system("pause");
	system("cls");
}