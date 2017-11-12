#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

const int MAX_N = 100;
int n, w[MAX_N], v[MAX_N], W;
int dp[MAX_N][MAX_N];

int dfs(int i, int j) {
    if (dp[i][j] >= 0) {
        return dp[i][j];
    }
    int value = 0;
    if (i == n) {
        return 0;
    } else if (j < w[i]) {
        value = dfs(i + 1, j);
    } else {
        value = max(dfs(i + 1, j), dfs(i + 1, (j - w[i])) + v[i]);
    }
    return dp[i][j] = value;
}

int main(int argc, char const* argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        cin >> v[i];
    }
    cin >> W;

    fill(dp[0], dp[MAX_N], -1);

    cout << dfs(0, W) << endl;
    return 0;
}
