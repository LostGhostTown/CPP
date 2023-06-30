#pragma once
using namespace std;
#include<iostream>

class Identity {
public:
	virtual void openMenu() = 0;
	string name;
	string password;
};