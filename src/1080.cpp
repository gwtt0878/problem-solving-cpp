#include <iostream>

using namespace std;

void inputMat(int mat[51][51], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char a;
            cin >> a;
            mat[i][j] = a - '0';
        }
    }
}

void change(int arr[51][51], int i, int j) {
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            arr[i+y][j+x] = 1 - arr[i+y][j+x];
        }
    }
}

// 그리디 알고리즘.
// 두 행렬이 동일해야 하기 때문에 순서대로 비교하며 연산을 진행하여
// 같다면 최솟값이고, 다르면 불가능하다.
int answer(int arr[51][51], int desti[51][51], int n, int m) {
    int ret = 0;
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++){
            if (arr[i][j] != desti[i][j]) {
                change(arr, i, j);
                ret++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != desti[i][j])
                return -1;
        }
    }

    return ret;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    
    int n, m;
    int arr[51][51], desti[51][51];

    cin >> n >> m;
    
    inputMat(arr, n, m);
    inputMat(desti, n, m);


    cout << answer(arr, desti, n, m);

    return 0;
}