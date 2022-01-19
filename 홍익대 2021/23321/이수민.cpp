#include <iostream>
#include <string>
using namespace std;

string s1, s2, s3, s4, s5;
char newarr[50010];

int main() {

	cin >> s1 >> s2 >> s3 >> s4 >> s5;

	int len = s3.length(); // 학생 수
	int idx = 1;
	for (int i = 0; i < len; i++) {
		if (s3[i] == 'm') { // 도약 준비
			newarr[idx++] = 'o';
			newarr[idx++] = 'w';
			newarr[idx++] = 'l';
			newarr[idx++] = 'n';
			newarr[idx++] = '.';
		}
		else if (s3[i] == 'l') { // 도약 중
			newarr[idx++] = '.';
			newarr[idx++] = 'o';
			newarr[idx++] = 'm';
			newarr[idx++] = 'l';
			newarr[idx++] = 'n';

		}
		else if (s3[i] == 'o') { // 착석
			newarr[idx++] = '.';
			newarr[idx++] = '.';
			newarr[idx++] = 'o';
			newarr[idx++] = 'L';
			newarr[idx++] = 'n';
		}
	}
		
	for (int i = 1; i <= 5; i++) {
		int start = i;
		for (int j = 1; j <= len; j++) {
			cout << newarr[start];
			start = start + 5;
		}
		cout << "\n";
	}

	return 0;
}
