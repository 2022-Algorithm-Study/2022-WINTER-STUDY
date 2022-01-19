// 두번째 시도
#include <iostream>
using namespace std;

int N;
int arr[101];
int X,Y;

int main() {
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> arr[i];
	cin >> X >> Y;

	float ratio = X/100.0; // X/100으로 하면 정수 값으로 인식됨
	cout << (N * ratio) << " ";
	int cnt=0;
	for(int i=0; i<N; i++){
		if (arr[i]>=Y) cnt++;
	}
	cout << cnt;
	return 0;
}
