#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <ctime>
using namespace std;

//Love lemon_TsyD
//Miss lydrainbowcat
//By ITX351

const int MAXN = 100011, MAXK = 10011;
int A[MAXN], B[MAXN], N, C[MAXK];

void output(const char* hint)
{
    printf("Result after %s:\n", hint);
    for (int i = 1; i <= N; i++)
    {
        printf("%d ", B[i]);
        if (B[i] < B[i - 1])
            cout << "Unsorted!!!\n";
    }
    printf("\n");
}

void CountSort()
{
    memset(B, 0, sizeof(B));
    memset(C, 0, sizeof(C));
    for (int i = 1; i <= N; i++)
        C[A[i]]++;
    for (int i = 2; i <= MAXK; i++)
        C[i] += C[i - 1];
    for (int i = N; i >= 1; i--)
    {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
    output("Count Sort");
}

void BucketSort()
{
    memset(B, 0, sizeof(B));
    memset(C, 0, sizeof(C));

    for (int i = 1; i <= N; i++)
        C[A[i]]++;

    int j = 0;
    for (int i = 1; i <= MAXK; i++)
        while (C[i] >= 1)
        {
            C[i]--;
            B[++j] = i;
        }

    output("BucketSort");
}

void input()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", A + i);
}

void datamaker()
{
    freopen("in.txt", "w", stdout);
    const int n = 1000;
    printf("%d\n", n);
    for (int i = 1; i <= n; i++)
        printf("%d ", rand() % 10000 + 1);
}

int main()
{
    srand(time(0));
    // datamaker();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    input();
    CountSort();
    BucketSort();
    return 0;
}
