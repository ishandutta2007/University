struct edge{
	int x, ne, c, f;
};

struct ISAP{
	edge e[M];
	int S, T, size, pos;
	int head[N], q[N], dis[N], pre[N], at[N], gap[N], cur[N];
	bool used[N];
	
	void adde(int u, int v, int c){
		//printf("Add edge %d -> %d of %d\n", u, v, c);
		e[++pos] = (edge){v, head[u], c, 0};
		head[u] = pos;
		e[++pos] = (edge){u, head[v], c, c};
		head[v] = pos;
	}
	
	void init(int size){
		this->size = size;
		pos = 1;
		memset(head, 0, sizeof(head));
	}
	
	bool number(){
		//printf("Number\n");
		memset(dis, 0x3f, sizeof(dis));
		memset(used, 0, sizeof(used));
		int p1, p2;
		dis[T] = 0;
		for (used[q[p1 = p2 = 1] = T] = true; p1 <= p2; ++p1){
			int u = q[p1];
			//printf(" Find %d\n", u);
			for (int i = head[u]; i; i = e[i].ne){
				int v = e[i].x;
				if (!used[v] && (i & 1)){
					used[q[++p2] = v] = true;
					dis[v] = dis[u] + 1;
				}
			}
		}
		//printf("Number over\n");
		return used[S];
	}
	
	int augment(){
		int cut = INF;
		for (int i = T; i != S; i = pre[i]){
			//printf("%d %d\n", e[at[i]].c, e[at[i]].f);
			cut = min(cut, e[at[i]].c - e[at[i]].f);
		}
		//printf("Path : ");
		for (int i = T; i != S; i = pre[i]){
			e[at[i]].f += cut;
			e[at[i] ^ 1].f -= cut;
			//printf("%d -> ", i);
		}
		//printf("%d\n Cut is %d\n", S, cut);
		return cut;
	}
	
	int maxflow(int S, int T){
		int flow = 0;
		this->S = S;
		this->T = T;
		number();
		memset(gap, 0, sizeof(gap));
		memcpy(cur, head, sizeof(head));
		for (int i = 0; i < size; ++i)
			if (dis[i] < INF)
				++gap[dis[i]];
		int u = S;
		while (dis[u] < size){
			//printf("Now is %d\n", u);
			if (u == T){
				flow += augment();
				u = S;
			}
			bool flag = false;
			for (int &i = cur[u]; i; i = e[i].ne){
				int v = e[i].x;
				if (e[i].c > e[i].f && dis[u] == dis[v] + 1){
					flag = true;
					at[v] = i;
					pre[v] = u;
					//printf("At %d\n", i);
					u = v;
					break;
				}
			}
			if (!flag){
				int _min = size - 1;
				for (int i = head[u]; i; i = e[i].ne){
					int v = e[i].x;
					if (e[i].c > e[i].f)
						_min = min(_min, dis[v]);
				}
				if (--gap[dis[u]] == 0)
					break;
				++gap[dis[u] = _min + 1];
				cur[u] = head[u];
				if (u != S)
					u = pre[u];
			}
		}
		return flow;
	}
}net;