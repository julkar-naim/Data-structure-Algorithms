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

void leastPrimeFactor(int n){
    vector<int> leastPf(n+1);
    for(int i = 2; i <= n; i++){
        if(!leastPf[i]){
            leastPf[i] = i;
            for(int j = i*2; j <= n; j+=i)
                if(!leastPf[j])
                    leastPf[j] = i;
        }
    }
    for(int i = 1; i <= n; i++){
        printf("%d\n" , leastPf[i]);
    }
}

int main(){
    int n; cin >> n;
    leastPrimeFactor(n);
}

