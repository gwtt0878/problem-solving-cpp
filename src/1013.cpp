#include <iostream>
#include <vector>

using namespace std;

struct node {
    node * nxt[2] = {NULL, NULL}; // 0 or 1
};

int main() { // Contact
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    
    int t;
    cin >> t;

    // 규칙 만들기
    node * start = new node;

    start->nxt[0] = new node;
    start->nxt[1] = new node;

    start->nxt[1]->nxt[0] = new node;
    start->nxt[1]->nxt[0]->nxt[0] = new node;
    start->nxt[1]->nxt[0]->nxt[0]->nxt[0] = start->nxt[1]->nxt[0]->nxt[0];
    start->nxt[1]->nxt[0]->nxt[0]->nxt[1] = new node;
    start->nxt[1]->nxt[0]->nxt[0]->nxt[1]->nxt[1] = new node;
    start->nxt[1]->nxt[0]->nxt[0]->nxt[1]->nxt[0] = start->nxt[0];

    // 10011 10011 혹은 10011 01 같은 경우 대비
    start->nxt[1]->nxt[0]->nxt[0]->nxt[1]->nxt[1]->nxt[1] = start->nxt[1]->nxt[0]->nxt[0]->nxt[1]->nxt[1];
    start->nxt[1]->nxt[0]->nxt[0]->nxt[1]->nxt[1]->nxt[0] = new node;
    start->nxt[1]->nxt[0]->nxt[0]->nxt[1]->nxt[1]->nxt[0]->nxt[0] = start->nxt[1]->nxt[0]->nxt[0];
    start->nxt[1]->nxt[0]->nxt[0]->nxt[1]->nxt[1]->nxt[0]->nxt[1] = start;

    start->nxt[0]->nxt[1] = start;
    node * fin1 = start->nxt[1]->nxt[0]->nxt[0]->nxt[1]->nxt[1];
    node * fin2 = start->nxt[1]->nxt[0]->nxt[0]->nxt[1];

    while (t--) {
        string s;
        cin >> s;

        node * cursor = start;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            cursor = cursor->nxt[ch - '0'];
            if (cursor == NULL)
                break;
        }

        if (cursor == start || cursor == fin1 || cursor == fin2) 
            cout << "YES\n";
        else cout << "NO\n";
    }
}