// G1: 23328 마을 구하기

#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <cstring>
using namespace std;

string s;
int N, cnt = 0, sh = 0;
char bomb;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N >> bomb;
	cin >> s;
	sort(s.begin(), s.end());

	int start = -1;
	char shield = tolower(bomb);
	for (int i = 0; i < N; i++) {
		if (s[i] == bomb) {
			if (start == -1)start = i;
			cnt++;
		}
		if (s[i] == shield)sh++;
	}
	s.erase(start, cnt);
	string b;
	while (cnt--)b.push_back(bomb);
	if (sh >= 2) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == shield) {
				s.erase(i, 2);
				break;
			}
		}
		int index = lower_bound(s.begin(), s.end(), shield) - s.begin();
		if (s.empty()) {
			s += b + shield + shield;
		}
		else {
			if (s[0] >= bomb) {
				s += shield;
				sort(s.begin(), s.end());
				s = b + shield + s;
			}
			else if (s[s.length() - 1] <= shield) {
				s += shield;
				sort(s.begin(), s.end());
				s = s + shield + b;
			}
			else {
				string c = shield + b + shield;
				s.insert(index, c);
			}
		}
	}
	else if (sh == 1) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == shield) {
				s.erase(i, 1);
				break;
			}
		}
		if (s.empty()) {
			s = b + shield;
		}
		else {
			if (s[0] >= bomb)s = b + shield + s;
			else s = s + shield + b;
		}
	}
	else {
		if (s[0] >= bomb)s = b + s;
		else s = s + b;
	}
	cout << s << '\n';
}
