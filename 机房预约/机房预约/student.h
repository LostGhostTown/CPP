#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<vector>
#include"computer.h"
#include<fstream>
#include"globalFile.h"
#include"orderManage.h"
#include<string>

class Student :public Identity {
public:
	Student();
	Student(int id, string name, string password);
	virtual void openMenu();
	void applyOrder();
	void showMyOrder();
	void showAllOrder();
	void cancelOrder();
	void initcom();
	int id;
	vector<computer>vCom;
};