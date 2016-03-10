#include<bits/stdc++.h>

using namespace std;


int main(){

    int w, m;
    scanf("%d%d", &w, &m);



    while(m > 0){
        int ret = m % w;
        if(ret == 0) m /= w;
        else if(ret == 1) m = (m - 1) / w;
        else if(ret == w - 1) m = (m + 1) / w;
        else{
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");

    return 0;
}
