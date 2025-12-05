#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long>> ranges;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    while (cin >> s) {
        int pos = s.find('-');
        if (pos == -1) break;

        long long a = stoll(s.substr(0, pos));
        long long b = stoll(s.substr(pos+1));
        ranges.push_back(make_pair(a, b));
    }

    sort(ranges.begin(), ranges.end());

    long long res = 0;
    long long left = ranges[0].first;
    long long right = ranges[0].second;
    for (int i = 0; i < ranges.size(); i++) {
        if (ranges[i].first <= right) {
            right = max(right, ranges[i].second);
        } else {
            res += right - left + 1;
            left = ranges[i].first;
            right = ranges[i].second;
        }
    }

    res += right - left + 1;

    cout << res << '\n';

    return 0;
}
