struct matrix {
  ll m[SZ][SZ];
  matrix() {
    memset(m, 0, sizeof(m));
  }
  matrix(int x) {
    memset(m, 0, sizeof(m));
    for (int i = 0; i < SZ; i++) m[i][i] = x;
  }
  void clear() {
    memset(m, 0, sizeof(m));
  }
  friend matrix operator *(matrix a, matrix b) {
    matrix c;
    for (int k = 0; k < SZ; k++)
      for (int i = 0; i < SZ; i++) if (a.m[i][k])
        for (int j = 0; j < SZ; j++)
          (c.m[i][j]+=a.m[i][k]*b.m[k][j]%oo)%=oo;
    return c;
  }
  friend matrix operator ^(matrix e, ll k) {
    matrix tmp = matrix(1);
    while(k) {
      if (k&1) tmp = tmp*e;
      k>>=1;
      e=e*e;
    }
    return tmp;
  }
  void show() {
    printf("============\n");
    for (int i = 0; i < SZ; i++)
      for (int j = 0; j < SZ; j++)
        printf("%I64d%c", m[i][j], j == SZ-1? '\n':' ');
    printf("============\n");
  }
};

