#include <iostream>
#include <vector>
#include<string>
#include<unordered_map>
#include<sstream>
using namespace std;
struct tree {
	string d;
	tree* left;
	tree* right;

	tree(string str) {
		d = str;
		left = nullptr;
		right = nullptr;
	}
};
int main() {
	string input;

	getline(cin, input);

	stringstream ss(input);

	string inp;
	int c = 0;
	vector<string>fb;
	vector<int>count;
	while (getline(ss, inp, ',')) {
		if (c % 2 == 0)fb.push_back(inp);
		else count.push_back(stoi(inp));
		c++;
	}
	//for (auto f : count)cout << f;
	vector<tree>mtree;
	int sonnum = 0;
	int num = 0;
	
	for (int i = 0; i < fb.size(); i++) {
		//cout << "fb:" << fb[i] << endl;

		tree* temp = new tree(fb[i]);
		cout << "i: " << i << "fb:" << fb[i] << " sonnum: " << sonnum << " num:" << num << endl;
		if (sonnum == 0) {
			mtree.push_back(*temp);
			num = 0;
		}
		if (sonnum > 0)sonnum--;
		if (sonnum == 0)sonnum += count[i];

		//cout << " sonnum:" << sonnum << endl;
		switch (count[i]) {
		case 1: {
			cout << "here is case1" << endl;
			tree* temp2 = new tree(fb[i + (2 * num + 1)]);
			temp->left = temp2;
			if (count[i+(2 * num + 1)] != 0)sonnum += count[i + (2 * num + 1)];
			
			cout << "i: " << i << "fb:" << fb[i + (2 * num + 1)] << " sonnum: " << sonnum << endl;
			cout << "count:" << count[i + (2 * num + 1)] << endl;
			num++;
			break;
		}
		case 2: {

			tree* temp2 = new tree(fb[i + (2 * num + 1)]);
			temp->left = temp2;
			if (count[i + (2 * num + 1)] != 0)sonnum += count[i + (2 * num + 1)];
			temp2 = new tree(fb[i + (2 * num + 2)]);
			temp->right = temp2;
			if (count[i + (2 * num + 2)] != 0)sonnum += count[i + (2 * num + 2)];
			num ++;
			break;
		}
		}
		

	}
	for (auto t : mtree)cout << t.d;
	//system("pause");
	return 0;
}
