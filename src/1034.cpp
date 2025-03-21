#include <iostream>
#include <vector>

using namespace std;

void toggle_elem(vector<vector<char>>& arr, int col) {
    for (auto &elem : arr) {
        char& ch = elem[col];
        ch = '0' + '1' - ch;
    }
}

int check_answer(vector<vector<char>>& arr) {
    int answer = 0;
    for (auto &elem : arr) {
        bool turn_on = true;
        for (auto &e : elem) {
            turn_on = (e == '1');
            if (!turn_on)
                break;
        }
        if (turn_on)
            answer++;
    }
    return answer;
}

int answer(vector<vector<char>>& arr, int remains) {
    int row = arr.size(), col = arr[0].size();
    int ret = 0;
    for (int i = 0; i < row; i++) {
        auto _arr = arr; // 값 복사
        // 하나의 행만 전부 1로 바꿔보고 값을 구한다. 최대값이 답.
        int rema = remains;
        for (int j = 0; j < col; j++) {
            if (_arr[i][j] == '0') {
                if (rema > 0) {
                    rema--;
                    toggle_elem(_arr, j);
                } else {
                    rema = -1;
                    break;
                }
            }
        }
        if (rema % 2) continue;
        ret = max(ret, check_answer(_arr));
    }

    return ret;
}

int main() { // 램프
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<vector<char>> arr(n, vector<char>(m));
    for (auto &elem : arr) {
        for (auto &e : elem)
            cin >> e;
    }

    // 열(세로 방향)를 바꿔서 행(가로 방향)이 최대한 많게 바꾼다.
    int k; cin >> k;

    cout << answer(arr, k);
}