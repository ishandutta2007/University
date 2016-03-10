#include<bits/stdc++.h>


using namespace std;

int a[100020];

int main(){


    int n, k;
    scanf("%d %d", &n, &k);

    int apre, anow;
    int len = 0;
    for(int i = 0; i < k; i++){
        int m;
        scanf("%d", &m);
        for(int j = 0; j < m; j++) scanf("%d", &a[j]);

        if(a[0] == 1) while(a[len] == len + 1) len++;
    }

    printf("%d\n", 2 * (n - 1) - 2*(len - 1) - (k - 1));


    return 0;
}
