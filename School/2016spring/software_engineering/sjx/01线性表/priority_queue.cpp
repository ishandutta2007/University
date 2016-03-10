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

const int INF = 0x7f7f7f7f;
template < typename T, int maxN, bool (*cmp)(const T&, const T&), T INF >
class Heap
{
private:
    T p[maxN]; int N;
public:
    inline Heap() { clear(); }
    inline void clear() { N = 0; for (int i = 1; i < maxN; i++) p[i] = INF; }
    inline bool isEmpty() { return N == 0; }
    inline T& top() { return p[1]; } //Keep not empty
    inline void insert(const T& data)
    {
        p[++N] = data;
        int i = N;
        while (i > 1)
            if (cmp(p[i], p[i >> 1]))
            {
                swap(p[i], p[i >> 1]);
                i >>= 1;
            }
            else
                break;
    }
    inline void pop()
    {
        p[1] = p[N];
        p[N--] = INF;
        int i = 1;
        while ((i << 1) <= N)
        {
            if (cmp(p[i << 1], p[i]) && cmp(p[i << 1], p[(i << 1) + 1]))
            {
                swap(p[i << 1], p[i]);
                i <<= 1;
            }
            else if (cmp(p[i << 1 | 1], p[i]) && cmp(p[i << 1 | 1], p[i << 1]))
            {
                swap(p[i << 1 | 1], p[i]);
                i = i << 1 | 1;
            }
            else
                break;
        }
    }
};

bool cmp(const int& a, const int& b)
{ return a < b; }

Heap < int, 10011, cmp, INF > heap;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int N;
    scanf("%d", &N);

    heap.clear();
    while (N--)
    {
        int op, data;
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            scanf("%d", &data);
            heap.insert(data);
            printf("Inserting succeeded.\n");
            break;
        case 2:
            if (heap.isEmpty())
                printf("Heap is empty.\n");
            else
                printf("Now min data: %d\n", heap.top());
            break;
        case 3:
            if (heap.isEmpty())
                printf("Heap is empty.\n");
            else
            {
                heap.pop();
                printf("Removing succeeded.\n");
            }
            break;
        case 4:
            heap.clear();
            printf("Heap cleared.\n");
            break;
        default:
            printf("Unknown command.\n");
            break;
        }
    }
    return 0;
}
