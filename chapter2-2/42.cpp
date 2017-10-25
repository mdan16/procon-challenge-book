#include <iostream>
using namespace std;

int cVal[6] = {1, 5, 10, 50, 100, 500};
int C[6];
int A, ans;

int main(int argc, char const* argv[])
{
    for (int i = 0; i < 6; i++) {
        cin >> C[i];
    }
    cin >> A;

    for (int i = 5; i >= 0; i--) {
        int num = min(A / cVal[i], C[i]);
        A -= cVal[i] * num;
        ans += num;
    }
    cout << ans << endl;
    return 0;
}
