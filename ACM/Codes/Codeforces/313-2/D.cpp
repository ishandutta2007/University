#include<bits/stdc++.h>
#define LL long long

using namespace std;

char str1[200020], str2[200020];


bool cmp(int s1, int s2, int len){
    for(int i = 0; i < len; i++)
        if(str1[s1 + i] != str2[s2 + i]) return false;

    return true;
}


bool strequal(int s1, int s2, int len){


//    printf("%d %d %d\n", s1, s2, len);
    if(cmp(s1, s2, len)) return true;

    if(len % 2 == 0){
        if(strequal(s1, s2, len / 2) && strequal(s1 + len / 2, s2 + len / 2, len / 2))
            return true;
        if(strequal(s1, s2 + len / 2, len / 2) && strequal(s1 + len / 2, s2, len / 2))
            return true;
    }

    return false;
}




int main(){

    scanf("%s%s", str1, str2);


    if(strequal(0, 0, strlen(str2)))
        printf("YES\n");
    else
        printf("NO\n");



    return 0;
}
