#include<bits/stdc++.h>
#define ll long long


using namespace std;

int tb[2][100020];
short blk[100020][2020];
int len[100020];



const ll mod = 1e9 + 7;


bool notblack(int r, int c){
    for(int i = 0; i < len[r]; i++)
        if(blk[r][i] == c) {return false;}
    return true;
}




int main(){

    int h, w, n;
    scanf("%d%d%d",&h,&w,&n);


    int r, c;
    for(int i = 0; i < n; i++){
        scanf("%d%d",&r, &c);
        blk[r][len[r]++] = (short)c;
    }

    tb[0][1] = 1;

    for(int i = 1; i <= h; i++){
    for(int j = 1; j <= w; j++)if(notblack(i, j)){
        ll tmp = 0;
        if(notblack(i - 1, j))
            tmp += tb[(i - 1) % 2][j];

        if(notblack(i, j - 1));
            tmp += tb[i % 2][j - 1];


        tb[i % 2][j] = tmp % mod;
    }
    else
        tb[i % 2][j] = 0;


    }

    printf("%d\n", tb[h % 2][w]);
    return 0;
}
