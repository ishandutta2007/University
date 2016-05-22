#define maxn 50020
struct BIT{
  int c[maxn];
  int n;
  void clear(int n){
    memset(c, 0, sizeof(c));
    this->n = n;
  }
  inline int lowbit(int x){
    return x & (-x);
  }
  void add(int pos, int delta){
    printf("n = %d\n", n);
    while(pos < maxn){
      c[pos] += delta;
      pos += lowbit(pos);
    }
  }
  int getsum(int pos){
    int ans = 0;
    while(pos > 0){
      ans += c[pos];
      pos -= lowbit(pos);
    }
    return ans;
  }
}bit;
