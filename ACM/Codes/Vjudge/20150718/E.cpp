#include<bits/stdc++.h>


using namespace std;


int a[100020][32];
int topbit[32] = {0};
int len[100020];


int tobit(int n, int x){
    int i = 0;
    while(x > 0){
        a[n][i++] = x % 2;
        x /= 2;
    }
    return i;
}


int main(){


    int n;
    scanf("%d", &n);

    minlen = 32;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        len[i] = tobit(i, a);
        minlen = min(minlen, len[i]);
        for(int j = len[i] - 1, k = 31; j >= 0; j--, k--){
            topbit[k] += a[i][j];
        }
    }


    int top = 31;
    int head = 0;
    while((topbit[top] == n || topbit[top] == 0) && head <= len) {top--;head++;}








    return 0;
}
