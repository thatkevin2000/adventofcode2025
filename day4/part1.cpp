#include <bits/stdc++.h>
using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

char a[140][140];

bool check(int r, int c) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        cnt += (a[r + dx[i]][c + dy[i]] == '@');
    }

    return cnt < 4;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int res = 0;
    for (int i = 1; i <= 135; i++) {
        for (int j = 1; j <= 135; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= 135; i++) {
        for (int j = 1; j <= 135; j++) {
            if (a[i][j] == '@') res += check(i, j);
        }
    }

    cout << res << '\n';

    return 0;
}
