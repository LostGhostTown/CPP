#include"演讲管理.h"
SpeechManager::SpeechManager() {
	this->init();

	this->createSpeaker();
}

void  SpeechManager::showMenu() {
	cout << "1.开始比赛" << endl;
	cout << "2.查看记录" << endl;
	cout << "3.清空记录" << endl;
	cout << "0.退出程序" << endl;
	cout << endl;
}

void SpeechManager::exitS() {
	exit(0);
}

void SpeechManager::init() {
	this->v1.clear();
	this->v2.clear();
	this->win.clear();
	this->Speakerm.clear();
	this->index = 1;
	this->Record.clear();
}

void SpeechManager::createSpeaker() {
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++) {
		string name = "选手";
		name += nameSeed[i];
		Speaker sp;
		sp.Name = name;
		for (int j = 0; j < 2; j++) {
			sp.score[j] = -1;
		}
		this->v1.push_back(i + 10001);
		this->Speakerm.insert(make_pair(i + 10001, sp));
	}
}

void SpeechManager::speechDraw() {
	cout << "第" << this->index << "轮" << endl;
	cout << "-----------------------" << endl;
	cout << "顺序如下：" << endl;
	if (this->index == 1) {
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	else {
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "-----------------------" << endl;
	system("pause");
	cout << endl;
}

void SpeechManager::speechContest() {
	cout << "第" << this->index << "轮比赛开始" << endl;
	vector<int>v_Src;//比赛选手容器
	multimap<double, int, greater<double>>gScore;//成绩
	int num = 0;
	if (this->index == 1) {
		v_Src = v1;
	}
	else {
		v_Src = v2;
	}
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++) {
		//评分
		num++;
		deque<double>d;
		for (int i = 0; i < 10; i++) {
			double score = (rand() % 401 + 600) / 10.f;//600`1000/10
			cout << score << " ";
			d.push_back(score);
		}
		cout << endl;
		sort(d.begin(), d.end(), greater<double>());//排序
		d.pop_front();
		d.pop_back();//去除最高最低分

		double sum = accumulate(d.begin(), d.end(), 0);
		double avg = sum / (double)d.size();//平均分
		cout << endl;

		this->Speakerm[*it].score[this->index - 1] = avg;
		cout << "编号" << *it << "姓名" << this->Speakerm[*it].Name << "平均分:" << avg << endl;
		gScore.insert(make_pair(avg, *it));//key是得分，value是编号
		if (num % 6 == 0) {
			cout << "第" << num / 6 << "小组的名次" << endl;
			for (multimap<double, int, greater<double>>::iterator it = gScore.begin(); it != gScore.end(); it++) {
				cout << "编号" << it->second << "姓名" << this->Speakerm[it->second].Name << "成绩" << this->Speakerm[it->second].score[this->index - 1] << endl;
			}
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = gScore.begin(); it != gScore.end() && count < 3; it++, count++) {
				if (this->index == 1) {
					v2.push_back((*it).second);
				}
				else {
					win.push_back((*it).second);
				}
			}
			gScore.clear();
			count = 0;
		}
	}
	cout << "第" << this->index << "轮结束" << endl;
	system("pause");
}

void SpeechManager::showScore() {
	cout << "第" << this->index << "轮晋级名单" << endl;
	vector<int>v;
	if(this->index==1){
		v = v2;
	}else{
		v = win;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "编号" << *it << "姓名" << this->Speakerm[*it].Name << "得分" << this->Speakerm[*it].score[this->index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->showMenu();
}

void SpeechManager::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//写入 | 追加
	for (vector<int>::iterator it = win.begin(); it != win.end(); it++) {
		ofs << *it << "," << this->Speakerm[*it].Name << "," << this->Speakerm[*it].score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "保存完毕" << endl << "比赛结束" << endl;
	this->fileIsEmpty = false;
	system("pause");
	system("cls");
}

void SpeechManager::startSpeech() {
	this->speechDraw();
	this->speechContest();
	this->showScore();
	this->index++;
	this->speechDraw();
	this->speechContest();
	this->showScore();
	this->saveRecord();
	//重置比赛
	this->init();
	this->createSpeaker();
	this->loadRecord();
}

void SpeechManager::loadRecord() {
	ifstream ifs("speech.csv", ios::in);//读取
	if (!ifs.is_open()) {
		this->fileIsEmpty = true;
		
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		this->fileIsEmpty = true;
		
		ifs.close();
		return;
	}
	this->fileIsEmpty = false;
	ifs.putback(ch);//将上面判断中的字符放回
	string data;
	int index = 1;
	while (ifs >> data) {
		vector<string>v;
		int pos = -1;
		int start = 0;
		while (true) {
			pos = data.find(",", start);
			if (pos == -1) {
				break;
			}
			else {
				string temp = data.substr(start, pos - start);
				v.push_back(temp);
				start = pos + 1;
				pos = -1;
			}
		}
		this->Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}

void SpeechManager::showRecord() {
	if (this->fileIsEmpty) {
		cout << "记录为空或不存在" << endl;
	}
	
	for (int i = 1; i <= this->Record.size(); i++) {
		cout << "第" << i << "届： " << " 冠军：" << this->Record[i][0] << "姓名：" << this->Record[i][1] << "得分" << this->Record[i][2] << " 亚军：" << this->Record[i][3] << "姓名：" << this->Record[i][4] << "得分" << this->Record[i][5] << " 季军：" << this->Record[i][6] << "姓名：" << this->Record[i][7] << "得分" << this->Record[i][8] << endl;
	}
	system("pause");
	system("cls");
}

void SpeechManager::clearRecord() {
	int s = -1;
	cout << "是否确定清空" << endl << "1.是" << endl << "2.否" << endl;
	cin >> s;
	if (s == 1) {
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		this->init();
		this->createSpeaker();
		this->loadRecord();
		cout << "清空完成" << endl;
	}
	system("pause");
	system("cls");
}

SpeechManager::~SpeechManager() {

}

