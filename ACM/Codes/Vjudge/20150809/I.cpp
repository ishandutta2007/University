#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;


char code[20][20];


bool ispre(char *s1, char *s2, int len){


//    printf("%s %s\n", s1, s2);
    for(int i = 0; i < len; i++)
        if(s1[i] != s2[i]) return false;
    return true;
}


bool isim(int n){

//    printf("!!!%d!!!\n", n);
    for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++){
        int len1 = strlen(code[i]);
        int len2 = strlen(code[j]);
        if(len1 == len2) continue;

        if(len1 < len2 && ispre(code[i], code[j], len1)) return false;

        if(len2 < len1 && ispre(code[j], code[i], len2)) return false;
    }

    return true;
}



int main(){


    int ka = 0;

    int cnt = 0;
    char tmp[20];
    while(scanf("%s", tmp) != EOF){
        if(tmp[0] == '9'){
            ka++;
            if(isim(cnt)) printf("Set %d is immediately decodable\n", ka);
            else printf("Set %d is not immediately decodable\n", ka);
            cnt = 0;
            continue;
        }
        strcpy(code[cnt], tmp);
        cnt++;
    }



    return 0;
}
