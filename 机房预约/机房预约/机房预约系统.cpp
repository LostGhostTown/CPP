#include<iostream>
#include"identity.h"
#include<fstream>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
using namespace std;
void managerMenu(Identity*& manager);
void studentMenu(Identity*& student);
void teacherMenu(Identity*& teacher);
void LoginIn(string filename, int type) {
	Identity* person = NULL;
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string password;

	if (type == 1) {//学生
		int fId;
		string fName, fPassword;
		cout << "请依次输入学号，用户名和密码" << endl;
		cin >> id;
		cin >> name;
		cin >> password;
		while (ifs >> fId && ifs >> fName && ifs >> fPassword) {//3个一组 会在没信息后停止。相当于遍历
			if (fId == id && fName == name && fPassword == password) {
				cout << "学生登入成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, password);
				studentMenu(person);
				return;
			}
		}
		cout << "信息错误" << endl;
	}
	else if (type == 2) {
		int fId;
		string fName, fPassword;
		cout << "请依次输入职工号，用户名和密码" << endl;
		cin >> id;
		cin >> name;
		cin >> password;
		while (ifs >> fId && ifs >> fName && ifs >> fPassword) {//3个一组 会在没信息后停止。相当于遍历
			if (fId == id && fName == name && fPassword == password) {
				cout << "教授登入成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, password);
				teacherMenu(person);
				return;
			}
		}
		cout << "信息错误" << endl;
	}
	else if (type == 3) {
		string fName, fPassword;
		cout << "请依次输入用户名和密码" << endl;
		cin >> name;
		cin >> password;
		while (ifs >> fName && ifs >> fPassword) {//3个一组 会在没信息后停止。相当于遍历
			if (fName == name && fPassword == password) {
				cout << "管理员登入成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, password);
				managerMenu(person);
				return;
			}
		}
		cout << "信息错误" << endl;
	}
	
		cout << "登入失败" << endl;
		system("pause");
		system("cls");
		return;
	

}
void managerMenu(Identity*& manager) {//这是个父类指针  传入的是子类 “*”是类型“&”是引用 
	while (true) {
		manager->openMenu();//只能调用父类成员
		Manager* man = (Manager*)manager;//将指针转为子类指针
		int s = 0;
		cin >> s;
		switch (s) {
		case 1:
			cout << "添加" << endl;
			man->addUser();
			break;
		case 2:
			cout << "查看" << endl;
			man->showUser();
			break;
		case 3:
			cout << "机房" << endl;
			man->ShowComputer();
			break;
		case 4:
			cout << "预约" << endl;
			man->cleanFile();
			break;
		default:
			cout << "再见" << endl;
			system("pause");
			system("cls");
			delete manager;
			return;
			break;
		}
	}
}
void studentMenu(Identity*& student) {
	while (true) {
		student->openMenu();//只能调用父类成员
		Student* stu = (Student*)student;//将指针转为子类指针
		int s = 0;
		cin >> s;
		switch (s) {
		case 1:
			cout << "申请" << endl;
			stu->applyOrder();
			break;
		case 2:
			cout << "查看" << endl;
			stu->showMyOrder();
			break;
		case 3:
			cout << "查看" << endl;
			stu->showAllOrder();
			break;
		case 4:
			cout << "取消" << endl;
			stu->cancelOrder();
			break;
		default:
			cout << "再见" << endl;
			system("pause");
			system("cls");
			delete student;
			return;
			break;
		}
	}
}
void teacherMenu(Identity*& teacher) {
	while (true) {
		teacher->openMenu();
		Teacher* tea = (Teacher*)teacher;
		int s = -1;
		cin >> s;
		switch (s) {
		case 1:
			cout << "查看" << endl;
			tea->showAllOrder();
			break;
		case 2:
			cout << "审核" << endl;
			tea->validOrder();
			break;
		default:
			delete teacher;
			cout << "再见" << endl;
			system("pause");
			system("cls");
			return;
			break;
		}
	}
}
void main() {
	int select = -1;
	while (true) {
		cout << "======================欢迎来到机房预约系统======================" << endl;
		cout << endl << "\t\t         请选择你的身份" << endl;
		cout << "\t\t--------------------------------\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|         1.学生代表           |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|         2.老    师           |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|         3.管 理 员           |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|         0.退    出           |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t--------------------------------\n";
		
		cin >> select;
		switch (select) {
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "再见" << endl;
			system("pause");
			return;
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return;
}