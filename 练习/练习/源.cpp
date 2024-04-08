#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
    vector<char> nums;  // 存储每张手牌的数字
    vector<char> colors;  // 存储每张手牌的颜色
    // dp数组，表示前i张牌最多能打出的手牌数量
    char input;
    // 输入每张手牌的数字
    do {
        cin >> input;
        nums.push_back(input);
    } while (getchar() != '\n');

    // 输入每张手牌的颜色
    for (int i = 0; i < nums.size(); i++) {
        cin >> input;
        colors.push_back(input);
    }
    // 遍历每张手牌
    for (auto num : nums)cout << num;
    for (auto color : colors)cout << color;
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(4, 1));  // dp数组，表示前i张牌每种颜色的最多能打出的手牌数量

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < i; ++k) {
                if (colors[i] == colors[k] || nums[i] == nums[k]) {
                    dp[i][j] = max(dp[i][j], dp[k][j] + 1);
                }
            }
        }
    }

    // 找到最大值
    int maxCount = *max_element(dp[n - 1].begin(), dp[n - 1].end());

    cout << maxCount << endl;

    return 0;
}
