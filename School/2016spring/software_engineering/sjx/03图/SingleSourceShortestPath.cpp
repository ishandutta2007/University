#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

//Love lemon_TsyD
//By ITX351

const int INF = 0x7f7f7f7f;
template < typename T >
inline bool upd_min(T& a, const T& b) { if (b < a) { a = b; return true; } return false; }

const int MAXV = 2511, MAXE = 6211 * 2;

struct Arc
{
	int dest, cost; Arc *next;
	inline Arc() { next = NULL; }
	inline Arc(int iD, int iC, Arc *iN)
	{ dest = iD, cost = iC, next = iN; }
}*adj[MAXV], Npool[MAXE], *Nptr;

inline void insert(int start, int finish, int cost)
{ adj[start] = new (Nptr++) Arc(finish, cost, adj[start]); }

//最短路 无负环的图 如果起点与终点联通 则可以求得最短路
int V, E, sht[MAXV], preV[MAXV]; //点数V, 单源最短路 从开始点到目标点的最短距离

/*
Dijkstra 算法
基于贪心. 每次都寻找从原点到每个目标点中哪个最短
复杂度 O(v^2) 且稳定
优点: 复杂度稳定。可以被堆优化到 O(nlogn) 适合稠密图
缺点: 不能处理带有负权值的图. 当图带有负权值的时候, 贪心的算法是错误的
*/
bool chk[MAXV];
inline int Dijkstra(int start, int finish) //表示求从 S 到 T 的最短路
{
	memset(sht, 0x7f, sizeof(sht)); sht[start] = 0; //初始认为 不可到达每一个点
	memset(chk, 0, sizeof(chk)); chk[start] = true; //初始 所有的点都未被处理过
	memset(preV, 0xff, sizeof(preV));

	int id = start; //当前检测的点是 id
	for (int i = 1; i <= V; i++) //i无实际意义, 仅为计数器
	{
		//目前检查的点是id, 需要遍历当前点能够到达的点并更新最短路
		for (Arc *p = adj[id]; p; p = p->next)
            if (!chk[p->dest] && upd_min(sht[p->dest], p->cost + sht[id]))
                preV[p->dest] = id;


		//寻找下一个 所有未开始处理的点中 距原点最短 的点
		int minValue = INF;
		for (int j = 1; j <= V; j++)
			if (!chk[j] && upd_min(minValue, sht[j]))
				id = j;
		chk[id] = true; //标记当前点已经确定最短路
	}
	//返回求得最短路
	return sht[finish];
}

/*
Dijkstra 算法的堆优化
复杂度 O(vlogv)
*/
struct Node
{
    int length, vertex;
    inline friend bool operator <(const Node& a, const Node& b)
    { return b.length < a.length; }
    inline Node(int _length, int _vertex)
    { length = _length, vertex = _vertex; }
};

priority_queue < Node > heap;
bool used[MAXV];
int DijkstraHeap(int s, int t)
{
    memset(sht, 0x7f, sizeof(sht));
    memset(used, 0, sizeof(used));
    memset(preV, 0xff, sizeof(preV));
    memset(chk, 0, sizeof(chk));
    sht[s] = 0;
    chk[s] = true;

    int nowi = s;
    for (int i = 1; i <= V; i++)
    {
        for (Arc *p = adj[nowi]; p; p = p->next)
            if (!chk[p->dest] && upd_min(sht[p->dest], sht[nowi] + p->cost))
            {
                heap.push(Node(sht[p->dest], p->dest));
                preV[p->dest] = nowi;
            }

        used[nowi] = true;
        while (used[nowi] && !heap.empty())
        {
            nowi = heap.top().vertex;
            heap.pop();
        }
        chk[nowi] = true;
    }
    return sht[t];
}

/*
Shortest Path Faster Algorithm 算法
基于迭代求解与队列优化.
每次更新一条边, 认为这条边需要继续下一次更新压入队列
复杂度 O(kE) k为一个十分不稳定的常数

Bellman-Ford算法也可以求得带有负权值的最短路, 但是较慢

优点: 可以求得带有 负权值 的图 , 适合稀疏图
缺点: 复杂度极其不稳定 优化前途不够
		如果rp不够高的话可能被卡掉
*/
bool inQueue[MAXV]; int pushTime[MAXV]; //记录点是否在队列中 如果在, 无需再压入队列
queue < int > q; //使用队列优化 但要求为循环队列
inline int SPFA(int start, int finish)
{
	memset(sht, 0x7f, sizeof(sht)); sht[start] = 0;
	memset(inQueue, 0, sizeof(inQueue)); inQueue[start] = true;
	memset(preV, 0xff, sizeof(preV));
	memset(pushTime, 0, sizeof(pushTime));

	while (!q.empty())
        q.pop();
	q.push(start);
	pushTime[start]++;

	//队列中为待处理的元素
	//每次更新都压入新更新的点 队列不为空则弹出处理
	while (!q.empty())
	{
		int id = q.front(); q.pop(); inQueue[id] = false; //弹出队头的点, 标记当前点已经出队
		for (Arc *p = adj[id]; p; p = p->next)
			if (upd_min(sht[p->dest], p->cost + sht[id])) //更新最短路
			{
			    preV[p->dest] = id;
			    if (!inQueue[p->dest])
                {
                    if (pushTime[p->dest] > V)
                        return sht[finish] = -INF;
                    q.push(p->dest); //如果点没有在队列里 则压入队列并标记
                    pushTime[p->dest]++;
                    inQueue[p->dest] = true;
                }
			}

	}
	return sht[finish];
}

int path[MAXV], Npath;
inline void showPath(const char* hint, int finish)
{
    printf("%s:\n", hint);
    if (sht[finish] == -INF)
    {
        printf("There is a negetive circle.\n\n");
        return;
    }
    Npath = 0;
    for (int i = finish; i != -1; i = preV[i])
        path[++Npath] = i;
    printf("Start at %d.\n", path[Npath]);
    for (int i = Npath - 1; i >= 1; i--)
        printf("Pass an edge spent %d and arrive at %d.\n", sht[path[i]] - sht[path[i + 1]], path[i]);
    printf("Cost summed is: %d.\n\n", sht[finish]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("sht.in", "r", stdin);
	//freopen("sht.out", "w", stdout);
#endif

	int Case = 0;
	while (scanf("%d%d", &V, &E) > 0)
    {
        int start, finish, directed;
        scanf("%d%d%d", &start, &finish, &directed);
        printf("Test case %d.\n", ++Case);

        Nptr = Npool;
        memset(adj, 0, sizeof(adj));

        for (int i = 1; i <= E; i++)
        {
            int s, t, c;
            scanf("%d%d%d", &s, &t, &c);
            insert(s, t, c);
            if (directed == 0)
                insert(t, s, c); //无向图反向插边
        }

        Dijkstra(start, finish);
        showPath("Dijkstra", finish);

        DijkstraHeap(start, finish);
        showPath("Dijkstra with heap", finish);

        SPFA(start, finish);
        showPath("SPFA", finish);
    }
    return 0;
}
