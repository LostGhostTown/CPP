#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

struct data1 {
	int d;
	int k;
	bool operator<(const data1& other) const {
		if (k < other.k) return false;
		else if (k == other.k) return d < other.d;
		else return true;
	}
};
bool datasort(const data1& a, const data1& b) {
	return a < b;
}
int main() {
	vector<data1>mdata = {
		{10,1},{20,1},{30,2},{40,3} };

	sort(mdata.begin(), mdata.end(), datasort);

	// 打印排序后的结果
	for (const data1& item : mdata) {
		cout << "d: " << item.d << ", k: " << item.k << endl;
	}

	return 0;
}