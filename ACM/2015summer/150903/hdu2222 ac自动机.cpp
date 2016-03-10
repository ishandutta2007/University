#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAXN 250000
using namespace std;
int n, m;
char a, b;
int trie[MAXN][26];
int sz = 1;
int val[MAXN];
void insert(char *s) {
	int cur = 1;
	for(int i = 0; s[i]; i++){
		if(!trie[cur][s[i] - 'a'])
			trie[cur][s[i] - 'a'] = ++sz;
		cur = trie[cur][s[i] - 'a'];
	}
	val[cur]++;
}
int fail[MAXN];
void build_ac(){
	queue<int>q;
	q.push(1);
	fail[1] = 1;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i=0;i<26;i++)
			if(trie[cur][i]){
				if(cur == 1) fail[trie[cur][i]] =1;
				else{
					int tmp = fail[cur];
					while(tmp != 1 && trie[tmp][i] == 0) tmp = fail[tmp];
					if(trie[tmp][i]) fail[trie[cur][i]] = trie[tmp][i];
					else fail[trie[cur][i]] = 1;
				}
				q.push(trie[cur][i]);
			}
	}
}
char ss[1000010];
int query(){
	int ret = 0;
	int cur = 1, tmp;
	for(int i = 0; ss[i]; i++){

		if(trie[cur][ss[i] - 'a']) cur=trie[cur][ss[i] - 'a'];
		else{
			while(cur != 1 && trie[cur][ss[i] - 'a'] == 0) cur = fail[cur];
			if(trie[cur][ss[i] - 'a']) cur = trie[cur][ss[i] - 'a'];
		}
		tmp = cur;
		while(tmp != 1  && val[tmp] != -1){
			ret += val[tmp];
			val[tmp] = -1;
			tmp = fail[tmp];
		}
	}
	return ret;
}
void clear(){
	sz = 1;
	memset(val, 0, sizeof(val));
	memset(trie, 0, sizeof(trie));
	memset(fail, 0, sizeof(fail));
}
int main(){
	int t;
	scanf("%d",&t);
	char s[55];
	while(t--){
		clear();
		scanf("%d",&n);
		getchar();
		for(int i = 1; i <= n; i++){
			gets(s);
			insert(s);
		}
		gets(ss);
        build_ac();
        cout << query() << endl;
	}
}


