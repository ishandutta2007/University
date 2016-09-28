struct Matrix {
  double m[3][3];
  Matrix(){
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        m[i][j]=0.0;
  }
  Matrix(double a) {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        m[i][j]=0.0;
    for (int i = 0; i < 3; i++)
      m[i][i] = a;
  }
  Matrix operator * (Matrix M) {
    Matrix ret;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        for (int k = 0; k < 3; k++)
          ret.m[i][j] += m[i][k]*M.m[k][j];
    return ret;
  }
  void init(double x, double y, double r) {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        m[i][j]=0.0;
    m[0][0]=cos(r);
    m[0][1]=sin(r);
    m[1][0]=-sin(r);
    m[1][1]=cos(r);
    m[2][0]=x*(1-cos(r))+y*sin(r);
    m[2][1]=y*(1-cos(r))-x*sin(r);
    m[2][2]=1.0;
  }
}t;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    Matrix ans = Matrix(1);
    double x, y, r;
    for (int i = 1; i <= n; i++) {
      scanf("%lf%lf%lf", &x,&y,&r);
      t.init(x,y,r);
      ans = ans*t;
    }
    double theta = atan2(ans.m[0][1], ans.m[0][0]);
    if (dcmp(theta) < 0) theta += pi*2.0;
    double a = 1-ans.m[0][0];
    double b = ans.m[0][1];
    double A = ans.m[2][0];
    double B = ans.m[2][1];
    y = (b*A+a*B) / (a*a+b*b);
    x = (a*A-b*B) / (a*a+b*b);
    printf("%.8f %.8f %.8f\n", x, y, theta);
  }
  return 0;
}

