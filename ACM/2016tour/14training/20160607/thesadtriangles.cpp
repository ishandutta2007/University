#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 400020;
const int oo = 1e9+7;

int n, m, L;
int height[maxn];
int maxlen = 100000 * 4;
int S[maxn];

vector<pii> faceleft11, faceright11, faceleft13, faceright13;

bool cmpr(pii &a, pii &b)
{
  return a.X == b.X ? (a.Y > b.Y) : a.X < b.X;
}
bool cmpl(pii &a, pii &b)
{
  return a.X == b.X ? (a.Y > b.Y) : a.X > b.X;
}

void calheightr(vector<pii> v, int d)
{
  int pos = 0;
  int now = 0;
  int len = v.size();
  if (len == 0) return;
  for (int i = v[pos].X, now = v[pos].Y * d; i <= maxlen; i++)
  {
    while(pos + 1 < len && now < v[pos+1].Y * d && i >= v[pos+1].X)
    {
      now = v[pos+1].Y * d;
      pos++;
    }
    if (pos >= len) return;
    S[i+1] = max(S[i+1], (now*2 - d));
    // height[i] = max(height[i], now);
    now -= d;
  }
}

void calheightl(vector<pii> v, int d)
{
  int pos = 0;
  int now = 0;
  int len = v.size();
  if (len == 0) return;
  for (int i = v[pos].X, now = v[pos].Y * d; i >= 0; i--)
  {
    while(pos + 1 < len && now < v[pos+1].Y * d && i <= v[pos+1].X)
    {
      now = v[pos+1].Y * d;
      pos++;
    }
    if (pos >= len) return;
    S[i] = max(S[i], (now*2 - d));
    // height[i] = max(height[i], now);
    now -= d;
  }
}


void adjustl(vector<pii> &v)
{
  if (v.size() == 0) return;
  vector<pii> tmp;
  tmp.push_back(v[0]);
  int pos = 0;
  for (int i = 1, len = v.size(); i < len; i++)
  {
    if (v[i].X <= tmp[pos].X && v[i].X + v[i].Y >= tmp[pos].X + tmp[pos].Y) continue;
    else
    {
      pos++;
      tmp.push_back(v[i]);
    }
  }
  v = tmp;
}


void adjustr(vector<pii> &v)
{
  if (v.size() == 0) return;
  vector<pii> tmp;
  tmp.push_back(v[0]);
  int pos = 0;
  for (int i = 1, len = v.size(); i < len; i++)
  {
    if (v[i].X >= tmp[pos].X && v[i].X + v[i].Y <= tmp[pos].X + tmp[pos].Y) continue;
    else
    {
      pos++;
      tmp.push_back(v[i]);
    }
  }
  v = tmp;
}


ll calans()
{
  ll ans = 0, tmp = 0;
  int l = 0;
  for (int r = 1; r <= maxlen; r++)
  {
    tmp += S[r];
    if (r - l > L)
    {
      l++;
      tmp -= S[l];
    }
    if (r - l == L)
    {
      ans = max(ans, tmp);
    }
  }
  return ans;
}

int main()
{
  // freopen("in.txt", "r", stdin);
  int T;
  scanf("%d", &T);

  for (int ka = 1; ka <= T; ka++)
  {
    scanf("%d%d%d", &n, &m, &L);
    L *= 4;
    faceleft11.clear();
    faceright11.clear();
    faceleft13.clear();
    faceright13.clear();
    int tx, tk, tl;
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d%d", &tx, &tk, &tl);
      tx *= 4;
      tl *= 4;
      if (tk == 1)
        faceleft11.push_back(pii(tx, tl));
      else
        faceleft13.push_back(pii(tx, tl));
    }
    for (int i = 0; i < m; i++)
    {
      scanf("%d%d%d", &tx, &tk, &tl);
      tx *= 4;
      tl *= 4;
      if (tk == 1)
        faceright11.push_back(pii(tx, tl));
      else
        faceright13.push_back(pii(tx, tl));
    }
    
    // memset(height, -1, sizeof(height));
    memset(S, 0, sizeof(S));
    // sort the triangle
    sort(faceright11.begin(), faceright11.end(), cmpr);
    sort(faceright13.begin(), faceright13.end(), cmpr);
    adjustr(faceright11);
    adjustr(faceright13);


    sort(faceleft11.begin(), faceleft11.end(), cmpl);
    sort(faceleft13.begin(), faceleft13.end(), cmpl);
    adjustl(faceleft11);
    adjustl(faceleft13);

    // cout << faceleft11[0].X << " " << faceleft11[0].Y << endl;
    // cout << faceleft11[1].X << " " << faceleft11[1].Y << endl;
    // cout << faceright11[0].X << " " << faceright11[0].Y << endl;
    // cout << faceright11[1].X << " " << faceright11[1].Y << endl;

    calheightr(faceright11, 1);
    // for (int i = 1; i <= maxlen; i++)
    // {
    //   printf("%.4f ", S[i]);
    // }
    // printf("\n");
    calheightr(faceright13, 3);
    calheightl(faceleft11, 1);
    calheightl(faceleft13, 3);

    // for (int i = 1; i <= maxlen; i++)
    // {
    //   printf("%.4f ", S[i]);
    // }

    // printf("\n[%d]\n", L);

    // cout << endl;
    printf("Case #%d: %.6f\n", ka, calans()*1.0 / 32.0);
  }
  return 0;
}
