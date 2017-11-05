#include <iostream>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;

const int MAX_N = 100000;

int n, s[MAX_N], t[MAX_N];

int main(int argc, char const* argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    pair<int, int> p[MAX_N];
    for (int i = 0; i < n; i++) {
        p[i].first = t[i];
        p[i].second = s[i];
    }

    sort(p, p+n);

    int time = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (time <= p[i].second) {
            time = p[i].first;
            cout << time << endl;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
