#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define MAXN 1000002
using namespace std;
bool flag[MAXN];
int dist[MAXN],n;
struct Node{
	int id,val;
	Node(){}
	Node(int _id,int _val):id(_id),val(_val){}
	bool operator<(const Node &a)const{
//重载<,使优先队列队首始终是val最小的元素
		return val > a.val;
	}
};
struct Old{
	int u,v,w;
	Old(){}
	Old(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
}a[MAXN];
struct Edge{
	int v,cost;
	Edge(){}
	Edge(int _v,int _cost):v(_v),cost(_cost){}
};
vector<Edge>mp[MAXN];                                        //mp[i][j].v表示i的第j条边连接的是顶点v，权值为mp[i][j].cost
long long dijkstra(int s){
	int i,j,k,v,cost;
	Node tep,tep2;
	memset(flag,false,sizeof(flag));
	memset(dist,0x7f,sizeof(dist));
	priority_queue<Node>que;
	while(!que.empty()) que.pop();//清空队列
	dist[s] = 0;
	tep.id = s;
	tep.val = 0;
	que.push(tep);   //起点入队
	while(!que.empty()){
		tep = que.top();
		que.pop();
		if(flag[tep.id]) continue;
 //如果tep.id已经在集合中，不用拿出
		flag[tep.id] = true;                                                  //将tep.id放入集合
		for(i = 0;i < mp[tep.id].size(); i++){
			v = mp[tep.id][i].v;
			cost = mp[tep.id][i].cost;
			if(!flag[v] && dist[v] > dist[tep.id] + cost){                //松弛
				dist[v] = dist[tep.id] + cost;
				tep2.id = v;
				tep2.val = dist[v];
    //优先队列中按节点权值排列，由小到大
				que.push(tep2);                                     //加入集合
			}
		}
	}
	long long sum = 0;
	for(i = 1;i <= n; i++) sum += dist[i];
	return sum;
}
int main()
{
	int i,j,k,m,T;
        int u,v,w;
        long long ans;
        scanf("%d",&T);
        while(T--){
                scanf("%d%d",&n,&m);
                for(i = 1;i <= n; i++) mp[i].clear();
                for(i = 1;i <= m;i++){
                        scanf("%d%d%d",&u,&v,&w);
                        a[i] = Old(u,v,w);
                        mp[u].push_back(Edge(v,w));
                }
                ans = 0;
                ans += dijkstra(1);
                for(i = 1;i <= n; i++) mp[i].clear();
                for(i = 1;i <= m; i++){
                        u = a[i].u;
                        v = a[i].v;
                        w = a[i].w;
                        mp[v].push_back(Edge(u,w));
                }
                ans += dijkstra(1);
                printf("%I64d/n",ans);
        }
}
