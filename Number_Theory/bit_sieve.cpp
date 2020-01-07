#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

bool check(int n, int pos){
    return (n & (1<<pos));
}
void change(int* n, int pos){
    *n |= (1 << pos);
}
void sieve(int n, int* prime){
    change(&prime[0], 0);
    change(&prime[0], 1);

    int root = sqrt(n);
    for(int i = 2; i <= root; i++)
        if(!check(prime[i>>5], i&31))
            for(int j = i*i; j < n; j += i)
                change(&prime[j>>5], j&31);
}
int main(){
    int input;
    cin >> input;
    int size = input>>5;
    int* prime = new int[size];
    sieve(input, prime);

    for(int i = 1; i < input; i++)
        if(!check(prime[i>>5], i&31))
            printf("%d\n", i);
}