#include <iostream>
using namespace std;

const int MAX = 10000001;
int spf[MAX];

void sieve() {
    for (int i = 1; i < MAX; i++) {
        spf[i] = i;
    }

    for (int i = 2; i * i < MAX; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAX; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    int num;
    cin >> num;

    while (num--) {
        int n;
        cin >> n;

        int count = 0;

        while (n > 1) {
            int p = spf[n];
            count++;

            while (n % p == 0) {
                n = n / p;
            }
        }

        int ans = 1;
        for (int i = 0; i < count; i++) {
            ans = ans * 2;
        }

        cout << ans << "\n";
    }

    return 0;
}
