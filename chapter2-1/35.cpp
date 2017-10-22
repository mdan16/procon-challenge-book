#include <iostream>
using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;
char input[MAX_N][MAX_M];
int N, M;
int ans;

void dfs(int x, int y)
{
    input[x][y] = '.';
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int nx = x + dx;
            int ny = y + dy;
            if ((nx >= 0 && nx < M) && (ny >= 0 && ny <= N) && input[nx][ny] == 'W') {
                input[nx][ny] = '.';
                dfs(nx, ny);
            }
        }
    }
    return;
}

int main(int argc, char const* argv[])
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input[j][i];
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (input[j][i] == 'W') {
                dfs(j, i);
                ans++;
                cout << j << " " << i << endl;
            }
        }
    }
    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << input[j][i];
        }
        cout << endl;
    }
    */
    cout << ans << endl;
    return 0;
}
