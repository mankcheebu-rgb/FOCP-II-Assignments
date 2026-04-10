#include <bits/stdc++.h>
using namespace std;
bool canTurnOff(const string &bulbs, int n, int k, int l) {
    int ops = 0;
    for (int i = 0; i < n; ) {
        if (bulbs[i] == '1') {
            ops++;
            if (ops > k) return false;
            i += l; 
        } else {
            i++;
        }
    }

    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    string bulbs;
    cin >> bulbs;
    int left = 1, right = n, ans = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canTurnOff(bulbs, n, k, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}