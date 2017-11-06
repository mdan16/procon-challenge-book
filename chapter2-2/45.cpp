#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_N = 2000;

int N;
string S, T;

int main(int argc, char const* argv[])
{
    cin >> N;
    cin >> S;

    for (int i = 0; i < N; i++) {
        string r_S = S;
        reverse(r_S.begin(), r_S.end());
        if (S < r_S) {
            T += S.substr(0, 1);
            S = S.substr(1);
        } else {
            T += r_S.substr(0,1);
            S = S.substr(0, S.size() - 1);
        }
    }

    cout << T << endl;
    return 0;
}
