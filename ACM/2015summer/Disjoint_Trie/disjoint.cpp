struct Disjoint
{
	int fa[1111], size[1111];
	void clear(int n)
	{
		for (int i = 1; i <= n; i++)
			size[i] = 1, fa[i] = i;
	}
	int root(int i)
	{
		while (i != fa[i])
			i = fa[i] = fa[fa[i]];
		return i;
	}
	int unite(int x, int y)
	{
		size[root(y)] += size[root(x)];
		fa[root(x)] = root(y);
	}
	bool query(int x, int y)
	{
		return root(x) == root(y);
	}
	int query(int x)
	{
		return size[root(x)];
	}
};