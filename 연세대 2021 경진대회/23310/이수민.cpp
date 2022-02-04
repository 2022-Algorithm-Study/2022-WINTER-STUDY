#include <iostream>
using namespace std;

int N, M;
int main() {
	cin >> N >> M;

	int idx = 1;
	int mmin = 987654321;
	int mminidx = 0;

	while (idx <= N) {
		int cnt = 0; // x와 값이 같아져서 종료 조건에 사용
		int x; cin >> x;
		if (N % M == 0 && idx % M == 0) { // 절대 끝날 수 없음
			idx++;
		}
		else {
			int times = 0; // 총 검사하는 횟수

			int a = x / M; 
		
			times = times + M * (a-1); 
			cnt = cnt + (M - 1) * (a-1);
	
			while (1) {
				if (cnt == x) {
					break;
				}
				else { // 더 검사를 해야 한다면
					times++;
					if (times >= mmin) break; // 최소 조건보다 크다면
					
					long long temp = N * (times - 1) + idx;
					if (temp % M != 0) { // M의 배수가 아닌 경우
						cnt++;
					}
				}				
			}

			if (mmin > times) {
				mmin = times;
				mminidx = idx;
			}
			idx++;
			// cout << x << " " << times << "\n";
		}
	}
	cout << mminidx;
	return 0;
}
