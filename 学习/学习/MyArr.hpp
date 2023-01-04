#pragma once
#include<iostream>
using namespace std;
#include<string>
template<class T>
class MyArr {
public:
	MyArr(int Capacaty) {
		this->Capacity = Capacaty;
		this->Size = 0;
		this->pAddress = new T[Capacaty];
	}
	MyArr(const MyArr& arr) {
		this->Capacity = arr.Capacity;
		this->Size = arr.Size;
		this->pAddress = new T[arr.Capacity];
		for (int i = 0; i < arr.Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	MyArr& operator=(const MyArr& arr) {
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->Capacity = 0;
			this->Size = 0;
		}
		this->Capacity = arr.Capacity;
		this->Size = arr.Size;
		this->pAddress = new T[arr.Capacity];
		for (int i = 0; i < arr.Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	//尾插法
	void push_Back(const T &val) {
		if (this->Capacity == this->Size) {
			return;
		}
		this->pAddress[this->Size] = val;
		this->Size++;
	}
	//尾删法
	void pop_Back() {
		if (this->Size == 1) {
			return;	
		}
		this->Size--;
	}
	T& operator[](int index) {
		return this->pAddress[index];
	}
	int getCapacity() {
		return this->Capacity;
	}
	int getSize() {
		return this->Size;
	}
	~MyArr()
	{
		if (this->pAddress != NULL) {
			delete[]this->pAddress;
			pAddress = NULL;
		}
	}
private:
	T* pAddress;//指向堆区数组
	int Capacity;
	int Size;
};