#include <math.h>
#include <stdio.h>

typedef unsigned long long ull;

ull fib(ull n) {
ull a, b, c, d, t;
#define ad t
#define dd t
    a = d = 1;
    b = c = 0;
    while(1){
        if (n & 1) {
            ad = a*d;
            a = ad + a*c + b*d;
            b = ad + b*c;
        }
        n >>= 1;
        if (n == 0)
            break;
        dd = d*d;
        d = dd + 2*d*c;
        c = dd + c*c;
    }
    return b;
}
ull logb(ull n){
    return log(n)/log(2);
}

int main()
{
    int t; scanf("%d", &t);
    for(int i = 1;i <= t; i++){
        ull n;
        scanf("%llu", &n);
        printf("%llu\n",fib(pow(2, logb(n))-1)%10);
    }
}

