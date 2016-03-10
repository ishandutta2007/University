#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1111111;

int tree[MAXN];
void ins(int x, int val) {
    for (int z = x; z <= 1000000; z += z & -z) tree[z] += val;
}

int ask(int r) {
    int ret = 0;
    for (int z = r; z; z -= z & -z) ret += tree[z];
    return ret;
}

pair<int,int> A[MAXN], B[MAXN];
int Array[MAXN];
int n;
int main() {
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    cin >> n;
    vector<int> tmp;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &A[i].first, &A[i].second);
        tmp.push_back(A[i].first); tmp.push_back(A[i].second);
    }
    sort(tmp.begin(), tmp.end());
    unique(tmp.begin(), tmp.end());//ÒÆ³ýÖØ¸´µÄÔªËØ
    int pn = 0;
    for (int i = 0; i < tmp.size(); ++i) {
        if (i && tmp[i] <= tmp[i - 1]) break ;
        if (i && tmp[i] > tmp[i - 1] + 1) B[++pn] = {tmp[i - 1] + 1, tmp[i] - 1};
        B[++pn] = {tmp[i], tmp[i]};
    }
    for (int i = 1; i <= pn; ++i) Array[i] = i;
    for (int i = 1; i <= n; ++i) {
        int x = lower_bound(B + 1, B + pn + 1, make_pair(A[i].first, -1)) - B;
        int y = lower_bound(B + 1, B + pn + 1, make_pair(A[i].second, -1)) - B;
        swap(Array[x], Array[y]);
    }
    long long ans = 0;
    for (int i = pn; i >= 1; --i) {
        ans += (long long)(B[Array[i]].second - B[Array[i]].first + 1) * ask(Array[i] - 1);
        ins(Array[i], B[Array[i]].second - B[Array[i]].first + 1);
    }
    cout << ans << endl;
    return 0;
}
