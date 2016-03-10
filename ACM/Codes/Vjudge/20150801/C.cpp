#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int road[200][200];
int n;
bool vis[200];

int cal(){


    memset(vis, 0, sizeof(vis));
    int start = 1;
    int tmp = 0;
    vis[start] = true;
    for(int i = 1; i < n; i++){

        for(int j = 1; j <= n; j++)if(vis[j] == false && road[start][j] != 0){
            if(road[start][j] > 0)
            {
                tmp += road[start][j];
            }
            start = j;
            vis[start] = true;
            break;
        }
    }

    if(road[start][1] > 0)
        tmp += road[start][1];

    int ans = tmp;

//    printf("ans : %d\n", ans);


    memset(vis, 0, sizeof(vis));
    start = 1;
    tmp = 0;
    vis[start] = true;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= n; j++)if(vis[j] == false && road[start][j] != 0){
            if(road[start][j] < 0)
            {
                tmp -= road[start][j];
            }
            start = j;
            vis[start] = true;
            break;
        }
    }

    if(road[start][1] < 0)
        tmp -= road[start][1];
    ans = min(ans, tmp);
//    printf("ans : %d\n", ans);
    return ans;
}




int main(){


    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        road[a][b] = c;
        road[b][a] = -c;
    }

    printf("%d\n", cal());

    return 0;
}
