#include <bits/stdc++.h>
#define endl '\n'
#define umap unordered_map
#define all(var) var.begin(), var.end()
#define input freopen("input", "r", stdin)
#define output freopen("output", "w", stdout)
#define Fast ios_base::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define dbg(x) cerr << #x << " => " << x << endl
using Long = long long;
using namespace std;

class MergeSortTree {
    private: 
        vector<vector<int>> tree;
        unsigned int sz;
    public:
        MergeSortTree (vector<int>& arr) {
            this->sz = arr.size();
            this->tree.resize(4 * sz);
            build(1, 0, sz - 1, arr);
        }
    private:
        void build (int node, int lo, int hi, vector<int>& arr) {
            if (lo > hi) return;
            if (lo == hi) {
                tree[node] =  {arr[lo]};
                return;
            }
            int left = 2 * node;
            int right = 2 * node + 1;
            int mid = (lo + hi) / 2;
            build(left, lo, mid, arr);
            build(right, mid + 1, hi, arr);
            merge(all(tree[left]), all(tree[right]), back_inserter(tree[node]));
        }
        int query (int node, int lo, int hi, int l, int r, int element) {
            if (hi < l || lo > r) return 0;
            if (lo >= l && hi <= r) {
                return upper_bound(all(tree[node]), element) - tree[node].begin();
            }
            int left = 2 * node;
            int right = 2 * node + 1;
            int mid = (lo + hi) / 2;
            return query(left, lo, mid, l, r, element) + query(right, mid + 1, hi, l, r, element);
        }
    public: 
        int query (int l, int r, int element) {
            return query(1, 0, sz - 1, l, r, element);
        }
};


signed main () {

}

