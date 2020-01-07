#include <bits/stdc++.h>
using namespace std;

double mysqrt(double n){
    double low = 0.0;
    double high = n;
    double mid;
    while(high - low > .0001){
        mid = (low+high)/2;
        if(mid*mid > n)
            high = mid;
        else
            low = mid;
    }
    return mid;
}



int main(){
    double test = mysqrt(50);
    printf("%.2lf\n", test);
}

