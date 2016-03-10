#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#define LL long long

using namespace std;

char s[100020];
int cnt[30];


int main(){

    int k;
    scanf("%s %d", s, &k);
    int len = strlen(s);

    int _minus = 0;
    int _add = 0;

    for(int i = 0; i < len; i++){
        if(s[i] != '?') cnt[s[i] - 'a'] ++;
        else if(i % 2 == 0) _add++;
        else _minus++;
    }

    int tp = 0;
    for(int i = 0; i < 30; i++) if(cnt[i] > 0) tp++;

    if(tp + _minus + _add < k){
        printf("-1\n");
        return 0;
    }

    int low = 0;
    while(cnt[low]) low++;
    int high = 25;
    while(cnt[high]) high--;

    int need = k - tp;


    int aaa[30] = {0};
    int mmm[30] = {0};
    int lenadd = 0;
    int lenmin = 0;
    while(need--){
        if(_add == 0 || (high < 25 - low)){
            _minus--;
            mmm[lenmin] = low;
            lenmin++;
            cnt[low] ++;
            while(cnt[low]) low++;
            continue;
        }
        else{
            _add--;
            aaa[lenadd] = high;
            lenadd++;
            cnt[high]++;
            while(cnt[high]) high--;
            continue;
        }
    }
    int pa = 0;
    int pm = 0;
    for(int i = 0; i < len; i++){
        if(s[i] != '?'){
            printf("%c", s[i]);
            continue;
        }
        else{
            if(i % 2 == 0){
                if(pa < lenadd) printf("%c", aaa[pa++] + 'a');
                else printf("z");
                continue;
            }
            if(i % 2 == 1){
                if(pm < lenmin) printf("%c", mmm[pm++] + 'a');
                else printf("a");
                continue;
            }
        }

    }
    printf("\n");
    return 0;
}
