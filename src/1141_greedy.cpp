#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);

    int n; cin >> n;
    vector<string> V(n);
    for (auto & elem : V) 
        cin >> elem;
    
    sort(V.begin(), V.end(), [] (string a, string b) {
        return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
    });

    int answer = 1; // 무조건 한 문자열은 집합에 포함된다.
    for (int i = 0; i < n - 1; i++) {
        if (V[i+1].find(V[i]) == 0) // 현재 문자열이 다음 문자열의 접두사일 때.
            answer--;
        answer++;
    }
    cout << answer;
}