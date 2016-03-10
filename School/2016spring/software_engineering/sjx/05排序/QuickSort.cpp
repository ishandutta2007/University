#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <ctime>
//#pragma comment(linker, "/STACK:36777216")
using namespace std;

//Love lemon_TsyD
//Miss lydrainbowcat
//By ITX351

const int MAXN = 2500011;
long long A[MAXN], a[MAXN];
int N;

void ShowTime(const char* hint)
{
    fprintf(stderr, "%s, %d ms\n", hint, clock());
}

void output(const char* hint)
{
    printf("Result after %s:\n", hint);
    for (int i = 1; i <= N; i++)
    {
        printf("%lld ", a[i]);
        if (a[i] < a[i - 1])
            cout << "Fuck\n";
    }

    printf("\n");
}

void Reset()
{
    for (int i = 1; i <= N; i++)
        a[i] = A[i];
}

void _QuickSort(int L, int R)
{
    if (L >= R) return;

    int X = rand() % (R - L + 1) + L;
    swap(a[X], a[R]);

    int StorePosition = L;
    for (int i = L; i < R; i++)
        if (a[i] < a[R])
            swap(a[i], a[StorePosition++]);
    swap(a[StorePosition], a[R]);

    _QuickSort(L, StorePosition - 1);
    _QuickSort(StorePosition + 1, R);
}

void QuickSort()
{
    ShowTime("Qs1 reseting");
    Reset();
    ShowTime("Qs1 sorting");
    _QuickSort(1, N);
    ShowTime("Qs1 outputing");
    output("Quick Sort without Optimizing");
}

void _QuickSort3(int L, int R)
{
    if (L >= R) return;
    if (R - L <= 5) //较小数据使用选择排序
    {
        for (int i = L; i <= R; i++)
        {
            long long minvalue = 0x7f7f7f7f7f7f7f7fLL;
            int mini = -1;
            for (int j = i; j <= R; j++)
            {
                if (a[j] < minvalue)
                {
                    minvalue = a[j];
                    mini = j;
                }
            }
            swap(a[i], a[mini]);
        }
        return;
    }

    int X1 = rand() % (R - L + 1) + L;
    int X2 = rand() % (R - L + 1) + L;
    int X3 = rand() % (R - L + 1) + L;

    int X;
    if (a[X1] < a[X2] && a[X2] < a[X3])
        X = X2;
    else if (a[X3] < a[X1] && a[X1] < a[X2])
        X = X1;
    else
        X = X3;
    swap(a[X], a[R]); //三取中间

    int StorePosition = L, EqAdd = 0;
    for (int i = L; i < R; i++)
    {
        if (a[i] < a[R])
        {
            if (StorePosition + EqAdd != i)
                swap(a[StorePosition], a[StorePosition + EqAdd]);
            swap(a[i], a[StorePosition++]);
        }
        else if (a[i] == a[R]) //相同的数存放在比它小的数的后面
            swap(a[i], a[StorePosition + (EqAdd++)]);
    }
    swap(a[StorePosition + EqAdd], a[R]);

    _QuickSort3(L, StorePosition - 1);
    _QuickSort3(StorePosition + EqAdd + 1, R);
}

void QuickSort3()
{
    ShowTime("Qs3 reseting");
    Reset();
    ShowTime("Qs3 sorting");
    _QuickSort3(1, N);
    ShowTime("Qs3 outputing");
    output("Quick Sort with Optimizing");
}

const int MAXS = 111;
char str[MAXS]; long long nownum = 0;
void input2()
{

    ShowTime("Now Readin");
    N = 0;
    while (scanf("%s", str) > 0)
    {
        scanf("%*s%s", str);

        ++N;
        if (N % 100000 == 0)
            fprintf(stderr, "%d\n", N);

        nownum = 0;
        char *p = str + 39;
        while (*p != ',')
        {
            if ((*p) <= '9' && (*p) >= '0')
                nownum = nownum * 10 + (*p) - '0';
            p++;
        }

        A[N] = nownum;

        if (N == 2352079)
            break;
    }
}

int main()
{
    srand(time(0));

    freopen("J:\\NodeInfo.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    input2();

    QuickSort3();
    //QuickSort();

    ShowTime("All finished");
    return 0;
}
