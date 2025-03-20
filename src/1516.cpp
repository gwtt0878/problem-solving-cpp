#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int main() { // 게임 개발
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<int> costs(n);
    vector<deque<int>> nxt_build(n); // 다음 건물들
    vector<int> indegree(n);

    for (int i = 0; i < n; i++) {
        cin >> costs[i];
        int preced; // 선행 조건
        cin >> preced;
        while (preced != -1)
        {
            nxt_build[preced - 1].push_back(i); // 1 ~ N
            indegree[i]++;
            cin >> preced;
        }
    }
    
    vector<int> answer(n);
    queue<int> Q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            Q.push(i);
            answer[i] = costs[i];
        }
    }

    while (!Q.empty()){
        int curr = Q.front();
        Q.pop();

        for (int nxt : nxt_build[curr]) {
            indegree[nxt]--;
            answer[nxt] = max(answer[nxt], answer[curr] + costs[nxt]);
            if (indegree[nxt] == 0) {
                Q.push(nxt);
            }
        }
    }

    for (int &elem : answer)
        cout << elem << '\n';
}