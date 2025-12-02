#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string rotation;
    int dial = 50;
    int zero_cnt = 0;

    while (cin >> rotation) {
        char orientation = rotation[0];
        int distance = stoi(rotation.substr(1));
        zero_cnt += distance / 100;

        int oriented_distance = (distance % 100) * (orientation == 'L' ? -1 : 1);
        zero_cnt += (dial > 0 && dial + oriented_distance <= 0) || (dial + oriented_distance >= 100);
        dial = (100 + dial + oriented_distance) % 100;
    }

    cout << zero_cnt << '\n';

    return 0;
}
