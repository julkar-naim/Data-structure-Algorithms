#include <bits/stdc++.h>
#define endl '\n'
#define umap unordered_map
#define all(var) var.begin(), var.end()
#define input freopen("input", "r", stdin)
#define output freopen("output", "w", stdout)
#define Fast ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL)
#define dbg(x) cerr << #x << " => " << x << endl
using ll = long long;
using namespace std;

const int mx = 10;
int arr[mx];
int tree[mx * 4];

void buildTree (int node, int l, int r) {
    if (l == r) {
        tree[node] = arr[l];
        return;
    }
    int Left = 2 * node;
    int Right = 2 * node + 1;
    int Mid = (l + r) / 2;
    buildTree(Left, l, Mid);
    buildTree(Right, Mid + 1, r);
    tree[node] = tree[Left] + tree[Right];
}

int query (int node, int l, int r, int i, int j) {
    if (i > r || j < l)
        return 0;
    if (l >= i && r <= j)
        return tree[node];
    int left = 2 * node;
    int right = 2 * node + 1;
    int mid = (l + r) / 2;
    return query(left, l, mid, i, j) + query(right, mid + 1, r, i, j);
}

void update (int node, int l, int r, int index, int value) {
    if (l > index || r < index)
        return;
    if (index == l && index == r) {
        tree[node] = value;
        return;
    }
    int left = 2 * node;
    int right = 2 * node + 1;
    int mid = (l + r) / 2;
    update(left, l, mid, index, value);
    update(right, mid + 1, r, index, value);
    tree[node] = tree[left] + tree[right];
}

signed main(){
    int n = 6;
    for (int i = 1; i <= n; i++) 
        arr[i] = i;
    /* int n; cin >> n; */
    /* for (int i = 1; i <= n; i++) */ 
    /*     cin >> arr[i]; */

    buildTree(1, 1, n);
    cout << query(1, 1, n, 5, 5) << endl;
    update(1, 1, n, 4, 8);
    cout << query(1, 1, n, 3, 5);
}

