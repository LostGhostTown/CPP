#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include<stack>
using namespace std;
int main() {
	string str;
	cin >> str;
	int temp1 = 0, temp2 = 0;
	stack<string> mstr;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] > '0' && str[i] <= '9') {
			temp1 = i;
			for (int j = temp1 + 1; j < str.size(); j++) {
				if (str[j] == '[') { 
					temp2 = j; 
					break;
				}
			}
			cout << " ;substr:" << str.substr(temp1 + 1, temp2 - 1) << endl;
			int num = stoi(str.substr(temp1,temp2-1));
			cout << "num:" << num << endl;
			temp1 = temp2;
			for (int j = temp1; j < str.size(); j++) {
				if (str[j] == ']') {
					temp2 = j;
					break;
				}
			}
			//cout << "temp1:" << temp1 << " ;temp2:" << temp2 << " ;substr:" << str.substr(temp1 + 1, temp2 - 1) << endl;
			for (int j = 0; j < num; j++) {
				mstr.push(str.substr(temp1 + 1, temp2 - 1));
			}
			i = temp2;
			continue;
		}
	}
	stack<string>temp = mstr;
	while (!temp.empty()) {
		cout << temp.top() << endl;
		temp.pop();
	}
	return 0;
}