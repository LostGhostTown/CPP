#include"MyArr.hpp"
void paintintArr(MyArr<int>& arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr[i] << endl;
	}
}
void main() {
	MyArr <int>arr1(5);
	for (int i = 0; i < 5; i++) {
		arr1.push_Back(i);
	}
	paintintArr(arr1);
	return;
}