#pragma once
#include<iostream>
using namespace std;
#include"globalFile.h"
#include<fstream>
#include<map>

class OrderFile {
public:
	OrderFile();
	void update();
	bool check(string date, string time, string id,string stuid);
	int size;
	map<int, map<string, string>>orderData;
};