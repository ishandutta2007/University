#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>


using namespace std;


char s1[1020], s2[1020];
int ans[1020][1020];


int main(){



    while(scanf("%s%s", s1, s2) != EOF){
        int l1 = strlen(s1), l2 = strlen(s2);

        memset(ans, 0, sizeof(ans));

        for(int i = 0; i < l1; i++)
        for(int j = 0; j < l2; j++){
            if(s1[i] == s2[j])
                ans[i + 1][j + 1] = ans[i][j] + 1;
            else
                ans[i + 1][j + 1] = max(ans[i][j + 1], ans[i + 1][j]);

        }


        printf("%d\n", ans[l1][l2]);



    }


    return 0;
}
