#include <bits/stdc++.h>
using namespace std;

int dp1[105], dp2[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    int res = 0;
    while (cin >> s) {
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));

        for (int i = s.size() - 1; i >= 0; i--) {
            int n = s[i] - '0';
            if (i == 99) {
                dp1[i] = n;
                dp2[i] = n;

                continue;
            }

            dp1[i] = max(n, dp1[i+1]);
            dp2[i] = max(n * 10 + dp1[i+1], dp2[i+1]);
        }

        res += dp2[0];
    }

    cout << res << '\n';

    return 0;
}