//spfa费用流(max)
bool find()
{
	for (int i=st;i<=ed;i++) d[i]=-inf;
	int head=0,tail=1;
	q[1]=st,d[st]=0,inque[st]=1;
	while (head<tail)
	{
		int now=q[++head];
		for (int j=fir[now];j;j=e[j].next)
		{
			int k=e[j].t;
			if (e[j].val&&d[k]<d[now]+e[j].cost)
			{
				d[k]=d[now]+e[j].cost;
				pre[k]=j;
				if (!inque[k]) q[++tail]=k，inque[k]=1;
			}
		}
		inque[now]=0;
	}
	return (d[ed]>-inf) ;
}
void fare_flow()
{
	fare=flow=0;
	while (find())
	{
		int tmp=inf;
		for (int j=pre[ed];j;j=pre[e[j].s]) tmp=min(tmp,e[j].val);
		fare+=tmp*d[ed];
		flow+=tmp;
		for (int j=pre[ed];j;j=pre[e[j].s]) e[j].val-=tmp,e[j^1].val+=tmp;
	}
}