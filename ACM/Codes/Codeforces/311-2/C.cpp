#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

#define LL long long

using namespace std;

struct leg{
    int len;
    int cost;
}l[100020];


bool cmp(struct leg a, struct leg b)
{
    return a.len > b.len || (a.len==b.len && a.cost < b.cost);
}

int cnt[100020];

int main(){

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &l[i].len);
        cnt[l[i].len] ++;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &l[i].cost);
    }

    sort(l, l + n, cmp);
    int rem = 0;
    int sum = 0;
    int all = n;



    for(int i = 0; i < n; i++)
    {


        if(all - rem == 2 && cnt[l[i].len] == 2) break;
        else if(all - rem == 1) break;
        else if(cnt[l[i].len] > (all - rem - 1) / 2) break;
        cnt[l[i].len]--;
        sum += l[i].cost;
        rem++;
    }

    printf("%d\n", sum);

    return 0;
}

