#include<iostream>
using namespace std;
#include"演讲管理.h"
#include<ctime>
void main() {
	srand((unsigned int)time(NULL));
	SpeechManager sm;

	//test
	for (map<int, Speaker>::iterator it = sm.Speakerm.begin(); it != sm.Speakerm.end(); it++) {
		cout << "编号:" << it->first << "姓名:" << it->second.Name << "分数:" << it->second.score[0] << endl;
	}
	sm.loadRecord();
	sm.showRecord();
	int choice = -1;
	while (true) {
		sm.showMenu();
		cout << "请选择你想要运行的功能" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			sm.startSpeech();
			break;
		case 2:
			sm.loadRecord();
			sm.showRecord();
			break;
		case 3:
			sm.clearRecord();
			break;
		case 0:
			sm.exitS();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return;
}