#include<iostream>
using namespace std;
class Cube {
public:
	void setLength(int l) {
		length = l;
	}
	int getLength() {
		return length;
	}
	void setwidth(int w) {
		width = w;
	}
	int getwidth() {
		return width;
	}
	void setheight(int h) {
		height = h;
	}
	int getheight() {
		return height;
	}
	int calculateS() {
		return 2 * length * width + 2 * width * height + 2 * length * height;
	}
	int calculateV() {
		return length * width * height;
	}

	bool issame(Cube &c) {
		if (getLength() == c.getLength() && getheight() == c.getheight() && getwidth() == c.getwidth()) {
			return true;
		}
		return false;
	}
private:
	int length;
	int	width;
	int	height;
};
bool equal( Cube &c1, Cube &c2) {
	if (c1.getLength() == c2.getLength() && c1.getheight() == c2.getheight() && c1.getwidth() == c2.getwidth()) {
		return true;
	}
	return false;
}
int main() {
	Cube c1;
	c1.setLength(10);
	c1.setwidth(10);
	c1.setheight(10);
	cout << c1.calculateS()<<endl;
	cout << c1.calculateV() << endl;

	Cube c2;
	c2.setLength(10);
	c2.setwidth(10);
	c2.setheight(10);

	bool ret = equal(c1, c2);
	if (ret) {
		cout << "相等" << endl;
	}
	else {
		cout << "不相等" << endl;
	}
	bool ret2 = c1.issame(c2);
	if (ret2) {
		cout << "相等" << endl;
	}
	else {
		cout << "不相等" << endl;
	}
	return 0;
}