//By Sss 2015.4.12
//����ͼ�޻�·������㷨������������ɨ�裬 o(n + m)
#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>
const int N = 100;
using namespace std;
struct Edge{
    int ed, w; //�ߵ��յ�ͱ�Ȩ
    Edge* next;
    Edge(int _ed, int _w, Edge* _next)
    {
        ed = _ed; w = _w; next = _next;
    }
};

struct Node{
    int du; //��¼�˵�����
    Edge* e; //�ڽӱ�洢�˵������ı�
    Node()
    {
        du = 0; e = NULL;
    }
};

int n, m, x, y, w, d[N];
Node* st[N];

int main()
{
    //freopen("test.in", "r", stdin);
    cout << "����������ͱ���" << endl;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        st[i] = new Node();
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &x, &y, &w);
        st[x]->e = new Edge(y, w, st[x]->e);
        st[y]->du++; //���������
    }
    stack<int> S; //�洢���Ϊ��ĵ�
    queue<int> Q; //�洢��������
    while(!S.empty()) S.pop();
    while(!Q.empty()) Q.pop();
    for(int i = 1; i <= n; i++)
        if(st[i]->du == 0) S.push(i);
    //������Ƚ�����������
    while(!S.empty()){
        x = S.top(); S.pop();
        Q.push(x);
        for(Edge* p = st[x]->e; p != NULL; p = p->next)
        {
            st[p->ed]->du--;
            if(st[p->ed]->du == 0) S.push(p->ed);
        }
    }
    memset(d, 0x3f, sizeof(d));
    cout << "��������㣺" << endl;
    cin >> y; d[y] = 0;
    //������������ÿ����Ϊ�����������ĵ����̾���
    while(!Q.empty()){
        x = Q.front(); Q.pop();
        for(Edge* p = st[x]->e; p != NULL; p = p->next)
            d[p->ed] = min(d[p->ed], d[x] + p->w);
    }
    printf("���Ϊ%d�ĵ㵽���е�����·��Ϊ\n", y);
    for(int i = 1; i <= n; i++)
        if(d[i] == 0x3f3f3f3f)
            printf("%d: oo\n", i);
        else
            printf("%d: %d\n", i, d[i]);
}
