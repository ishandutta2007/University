#include<bits/stdc++.h>
#define LL long long


using namespace std;

char s[100020];
LL odd, even;
int cnt[2][2];


int main(){

    scanf("%s", s);
    for(int i = 0, len = strlen(s); i < len; i++){
        cnt[i & 1][s[i] - 'a'] ++;
        odd += cnt[i & 1][s[i] -'a'];
        even += cnt[i & 1 ^ 1][s[i] - 'a'];
    }

    printf("%I64d %I64d\n", even, odd);

    return 0;
}
