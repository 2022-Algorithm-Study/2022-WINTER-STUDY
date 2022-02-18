#include <iostream>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;

int N;
ll T;
ll arr[13];
ll newarr[13];
long double cnt = 0;

void check(int turn) {
	if (turn == N) { // 종료조건
		//for (int i = 0; i < N; i++)
		//	cout << newarr[i] << " ";
		//cout << "\n";
		for (int i = 0; i < N-1; i++) {
			for (int j = i+1; j < N; j++) {
				if (newarr[i] >= newarr[j]) {
					cnt++;
				}
			}
		}
		return;
	}
	newarr[turn] = arr[turn] + T;
	check(turn+1);
	newarr[turn] = arr[turn] - T;
	check(turn+1);

}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> T;
	sort(arr, arr + N);
	check(0);

	long double bottom = pow(2.0, N);
	long double top = cnt;

	long double ans = top / bottom;
	// cout << top << " " << bottom << "\n";
	cout << ans << "\n";

	return 0;
}
