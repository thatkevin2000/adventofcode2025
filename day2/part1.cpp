#include <bits/stdc++.h>
using namespace std;

bool isValid(long long n) {
    string s = to_string(n);
    int size = s.size();
    if (size & 1) return false;

    string a = s.substr(0, size / 2);
    string b = s.substr(size / 2);

    return a == b;
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
            if (isValid(i)) {
                result += i;
            }
        }
    }

    cout << result << '\n';

    return 0;
}