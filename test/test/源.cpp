#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    int p, n, m;
    cin >> p >> n >> m;
    cin.ignore();
    vector<int>xiaoguai;
    vector<int>boss;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        cin.ignore();
        xiaoguai.push_back(t);
    }
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        cin.ignore();
        boss.push_back(t);
    }
    sort(xiaoguai.begin(), xiaoguai.end());
    sort(boss.begin(), boss.end());
    int count = 0;
    for (int i = 0; i < boss.size(); i++) {
        for (int j = 0; j < xiaoguai.size(); j++) {
            if (p > boss[i])break;
            bool isf = true;
            for (int k = xiaoguai.size() - 1; k >= 0; k++) {
                if (xiaoguai[k]<p && xiaoguai[k]>p / 10 && xiaoguai[k] > 0) {
                    isf = false;
                    p += xiaoguai[k];
                    count++;
                    xiaoguai[k] = -xiaoguai[k];
                }
            }
            if (isf) {
                p = p + (p / 10);
                j--;
                count++;
            }

        }
        if (p <= boss[i]) {
            p = p + (p / 10);
            count++;
            i--;
        }
    }
    cout << count;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")