#include<iostream>
using namespace std;
#include<string>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"mananger.h"
#include"boss.h"
int main() {
	WorkerManager wm;
	int input = 0;
	while (true) {
		wm.ShowMenu();
		cout << "请输入您的选择" << endl;
		cin >> input;
		switch (input)
		{
		case 0://退出系统
			wm.Exit();
			return 0;
			break;
		case 1://添加职工
			wm.addEmp();
			break;
		case 2://显示职工
			wm.show();
			break;
		case 3: //删除职工
			wm.del();
			break;
		case 4://修改职工
			wm.modify();
			break;
		case 5://查找职工
			wm.find();
			break;
		case 6://排序职工

			break;
		case 7://清空文档
			break;
		default:
			cout << "请选择一个选项" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}