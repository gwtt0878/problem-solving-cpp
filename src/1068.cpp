#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// DFS 방식으로 말단 노드 찾기
int find_leaf(vector<deque<int>> &children, int &deletedNode, int curr) {
    if (children[curr].size() > 0) { // 하위 노드가 있다면
        int ret = 0;
        for (auto & nxt : children[curr])
            if (nxt != deletedNode)
                ret += find_leaf(children, deletedNode, nxt);
        // 하위 노드에 deletedNode밖에 없다면
        if (children[curr].size() == 1 && children[curr][0] == deletedNode)
            ret++;

        return ret;
    }
    else return 1;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> V(n); // 부모 노드
    int rootNode;
    vector<deque<int>> children(n);
    
    for (int i = 0; i < n; i++) {
        cin >> V[i];
        if (V[i] != -1)
            children[V[i]].push_back(i);
        else // 루트 노드가 0이라고 한 적 없다.
            rootNode = i;
    }
    
    int nodeNum;
    cin >> nodeNum;
    if (nodeNum == rootNode)
        cout << 0;
    else
        cout << find_leaf(children, nodeNum, rootNode);
}