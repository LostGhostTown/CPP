#include<iostream>
using namespace std;
#include<string>
class AbstractDrinking {
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加辅料
	virtual void PutSth() = 0;
	//制作
	void makeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSth();
	}
};
class Coffee :public AbstractDrinking {
	//煮水
	virtual void Boil() {
		cout << "煮山泉水" << endl;
	}

	//冲泡
	virtual void Brew() {
		cout << "冲咖啡" << endl;
	}
	//倒入杯中
	virtual void PourInCup() {
		cout << "倒入咖啡杯" << endl;
	}
	//加辅料
	virtual void PutSth() {
		cout << "加奶精和方糖" << endl;
	}
};
class Tea :public AbstractDrinking {
	//煮水
	virtual void Boil() {
		cout << "煮山泉水" << endl;
	}

	//冲泡
	virtual void Brew() {
		cout << "放茶叶" << endl;
	}
	//倒入杯中
	virtual void PourInCup() {
		cout << "倒入茶杯" << endl;
	}
	//加辅料
	virtual void PutSth() {
		cout << "加柠檬" << endl;
	}
};
void doWork(AbstractDrinking *abs) {
	abs->makeDrink();
	delete abs;
}
void test01() {
	//制作咖啡
	doWork(new Coffee);//另一种指针用多态方式
	cout << "------------" << endl;
	doWork(new Tea);
}
int main() {
	test01();
	return 0;
}