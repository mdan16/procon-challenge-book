#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;

int n, m;
char s[MAX_N], t[MAX_M];
int dp[MAX_N + 1][MAX_M + 1];

int main(int argc, char const* argv[])
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
