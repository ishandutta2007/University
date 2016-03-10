#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;


int a[4];
bool vis[10000];
bool notprime[10000];

int m[5] = {1, 10, 100, 1000, 100000};


void init(){
    for(int i = 2; i <= 9999; i++)
    if(!notprime[i]){
        for(int j = i * 2; j <= 9999;j+=i){
            notprime[j] = true;
        }
    }

}


int bfs(int s, int e){

    queue<int>qn,qt;

    qn.push(s);qt.push(0);
    int now, t, tmp;
    int dig;
    while(!qn.empty())
    {
        now = qn.front();t = qt.front();
        qn.pop();qt.pop();
        if(now == e) return t;
        for(int i = 0; i < 4; i++)
        {
            a[i] = now % 10;
            now /= 10;
        }
        for(int i = 0; i < 4; i++)
        {
            int j;
            if(i == 3) j = 1;
            else j = 0;
            for(; j <= 9; j++)if(j != a[i]){
                tmp =


            }


        }
    }
    return -1;
}



int main(){



    init();
    int T;
    scanf("%d", &T);
    int a, b;
    while(T--){
        scanf("%d%d", &a, &b);

        int ans = bfs(a, b);

        if(ans == -1) printf("Impossible\n");
        else printf("%d\n", ans);
    }

    return 0;
}
