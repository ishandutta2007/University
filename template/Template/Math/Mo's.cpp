/*
 * offlien Algorithm
 */
int rtn = sqrt(n);
bool operator < (const Query &a, const Query &b) {
  if (a.lp == b.lp) return a.r < b.r;
  else return a.lp < b.lp;
}

void update(int &l, int &r, int L, int R) {
  while(r < R) {
    r++;
    bita.add(a[r], 1);
    bitb.add(b[r], 1);
  }
  while(r > R) {
    bita.add(a[r], -1);
    bitb.add(b[r], -1);
    r--;
  }
  while(l < L) {
    bita.add(a[l], -1);
    bitb.add(b[l], -1);
    l++;
  }
  while(l > L) {
    l--;
    bita.add(a[l], 1);
    bitb.add(b[l], 1);
  }
}


