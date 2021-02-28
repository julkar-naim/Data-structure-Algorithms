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

ll const M = 2500;
ll const MOD = 1e9;
ll C[M][M]{};

ll computeC (ll n, ll r) {
    if (n == r || r == 0) return 1LL;
    if (n == r) return n;
    if (C[n][r]) return C[n][r];
    return C[n][r] = (computeC(n-1, r) % MOD + computeC(n-1, r-1) % MOD) % MOD;
}

signed main () {
    cout << computeC(20, 6) << endl;
}
