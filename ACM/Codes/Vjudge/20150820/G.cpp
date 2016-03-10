#include "stdio.h"
#include "iostream"
#include "algorithm"
#include "string.h"
#include "math.h"
#include "stdlib.h"

#define maxn 1000020
#define inf 2147483646

using namespace std;

int c[maxn][2], fa[maxn];
int ma[maxn], la[maxn], ra[maxn], a[maxn], key[maxn], sum[maxn], cov[maxn], size[maxn];
bool rev[maxn];
int q[maxn];
int n,m,rot,num = 0, tail;

void update(int x)
{
	if (x == 0) return;
	la[x]=max(la[c[x][0]],sum[c[x][0]]+key[x]+max(0,la[c[x][1]]));
	ra[x]=max(ra[c[x][1]],sum[c[x][1]]+key[x]+max(0,ra[c[x][0]]));
	ma[x]=max(max(ma[c[x][0]],ma[c[x][1]]),key[x]+max(0,ra[c[x][0]])+max(0,la[c[x][1]]));sum[x]=sum[c[x][0]]+sum[c[x][1]]+key[x];
	size[x]=size[c[x][0]]+size[c[x][1]]+1;
}
void reverse(int x)
{
    if (!x) return;
    swap(c[x][0],c[x][1]);
    swap(la[x],ra[x]);
    rev[x]^=1;
}
void recover(int x,int z)
{
	if (!x) return ;
	key[x]=cov[x]=z;
	sum[x]=size[x]*z;
	la[x]=ra[x]=ma[x]=max(z,sum[x]);
}
void down(int x)
{
	if (!x) return;
	if (rev[x])
	{
	    reverse(c[x][0]);
	    reverse(c[x][1]);
	    rev[x]=0;
	}
	if (cov[x]!=-inf)
	{
	    recover(c[x][0],cov[x]);
	    recover(c[x][1],cov[x]);
	    cov[x]=-inf;
	}
}

void relax(int x,int rot)
{
        if (x!=rot) relax(fa[x],rot);
        down(x);
}
void rotate(int x,int &rot)
{
    int y=fa[x],z=fa[y];
    int p=(c[y][1]==x),q=p^1;
    if (y==rot) rot=x; 
    else if (c[z][0]==y) c[z][0]=x; else c[z][1]=x;
    fa[x]=z; fa[y]=x; fa[c[x][q]]=y;
    c[y][p]=c[x][q]; c[x][q]=y;
    update(y);
}
void splay(int x,int &rot)
{
	relax(x,rot);
	while (x!=rot)
	{
	    int y=fa[x], z=fa[y];
	    if (y!=rot)
	        if ((c[y][0]==x)xor(c[z][0]==y)) rotate(x,rot); else rotate(y,rot);
	    rotate(x,rot);
	}
	update(x);
}
int pick()
{
	if(tail) return q[tail--];
	return ++num;
}

int setup(int x)
{
	int t = pick();
	key[t] = a[x];
	cov[t] = -inf;
	rev[t] = false;
	la[t] = ra[t] = ma[t] = -inf;
	return t;
}


int build(int l, int r)
{
	int mid = (l + r) >> 1, left = 0, right = 0;
	if(l < mid) left = build(l, mid - 1);
	int t = setup(mid);
	if(r > mid) right = build(mid + 1, r);
	if(left) c[t][0] = left, fa[left] = t;
	if(right) c[t][1] = right, fa[right] = t;
	update(t);
	return t;
}

void output(int x)
{
	if(x == 0) return;
	printf("x = %d, max = %d, lmax = %d, rmax = %d, key = %d, sum = %d, lson = %d, rson = %d\n",x,  ma[x], la[x], ra[x], key[x], sum[x], c[x][0], c[x][1]);
	output(c[x][0]);
	output(c[x][1]);
}
void del(int &x)
{
    if (!x) return;
    q[++tail] = x;
    fa[x]=0;
    del(c[x][0]);
    del(c[x][1]);
    la[x]=ra[x]=ma[x]=-inf;
    x=0;
}
int find(int t,int k)
{
	down(t);
	if (k==size[c[t][0]]+1) return t;
	if (k<size[c[t][0]]+1) return find(c[t][0],k);
	else return find(c[t][1],k-size[c[t][0]]-1);
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif




	scanf("%d%d", &n, &m);
	for(int i = 2; i <= n + 1; i++) scanf("%d", &a[i]);

	ra[0] = la[0] = ma[0] = -inf;
	rot = build(1, n + 2);
	//output(rot);
	char sign[20];
    int x,y,l,r,z,ans;
	for (int i=1;i<=m;i++)
    {
        scanf("%s",sign);
        if (sign[0]=='I')
        {
            scanf("%d %d",&x,&y);
            l=find(rot,x+1); r=find(rot,x+2);
            splay(r,rot); splay(l,c[rot][0]);
            for (int j=1;j<=y;j++) 
                scanf("%d",&a[j]);
            int tmp=build(1,y);
            fa[tmp]=l; c[l][1]=tmp;                 
            update(l); update(r);
        }
        if (sign[0]=='D')
        {
            scanf("%d %d",&x,&y);
            l=find(rot,x);  r=find(rot,x+y+1);
            splay(r,rot); splay(l,c[rot][0]);
            del(c[l][1]);
            update(l); update(r);
        }                       
        if (sign[0]=='M'&&sign[2]=='K')
        {
            scanf("%d %d %d",&x,&y,&z);
            l=find(rot,x); r=find(rot,x+y+1);
            splay(r,rot); splay(l,c[rot][0]);
            recover(c[l][1],z);
        }
        if (sign[0]=='R')
        {
            scanf("%d %d",&x,&y);
            l=find(rot,x); r=find(rot,x+y+1);
            splay(r,rot); splay(l,c[rot][0]);
            reverse(c[l][1]);
        }
        if (sign[0]=='G')
        {
            scanf("%d %d",&x,&y);
            l=find(rot,x); r=find(rot,x+y+1);
            splay(r,rot); splay(l,c[rot][0]);
            ans=sum[c[l][1]];
            printf("%d\n",ans);
        }
        if (sign[0]=='M'&&sign[2]=='X')
        {
    	    splay(n + 2,rot); splay(1,c[rot][0]);
            ans=ma[c[1][1]];
            printf("%d\n",ans);
        }
        //for(int i=1;i<=num;i++) cout<<find(rot,i)<<' ';cout<<"\n";
        //for (int i=1;i<=num;i++) cout<<i<<' '<<size[i]<<' '<<fa[i]<<' '<<c[i][0]<<' '<<c[i][1]<<' '<<la[i]<<' '<<ra[i]<<' '<<ma[i]<<' '<<sum[i]<<endl;
    }

	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}