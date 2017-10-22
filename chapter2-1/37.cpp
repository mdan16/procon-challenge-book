#include <iostream>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;

const int MAX_N = 100;
const int MAX_M = 100;
const int INF = 100000000;

int N, M, sx, sy, gx, gy, ans;
int d[MAX_M][MAX_N];
char field[MAX_M][MAX_N];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs() {
    queue<P> que;
    que.push(P(sx, sy));
    d[sx][sy] = 0;

    while (que.size()) {
        P p = que.front();
        que.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if ((nx >= 0 && nx < M) && (ny >= 0 && ny < N) && d[nx][ny] == INF) {
                if (field[nx][ny] == '.') {
                    d[nx][ny] = d[p.first][p.second] + 1;
                    que.push(P(nx, ny));
                } else if (field[nx][ny] == 'G') {
                    d[nx][ny] = d[p.first][p.second] + 1;
                }
            }
        }
    }

    return d[gx][gy];
}

int main(int argc, char const* argv[])
{
    //input
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int  j = 0; j < M; j++) {
            cin >> field[j][i];
            if (field[j][i] == 'S') {
                sx = j;
                sy = i;
            } else if (field[j][i] == 'G') {
                gx = j;
                gy = i;
            }
            d[j][i] = INF;
        }
    }

    ans = bfs();
    cout << ans << endl;

    /*
    for (int i = 0; i < N; i++) {
        for (int  j = 0; j < M; j++) {
            cout << field[j][i];
        }
        cout << endl;
    }
    */
    return 0;
}
