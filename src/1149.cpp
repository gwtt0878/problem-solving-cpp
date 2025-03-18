#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    
    int arr[1001][3];
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];

            if (i != 0) {
                // DP 아이디어: 값의 최솟값으로 갱신한다.
                arr[i][j] += min(arr[i-1][(j+1)%3], arr[i-1][(j+2)%3]);
            }
        }
    }

    // cout << min({arr[n-1][0], arr[n-1][1], arr[n-1][2]});
    cout << min(arr[n-1][0], min(arr[n-1][1], arr[n-1][2]));
}