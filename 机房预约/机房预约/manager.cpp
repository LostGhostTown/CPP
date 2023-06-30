#include"manager.h"
Manager::Manager() {

}
Manager::Manager(string name, string password) {
	this->name = name;
	this->password = password;
}
void Manager::openMenu() {
	cout << "======================欢迎"<<this->name<<"======================" << endl;
	cout << "--------------------------------\n";
	cout << "|                              |\n";
	cout << "|         1.添加账号           |\n";
	cout << "|                              |\n";
	cout << "|         2.查看账号           |\n";
	cout << "|                              |\n";
	cout << "|         3.查看机房           |\n";
	cout << "|                              |\n";
	cout << "|         4.清空预约           |\n";
	cout << "|                              |\n";
	cout << "|         0.注销登入           |\n";
	cout << "|                              |\n";
	cout << "--------------------------------\n";
}
void Manager::addUser() {
	this->initVecid();
	cout << "请输入添加账号的类型" << endl << "1.学生" << endl << "2.老师" << endl;
	string fileName;
	string tip;
	ofstream ofs;
	int s = -1;
	cin >> s;
	if (s == 1) {
		fileName = STUDENT_FILE;
		tip = "请输入学号";
	}
	else {
		fileName = TEACHER_FILE;
		tip = "请输入职工号";
	}
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string password;
	cout << tip << endl;
	while (true) {
		cin >> id;
		bool ret = checkRepeat(id, s);
		if (ret) {
			cout << "id重复" << endl;
		}
		else {
			break;
		}
	}
	cout << "请输入用户名密码" << endl;
	cin >> name;
	cin >> password;
	ofs << id << " " << name << " " << password << endl;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
	ofs.close();
	this->initVecid();
}

void printStudent(Student& s ) {
	cout << "学号:" << s.id << " 姓名：" << s.name << " 密码：" << s.password << endl;
}
void printTeacher(Teacher& s) {
	cout << "职工:" << s.id << " 姓名：" << s.name << " 密码：" << s.password << endl;
}
void Manager::showUser() {
	this->initVec();
	cout << "请选择你要查看的人员" << endl << "1.学生" << endl << "2.老师" << endl;
	int s = -1;
	cin >> s;
	if (s == 1) {
		cout << "学生信息如下" << endl;
		for_each(vStu.begin(), vStu.end(),printStudent);
	}
	else {
		cout << "教授信息如下" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}
void Manager::ShowComputer() {
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	computer c;
	while (ifs >> c.id && ifs >> c.size) {
		vCpt.push_back(c);
	}
	ifs.close();
	cout << "机房信息如下： " << endl;
	for (vector<computer>::iterator it = vCpt.begin(); it != vCpt.end(); it++) {
		cout << "编号: " << it->id << " 容量：" << it->size << endl;
	}
	system("pause");
	system("cls");
}
void Manager::cleanFile() {
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清除成功" << endl;
	system("pause");
	system("cls");
}

void Manager::initVecid() {
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "打开失败" << endl;
		return;
	}
	vStuid.clear();
	Student s;
	while (ifs >> s.id && ifs >> s.name && ifs >> s.password) {
		vStuid.push_back(s.id);
	}
	//测试
	cout << "当前学生数量" << vStuid.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "打开失败" << endl;
		return;
	}
	vTeaid.clear();
	Teacher T;
	while (ifs >> T.id && ifs >> T.name && ifs >> T.password) {
		vTeaid.push_back(T.id);
	}
	//测试
	cout << "当前老师数量" << vTeaid.size() << endl;
	ifs.close();
}

void Manager::initVec() {
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "打开失败" << endl;
		return;
	}
	vStu.clear();
	Student s;
	while (ifs >> s.id && ifs >> s.name && ifs >> s.password) {
		vStu.push_back(s);
	}
	//测试
	cout << "当前学生数量" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "打开失败" << endl;
		return;
	}
	vTea.clear();
	Teacher T;
	while (ifs >> T.id && ifs >> T.name && ifs >> T.password) {
		vTea.push_back(T);
	}
	//测试
	cout << "当前老师数量" << vTea.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id, int type) {
	if(type==1){
		for (vector<int>::iterator it = vStuid.begin(); it != vStuid.end(); it++) {
			if (id == *it)return true;
		}
	}
	else {
		for (vector<int>::iterator it = vTeaid.begin(); it != vTeaid.end(); it++) {
			if (id == *it)return true;
		}
	}
	return false;
}