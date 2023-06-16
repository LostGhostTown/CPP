#pragma once
#include<iostream>
#include<vector>
#include<map>
#include"选手.h"
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<fstream>
using namespace std;

class SpeechManager {
public:
	SpeechManager();
	void showMenu();
	void exitS();
	void init();
	void createSpeaker();
	void startSpeech();
	void speechDraw();//抽签
	void speechContest();//比赛流程
	void showScore();
	void saveRecord();
	void loadRecord();
	void showRecord();
	void clearRecord();

	bool fileIsEmpty;
	
	map<int,  vector<string>>Record;

	~SpeechManager();
	
	vector<int> v1;
	vector<int> v2;
	vector<int> win;
	map<int, Speaker>Speakerm;
	int index;
};