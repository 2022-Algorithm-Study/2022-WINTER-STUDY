#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define ll long long
#define MAX 200002
using namespace std;

int V; // 정점 
int M; // 워프
vector<pair<int, ll>> adj[MAX]; // 번호, 시간

// union-find
struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}
	//u가 속한 트리의 루트 번호 반환
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	//u가 속한 트리와 v가 속한 트리를 합친다
	void merge(int u, int v) {
		u = find(u); v = find(v);
		//u와 v가 이미 같은 트리에 속하는 경우 걸러냄
		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if (rank[u] == rank[v]) ++rank[v];
	}
};

ll kruskal() {
	ll ret = 0;

	vector<pair<ll, pair<int, int>>> edges;

	for (int u = 0; u < V; ++u) {
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i].first;
			ll cost = adj[u][i].second;
			edges.push_back({ cost, {u, v} });
		}
	}

	sort(edges.begin(), edges.end()); // 가중치순

	DisjointSet sets(V); //처음엔 모든 정점이 서로 분리되어 있다.

	for (int i = 0; i < edges.size(); ++i) {
		ll cost = edges[i].first;
		int u = edges[i].second.first;
		int v = edges[i].second.second;

		//간선 (u, v)를 검사한다.
		//이미 u와 v가 연결되어있을 경우(사이클) 무시
		if (sets.find(u) == sets.find(v)) continue;

		//설치할 수 있는 워프의 개수 확인
		if (u != 0 && v != 0) {
			if (M == 0) continue;
			else M--;
		}
		sets.merge(u, v);
		ret += cost;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//워프: 두 도시 사이를 연결하는 간선
	//비상 탈출구: 출구와 도시를 연결하는 간선

	cin >> V >> M;

	V++;

	for (int i = 0; i < M; ++i) { 		//워프 가중치
		int a, b;
		ll c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

		
	for (int i = 1; i < V; ++i) { //비상 탈출구 가중치
		ll t;
		cin >> t;
		adj[0].push_back({ i, t });
		adj[i].push_back({ 0, t });
	}

	cout << kruskal();
	return 0;
}
