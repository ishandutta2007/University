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


priority_queue<int, vector<int> ,greater<int> >q[2];

int add[30020];
int get[30020];

void show(int from , int ii, int n){


    int to = (from + 1) % 2;
    for(int i = 1; i <= n; i++)
    {
        if(i == ii) printf("%d\n", q[from].top());
        q[to].push(q[from].top());
        q[from].pop();
    }
}


int main(){



    int m, n;
    scanf("%d%d", &m, &n);

    for(int i = 0; i < m; i++) scanf("%d", &add[i]);
    for(int i = 0; i < n; i++) scanf("%d", &get[i]);

    int flag = 0;
    int p = 0;
    int ii = 0;
    for(int i = 0; i < m && p < n; i++){
        q[flag].push(add[i]);

//        printf("before : %d %d %d\n", i, p, flag);
        while(q[flag].size() == get[p]){
            ii++;
            show(flag, ii, get[p]);
            flag = (flag + 1) % 2;
            p++;
        }
//        printf("after : %d %d %d\n", i, p, flag);
//        printf("after : %d %d %d\n", ii, deleted, pq.size());
    }



    return 0;
}


