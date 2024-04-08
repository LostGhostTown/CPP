#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<char> nums;  // 存储每张手牌的数字
    vector<char> colors;  // 存储每张手牌的颜色
    vector<int> lastIdx(10, -1);  // 记录每个数字上一次出现的位置
    vector<int> dp(10, 1);  // dp数组，表示前i张牌最多能打出的手牌数量
    char input;
    // 输入每张手牌的数字
    do {
        cin >> input;
        nums.push_back(input);
    } while (getchar() != '\n');

    // 输入每张手牌的颜色
    do {
        cin >> input;
        colors.push_back(input);
    } while (getchar() != '\n');

    // 遍历每张手牌
    for (int i = 0; i < nums.size(); ++i) {
        // 遍历之前的每张手牌
        for (int j = 0; j < i; ++j) {
            // 判断是否符合颜色或数字条件
            if (colors[i] == colors[j] || (nums[i] == nums[j] && lastIdx[nums[i]] < j)) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        lastIdx[nums[i]] = i;  // 更新数字出现的位置
    }

    // 找到最大值
    int maxCount = *max_element(dp.begin(), dp.end());

    cout << maxCount << endl;

    return 0;
}
