#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;


int main(){


    int n, m, x, y;
    while(~scanf("%d%d%d%d", &n, &m, &x, &y)){
        if(n <= 2 || m <= 2){
            printf("1\n");
            continue;
        }

        if((n % 2 == 1) && (m % 2 == 1)){


            if(x == n / 2 + 1 && y == m / 2 + 1){

                printf("%d\n", max(min(n / 2, m / 2 + 1), min(n / 2 + 1, m / 2)));
                continue;
            }


            printf("%d\n", min(n / 2 + 1, m / 2 + 1));
            continue;
        }

        if(n % 2 == 1 && m % 2 == 0){
            swap(n, m);
            swap(x, y);
        }

        if(n % 2 == 0 && m % 2 == 1)
        {
            if((x < n / 2 && y == m / 2 + 1) || (x > n / 2 + 1 && y == m / 2 + 1)){
                printf("%d\n", min(n / 2 + 1, m / 2 + 1));
                continue;
            }

            if((y <= m / 2 || y > m / 2 + 1) && (x == n / 2 || x == n / 2 + 1)){
                printf("%d\n", min(n / 2, m / 2 + 1));
                continue;
            }
            printf("%d\n", min(n / 2, m / 2 + 1));
            continue;
        }

        else{

            if((x < n / 2 && y < m / 2) || (x < n / 2 && y > m / 2 + 1) || (x > n / 2 + 1 && y < m / 2) || (x >= n / 2 && x <= n / 2 + 1 && y >= m / 2 && y <= m / 2 + 1))
            {
                printf("%d\n", min(n / 2, m / 2));
                continue;
            }
            if(x < n / 2 || x > n / 2 + 1){
                printf("%d\n", min(m / 2, n / 2 + 1));
                continue;
            }

            if(y < m / 2 || y > m / 2 + 1){
                printf("%d\n", min(m / 2 + 1, n / 2));
                continue;
            }

        }


    }

    return 0;
}
