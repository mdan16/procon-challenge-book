#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 20000;

int N, L[MAX_N];

int main(int argc, char const* argv[])
{
    cin >> N;
    int sum = 0, num = 0;
    for (int i = 0; i < N; i++) {
        cin >> L[i];
        sum += L[i];
        num++;
    }

    int dep = 0, node = N;
    while (true) {
        if (node%2 == 0) {
            node = node / 2;
        } else {
            node = node / 2 + 1;
        }
        dep++;
        if (node == 1) {
            break;
        }
    }

    int ans = sum * (dep - 1);
    cout << ans << endl;
    sort(L, L + N);

    int end = (N - 2 * (dep - 1)) * 2;
    cout << end << endl;
    for (int i = 0; i < end; i++) {
        ans += L[i];
    }

    cout << ans << endl;
    return 0;
}
