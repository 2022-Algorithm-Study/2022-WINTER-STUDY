#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <queue>
#include <set>
#include <map>
using namespace std;

int N;
int ans1;
int ans2;
int arr[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++){
		cin >> arr[i];
		ans1 += arr[i];
	}
	
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		if (x == 0) ans2 += arr[i];
	}

	cout << ans1 << "\n";
	cout << ans2;
	return 0;
}
