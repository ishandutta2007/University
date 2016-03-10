#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;


const int maxm = 10000000;

struct Trie
{
	struct Node
	{
		bool end;
		int id;
		int next[26];
		// Node *next[26];
	}node[maxm];
	// Node *head;
	int head, tot;
	void clear()
	{
		head = 0;
		memset(node[head].next, -1, sizeof(node[head].next));
		tot = 0;
	}

	void insert(char *s, int id)
	{
		// cout << s << " " << id << endl;
		int len = strlen(s);
		int nowid = head;
		for (int i = 0; i < len; i++)
		{
			Node& now = node[nowid];
			int x = s[i] - 'a';
			if (now.next[x] == -1)
			{
				now.next[x] = ++tot;
				node[tot].end = false;
				memset(node[tot].next, -1, sizeof(node[tot].next));
			}
			nowid = now.next[x];
			if (i == len - 1)
			{
				node[nowid].end = true;
				// cout << "!!" <<  s << "  " << id << endl;
				node[nowid].id = id;
			}
		}
	}
	int query(char *s)
	{
		int len = strlen(s);
		int nowid = head;
		for (int i = 0; i < len; i++)
		{
			Node& now = node[nowid];
			int x = s[i] - 'a';
			if (now.next[x] == -1)
				return false;
			nowid = now.next[x];
			if (i == len - 1){
				if(node[nowid].end) return node[nowid].id;
				else return 0;
			}
		}
		return 0;
	}
} t;



int fa[500020];
int tot = 1;
int divs[500020];

int root(int i){
    if(fa[i] == i)
        return i;

    fa[i] = root(fa[i]);
    return fa[i];
}
void unionset(int a, int b){
    int ra = root(a);
    int rb = root(b);

    if(ra == rb) return;

    fa[ra] = rb;

}

int main(){
    t.clear();
    char s1[24], s2[24];

    for(int i = 0; i < 500000; i++)
        fa[i] = i;
    int id1, id2;
    while(scanf("%s%s", s1, s2) != EOF){
        if(s1[0] == '!') break;
        if(!t.query(s1)) t.insert(s1, tot++);
        if(!t.query(s2)) t.insert(s2, tot++);
        id1 = t.query(s1);
        id2 = t.query(s2);
       // printf("%s %d\n", s1, id1);
       // printf("%s %d\n", s2, id2);
        divs[id1]++;
        divs[id2]++;
        unionset(id1, id2);
    }

    bool flag = true;
    int rot = root(1);

    for(int i = 1; i < tot; i++)
        if(root(i) != rot) flag = false;

//    for(int i = 1; i < tot; i++)
//        printf("%d %d\n", i, root(i));

    int cnt = 0;
    for(int i = 1; i < tot; i++)
        if(divs[i] % 2 == 1) cnt++;
    if(cnt != 2 && cnt != 0) flag = false;

    if(flag) printf("Possible\n");
    else printf("Impossible\n");

    return 0;
}