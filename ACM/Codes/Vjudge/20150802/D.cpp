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


int a[1200];
int n, k;

void do_per(){

    if(next_permutation(a, a + n)){
        return;

    }
    sort(a, a + n);

}


int main(){


    int T;
    scanf("%d", &T);

    while(T--){
        scanf("%d %d", &n, &k);

        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        while(k--){
            do_per();
        }

        for(int i = 0; i < n; i++)
            printf("%d ", a[i]);
        cout << endl;
    }

    return 0;
}

