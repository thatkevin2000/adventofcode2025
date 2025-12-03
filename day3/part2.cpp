#include <bits/stdc++.h>
using namespace std;

long long dp[105][15];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    long long res = 0;
    while (cin >> s) {
        memset(dp, -1, sizeof(dp));

        long long m = 1;
        for (int i = 0; i < 12; i++) {
            for (int j = s.size() - i - 1; j >= 0; j--) {
                long long n = s[j] - '0';

                if (i == 0) dp[j][i] = max(n * m, dp[j+1][i]);
                else dp[j][i] = max(n * m + dp[j+1][i-1], dp[j+1][i]);

            }

            m *= 10;
        }

        res += dp[0][11];
    }

    cout << res << '\n';

    return 0;
}