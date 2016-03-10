#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>



using namespace std;

double score[120];
bool svr[120][12];
int atk[120][120];


int N, Q, S, C;


int main(){

    int t;
    scanf("%d", &t);
while(t--){
    scanf("%d%d%d%d", &N, &Q, &S, &C);
    for(int i = 1; i <= N; i++)
        score[i] = S;

while(C--){
    int A;
    scanf("%d",&A);
    for(int i = 1; i <= A; i++){
        memset(atk, 0, sizeof(atk));
        int a, b, c;
        scanf("%d%d%d",&a, &b, &c);


    }




}


}


    return 0;
}
