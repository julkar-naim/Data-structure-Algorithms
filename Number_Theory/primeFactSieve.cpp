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

ll const M = 1e7;

vector<ll> prime;

void sieve(){
    vector<bool> p(M);
    for(ll i = 2; i <= sqrt(M); i++){
        if(!p[i])
            for(ll j = i*i; j < M; j+=i)
                p[j] = true;
    }
    for(ll i = 2; i < M; i++)
        if(!p[i]) prime.push_back(i);
}

int main(){
    sieve();
    ll n; cin >> n;
    int cnt = 0;

    while(n!=0){
        bool flag = true;
        for(int i = 0; i < (int)prime.size(); i++){
            if(n%prime[i]==0){
                cnt++;
                n -= prime[i];
                flag = false;
                break;
            }
        }
        if(flag) break;
    }
    cout << (cnt ? cnt : 1) << endl;
}

