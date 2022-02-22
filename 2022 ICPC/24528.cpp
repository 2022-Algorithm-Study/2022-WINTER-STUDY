nclude <iostream>
#define ll long long
using namespace std;

ll N, M;
ll ans = 0;

int calc(int n, int m) {
	return (m - 1) * m / 2.0 * (n / m) + (1 + (n % m)) / 2.0 * (n % m);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	ll mid = N / 2;
	ll cur = 0;

	for (ll i = 1; i <= mid; i++) {		
		ans = (ans + (N / i) * (i % M));
	}
	ans %= 1000000007;

	long double sigma = (M - 1) * M / 2.0; // 3

	ll newtotal = 0;
	if (N > M) {
		newtotal = calc(N, M) - calc(N / 2, M);
	}

	else if (N == M) {
		newtotal = (1.0 + N-1) / 2.0 * (N-1) - (1.0 + mid) / 2.0 * mid;
	}
	else{ // N < M
		newtotal = (1.0 + N) / 2.0 * N - (1.0 + mid) / 2.0 * mid;
	}
	newtotal %= 1000000007;
	ans += newtotal;
	cout << ans;
}
