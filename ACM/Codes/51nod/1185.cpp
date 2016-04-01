#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e18;

long long k2[2], a2[2], ak[2];


int main()
{
    int T;
    scanf("%d", &T);
    long long a, b;
    
    while(T--)
    {
    	k2[0] = k2[1] = a2[0] = a2[1] = ak[1] = ak[2] = 0LL;
    	cin >> a >> b;
        if(a > b) swap(a, b);
        
        long long k = b - a;
        if(a == (long long)((k)*(1+sqrt(5.0))/2.0)) cout << "B" << endl;
        else cout << "A" << endl;
        
    }
    return 0;
}