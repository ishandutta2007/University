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


struct Query{
    int num;
    int time, m;

    bool operator < (const Query &a)const{
        if(time == a.time)
            return num > a.num;
        return time > a.time;
    }

}tmp;

priority_queue<Query>pq;





int main(){

    char cmd[20];

    while(scanf("%s", cmd)){
        if(cmd[0] == '#') break;
        scanf("%d%d",&tmp.num, &tmp.time);
        tmp.m = tmp.time;
        pq.push(tmp);
    }

//    while(!pq.empty()){
//        tmp = pq.top();
//        printf("%d %d\n", tmp.num, tmp.time);
//
//        pq.pop();
//    }
    int n;



    scanf("%d", &n);



    while(n--){
        tmp = pq.top();
        pq.pop();
        printf("%d\n", tmp.num);
        tmp.time += tmp.m;
        pq.push(tmp);
    }



    return 0;
}
