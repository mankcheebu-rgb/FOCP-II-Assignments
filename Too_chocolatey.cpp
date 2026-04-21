#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.rbegin(), a.rend());

        unordered_set<int> usedA, usedB;

        long long alex = 0, bob = 0;

        for (int i = 0; i < n; i++) {
            int x = a[i];

            if (i % 2 == 0) {
                if (!usedA.count(x)) {
                    alex += x;
                    usedA.insert(x);
                }
            } else {
                if (!usedB.count(x)) {
                    bob += x;
                    usedB.insert(x);
                }
            }
        }

        if (alex > bob) cout << "Alex\n";
        else cout << "Bob\n";
    }

    return 0;
}