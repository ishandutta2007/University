struct edge
{
	int x, ne, c, f;
};

struct NetFlow
{
	edge e[M];
	int head[N], h[N], dis[N], q[N], stack[N];
	bool used[N];
	int pos, stop, top, S, T;
	LL flow;
	
	void init(int s, int t)
	{
		pos = 1;
		flow = top = 0;
		S = s;
		T = t;
		memset(head, 0, sizeof(head));
	}
	
	void adde(int u, int v, int c)
	{
		e[++pos] = (edge){v, head[u], c, 0};
		head[u] = pos;
		e[++pos] = (edge){u, head[v], c, c};
		head[v] = pos;
	}
	
	bool number()
	{
		memset(dis, 0, sizeof(dis));
		memset(used, 0, sizeof(used));
		int p1, p2, x;
		used[q[p1 = p2 = 1] = S] = true;
		while (p1 <= p2)
		{
			x = q[p1++];
			for (int i = head[x]; i; i = e[i].ne)
				if (e[i].c > e[i].f && !used[e[i].x])
				{
					used[q[++p2] = e[i].x] = true;
					dis[e[i].x] = dis[x] + 1;
				}
		}
		if (!used[T])
			return false;
		memcpy(h, head, sizeof(head));
		return true;
	}
	
	bool dinic(int x)
	{
		if (x == T)
		{
			int cut = INF;
			for (int i = 1; i <= top; ++i)
				cut = min(cut, e[stack[i]].c - e[stack[i]].f);
			for (int i = 1; i <= top; ++i)
			{
				e[stack[i]].f += cut;
				e[stack[i] ^ 1].f -= cut;
				if (e[stack[i]].c == e[stack[i]].f)
					stop = i;
			}
			flow += cut;
			return true;
		}
		for (int &i = h[x]; i; i = e[i].ne)
			if (e[i].c > e[i].f && dis[x] == dis[e[i].x] - 1)
			{
				stack[++top] = i;
				if (dinic(e[i].x) && stop != top)
				{
					--top;
					return true;
				}
				--top;
			}
		return false;
	}
	
	LL maxflow()
	{
		while (number())
			dinic(S);
		return flow;
	}
}net;
