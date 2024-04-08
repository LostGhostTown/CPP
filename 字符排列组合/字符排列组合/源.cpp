#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
vector<string>marr;
//dfs实现全排列(含重复元素情况)
void dfs(string& s, int l, int r)
{
	if (l == r) {
		//cout << s << endl;
		marr.push_back(s);
		return;
	}
	set<char>st;//检测重复的set
	for (int i = l; i < r; i++) {
		if (i == l || st.count(s[i]) == 0) {//防止后续进行重复排列
			st.insert(s[i]);//满足  记录这个字符 

			swap(s[l], s[i]);
			dfs(s, l + 1, r);
			swap(s[l], s[i]);
		}
	}
}


int main()
{
	string s = "aaaabbbb";
	int len = s.size();
	dfs(s, 0, len);
	for (auto str : marr)cout << str << endl;
	system("pause");
	return 0;
}
