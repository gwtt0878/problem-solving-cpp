#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<long long int> arr(n); // 빌딩

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 기울기 문제

    int answer = 0;

    for (int i = 0; i < n; i++) {
        int count_i = 0;
        long long int dist = 0LL;
        long long int height = 0LL;

        for (int l = i - 1; l >= 0; l--) {
            if (dist == 0 || (arr[i] - arr[l]) * dist < height * (i - l)) {
                // 기존 기울기보다 작으면
                // 볼 수 있는 빌딩
                count_i++;
                height = arr[i] - arr[l];
                dist = i - l;
            }
        }
        
        dist = 0LL;
        height = 0LL;

        for (int r = i + 1; r < n; r++) {
            if (dist == 0 || (arr[r] - arr[i]) * dist > height * (r - i)) {
                // 기존 기울기보다 크면
                // 볼 수 있는 빌딩
                count_i++;
                height = arr[r] - arr[i];
                dist = r - i;
            }
        }
        
        answer = max(answer, count_i);
    }

    cout << answer;
    return 0;
} 