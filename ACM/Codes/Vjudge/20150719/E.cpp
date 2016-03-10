#include<stdio.h>
#include<iostream>
#include<string.h>



using namespace std;

char str[1020];
int n;
int len;
int head;



void del(int pos){
    for(int i = head; i < len; i++)
        str[i] = str[i + (i >= pos ? 1 : 0)];


    len--;
}


void deldig(){
    int pos;
    for(pos = head; pos < len; pos++)
        if(str[pos] > str[pos + 1]) break;

    del(pos);
}


int main(){

    while(scanf("%s %d", str, &n) == 2){


//        printf("!!!\n");
        len = strlen(str);
        head = 0;
        while(n--)
            deldig();


        while(str[head] == '0') head++;

        if(head == len) printf("0");
        else
            for(int i = head; i < len; i++)
                printf("%c", str[i]);

        printf("\n");
    }
    return 0;
}
