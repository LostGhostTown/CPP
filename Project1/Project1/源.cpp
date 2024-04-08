#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

int dfs(vector<char>& nums, vector<char>colors, vector<bool>used, int i, int count) {
	if (i >= nums.size() || used[i])return count - 1;
	used[i] = true;
	int ret = count;
	for (int j = 0; j < nums.size(); j++) {
		if (j != i && used[j] == false) {
			if (nums[j] == nums[i] || colors[j] == colors[i]) {
				ret = max(count, dfs(nums, colors, used, j, count + 1));
			}
		}
	}
	used[i] = false;
	return ret;
}

void main() {

	vector<char> nums;
	vector<char> colors;
	string input;
	string num;
	getline(cin, input);
	stringstream ss(input);
	while (getline(ss, num, ' ')) {
		char nnum = num[0];
		nums.push_back(nnum);
	}
	string color;
	string input1;
	getline(cin, input1);
	stringstream ss1(input1);
	while (getline(ss1, color, ' ')) {//¿Õ¸ñÊÇ·Ö¸ô·û
		char ccolor = color[0];
		colors.push_back(ccolor);
	}
	vector<int>ret;
	int count = 1;
	vector<bool>used(nums.size(),false);
	for (int i = 0; i < nums.size(); i++) {
		ret.push_back(dfs(nums, colors, used, i, count));
	}
	sort(ret.begin(),ret.end());
	int ans = ret.back();
	cout << ans;


	return;
}