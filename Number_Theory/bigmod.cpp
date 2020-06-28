#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <climits>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define all(var) var.begin(), var.end()
#define input freopen("input", "r", stdin)
#define output freopen("output", "w", stdout)
#define Fast ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL)
typedef long long ll;
using namespace std;

// calculate a^b in O(logn) time
const int mod = 1e9+7;

ll bigMod(ll a, ll b){
    if(b == 0) return 1;
    if(b == 1) return a;
    if(b&1) 
        return a*bigMod(a, b-1)%mod;
    a = bigMod(a, b/2)%mod;
    return a*a%mod;
}

int main(){
    cout << bigMod(2, 1e18) << endl;
}

