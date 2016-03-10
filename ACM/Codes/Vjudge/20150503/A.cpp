#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

char s[100020];
int cnt[30];



int main(){
    int k;
    scanf("%s", s);
    scanf("%d", &k);
    int len = strlen(s);
    for(int i = 0; i < len; i++)
        cnt[s[i] - 'a'] ++;

    sort(cnt, cnt + 26, greater<int>());

//    for(int i = 0; i < 26; i++)
//        printf("%d ", cnt[i]);
//    printf("%d\n");


    int _max = 0;
    int ans = 1;
    for(int i = 0; i < k; i++)
        _max += cnt[i];
    int t1 = 0;
    int t2 = 0;
    for(int i = 0; i < 26; i++)
        if(cnt[i] == cnt[k - 1])
            t1 ++;
    for(int i = 0; i < k; i++)
        if(cnt[i] == cnt[k - 1])
            t2 ++;

    for(int i = 1; i <= t2; i++)
        ans *= t1--;
    while(t1){
        ans /= t1;
        t1--;
    }
    printf("%d %d\n", _max, ans);
    return 0;
}
