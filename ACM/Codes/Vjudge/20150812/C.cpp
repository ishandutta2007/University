#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>


using namespace std;


char s1[1020], s2[1020];
int ans[2][1020];


int main(){



    while(scanf("%s%s", s1, s2) != EOF){
        int l1 = strlen(s1), l2 = strlen(s2);
        memset(ans, 0, sizeof(ans));
        int sub = 0;
        for(int i = 0; i < l1; i++)
        {

            for(int j = 0; j < l2; j++){
//                printf("!!\n");
                if(s1[i] == s2[j])
                    ans[sub][j + 1] = ans[(sub + 1) % 2][j] + 1;
                else
                    ans[sub][j + 1] = max(ans[(sub + 1) % 2][j + 1], ans[sub][j]);

//            }
//            for(int j = 1; j <= l2; j++)
//                printf("%d ", ans[j]);
//            printf("\n");
            }
            sub = (sub + 1) % 2;

        }
        printf("%d\n", ans[(sub + 1) % 2][l2]);



    }


    return 0;
}

