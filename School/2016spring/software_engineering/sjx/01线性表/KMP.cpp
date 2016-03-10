#define ONLINE_JUDGE
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

//Love lemon_TsyD
//Miss lydrainbowcat
//By ITX351

const int MAXS = 10011;
char A[MAXS], B[MAXS]; int P[MAXS], N, M;

inline void init()
{
    P[0] = 0;
    int j = 0;
    for (int i = 1; i < M; i++)
    {
        while (j > 0 && B[j] != B[i])
            j = P[j - 1];
        if (B[j] == B[i])
            j++;
        P[i] = j;
    }
}

inline void KMP()
{
    int j = 0; bool found = false;
    for (int i = 0; i < N; i++)
    {
        while (j > 0 && B[j] != A[i])
            j = P[j - 1];
        if (B[j] == A[i])
            j++;
        if (j == M)
        {
            found = true;
            printf("Found at %d.\n", i - M + 1);
            j = P[j - 1];
        }
    }
    if (!found)
        printf("Not Found.\n");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%s%s", A, B);
    N = strlen(A), M = strlen(B);

    init();

    cout << "Next Array: ";
    for (int i = 0; i < M; i++)
        cout << P[i] << " ";
    cout << "\n";

    KMP();

    return 0;
}
