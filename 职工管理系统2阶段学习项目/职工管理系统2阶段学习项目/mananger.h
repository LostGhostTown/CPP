#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"
//æ≠¿Ì¿‡
class Manager :public Worker{
public:
	Manager(int id, string name, int did);
	void showInfo();
	string getDeptID();
};
