#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[1002][1002][2];
int ans[4] = { 0, 0, 0 };

pair<int, int> fv, sv;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

queue<pair<pair<int, int>, int>> q;

void bfs() {
    q.push({ fv, 0 });
    q.push({ sv, 0 });

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int a = x + dx[k];
            int b = y + dy[k];

            if (a < 0 || a >= n || b < 0 || b >= m) continue;

            if (arr[x][y][0] == 1) {
                if (arr[a][b][0] == 0) {
                    arr[a][b][0] = 1;
                    arr[a][b][1] = z + 1;
                    q.push({ { a, b }, z + 1 });
                }
                else if (arr[a][b][0] == 2 && arr[a][b][1] == z + 1) {
                    arr[a][b][0] = 3;
                    arr[a][b][1] = z + 1;
                }
            }

            else if (arr[x][y][0] == 2) {
                if (arr[a][b][0] == 0) {
                    arr[a][b][0] = 2;
                    arr[a][b][1] = z + 1;
                    q.push({ { a, b }, z + 1 });
                }
                else if (arr[a][b][0] == 1 && arr[a][b][1] == z + 1) {
                    arr[a][b][0] = 3;
                    arr[a][b][1] = z + 1;
                }
            }
        }
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j][0];
            if (arr[i][j][0] == 1) fv = { i, j };
            else if (arr[i][j][0] == 2) sv = { i, j };
        }
    }

    bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j][0] << ' ';
            if (arr[i][j][0] == -1) continue;
            ans[arr[i][j][0]]++;
        }
        cout << '\n';
    }

    for (int i = 1; i < 4; i++) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}
