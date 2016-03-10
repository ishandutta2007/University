#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<map>

using namespace std;


int A[500];
int B[500];
int C[500];
int na, nb, nc;
int aM, bM, cM;
int am, bm, cm;


bool isfound(int dest){

//    printf("dest : %d\n", dest);
    long long tmp = 0;
    for(int i = 0; i < na; i++)
    {
        for(int j = 0; j < nb; j++){
            tmp = A[i] + B[j];
            tmp = dest - tmp;
            int pos = lower_bound(C, C + nc, tmp) - C;
            if(C[pos] == tmp) return true;

        }

    }

    return false;


}



int main(){

    int kase = 0;
    while(scanf("%d%d%d",&na,&nb,&nc) == 3){
        kase ++;
        printf("Case %d:\n", kase);

        for(int i = 0; i < na; i++){
            scanf("%d", &A[i]);
            if(i == 1) aM = am = A[i];
            else{
                aM = max(aM, A[i]);
                bM =
            }
        }
        for(int i = 0; i < nb; i++)
            scanf("%d", &B[i]);
        for(int i = 0; i < nc; i++)
            scanf("%d", &C[i]);

        sort(C, C + nc);
        int S;
        scanf("%d", &S);

        while(S --){
            int dest;
            scanf("%d", &dest);

            if(isfound(dest)) printf("YES\n");
            else printf("NO\n");
        }


    }




    return 0;
}
