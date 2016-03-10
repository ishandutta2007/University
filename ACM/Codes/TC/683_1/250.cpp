#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
struct edge{
	LL x, ne, c, f, w;
};

const LL N = 3000, M = 3000;
const LL INF = 0x7fffffff7fffffff;
struct MinCostFlow{
	edge e[M];
	LL S, T, pos, quantity, cost;
	LL head[N], dis[N], pre[N], at[N];
	queue <LL> q;
	bool used[N];
	
	void adde(LL u, LL v, LL c, LL w){
		//printf("Add edge : %d -> %d c : %d w : %d\n", u, v, c, w);
		e[++pos] = (edge){v, head[u], c, 0, w};
		head[u] = pos;
		e[++pos] = (edge){u, head[v], c, c, -w};
		head[v] = pos;
	}
	
	bool spfa(){
		memset(dis, 0x3f, sizeof(dis));
		memset(used, 0, sizeof(used));
		used[S] = true;
		while (!q.empty())
			q.pop();
		q.push(S);
		dis[S] = 0;
		while (!q.empty()){
			LL x = q.front();
			//printf("Now : %d\n", x);
			for (LL i = head[x]; i; i = e[i].ne){
				LL y = e[i].x;
				if (e[i].c > e[i].f && dis[x] + e[i].w < dis[y]){
					dis[y] = dis[x] + e[i].w;
					at[y] = i;
					pre[y] = x;
					if (!used[y]){
						used[y] = true;
						q.push(y);
					}
				}
			}
			used[x] = false;
			q.pop();
		}
		//printf("Spfa : %d\n", dis[T]);
		return dis[T] != INF;
	}
	
	void update(){
		LL cut = INF;
		for (LL i = T; i != S; i = pre[i]){
			cut = min(cut, e[at[i]].c - e[at[i]].f);
		}
		//printf("Cut %d's path : %d -> ", T);
		for (LL i = T; i != S; i = pre[i]){
			e[at[i]].f += cut;
			e[at[i] ^ 1].f -= cut;
			//printf(" - > %d", pre[i]);
		}
		quantity += cut;
		cost += cut * dis[T];
		//puts("-------");
	}
	
	void init(LL s, LL t){
		S = s;
		T = t;
		pos = 1;
		quantity = cost = 0;
		memset(head, 0, sizeof(head));
	}
	
	LL work(){
		//puts("Starting");
		while (spfa())
			update();
		//printf("%d %d\n", quantity, cost);
		cost;
	}
}flow;


class MoveStones
{
public:
	long long get(vector <int> a, vector <int> b)
	{
		int len = a.size();
		flow.init(len, len + 1);
		for (int i = 0; i < len ; i++)
		{
			a[i] -= b[i];
		}

		for (int i = 0; i < len; i++)
		{
			flow.adde((LL)i, (LL)((i+1)%len), (LL)1, INF);
			flow.adde((LL)((i+1)%len), (LL)i, (LL)1, INF);
			if(a[i] >= 0) flow.adde(len, i, 0, a[i]);
			else flow.adde(len+1, i, 0, -a[i]);
		}

		return flow.work();
	}
};

int main()
{
	return 0;
}