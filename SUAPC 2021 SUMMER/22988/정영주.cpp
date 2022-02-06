#include <iostream>
#include <set>
using namespace std;

multiset<long double> s;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long n;
    long double x;
    cin >> n >> x;
    long double half = x / 2;

    for (int i = 0, a; i < n; i++) {
        cin >> a;
        s.insert(a);
    }

    long long ans = 0;
    while (s.size() > 1) {
        long double sum = *s.begin() + *s.rbegin();
        if (sum >= half) {
            ans++;
            s.erase(s.begin());
            s.erase(--s.end());
        }
        else {
            sum = *s.begin();
            s.erase(s.begin());
            sum += *s.begin();
            s.erase(s.begin());
            s.insert(sum + half);
        }
    }

    cout << ans << '\n';

    return 0;
}
