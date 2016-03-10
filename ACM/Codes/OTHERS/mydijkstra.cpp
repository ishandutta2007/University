#include"cstdio"
#include"cstring"
#include"iostream"

using namespace std;

struct node{
	int pos;
	int v;
	node *next = NULL;
};

node *list[500];
int n,m;
int visited[500];
int shortpath[500];

void init(){
	int i,x,y,z;
	for(i=0; i<m; i++){
		scanf("%d %d %d",&x,&y,&z);
		struct node tmp1,tmp2;
		tmp1.v = z;
		tmp2.v = z;
		tmp1.pos = x;
		tmp2.pos = y;
		tmp1.next = list[y];
		tmp2.next = list[x];
		list[y] = &tmp1;
		list[x] = &tmp2;
	}

}


int search_path(int start){
	visited[start] = 1;
	(struct node *)now;
	now = list[start];
	while(now != NULL)
		shortpath[*now.pos] = min(shortpath[*now.pos],now.v);
	
	
	
	
	
}




int main(){
	
	while(scanf("%d %d",&n,&m) == 2){
		
		init();
		int start;
		memset(shortpath,0x3f,sizeof(shortpath));
		memset(visited,0,sizeof(visited));
		scanf("%d",&start);
		
		printf("%d\n",search_path(start));
	
	}
	
	return 0;
}

