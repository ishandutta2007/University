#include<stdio.h>
#include<string.h>


char str[10000];
char p[10000];
int next1[10000];
int next2[10000];


void get_next(){
    next1[0] = -1;
    int k = -1;
    int len = strlen(p);
    for(int i = 1; i < len; i++){
        while(k > -1 && p[k + 1] != p[i])
            k = next1[k];

        if(p[k + 1] == p[i]){
            k++;
        }
        next1[i] = k;
    }

    for(int i = 0; i < len;i++)
        printf("%d ",next1[i]);
    printf("\n");
}
void get_next2(){
    next2[0] = 0;
    int k = 0;
    int len = strlen(p2);
    for(int i = 2; i < len; i++){
        while(k > 0 && p2[k + 1] != p2[i])
            k = next2[k];
        if(p2[k + 1] == p2[i]){
            k++;
        }
        next2[i] = k;
//        printf("next %d = %d\n", i, k);
    }

    for(int i = 1; i < len;i++)
        printf("%d ",next2[i]);
    printf("\n");
}


int KMP(){
    get_next();
    get_next2();
    getchar();
    int lens = strlen(str);
    int lenp = strlen(p);
    int f = 0;
    int i = 0;
    int j = 0;
    while(i < lens && j < lenp){
        if(str[i] == p[j]){
            i++;
            j++;
        }
        else{
            i = i - j + next1[j];
            j = next1[j] + 1;
            f = i - next1[j];
        }
    }
    if(j == lenp)
        return f;
    return -1;
}






int main(){


    int ans;
//    scanf("%s%s%s",str,p,p2);

    ans = KMP();

    printf("%d\n", ans);


    return 0;
}
