#include <iostream>
using namespace std;

const int MAX_N = 1000;

int N, R, X[MAX_N];

int main(int argc, char const* argv[])
{
    cin >> N >> R;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    int ans = 1, last = 0;
    for (int i = 0; i < N; i++) {
        if (X[i] >= R) {
            last = i - 1;
            break;
        }
    }

    for (int i = last + 1; i < N; i++) {
        if (X[i] - X[last] > R) {
            last = i;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
