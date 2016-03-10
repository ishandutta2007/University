#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>



using namespace std;


int a[100020];
int L, n, m;

bool reach(int r){
    int pos = 0;
    int next;
//    printf("reach %d :\n", r);
    for(int i = 1; i <= m; i++){
        next = lower_bound(a, a + n + 1, a[pos] + r) - a;
        if(a[next] > a[pos] + r)
            next --;
        pos = next;
//        printf("%d\n", next);
//        printf("next : %d\n", next);
        if(pos >= n + 1){
//            printf("true\n");
            return true;
        }
    }
//    printf("false\n");
    return false;
}



int search_update(int l, int r){
    int ans = L;
    while(l <= r){

//        printf("%d %d %d\n", l, (l + r) / 2, r);
        int mid = (l + r) / 2;
        if(reach(mid))
        {
            r = mid - 1;
            if(mid < ans)
                ans = mid;
        }
        else{
            l = mid + 1;
        }

    }

    return ans;
}


int main(){

    while(scanf("%d %d %d", &L, &n, &m) == 3){
        memset(a, 0, sizeof(a));
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        a[n] = L;
        a[n + 1] = 0;
        sort(a, a + n + 2);
//        for(int i = 0; i <= n + 1; i++)
//            printf("%d ", a[i]);

//        printf("\n");
        int l = L / m;
        int r = L;
        cout << search_update(l, r) << endl;
    }

    return 0;
}
