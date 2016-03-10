#include"cstdio"
#include"cstring"
#include"iostream"

using namespace std;

int parrent[50020];
int N,M;


void make_set(){
	for(int i=1; i<=N ;i++)
		parrent[i] = i;
}

int find_set(int i){
	if(parrent[i] != i)
		parrent[i] = find_set(parrent[i]);
	
	return parrent[i];
}

void union_set(int a, int b){
	int pa = find_set(a);
	int pb = find_set(b);
	if(pa != pb)
		parrent[pa] = pb;
}



int main(){
	int cc = 1;
	while(scanf("%d%d",&N,&M) == 2){
		if(N==0 && M==0)
			break;
		make_set();
		int i;
		int a,b;
		for(i=1;i<=M;i++){
			scanf("%d%d",&a,&b);
			union_set(a,b);
		}
		int ans = 0;
		for(i=1; i<=N; i++)
			if(parrent[i] == i)
				ans++;
		printf("Case %d: %d\n",cc++,ans);
		
	}
	
	
	return 0;
}
