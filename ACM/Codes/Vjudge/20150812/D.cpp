#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>


using namespace std;


char s1[5020], s2[5020];
int ans[2][5020];


int main(){

    int len;
    scanf("%d", &len);
    scanf("%s", s1);

    for(int i = 0; i < len; i++)
        s2[i] = s1[len - i - 1];
    s2[len] = '\0';
    int sub = 0;
    for(int i = 0; i < len; i++)
        {

            for(int j = 0; j < len; j++){
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
        printf("%d\n", len - ans[(sub + 1) % 2][len]);




    return 0;
}


