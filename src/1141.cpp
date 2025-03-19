#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node {
    node * nxt['z'-'a' + 1] = {};
};

int dfs(node * curr) {
    int ret = 0;
    bool not_leaf = false;
    for (int i = 0; i <= 'z'-'a'; i++) { // 'a' ~ 'z'
        if (curr->nxt[i]) {
            not_leaf = true;
            ret += dfs(curr->nxt[i]);
        }
    }
    if (!not_leaf) return 1;
    return ret;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    // 그래프 문제
    // 리프 노드의 갯수를 구하자.
    // a~z 까지의 하위 노드로 연결된다고 생각하자.

    node * root = new node; // 공집합

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        node * cursor = root;
        
        for (auto & elem : input) {
            if (!(cursor->nxt[elem-'a']))
                cursor->nxt[elem-'a'] = new node;
            cursor = cursor->nxt[elem-'a'];
        }
    }

    cout << dfs(root);

    // 혹은 그리디 알고리즘으로 접근한다.
    // 전체 문자열을 (알파벳순, 길이순)으로 오름차순 정렬하고
    // 인접한 문자열을 비교하면서 카운팅하면 된다.
}