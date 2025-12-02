#include <bits/stdc++.h>
using namespace std;

bool check(string str, int divisor) {
    int size = str.size();

    set<string> s;
    for (int i = 0; i < size; i += divisor) {
        s.insert(str.substr(i, divisor));

        if (s.size() > 1) return false;
    }

    return s.size() == 1;
}

bool isValid(long long n) {
    string str = to_string(n);
    int size = str.size();

    for (int i = 1; i < size; i++) {
        if (size % i != 0) continue;

        if (check(str, i)) return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string token;
    long long result = 0;
    while (getline(cin, token, ',')) {
        int pos = token.find('-');

        long long lowerBound = stoll(token.substr(0, pos));
        long long upperBound = stoll(token.substr(pos+1));

        for (long long i = lowerBound; i <= upperBound; i++) {
            if (isValid(i)) result += i;
        }
    }

    cout << result << '\n';

    return 0;
}