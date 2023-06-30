#include"student.h"
Student::Student() {

}
Student::Student(int id, string name, string password) {
	this->id = id;
	this->name = name;
	this->password = password;
}
void Student::initcom() {
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	computer com;
	while (ifs >> com.id && ifs >> com.size) {
		vCom.push_back(com);
	}
	ifs.close();
}
void Student::openMenu() {
	cout << "======================欢迎" << this->name << "======================" << endl;
	cout << "--------------------------------\n";
	cout << "|                              |\n";
	cout << "|         1.申请预约           |\n";
	cout << "|                              |\n";
	cout << "|         2.查看预约           |\n";
	cout << "|                              |\n";
	cout << "|         3.查看排表           |\n";
	cout << "|                              |\n";
	cout << "|         4.取消预约           |\n";
	cout << "|                              |\n";
	cout << "|         0.注销登入           |\n";
	cout << "|                              |\n";
	cout << "--------------------------------\n";
}
void Student::applyOrder() {
	initcom();
	cout << "机房开放时间为周一至周五的早上10点至下午4点,每小时为一组" << endl;
	cout << "注意 时间请以24小时制输入整点" << endl;
	cout << "以下是机房信息:" << endl;
	for (int i = 0; i < vCom.size(); i++) {
		cout << vCom[i].id << "号机房容量：" << vCom[i].size << endl;
	}
	cout << "请依次输入申请日期，时间，机房编号：" << endl;
	OrderFile of;
	int id;
	int date;
	int time;
	while (true) {
		while (true) {
			cin >> date;
			if (date >= 1 && date <= 31)break;
			else cout << "输入有误" << endl;
		}


		while (true) {
			cin >> time;
			if (time >= 10 && time <= 15)break;
			else cout << "输入有误" << endl;
		}

		while (true) {
			cin >> id;
			if (id >= 1 && id <= 3)break;
			else cout << "输入有误" << endl;
		}
		if (of.check(to_string(date), to_string(time), to_string(id), to_string(this->id)))break;
		else cout << "重复预约或已预约,请重新输入" << endl;
	}
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " " << "time:" << time << " " << "id:" << id << " " << "stuid:" << this->id << " " << "state:" << 1 << endl;
	ofs.close();
	cout << "预约成功，审核中" << endl;
	system("pause");
	system("cls");
}
void Student::showMyOrder() {
	OrderFile of;
	if (of.size == 0) {
		cout << "无记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.size; i++) {
		if (to_string(this->id) == of.orderData[i]["stuid"]) {
			cout << "日期：" << of.orderData[i]["date"] << " 时间：" << of.orderData[i]["time"] << " 机房号：" << of.orderData[i]["id"] << " 状态为：";
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
	}
	system("pause");
	system("cls");
	
}
void Student::showAllOrder() {
	OrderFile of;
	if (of.size == 0) {
		cout << "无记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.size; i++) {
		cout << "日期：" << of.orderData[i]["date"] << " 时间：" << of.orderData[i]["time"] << " 机房号：" << of.orderData[i]["id"] <<"申请人学号："<<of.orderData[i]["stuid"]<< " 状态为：";
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
void Student::cancelOrder() {
	OrderFile of;
	if (of.size == 0) {
		cout << "无记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	int s = -1;
	for (int i = 0; i < of.size; i++) {
		if (to_string(this->id) == of.orderData[i]["stuid"]&&of.orderData[i]["state"]!="0") {
			cout << "查询到记录为： " << endl;
			cout << "日期：" << of.orderData[i]["date"] << " 时间：" << of.orderData[i]["time"] << " 机房号：" << of.orderData[i]["id"] << " 状态为：";
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
		cout << "是否取消这条预约" << endl << "1.是" << endl<< "2.否" << endl;
		cin >> s;
		if (s == 1) {
			of.orderData[i]["state"] = "0";
			of.update();
			cout << "已取消" << endl;
			break;
		}
		
	}
	cout << "没有找到更多记录" << endl;
	system("pause");
	system("cls");
}