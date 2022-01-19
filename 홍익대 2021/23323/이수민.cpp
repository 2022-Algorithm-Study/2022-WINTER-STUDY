// 현재 가진 먹이로 황소가 최대 며칠까지 생존 가능한지

#include <iostream>
using namespace std;

long long day = 0;
int T; // 테스트 케이스

int main() {
	
	cin >> T;
	while (T--) {
		long long n, m; cin >> n >> m;
		long long cnt = 1;
		while (n > 1) {
			n = n / 2;
			cnt++;
		}
		cnt += m;
		cout << cnt << "\n";
	}
	return 0;
}
