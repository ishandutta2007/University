#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<algorithm>

#define ll long long

using namespace std;

queue<int>tq[1020];
queue<int>Q;
map<int, int>team;

int n;


void Enqueue(int id){
    int t = team[id];
    tq[t].push(id);
    if(tq[t].size() == 1)
        Q.push(t);
}

void Dequeue(){
    int t = Q.front();
    int id = tq[t].front();
    printf("%d\n", id);
    tq[t].pop();
    if(tq[t].empty()) Q.pop();
}


void init(){
    for(int i = 0; i < n; i++)
        while(!tq[i].empty()) tq[i].pop();
    while(!Q.empty()) Q.pop();
}


int main(){


    int ka = 0;
    while(scanf("%d", &n)){
        init();
        if(n == 0) return 0;
        ka ++;
        printf("Scenario #%d\n", ka);
        for(int i = 0; i < n; i++){
            int m;
            scanf("%d", &m);
            while(m--){
                int tmp;
                scanf("%d", &tmp);
                team[tmp] = i;
            }
        }
        char cmd[10];
        while(scanf("%s", cmd)){
            if(cmd[0] == 'E'){
                int tmp;
                scanf("%d", &tmp);
                Enqueue(tmp);
            }
            else if(cmd[0] == 'D')
                Dequeue();

            else{
                printf("\n");
                break;
            }
        }

    }





    return 0;
}

