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

void primeFactor(ll n){
    while(!(n&1)){
        cout << 2 << " ";
        n /= 2;
    }
    for(int i = 3; i <= sqrt(n); i++){
        while(n%i == 0){
            cout << i << " ";
            n /= i;
        }
    }
    if(n > 2) cout << n;
    cout << endl;
}

int main(){
    ll n; cin >>n;
    primeFactor(n);
}

