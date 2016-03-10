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
#include<sstream>

#define ll long long

using namespace std;


queue<int>q,t;
bool visited[100020];


bool check(int n){
    if(n >= 0 && n <= 100000 && visited[n] == false)
    {
        visited[n] = true;
        return true;
    }
    return false;
}


int main(){


    int n, k;

    scanf("%d%d",&n,&k);

    visited[n] = true;
    q.push(n);
    t.push(0);
    int now, step;
    int tmp;
    while(!q.empty()){
        now = q.front();
        q.pop();
        step = t.front();
        t.pop();


        if(now == k){
            printf("%d\n", step);
            return 0;
        }

        if(check(now + 1)){
            q.push(now + 1);
            t.push(step + 1);
        }
        if(check(now - 1)){
            q.push(now - 1);
            t.push(step + 1);
        }
        if(check(now * 2)){
            q.push(now * 2);
            t.push(step + 1);
        }


    }
    return 0;
}
