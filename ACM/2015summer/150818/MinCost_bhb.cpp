struct edge{
	int x, ne, c, f, w;
};

struct MinCostFlow{
	edge e[M];
	int S, T, pos, quantity, cost;
	int head[N], dis[N], pre[N], at[N];
	queue <int> q;
	bool used[N];
	
	void adde(int u, int v, int c, int w){
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
			int x = q.front();
			//printf("Now : %d\n", x);
			for (int i = head[x]; i; i = e[i].ne){
				int y = e[i].x;
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
		int cut = INF;
		for (int i = T; i != S; i = pre[i]){
			cut = min(cut, e[at[i]].c - e[at[i]].f);
		}
		//printf("Cut %d's path : %d -> ", T);
		for (int i = T; i != S; i = pre[i]){
			e[at[i]].f += cut;
			e[at[i] ^ 1].f -= cut;
			//printf(" - > %d", pre[i]);
		}
		quantity += cut;
		cost += cut * dis[T];
		//puts("-------");
	}
	
	void init(int s, int t){
		S = s;
		T = t;
		pos = 1;
		quantity = cost = 0;
		memset(head, 0, sizeof(head));
	}
	
	PII work(){
		//puts("Starting");
		while (spfa())
			update();
		//printf("%d %d\n", quantity, cost);
		return make_pair(quantity, cost);
	}
}flow;