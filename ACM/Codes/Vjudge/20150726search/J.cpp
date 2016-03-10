#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>


using namespace std;


int a[22];
int n;
int sum;
int edge;
bool flag;

void dfs(int *e, int depth){

    printf("%d %d %d\n", e[0], e[1], e[2]);
    if(depth >= n)
    return;

    if(e[0] == e[1] && e[1] == e[2] && e[2] == edge){
        flag = true;
        return;
    }

    for(int i = 0; i < 3 && flag == false; i++){
        if(e[i] + a[depth] <= edge)
        {
//            if(e[i] + a[depth] < edge && e[i] + a[depth] + a[depth + 1] > edge) continue;
            e[i] += a[depth];
            dfs(e, depth + 1);
            if(flag) return;
            e[i] -= a[depth];
        }
    }




}


int main(){


    int T;
    scanf("%d", &T);
    while(T--){
        sum = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }

        if(sum % 4 != 0)
        {
            printf("no\n");
            continue;
        }
        edge = sum / 4;
        sort(a, a + n);
        flag = false;
        int e[4] = {0};
        e[0] = a[0];
        dfs(e, 1);

        if(flag) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
