#TLE

#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
#define INF 1e9
using namespace std;

int n, s, e;
pair<int, int> pos[100001];
int cost[100001];
int sdir[100001];
long long dist[100001];
int parent[100001];

string dir[8] = { "N", "NE", "E", "SE", "S", "SW", "W", "NW" };

int dirof(int cur, int next) {
    if (pos[cur].first == pos[next].first) { // x 좌표가 같을 때
        if (pos[cur].second < pos[next].second) return 0; // N
        else return 4; // S
    }

    if (pos[cur].second == pos[next].second) { // y 좌표가 같을 때
        if (pos[cur].first < pos[next].first) return 2; // E
        else return 6; // W
    }

    if (abs(pos[cur].first - pos[next].first) == abs(pos[cur].second - pos[next].second)) { // 대각선 방향에 있을 때
        if (pos[cur].first < pos[next].first) { // next가 cur의 동쪽에 있음 (NE 또는 SE)
            if (pos[cur].second < pos[next].second) return 1; // NE
            else return 3; // SE
        }
        else { // pos[cur].first > pos[next].first // next가 cur의 서쪽에 있음 (NW 또는 SW)
            if (pos[cur].second < pos[next].second) return 7; // NW
            else return 5; // SW
        }
    }

    return -1;
}

void dijkstra(int st, int en) {
    priority_queue<pair<int, int>> pq;
    memset(parent, -1, sizeof(parent));
    fill(dist, dist + n + 1, INF);
    dist[st] = 0;
    pq.push({ 0, st });

    while (!pq.empty()) {
        int cc = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cc) continue;

        int d;
        for (int next = 1; next <= n; next++) {
            if (next == cur) continue;
            if ((d = dirof(cur, next)) == -1) continue;
            int nc = cc + abs(sdir[cur] - d) * cost[cur];
            if (nc < dist[next]) {
                dist[next] = nc;
                parent[next] = cur;
                pq.push({ -nc, next });
            }
        }
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> s >> e;
    for (int i = 1; i <= n; i++) {
        string dstr;
        cin >> pos[i].first >> pos[i].second >> cost[i] >> dstr;
        for (int j = 0; j < 8; j++) {
            if (dstr == dir[j]) {
                sdir[i] = j; break;
            }
        }
    }

    dijkstra(s, e);

    if (dist[e] == INF) {
        cout << "-1\n";
        return 0;
    }

    cout << dist[e] << '\n';
    int cur = e;
    stack<int> s;
    while (cur != -1) {
        s.push(cur);
        cur = parent[cur];
    }
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';
    
    return 0;
}
