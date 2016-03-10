#include<bits/stdc++.h>


using namespace std;

int l[1000020];
int r[1000020];
int t[1000020];


int main(){


    int n;
    scanf("%d", &n);
    int mmax = 0;
    for(int i = 1; i <= n; i++){
        int tmp;
        scanf("%d", &tmp);
        t[tmp] ++;
        mmax = max(mmax, t[tmp]);
        if(l[tmp] == 0) l[tmp] = i;
        if(r[tmp] == 0) r[tmp] = i;
        l[tmp] = min(l[tmp], i);
        r[tmp] = max(r[tmp], i);
    }
    int mmin = 10000000;
    int ans = 0;
    for(int i = 1; i <= 1000000; i++)
        if(t[i] == mmax && r[i] - l[i] < mmin)
        {
            mmin = r[i] - l[i];
            ans = i;
        }

    printf("%d %d\n", l[ans], r[ans]);
    return 0;
}
