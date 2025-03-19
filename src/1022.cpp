#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int find_elem(int r, int c) {
    // (1, 2) ~ (-2, 2) | (-2, 1) ~ (-2, -2) | (-1, -2) ~ (2, -2) | (2, -1) ~ (2, 2)
    // (2k+1) ** 2 + 1
    // 네 구간 구분 짓기
    int r_abs = abs(r);
    int c_abs = abs(c);
    if (r_abs > c_abs) { // 좌 혹은 우
        if (r < 0) { // 좌 방향
            int base = find_elem(r, r_abs); // 우상단 모서리값.
            return base + (r_abs - c);
        } else { // 우
            int base = find_elem(r, -r_abs);
            return base + (c + r_abs);
        }
    }
    else if (r_abs < c_abs) { // 상 혹은 하
        if (c < 0) { // 하 방향 
            int base = find_elem(c, -c_abs);
            return base + (r + c_abs);
        } else {
            int base = find_elem(c-1, c_abs-1) + 1; // 우하단 (k-1, k-1) + 1
            return base + (c - 1 - r);
        }
    }
    else { // 각 모서리
        int base = (2 * r_abs - 1) * (2 * r_abs - 1);
        if (r < 0 && c > 0) 
            return base + 2 * r_abs;
        else if (r < 0 && c < 0) 
            return base + 4 * r_abs;
        else if (r > 0 && c < 0) 
            return base + 6 * r_abs;
        else if (r > 0 && c > 0)
            return base + 8 * r_abs;
        else // 0, 0 -> 1
            return base;
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    
    int r1, c1, r2, c2;

    cin >> r1 >> c1 >> r2 >> c2;

    // 규칙성
    // (n, n)은 1, 9, 25, 49 ..
    // 홀수의 제곱수 (k, k) -> (2k+1) ** 2
    // (n, n+1)이 그 다음 수 (2n + 1) ** 2 + 1
    // 그 다음은 상, 좌, 하, 우 순으로 반복.
    // 좌상단 (r1, c1)에 대해 네가지 케이스로 구분
    // (1, 2) ~ (-2, 2) | (-2, 1) ~ (-2, -2) | (-1, -2) ~ (2, -2) | (2, -1) ~ (2, 2)
    // 찾는데 최대 4(r1)의 시간복잡도
    // 최대 200번 정도 서칭하면 된다.

    int answer[51][5] = {};
    int lengthMap[51][5] = {};

    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            answer[i - r1][j - c1] = find_elem(i, j);
        }
    }

    int maxLength = 0;
    
    for (int i = 0; i <= r2-r1; i++) {
        for (int j = 0; j <= c2-c1; j++) {
            int currLength = 0;
            int elem = abs(answer[i][j]);
            while (elem > 0) {
                elem /= 10;
                currLength++;
            }
            maxLength = max(maxLength, currLength);
            lengthMap[i][j] = currLength;
        }
    }
    
    // 포매팅
    for (int i = 0; i <= r2-r1; i++) {
        for (int j = 0; j <= c2-c1; j++) {
            while (maxLength > lengthMap[i][j]) {
                cout << ' ';
                lengthMap[i][j]++;
            }
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
}