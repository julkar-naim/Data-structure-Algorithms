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

struct tupple{
    int left, right, sum;
};

tupple maxCross(int arr[], int lo, int mid, int hi){
    int left_sum, right_sum, max_left, max_right, sum = 0;
    left_sum = right_sum = INT_MIN;
    for(int i = mid; i >= lo; i--){
        sum += arr[i];
        if(sum > left_sum)
            left_sum = sum, max_left = i;
    }
    sum = 0;
    for(int i = mid+1; i <= hi; i++){
        sum += arr[i];
        if(sum > right_sum)
            right_sum = sum, max_right = i;
    }
    return {max_left, max_right, left_sum+right_sum};
}
tupple findMaxSub(int arr[], int lo, int hi){
    if(lo == hi) return {lo, hi, arr[lo]};
    int mid = (lo+hi)/2;
    tupple left = findMaxSub(arr, lo, mid);
    tupple right = findMaxSub(arr, mid+1, hi);
    tupple cross = maxCross(arr, lo, mid, hi);
    if( left.sum >= right.sum && left.sum >= cross.sum )
        return left;
    else if( right.sum >= left.sum && right.sum >= cross.sum)
        return right;
    else return cross;
}

int main(){
    int arr[] = {1,-2, 3, -4, 13, 5, -6, 10};
    int hi = sizeof(arr) / sizeof(int); hi--;
    tupple a = findMaxSub(arr, 0, hi);
    cout << a.left <<' '<< a.right << ' ' << a.sum << endl;
}


