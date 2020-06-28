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
using namespace std;
const int  MAX = 1e7+1;

vector<int> prime;
vector<int> isPrime(MAX);
vector<int> spf(MAX);

void sieve(int n){
    for(int i = 2; i < n; i++){
        if(!isPrime[i]){
            prime.push_back(i);
            spf[i] = i;
        }
        for(int j = 0; j < (int)prime.size() && i*prime[j] < n && prime[j] <= spf[i]; j++){
            isPrime[i*prime[j]] = 1;
            spf[i*prime[j]] = prime[j];
        }
    }
}

int main(){
    int n = 1e7;
    sieve(n);
    cout << prime.size() << endl;
}

