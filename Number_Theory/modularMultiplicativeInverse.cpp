#include <bits/stdc++.h>
#define endl '\n'
#define umap unordered_map
#define all(var) var.begin(), var.end()
#define input freopen("input", "r", stdin)
#define output freopen("output", "w", stdout)
#define Fast ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define dbg(x) cerr << #x << " => " << x << endl
using ll = long long;
using namespace std;

const int MOD = 1e9 + 7;

ll power (int a, int n) {
    if (n == 0) return 1;
    if (n & 1) return (a * power(a, n - 1)) % MOD;
    ll ret = power(a, n / 2);
    return ret * ret % MOD;
}
ll fact[2005];

void genFactorial () {
    fact[0] = 1;
    for (ll i = 1; i <= 2000; i++) {
        fact[i] = (i * fact[i-1]) % MOD;
    }
}

signed main () {
    Fast;
    genFactorial();
    int tc; cin >> tc;
    while (tc--) {
        int n, m; cin >> n >> m;
        m--;
        ll up = fact[n + m];
        ll down = (fact[n] * fact[m]) % MOD;
        cout << (up * power(down, MOD-2)) % MOD << endl;   // Fermet's little theorem :)
    }

}
