#include"cstdio"
#include"cstring"
#include"iostream"

using namespace std;

int parrent[5020];
int N,M,Q;


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
	while(scanf("%d%d%d",&N,&M,&Q) == 3){
		make_set();
		int i;
		int a,b;
		for(i=1;i<=M;i++){
			scanf("%d%d",&a,&b);
			union_set(a,b);
		}
		
		for(i=1;i<=Q;i++){
			scanf("%d%d",&a,&b);
			if(find_set(a) == find_set(b))
				printf("yes\n");
			else
				printf("no\n");
			
			
		}
	}
	
	
	return 0;
}
