#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
#include "identity.h"
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"computer.h"

class Manager :public Identity {
public:
	Manager();
	Manager(string name, string password);
	virtual void openMenu();
	void addUser();
	void showUser();
	void ShowComputer();
	void cleanFile();
	void initVecid();
	void initVec();
	bool checkRepeat(int id, int type);
	vector<int>vStuid;
	vector<int>vTeaid;
	vector<Student>vStu;
	vector<Teacher>vTea;
	vector<computer>vCpt;
};