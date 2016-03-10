#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

char f[120][80];
int n;
char ans[120][80];

void _swap(char *s1, char *s2){
    char tmp[80] = {0};
    strcpy(tmp, s1);
    strcpy(s1, s2);
    strcpy(s2, tmp);
}


void _sort(){
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n ;j++)
            if(strcmp(f[i], f[j]) > 0)
                _swap(f[i], f[j]);
}



int main(){

    while(scanf("%d", &n) != EOF){
        memset(f, 0, sizeof(f));
        memset(ans, 0, sizeof(ans));
        int len = 0;
//        getchar();
        for(int i = 0; i < n; i++){
            scanf("%s", f[i]);
            int tmp = strlen(f[i]);
            len = max(len, tmp);
        }
        _sort();
        int R = 62 / (len + 2);
        int C = (n - 1) / R + 1;

        int k = 0;
        for(int j = 0; j < R && k < n; j++)
        for(int i = 0; i < C && k < n; i++)
            strcpy(ans[i] + j * (len + 2), f[k++]);

        printf("------------------------------------------------------------\n");
        if(n == 0)
            continue;
        int cnt2 = 1;
        for(int i = 0; i < C; i++){
            int cnt = 1;
            for(int j = 0; j < 60; j++){
                if(ans[i][j] != '\0' && ans[i][j + 1] == '\0')
                    {
                        cnt++;
                        cnt2++;
                    }
                printf("%c", ans[i][j] == '\0'? ' ':ans[i][j]);
                if(cnt > R || cnt2 > n)
                    break;
            }
            printf("\n");
        }
    }




    return 0;
}
