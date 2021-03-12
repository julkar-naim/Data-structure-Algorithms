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

int phi (int n) {
    int ret = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) 
                n /= i;
            ret -= ret / i;
        }
    }
    if (n > 1)
        ret -= ret / n;
    return ret;
}

signed main () {
    int n; cin >> n;
    cout << phi(n-1) << endl;
}
