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

//���· �޸�����ͼ ���������յ���ͨ �����������·
int V, E, sht[MAXV], preV[MAXV]; //����V, ��Դ���· �ӿ�ʼ�㵽Ŀ������̾���

/*
Dijkstra �㷨
����̰��. ÿ�ζ�Ѱ�Ҵ�ԭ�㵽ÿ��Ŀ������ĸ����
���Ӷ� O(v^2) ���ȶ�
�ŵ�: ���Ӷ��ȶ������Ա����Ż��� O(nlogn) �ʺϳ���ͼ
ȱ��: ���ܴ�����и�Ȩֵ��ͼ. ��ͼ���и�Ȩֵ��ʱ��, ̰�ĵ��㷨�Ǵ����
*/
bool chk[MAXV];
inline int Dijkstra(int start, int finish) //��ʾ��� S �� T �����·
{
	memset(sht, 0x7f, sizeof(sht)); sht[start] = 0; //��ʼ��Ϊ ���ɵ���ÿһ����
	memset(chk, 0, sizeof(chk)); chk[start] = true; //��ʼ ���еĵ㶼δ�������
	memset(preV, 0xff, sizeof(preV));

	int id = start; //��ǰ���ĵ��� id
	for (int i = 1; i <= V; i++) //i��ʵ������, ��Ϊ������
	{
		//Ŀǰ���ĵ���id, ��Ҫ������ǰ���ܹ�����ĵ㲢�������·
		for (Arc *p = adj[id]; p; p = p->next)
            if (!chk[p->dest] && upd_min(sht[p->dest], p->cost + sht[id]))
                preV[p->dest] = id;


		//Ѱ����һ�� ����δ��ʼ����ĵ��� ��ԭ����� �ĵ�
		int minValue = INF;
		for (int j = 1; j <= V; j++)
			if (!chk[j] && upd_min(minValue, sht[j]))
				id = j;
		chk[id] = true; //��ǵ�ǰ���Ѿ�ȷ�����·
	}
	//����������·
	return sht[finish];
}

/*
Dijkstra �㷨�Ķ��Ż�
���Ӷ� O(vlogv)
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
Shortest Path Faster Algorithm �㷨
���ڵ������������Ż�.
ÿ�θ���һ����, ��Ϊ��������Ҫ������һ�θ���ѹ�����
���Ӷ� O(kE) kΪһ��ʮ�ֲ��ȶ��ĳ���

Bellman-Ford�㷨Ҳ������ô��и�Ȩֵ�����·, ���ǽ���

�ŵ�: ������ô��� ��Ȩֵ ��ͼ , �ʺ�ϡ��ͼ
ȱ��: ���Ӷȼ��䲻�ȶ� �Ż�ǰ;����
		���rp�����ߵĻ����ܱ�����
*/
bool inQueue[MAXV]; int pushTime[MAXV]; //��¼���Ƿ��ڶ����� �����, ������ѹ�����
queue < int > q; //ʹ�ö����Ż� ��Ҫ��Ϊѭ������
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

	//������Ϊ�������Ԫ��
	//ÿ�θ��¶�ѹ���¸��µĵ� ���в�Ϊ���򵯳�����
	while (!q.empty())
	{
		int id = q.front(); q.pop(); inQueue[id] = false; //������ͷ�ĵ�, ��ǵ�ǰ���Ѿ�����
		for (Arc *p = adj[id]; p; p = p->next)
			if (upd_min(sht[p->dest], p->cost + sht[id])) //�������·
			{
			    preV[p->dest] = id;
			    if (!inQueue[p->dest])
                {
                    if (pushTime[p->dest] > V)
                        return sht[finish] = -INF;
                    q.push(p->dest); //�����û���ڶ����� ��ѹ����в����
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
                insert(t, s, c); //����ͼ������
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
