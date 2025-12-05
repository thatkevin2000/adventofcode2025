#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long>> ranges;
vector<long long> queries;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    while (cin >> s) {
        int pos = s.find('-');

        if (pos != -1) {
            long long a = stoll(s.substr(0, pos));
            long long b = stoll(s.substr(pos+1));
            ranges.push_back(make_pair(a, b));
        } else {
            queries.push_back(stoll(s));
        }
    }

    sort(ranges.begin(), ranges.end());
    sort(queries.begin(), queries.end());

    int i = 0, j = 0, res = 0;
    while (i < ranges.size() && j < queries.size()) {
        if (ranges[i].first <= queries[j] && ranges[i].second >= queries[j]) {
            res++;
            j++;
        } else if (ranges[i].first < queries[j]) {
            i++;
        } else {
            j++;
        };
    }

    cout << res << '\n';

    return 0;
}
