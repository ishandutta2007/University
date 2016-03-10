#include<bits/stdc++.h>


using namespace std;


struct tree{
    int x;
    int c;
}r[120],l[120];


bool cmp(struct tree a, struct tree b){
    return a.x < b.x;
}

int cntr,cntl;

int main(){


    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x, c;
        scanf("%d %d", &x, &c);
        if(x > 0){
            r[cntr].x = x;
            r[cntr].c = c;
            cntr ++;
        }
        else{
            l[cntl].x = -x;
            l[cntl].c = c;
            cntl ++;
        }
    }

    sort(l, l + cntl, cmp);
    sort(r, r + cntr, cmp);

//    for(int i = 0; i < 3; i++)
//        printf("%d %d %d %d\n",l[i].x,l[i].c,r[i].x,r[i].c);

    int cnt = min(cntl, cntr);
    int ans = 0;
    for(int i = 0; i < cnt; i++){
        ans += r[i].c;

        ans += l[i].c;
//    printf("%d\n", ans);
    }


    int tmp = ans;
    if(cntr > cnt) ans = max(ans, tmp + r[cnt].c);
    if(cntl > cnt) ans = max(ans, tmp + l[cnt].c);

    printf("%d\n", ans);

    return 0;
}
