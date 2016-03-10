struct edge
{
	int s,t,val,next;
}e[maxm];

void add(int x,int y,int z)
{
	e[++tot].s=x; e[tot].t=y; e[tot].val=z; e[tot].next=fir[x]; fir[x]=tot;
	e[++tot].s=y; e[tot].t=x; e[tot].val=0; e[tot].next=fir[y]; fir[y]=tot;
}

int dfs(int i,int flow)
{
	if (i==ed) return flow;
	int sap=0;
	for (int j=last[i];j;j=e[j].next)
	{
		int k=e[j].t;
		if (e[j].val&&dis[i]==dis[k]+1)
		{
			last[i]=j;
			int tmp=dfs(k,min(e[j].val,flow-sap));
			e[j].val-=tmp;
			e[j^1].val+=tmp;
			sap+=tmp;
			if (sap==flow) return sap;
		}
	}
	if (dis[st]>=num) return sap;
	if (!(--gap[dis[i]])) dis[st]=num;
	++gap[++dis[i]];
	last[i]=fir[i];
	return sap;
}