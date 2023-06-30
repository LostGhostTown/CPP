#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include"orderManage.h"
#include<string>

class Teacher :public Identity {
public:
	Teacher();
	Teacher(int id, string name, string password);
	virtual void openMenu();
	void showAllOrder();
	void validOrder();
	int id;
};