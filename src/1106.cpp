#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    
    int c, n;
    cin >> c >> n;
    vector<pair<int, int>> cities(n);

    for (auto & [cost, reward] : cities) {
        cin >> cost >> reward;
    }
    
    vector<int> rewardDP(c+1, 1e9+7);
    rewardDP[c] = 0;

    for (int i = c; i >= 0; i--) {
        for (auto & [cost, reward] : cities) {
            // DP의 대략적인 구조.
            // nxt의 값을 최소/최대로 업데이트하는 방식
            // reward가 배열의 인덱스를 결정하고 업데이트하는 값은 cost이다. 
            int nxt = max(0, i - reward);
            rewardDP[nxt] = min(rewardDP[nxt], rewardDP[i] + cost);
        }
    }

    cout << rewardDP[0];
}