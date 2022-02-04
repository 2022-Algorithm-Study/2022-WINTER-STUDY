#include <iostream>
#define ll long long
#define MAX 1e17
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll n, m, x, ans = MAX, idx; cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> x;

        if (n % m == 0 && i % m == 0) continue;

        ll a = x / m; // 몫 (주기 m인 사이클 몇 번?)
        ll d = a * m; // 주기동안 지난 날

        if (m % n == 0) { // ex) input : 2 4
            if (i == n) x -= (m - n) * a; // 2 4 에서 두번째 과제
            else x -= m * a; // 2 4 에서 첫번째 과제
        }
        else x -= (m - 1) * a;

        if (x <= 0 && d < ans) {
            ans = d;
            idx = i;
            continue;
        }

        if (d >= ans) continue;

        ll j = 0;
        while (++j) {
            ll value = n * (j - 1) + i;

            if (value % m == 0) continue;
            if (--x == 0) {
                // cout << i << " : " << d + j << '\n';
                if (d + j < ans) {
                    ans = d + j;
                    idx = i;
                }
                break;
            }

        }
    }

    cout << idx << '\n';

    return 0;
}
