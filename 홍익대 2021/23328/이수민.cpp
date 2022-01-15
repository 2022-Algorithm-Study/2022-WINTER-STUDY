// G1: 23328 마을 구하기

#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <cstring>
using namespace std;

int N;
char bomb;
char shield;
vector <char> v;
int Bcnt=0, bcnt=0;
int Bstart, bstart;
string ans = "";
string before = "";
string after = "";
string adds = "";

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N; cin >> bomb;
	for (int i = 0; i < N; i++) {
		char input; cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());

	shield= tolower(bomb);

	for (int i = 0; i < N; i++) {
		if (v[i] == bomb) {
			if (Bcnt == 0) Bstart = i;
			Bcnt++;
		}
		else if (v[i] == shield && bcnt<2) {
			if (bcnt == 0) bstart = i;
			bcnt++;
		}
	}
	v.erase(v.begin()+Bstart, v.begin()+Bstart+Bcnt); // Bstart부터 Bcnt 개수만큼 삭제
	
	if (bcnt == 0) { // 실드 없으면
		if (Bstart != 0 ) { // B맨 뒤로 (Bstart부터 Bcnt개)
			while (Bcnt >= 1) {
				Bcnt--;
				v.push_back(bomb);
			}
		}
		// Bstart=0이면 B가 맨앞이니까 맨 앞으로
	}
	else if (bcnt == 1) { // 실드 1개
		
		if (Bstart != 0) { // B맨뒤로
			for (int i = 0; i < N-Bcnt; i++) {
				if (v[i] == shield) {
					v.erase(v.begin() + i);
					break;
				}
			}
			v.push_back(shield);
			for (int i = 1; i <= Bcnt; i++) {
				v.push_back(bomb);
			}
		}
		else { // B맨앞에
			for (int i = 0; i < N - Bcnt; i++) { //실드 제거
				if (v[i] == shield) {
					v.erase(v.begin() + i);
					break;
				}
			}
			for (int i = 1; i <= Bcnt; i++) {
				v.insert(v.begin(), bomb);
			}
			v.insert(v.begin() + Bcnt, shield);
		}
	}

	else { // 2개이상이면 나머지들은 원래 자리에 
		// 전체 벡터에서 b 2개랑 B모두 빼고
		int tmpcnt = 0;
		for (int i = 0; i < N-Bcnt; i++) { // shield 제거
			if (v[i] == shield) {
				v.erase(v.begin() + i, v.begin() + i + bcnt);
				break;
			}
		}
		
		int j = 0; int k = 0;
		for (int i = 0; i < N - Bcnt - bcnt; i++) {
			cout << v[2];
			if (v[i] < shield) {
				cout << v[i];
				before[j++] = v[i];
			}
			else if (v[i] == shield) {
				cout << v[i];
				after[k++] = v[i];
			}
			else {
				cout << v[i];
				after[k++] = v[i];
			}
		}
		adds.push_back(shield);
		for (int j = 1; j <= Bcnt; j++) {
			adds.push_back(bomb);
		}
		adds.push_back(shield);
		ans = before + adds + after;
	}

	if (bcnt == 2) {
		cout << ans;
	}
	else {
		for (int i = 0; i < N; i++) {
			cout << v[i];
		}
	}
	
	return 0;
}
