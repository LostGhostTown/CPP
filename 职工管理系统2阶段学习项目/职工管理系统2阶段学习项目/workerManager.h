#pragma once//防止头文件重复包含
#include<iostream>
#include<string>
#include"worker.h"
#include"employee.h"
#include"mananger.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager {
public:
	WorkerManager();
	~WorkerManager();
	void ShowMenu();
	void Exit();
	void addEmp();
	void save();
	//判断文件是否为空
	bool FileisEmpty;
	//统计文件中的人数
	int get_eNum();
	int eNum;
	void initEmp();
	void show();
	void del();
	void modify();
	void find();
	void sort();
	void clean();

	int isExist(int id);
	
	Worker** WorkerAyy;
};