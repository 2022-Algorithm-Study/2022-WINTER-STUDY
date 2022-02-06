// 76% 틀렸습니다 (long double)
// 21% 틀렸습니다 (double)

#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll N;
long double X;
long double arr[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> X;
	for (ll i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr+N); // 오름차순으로 정렬

	ll start = 0;
	ll end = N - 1;

	ll cnt = 0; // 용기 수
	ll rest = N; // 2개 이하로 만들 수 없는 경우

	while (start <= end) { // 하나로 용기하나 채울 수 있는 경우
		if (arr[end] < X) break;
		else { // dp[end] >= X
			cnt++;
			end--;
			rest--;
		}
	}

	while (start < end) { // 2개로 최대한 해결해보기
		if (arr[start] + arr[end] >= X / 2.0) {
			cnt++; rest -= 2;
			start++; end--;
		}
		else start++;
	}
	
	cout << ( cnt + rest/3);

	return 0;
}
