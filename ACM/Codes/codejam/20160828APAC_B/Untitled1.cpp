#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
typedef pair<int, int> P;
P A[maxn];
vector<int> C;
int num[maxn * 3], L;
long long bit[maxn * 3];
void update(int v, int x)
{
    while(v <= L) {
        bit[v] += x;
        v += v & -v;
    }
}
long long query(int v)
{
    long long ans = 0;
    while(v > 0) {
        ans += bit[v];
        v -= v & -v;
    }
    return ans;
}
int ha[1000000];
int nn;
int geth(int x)
{
  return lower_bound(ha, ha+2*nn+1, x) - ha;
}

int main()
{
    freopen("data.in","r",stdin);
    freopen("ans.out", "w", stdout);
    int T, n; scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        int l, r, a, b, c1, c2, m;
        scanf("%d%d%d%d%d%d%d%d", &n, &l, &r, &a, &b, &c1, &c2, &m);
        nn = n;
        A[1].first = l, A[1].second = r;
        ha[1] = l;
        ha[2] = r;
        for(int i = 2; i <= n; i ++) {
            int nl = (a * 1LL * l + b * 1LL * r + c1) % m;
            int nr = (a * 1LL * r + b * 1LL * l + c2) % m;
            A[i].first = min(nl, nr);
            A[i].second = max(nl, nr);
            l = nl;
            r = nr;
          ha[i*2-1] = A[i].first;
          ha[i*2] = A[i].second;
        }
        sort(ha+1, ha+n*2+1);
        for (int i = 1; i <= n;i++)
      {
        cout << A[i].first << " " << A[i].second << endl;
      }
        C.clear();
        for(int i = 1; i <= n; i ++) {
       //     printf("[%d,%d]\n", A[i].first, A[i].second);
          //  if (A[i].first )
           // if (A[i].first )
            C.push_back(A[i].first - 1);
            C.push_back(A[i].first);
            C.push_back(A[i].second);
        }
        sort(C.begin(), C.end());
        C.erase(unique(C.begin(), C.end()), C.end());
        L = (int)C.size();
        memset(num, 0, sizeof num);
        memset(bit, 0, sizeof bit);
        for(int i = 1; i <= n; i ++) {
            A[i].first = lower_bound(C.begin(), C.end(), A[i].first) - C.begin();
            A[i].second = lower_bound(C.begin(), C.end(), A[i].second) - C.begin();
            num[A[i].first] ++;
            num[A[i].second + 1] --;
        }
        for(int i = 1; i < L; i ++) {
            num[i] += num[i - 1];
        }
        long long len = 0;
        for(int i = 0; i < L; i ++) {
            int x = 1;
            if (i) {
                x = C[i] - C[i - 1];
            }
            if (num[i] == 1) {
                bit[i] += x;
            }
            if (num[i]) {
                len += x;
            }
        }
        for(int i = 1; i < L; i ++) {
            bit[i] += bit[i - 1];
        }
        long long ans = 0;
        for(int i = 1; i <= n; i ++) {
            long long res = bit[A[i].second] - bit[A[i].first - 1];
          /*  if (num[A[i].first] == 1) {
                res ++;
            }*/
        //    printf("res[%d] = %lld\n", i, res);
            ans = max(ans, res);
        }
        printf("Case #%d: %lld\n", cas, len - ans);
    }
    return 0;
}
