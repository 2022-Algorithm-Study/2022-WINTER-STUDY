#include <iostream>
#include <vector>
#define ll long long
#define MAX 100002
using namespace std;

vector<int> v[MAX];
bool visited[MAX];
ll cnt;
int s1, s2;
bool flag;

void dfs(int now, int num) {
	visited[now] = true;
	cnt++;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (now != s1 && next == s2)
			flag = true;
		if (visited[next])
			continue;
		dfs(next, num + 1);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	ll N, M, K; cin >> N >> M >> K;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		if (i == K) {
			s1 = a;
			s2 = b;
			visited[b] = true;
		}
	}
	dfs(s1, 0);
	if (flag)
		cout << 0;
	else cout << (N - cnt) * cnt;
	return 0;
}
