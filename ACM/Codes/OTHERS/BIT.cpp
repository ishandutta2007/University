#include"cstdio"
#include"cstring"
#include"iostream"
#define MAXN 50020

using namespace std;



class BIT{
public:
	int t[MAXN];
	int tmp[MAXN];
	int n;
	BIT(){memset(t,0,sizeof(t));}
	
	int lowbit(int a){return (-a)&a;}
	void init(){
		memset(t,0,sizeof(t));
		scanf("%d",&n);
		for(int i = 1; i <= n; i++)
			scanf("%d",&tmp[i]);
		for(int i = 1; i <= n; i++){
			t[i] = tmp[i];
			for(int j = i-1; j > i-lowbit(i); j -= lowbit(j))
				t[i] += t[j];
		}
	}
	
	int _query(int a){
		if(a > n || a <= 0) return 0;
		int ans = 0;
		for(int i = a; i >= 1; i -= lowbit(i))
			ans += t[i];
		return ans;
	}
	
	int query(int a,int b){
		return _query(b) - _query(a - 1);
	}
	
	void modify(int a, int x){
		if(a > n || a <= 0) return ;
		
		for(int i = a; i <= n; i += lowbit(i)) t[i] += x;
	}
	
}T;



int tmp[MAXN];



int main(){
	int t;
	class BIT a;
	scanf("%d",&t);
	
	for(int i = 1; i <= t; i++){
		printf("Case %d:\n",i);
		a.init();
		
		char cmd[6];
		int x,y;
		
		while(1){
			scanf("%s", cmd);
			if(strcmp(cmd, "End") == 0)
				break;
			scanf("%d%d",&x,&y);
			if(strcmp(cmd, "Query") == 0)
				printf("%d\n",a.query(x, y));
			else if(strcmp(cmd, "Add") == 0)
				a.modify(x, y);
			else if(strcmp(cmd, "Sub") == 0)
				a.modify(x,-y);
		}
		
	}
	
	return 0;
}
