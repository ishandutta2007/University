#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;




bool edge[1020][1020];
int n, m;
int dest[1020];
bool vis[1020];



int main(){



    while(scanf("%d%d", &n, &m) == 2){
        memset(edge, 0, sizeof(edge));
        memset(dest, 0, sizeof(dest));
        memset(vis, 0, sizeof(vis));
        int x, y;
        for(int i = 0; i < m; i++){
            scanf("%d%d",&x, &y);
            if(!edge[x][y]){
                edge[x][y] = true;
                dest[y] ++;
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++)
                if(!vis[j] && dest[j] == 0){
                    printf("%d", j);
                    vis[j] = true;
                    for(int k = 1; k <= n; k++)
                        if(edge[j][k] == true)
                            dest[k]--;
                    break;
                }
            if(i == n) printf("\n");
            else printf(" ");
        }



    }

    return 0;
}

