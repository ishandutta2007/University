#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <complex>
#include <tuple>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fs first
#define sc second
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define next _next
#define prev _prev
#define link _link
#define rank _rank
#define hash _hash
#define y1 yy1

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(4e5) + 100;

struct node {

    int len, link;
    int next[26];

};

struct query {

    int l, r, num, ans;

};

bool operator < (const query& a, const query& b) {
    return a.r < b.r;
}

int sz, last, maxv, cur = 0, cur2 = 0;
char s[N];
int ver[N], gl[N], gr[N], next_heavy[N], ans[N], heavy_pos[N], light_gl[N], light_gr[N], light_pos[N], prev[N], size[N];
pii heavy_rmq[4 * N], light_rmq[4 * N], euler_rmq[4 * N];
vi g[N];
node v[N];
query q[N];
set<pii> queries[N];

inline void init() {
    for(int i=0;i<N;i++) {
        queries[i].clear();
    }
    memset(g,0,sizeof(g));
    memset(v,0,sizeof(v));
//    memset(q,0,sizeof(q));
    memset(gr,0,sizeof(gr));
    memset(next_heavy,0,sizeof(next_heavy));
    memset(light_gl,0,sizeof(light_gl));
    memset(gl,0,sizeof(gl));
    sz=0;
    last=0;
    maxv=0;
    cur=0;
    cur2=0;
    memset(ver,0,sizeof(ver));
    sz = 1;
    last = 0;
    v[0].len = 0;
    v[0].link = -1;
    memset(v[0].next, -1, sizeof(v[0].next));
}

inline void add(int c) {
    int nlast = sz++;
    v[nlast].len = v[last].len + 1;
    memset(v[nlast].next, -1, sizeof(v[nlast].next));
    int p = last;
    while (p != -1 && v[p].next[c] == -1) {
        v[p].next[c] = nlast;
        p = v[p].link;
    }
    if (p == -1) {
        v[nlast].link = 0;
    } else {
        int q = v[p].next[c];
        if (v[p].len + 1 == v[q].len) {
            v[nlast].link = q;
        } else {
            int clone = sz++;
            v[clone].len = v[p].len + 1;
            v[clone].link = v[q].link;
            memcpy(v[clone].next, v[q].next, sizeof(v[q].next));
            while (p != -1 && v[p].next[c] == q) {
                v[p].next[c] = clone;
                p = v[p].link;
            }
            v[nlast].link = v[q].link = clone;
        }
    }
    last = nlast;
}

void dfs1(int v) {
    size[v] = 1;
    gl[v] = cur++;
    for (int u : g[v]) {
        dfs1(u);
        size[v] += size[u];
    }
    gr[v] = cur - 1;
}

void dfs2(int v, int pv) {
    prev[v] = pv;
    heavy_pos[v] = cur++;
    light_gl[v] = cur2;
    light_gr[v] = cur2 - 1;
    int best = -1;
    for (int u : g[v]) {
        if (best == -1 || size[u] > size[best]) {
            best = u;
        }
    }
    if (best != -1) {
        next_heavy[v] = best;
        for (int u : g[v]) {
            if (u != best) {
                light_pos[u] = cur2++;
            }
        }
        light_gr[v] = cur2 - 1;
        dfs2(best, pv);
    }
    for (int u : g[v]) {
        if (u != best) {
            dfs2(u, u);
        }
    }
}

inline pii get(pii* rmq, int l, int r) {
    l += maxv;
    r += maxv;
    pii res(-inf, -1);
    while (l <= r) {
        res = max(res, rmq[l]);
        l = (l + 1) / 2;
        res = max(res, rmq[r]);
        r = (r - 1) / 2;
    }
    return res;
}

inline void update(pii* rmq, int pos, pii val) {
    pos += maxv;
    rmq[pos] = val;
    while (pos > 1) {
        pos /= 2;
        rmq[pos] = max(rmq[pos * 2], rmq[pos * 2 + 1]);
    }
}

inline void add_query(int num) {
    int v = ver[q[num].r];
    queries[v].insert(mp(q[num].l, num));
    pii val = *(queries[v].rbegin());
    update(euler_rmq, gl[v], val);
    val.fs += ::v[v].len - 1;
    update(heavy_rmq, heavy_pos[v], val);
    while (v != -1) {
        v = prev[v];
        int pos = light_pos[v], pv = ::v[v].link;
        if (pos != -1) {
            val = mp(q[num].l + ::v[pv].len - 1, num);
            if (val > light_rmq[pos + maxv]) {
                update(light_rmq, pos, val);
            }
        }
        v = pv;
    }
}

inline void del_query(int num) {
    int v = ver[q[num].r];
    queries[v].erase(mp(q[num].l, num));
    pii val;
    if (sz(queries[v]) > 0) {
        val = *(queries[v].rbegin());
    } else {
        val = mp(-inf, -1);
    }
    update(euler_rmq, gl[v], val);
    val.fs += ::v[v].len - 1;
    update(heavy_rmq, heavy_pos[v], val);
    while (v != -1) {
        v = prev[v];
        int pos = light_pos[v], pv = ::v[v].link;
        if (pos != -1) {
            pii cur = get(euler_rmq, gl[v], gr[v]);
            update(light_rmq, pos, mp(cur.fs + ::v[pv].len - 1, cur.sc));
        }
        v = pv;
    }
}
int lr[N];
int main() {
    int T;
    cin>>T;
    int _case=0;
    while(T--){
    cout<<"Case #"<<++_case<<":"<<endl;
    int n, m;
    scanf("%s", s);
    n=strlen(s);
    cin>>m;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &q[i].l, &q[i].r);
        lr[i]=q[i].r-q[i].l+1;
        --q[i].l;
        --q[i].r;
        q[i].num = i;
        q[i].ans = -1;
    }
    init();
    for (int i = 0; i < n; ++i) {
        add(s[i] - 'a');
        ver[i] = last;
    }
    for (int i = 0; i < sz; ++i) {
        if (v[i].link != -1) {
            g[v[i].link].pb(i);
        }
    }
    dfs1(0);
    cur = 0;
    for (int i = 0; i < sz; ++i) {
        light_pos[i] = -1;
        next_heavy[i] = -1;
    }
    dfs2(0, 0);
    maxv = 1;
    while (maxv < sz) {
        maxv *= 2;
    }
    for (int i = 1; i < 2 * maxv; ++i) {
        heavy_rmq[i] = light_rmq[i] = euler_rmq[i] = mp(-inf, -1);
    }
    sort(q, q + m);
    int ptr = m - 1;
    for (int i = n - 1; i >= 0; --i) {
        while (ptr >= 0 && q[ptr].r > i) {
            add_query(ptr--);
        }
        int v = ver[i];
        while (v != -1) {
            for (;;) {
                pii cur = get(heavy_rmq, heavy_pos[prev[v]], heavy_pos[v]);
                if (cur.fs < i) {
                    break;
                }
                q[cur.sc].ans = i;
                del_query(cur.sc);
            }
            for (;;) {
                pii cur = get(light_rmq, light_gl[prev[v]], light_gr[v]);
                if (cur.fs < i) {
                    break;
                }
                q[cur.sc].ans = i;
                del_query(cur.sc);
            }
            if (next_heavy[v] != -1) {
                int u = next_heavy[v];
                for (;;) {
                    pii cur = get(euler_rmq, gl[u], gr[u]);
                    cur.fs += ::v[v].len - 1;
                    if (cur.fs < i) {
                        break;
                    }
                    q[cur.sc].ans = i;
                    del_query(cur.sc);
                }
            }
            v = ::v[prev[v]].link;
        }
    }
    for (int i = 0; i < m; ++i) {
        ans[q[i].num] = max(q[i].ans - q[i].l + 1, 0);
    }
    for (int i = 0; i < m; ++i) {
        printf("%d\n", lr[i]-ans[i]);
    }
    }
    return 0;
}
