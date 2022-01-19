#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N; // 플레이어
vector <long long> v; // 음수 집합

int main() {
	
	cin >> N;

	int tmp = 0;
	int cnt = 0;
	for (long long i = 0; i < N; i++) {
		int x; cin >> x;
		if (x >= 0) {
			tmp = tmp + x;
			cnt++;
		}
		else {
			v.push_back(x);
		}
	}

	sort(v.begin(), v.end()); // 오름차순으로 정렬

	long long idx = 0;
	long long ans = tmp * cnt;
	while (!v.empty()) {
		int x = v.back(); v.pop_back();

		if ((ans + x) > (tmp + x) * cnt) {
			ans = (ans + x);
		}
		else {
			ans = (ans + x) * cnt;
			tmp = tmp + x;
			cnt++;
		}
	}

	cout << ans;

	return 0;
}
