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

const int MX = 1e5 + 5;
int arr[MX];

struct Node {
    int count, prop;
    Node(): count(0), prop(0) {}
};

Node tree[MX * 4];

void buildTree (int node, int l, int r) {
    if (l == r) {
        tree[node].count = arr[l];
        return;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (l + r) / 2;
    buildTree(left, l, mid);
    buildTree(right, mid + 1, r);
    tree[node].count = tree[left].count + tree[right].count;
}

void update (int node, int l, int r, int i, int j, int value) {
    if (r < i || l > j)
        return;
    if (l >= i && r <= j) {
        tree[node].count += value * (r - l + 1);
        tree[node].prop += value;
        return;
    }
    int left = 2 * node;
    int right = 2 * node + 1;
    int mid = (l + r) / 2;
    update(left, l, mid, i, j, value);
    update(right, mid + 1, r, i, j, value);
    tree[node].count = tree[left].count + tree[right].count + tree[node].prop * (r - l + 1);
}
int query (int node, int l, int r, int i, int j, int carry = 0) {
    if (r < i || l > j)
        return 0;
    if (l >= i && r <= j)
        return tree[node].count + carry * (r -l + 1);
    int left = 2 * node;
    int right = 2 * node + 1;
    int mid = (l + r) / 2;
    int q1 = query(left, l, mid, i, j, tree[node].prop + carry);
    int q2 = query(right, mid + 1, r, i, j, tree[node].prop + carry);
    return q1 + q2;
}

signed main () {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) 
        cin >> arr[i];
    buildTree(1, 1, n);

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int i, j, v; cin >> i >> j >> v;
            update(1, 1, n, i, j, v);
        }
        else {
            int i, j; cin >> i >> j;
            cout << query(1, 1, n, i, j) << endl;
        }
    }
}

