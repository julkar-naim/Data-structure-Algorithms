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

const int mod = 10;

struct Matrix{
    ll mat[2][2];
};
Matrix multiply(Matrix a, Matrix b){
    Matrix ret;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            ll sum = 0;
            for(int k = 0;k < 2; k++)
                sum += a.mat[i][k]*b.mat[k][j];
            sum%=mod;
            ret.mat[i][j] = sum;
        }
    }
    return ret;
}

Matrix maxpo(Matrix a, ll n){
    if(n == 1) return a;
    if(n&1) 
        return multiply(a, maxpo(a, n-1));
    Matrix ret = maxpo(a, n/2);
    return multiply(ret, ret);
}
ll fib(ll n){
    if( n == 0 || n == 1) return n;
    Matrix a,r;
    a.mat[0][0] = a.mat[0][1] = a.mat[1][0] = 1;
    a.mat[1][1] = 0;
    r = maxpo(a, n-1);
    return r.mat[0][0];
}

int main(){
    input;
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll i = pow(2, (int)log2(n)); // don't know why but it doesn't work :/ :/ 
        // but this thing works fine 
        // i = 1;
        // while(i*2 <= n) i*=2;
        cout << fib(i-1) << endl;
    }
}

