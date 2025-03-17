#include <iostream>
#include <vector>
#include <set>

using namespace std;

void dfs(vector<set<int>> &adj, vector<int>&visited, vector<int>& truth, int curr) {
    for (auto &nxt : adj[curr]) {
        if (visited[nxt]) continue;

        visited[nxt] = 1;
        dfs(adj, visited, truth, nxt);
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    
    int n, m, k;

    cin >> n >> m >> k;

    vector<set<int>> adj(n+1); // 인접 리스트
    vector<int> truth(k);
    vector<vector<int>> parties(m);

    for (auto &elem : truth)
        cin >> elem;

    for (int i = 0; i < m; i++) {
        int party_p;
        cin >> party_p;
        parties[i] = vector<int>(party_p);
        for (auto & elem: parties[i]) {
            cin >> elem;
        }
        for (int j = 0; j < party_p - 1; j++) {
            // Set을 사용해서 중복 간선 제거
            adj[parties[i][j]].insert(parties[i][j+1]);
            adj[parties[i][j+1]].insert(parties[i][j]);
        }
    }

    vector<int> visited(n+1);

    for (auto & elem: truth) {
        visited[elem] = 1;
        dfs(adj, visited, truth, elem);
    }

    int answer = 0;

    for (auto & elem : parties) {
        for (auto & e : elem) {
            if (visited[e]) {
                answer--;
                break;
            }
        }
        answer++;
    }

    cout << answer;
}