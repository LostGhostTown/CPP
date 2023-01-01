#include"workerManager.h"

WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		this->eNum = 0;
		this->WorkerAyy = NULL;
		this->FileisEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		this->eNum = 0;
		this->WorkerAyy = NULL;
		this->FileisEmpty = true;
		ifs.close();
		return;
	}
	int num = this->get_eNum();
	cout << "当前职工人数为： " << num << endl;
	this->eNum = num;
	this->WorkerAyy = new Worker * [num];
	this->initEmp();
}

void WorkerManager::addEmp() {
	cout << "请输入需要添加的职工的数量" << endl;
	int addnum;
	cin >> addnum;
	if (addnum > 0) {
		int newNum = this->eNum + addnum;
		Worker** newspace = new Worker * [newNum];
		//先拷贝原来的数据
		if (this->WorkerAyy != NULL) {
			for (int i = 0; i < this->eNum; i++) {
				newspace[i] = this->WorkerAyy[i];
			}
		}
		for (int i = 0; i < addnum; i++) {
			int id;
			string name;
			int d;
			int did;
			cout << "请输入第" << i + 1 << "个新员工的编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新员工的姓名：" << endl;
			cin >> name;
			cout << "请选择第" << i + 1 << "个新员工的岗位：" << endl;
			cout << "1、职工" << endl;
			cout << "2、管理" << endl;
			cout << "3、老板" << endl;
			cin >> did;
			
			Worker* worker = NULL;
			switch (did)
			{
			case 1:
				worker = new Employee(id,name,did);
				break;
			case 2:
				worker = new Manager(id, name, did);
				break;
			case 3:
				worker = new Boss(id, name, did);
				break;
			default:
				cout << "输入有误请重新添加这名员工" << endl;
				i--;
				system("pause");
				break;
			}
			newspace[this->eNum + i] = worker;
			system("cls");
		}
		delete[] this->WorkerAyy;
		this->WorkerAyy = newspace;
		this->eNum = newNum;
		this->FileisEmpty = false;
		cout << "添加成功，现在一共有" << newNum << "名职工" << endl;
		this->save();
	}
	else {
		cout << "输入数据有误，请重试" << endl;
	}
}
void WorkerManager::ShowMenu() {
	cout << "欢迎使用职工管理系统" << endl;
	cout << "   0.退出管理系统" << endl;
	cout << "   1.增加职工信息" << endl;
	cout << "   2.显示职工信息" << endl;
	cout << "   3.删除职工信息" << endl;
	cout << "   4.修改职工信息" << endl;
	cout << "   5.查找职工信息" << endl;
	cout << "   6.按照编号排序" << endl;
	cout << "   7.清空所有文档" << endl;
	cout << endl;
}
void WorkerManager::Exit() {
	cout << "欢迎你下次使用" << endl;
	system("pause");
	exit(0);
}
WorkerManager::~WorkerManager() {
	if (this->WorkerAyy != NULL) {
		delete[] this->WorkerAyy;
		this->WorkerAyy = NULL;
	}
}
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < eNum; i++) {
		ofs << this->WorkerAyy[i]->ID << " "
			<< this->WorkerAyy[i]->Name << " "
			<< this->WorkerAyy[i]->DeptID << endl;
		
	}
	ofs.close();
}
int WorkerManager::get_eNum() {
	int num = 0;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	while (ifs >> id && ifs >> name&& ifs >> did) {
		num++;
	}
	return num;
}
void WorkerManager::initEmp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int id;
	string name;
	int did;
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> did) {
		Worker* worker;
		if (did == 1){
			worker=new Employee(id,name,did);
		}
		else if (did == 2) {
			worker = new Manager(id, name, did);
		}
		else {
			worker = new Boss(id, name, did);
		}
		this->WorkerAyy[num] = worker;
		num++;
	}
	ifs.close();
}
void WorkerManager::show() {
	if (this->FileisEmpty) {
		cout << "无员工" << endl;
		return;
	}
	for (int i = 0; i < this->eNum; i++) {
		this->WorkerAyy[i]->showInfo();
	}
	system("pause");
	system("cls");
}
void WorkerManager::del() {
	if (this->FileisEmpty) {
		cout << "无员工" << endl;
		return;
	}
	cout << "请输入需要删除的职工的编号" << endl;
	int id;
	cin >> id;
	int ret = this->isExist(id);
	if (ret == -1) {
		cout << "职工不存在，无效操作" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = ret; i < this->eNum - 1; i++) {
		this->WorkerAyy[i] = this->WorkerAyy[i + 1];
	}
	this->eNum--;
	this->save();
	cout << "删除成功" << endl;
	system("pause");
	system("cls");
}
int WorkerManager::isExist(int id) {
	int index = -1;
	for (int i = 0; i < this->eNum; i++) {
		if (this->WorkerAyy[i]->ID == id) {
			index = i;
			break;
		}
	}
	return index;
}
void WorkerManager::modify() {
	if (this->FileisEmpty) {
		cout << "无员工" << endl;
		return;
	}
	cout << "请输入需要修改的职工的编号" << endl;
	int id;
	cin >> id;
	int ret = this->isExist(id);
	if (ret == -1) {
		cout << "职工不存在，无效操作" << endl;
		system("pause");
		system("cls");
		return;
	}
	
	string name;
	int did;
	cout << "请输入员工的姓名：" << endl;
	cin >> name;
	cout << "请选择员工的岗位：" << endl;
	cout << "1、职工" << endl;
	cout << "2、管理" << endl;
	cout << "3、老板" << endl;
	cin >> did;

	Worker* worker = NULL;
	switch (did)
	{
	case 1:
		worker = new Employee(id, name, did);
		break;
	case 2:
		worker = new Manager(id, name, did);
		break;
	case 3:
		worker = new Boss(id, name, did);
		break;
	default:
		cout << "输入有误请重新尝试" << endl;
		system("pause");
		system("cls");
		return;
	}
	this->WorkerAyy[ret] = worker;
	this->save();
	cout << "修改成功" << endl;
	system("pause");
	system("cls");
}
void WorkerManager::find() {
	if (this->FileisEmpty) {
		cout << "无员工" << endl;
		return;
	}
	int select = -1;
	cout << "请输入查找的方式\n1.按id查找\n2.按姓名查找" << endl;
	cin >> select;
	switch (select)
	{
	case 1: {
		int id;
		cout << "请输入需要查找的职工编号： " << endl;
		cin >> id;
		int ret = this->isExist(id);
		if (ret == -1) {
			cout << "职工不存在" << endl;
			break;
		}
		this->WorkerAyy[ret]->showInfo();
		break; }
	case 2: {
		string name;
		cout << "请输入需要查找的员工姓名" << endl;
		cin >> name;
		bool b = true;
		for (int i = 0; i < this->eNum; i++) {
			if (this->WorkerAyy[i]->Name == name) {
				this->WorkerAyy[i]->showInfo();
				b = false;
			}
		}
		if(b)cout << "职工不存在" << endl;
		break; }
	default:
		cout << "无效操作" << endl;
		
		break;
	}
	system("pause");
	system("cls");
	return;
}
void WorkerManager::sort() {

}