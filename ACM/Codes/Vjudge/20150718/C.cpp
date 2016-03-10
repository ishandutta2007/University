#include<bits/stdc++.h>

using namespace std;


char str[200020];
int cnt[2] = {0};

int main(){

    int n;
    scanf("%d", &n);

    scanf("%s", str);

    for(int i = 0; i < n; i++)
    {
//        printf("%d\n", str[i] - '0');
        cnt[str[i] - '0']++;
    }


    printf("%d\n", abs(cnt[0] - cnt[1]));

    return 0;
}
