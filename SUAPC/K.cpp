#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

string str;
long long sum[100003];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> str;
    str = " " + str;

    long long size = str.size();
    for (int i = 1; i < size; i++) {
        if (str[i] == '(') sum[i] = sum[i - 1] + 1;
        else sum[i] = sum[i - 1] - 1;
    }

    long long cnt = 0;
    if (sum[size - 1] > 0) { // '('가 더 많음
        for (int i = size - 1; i > 0; i--) {
            if (str[i] == '(') cnt++;
            else {
                if (sum[i] == 0) break;
            }
        }
    }

    else { // ')'가 더 많음
        for (int i = 1; i < size; i++) {
            if (str[i] == ')') cnt++;
            else {
                if (sum[i] == 0) break;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}
