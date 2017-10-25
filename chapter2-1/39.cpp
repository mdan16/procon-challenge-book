#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 10;

bool used[MAX_N];
int perm[MAX_N];

void permutation1(int pos, int n)
{
    if (pos == 0) {
        for (int i = 0; i < n; i++) {
            cout << perm[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            perm[pos] = i;
            used[i] = true;
            permutation1(pos + 1, n);
            used[i] = false;
        }
    }
    return;
}

int perm2[MAX_N];

void permutation2(int n)
{
    for (int i = 0; i < n; i++) {
        perm2[i] = i;
    }
    do {
        for (int i = 0; i < n; i++) {
            cout << perm2[i] << " ";
        }
        cout << endl;
    } while (next_permutation(perm2, perm2 + n));
    return;
}

int main(int argc, char const* argv[])
{
    permutation1(0, 3);
    return 0;
}
