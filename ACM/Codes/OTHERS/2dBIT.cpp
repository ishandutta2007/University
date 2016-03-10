#include"cstdio"
#include"iostream"
#include"cstring"
#define MAXN 32020
#define MAXM 15020

using namespace std;


class BIT{
public:
	int t[MAXN][MAXN];
	int n;
	int level[MAXM];
	BIT(){
		memset(t,0,sizeof(t));
		memset(level,0,sizeof(level));
	}
	
	int lowbit(int a){return (-a)&a;}
	void init(){
		memset(t,0,sizeof(t));
		scanf("%d",&n);
		for(int i = 1; i <= n; i++){
			
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

int main(){
	
	return 0;
}
