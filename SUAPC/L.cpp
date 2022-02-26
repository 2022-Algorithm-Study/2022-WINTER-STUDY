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

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        long long input; cin >> input;
        if (input % 10 == 0) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}
