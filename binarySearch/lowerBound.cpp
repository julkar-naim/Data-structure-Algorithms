#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> v, int x){
    int low,high;
    low = 0; high = v.size()-1;
    int index = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(v[mid] == x){
            high = mid-1;
        }
        else if(x > v[mid])
            low = mid+1;
        else
            high = mid-1;
    }
    return low;

}
int upperBound(vector<int> v, int x){
    int low,high;
    low = 0; high = v.size()-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(v[mid] == x){
            low = mid + 1;
        }
        else if(x > v[mid])
            low = mid+1;
        else
            high = mid-1;
    }
    return low;

}

int main(){
    vector <int> v = {10, 20, 20, 30, 30, 40, 50};

    int s; cin >> s;

    int index = upperBound(v, s);

    int lower = lowerBound(v, s);

    cout << "Lower bound: " << lower <<endl;
    cout << "upper bound: " << index << endl;

    return 0;

}
