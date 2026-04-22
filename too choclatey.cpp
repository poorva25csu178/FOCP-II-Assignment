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

        sort(a.begin(), a.end(), greater<int>());

        int alex = 0, bob = 0;
        set<int> sa, sb;

        bool turn = true;

        for (int i = 0; i < n; i++) {
            if (turn) {
                if (sa.count(a[i])) continue;
                alex += a[i];
                sa.insert(a[i]);
            } else {
                if (sb.count(a[i])) continue;
                bob += a[i];
                sb.insert(a[i]);
            }
            turn = !turn;
        }

        if (alex > bob)
            cout << "Alex\n";
        else
            cout << "Bob\n";
    }

    return 0;
}
