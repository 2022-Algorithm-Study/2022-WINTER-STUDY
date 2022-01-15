// G3: 23327 리그전 오브 레전드

#include <iostream>
using namespace std;

int N, Q;
long long arrsum[100001]; // N=100,000
long long sum[100001];

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) { // 1등의 index는 0번에
		int input; cin >> input; 
		if (i == 0) {
			sum[i] = input;
			arrsum[i] = 0;
		} 
		else {
			sum[i] = sum[i - 1] + input;
			arrsum[i] = arrsum[i - 1] + sum[i-1] * input;
		}
	}

	for (int i = 0; i < Q; i++) {
		int l, r;
		cin >> l >> r;
		
		long long ans = 0;
		
		if (l == 1) ans = arrsum[r];
		else ans = arrsum[r] - arrsum[l-1] - (sum[r] - sum[l - 1]) * sum[l - 1];

		cout << ans << "\n";
	}

	return 0;
}
