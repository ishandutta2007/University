#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//Çó(a^b) mod n
long long judge(long long a, long long b, long long n){
    long long d=1 , t=a;
    while (b>0) {
        if (t==1) return d ;
        if (b%2==1) d=d*t%n;
        b/=2;
        t=t*t%n;
    }
    return d;
}

bool nprime[10001] = {1,1};
void psieve(int n){
    int t = (int)sqrt(n), tmp ;
    for ( int i = 2; i <= t; i++ ){
        if ( !nprime[i] )
            for( int j=i; (tmp=j*i) <=n; j++ ) nprime[tmp] = true ;
    }
}

int main(){
    unsigned int n;
    psieve(10000) ;
    srand(100) ;
    while( scanf("%u", &n) != EOF ){
        if ( n <= 10000 ) printf("%s\n", nprime[n] ? "NO" : "YES") ;
        else if ( n%2 == 0 || n%3 == 0 ) puts("NO") ;
        else {
            int i, a ;
            for (i=1; i<=5; i++){
                a = 2 + rand()%(n-2) ;
                if ( judge(a, n-1, n) != 1 ) break ;
            }
        if( i == 6 ) puts("YES") ;
        else puts("NO") ;
        }
    }
    return 0;
}
