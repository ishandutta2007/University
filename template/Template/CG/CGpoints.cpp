struct Point {
  double x, y;
  Point(double _x, double _y):x(_x),y(_y){}
  Point():x(0.0),y(0.0){}
};
typedef Point Vec;

void showPoint(Point A) {
  printf("(%.6f, %.6f)\n", A.x, A.y);
}
const Vec operator + (Vec A, Vec B) {
  return Vec(A.x+B.x, A.y+B.y);
}
const Vec operator - (Vec A, Vec B) {
  return Vec(A.x-B.x, A.y-B.y);
}
const double operator * (Vec A, Vec B) {
  return A.x*B.x + A.y*B.y;
}
// A*B = |A|*|B|*sin(theta)
// theta为 A,B 向量的夹角
// 如果 A 在 B 的顺时针方向180度内，则theta取正值
// 向量叉乘
// 返回值为正时，表示 A 在 B 的右侧180度内
// 返回值的绝对值等于以A,B向量为邻边的平行四边型的面积
const double operator ^ (Vec A, Vec B) {
  return A.x*B.y - A.y*B.x;
}

double Lenth(Vec &v) {
	return sqrt(v*v);
}


// 将点 A 绕 p 逆时针旋转 theta 角度(弧度制)
// 1.平移坐标
// 2.旋转
// 3.平移坐标
Vec rotate(point A, point p， double theta) {
	A = A-p;
	point ret = point(A.x*cos(theta)-A.y*sin(theta), A.x*sin(theta)+A.y*cos(theta)) + p;
	return ret;
}


// 计算C到AB的距离
// isSeg = 1 : AB为线段
// isSeg = 0 : AB为直线
double linePointDist(Point A, Point B, Point C, bool isSeg) {
  double dist = ((B-A)^(C-A)) / sqrt((B-A)*(B-A));
  if (isSeg) {
    double dot1 = (C-B)*(B-A);
    if (dcmp(dot1) > 0) return sqrt((B-C)*(B-C));
    double dot2 = (C-A)*(A-B);
    if (dcmp(dot2) > 0) return sqrt((A-C)*(A-C));
  }
  return fabs(dist);
}

// 判断线段的两个端点是否在直线的两侧
bool lineCrossSeg(Point p1, Point p2, Point ls, Point le)
{
  Vec ver = ls-le, v1 = p1-ls, v2 = p2-ls;
  return dcmp((ver^v1)*(ver^v2)) <= 0;
}

// 判断点是否在线段上
// 叉积为 0 表示共线
bool pointOnSeg(point s1, point s2, point p, bool includeEnd)
{
  if ((s1 == p || s2 == p) && !includeEnd) return false;
  s2 = s2-s1;
  p = p-s1;
  return dcmp(s2^p)==0 && dcmp(s2*p)>=0;

  double minx = min(s1.x, s2.x);
  double maxx = max(s1.x, s2.x);
  double miny = min(s1.y, s2.y);
  double maxy = max(s1.y, s2.y);

  if ((s1 == p || s2 == p) && !includeEnd) return false;
  if (p.x-minx>=0 
      && maxx-p.x>=0 
      && p.y-miny>=0 
      && maxy-p.y>=0
      && ((s2-s1)^(p-s1)) == 0)
    return true;
  else
    return false;
}

// 判断两条线段是否相交
// 两次跨立试验
typedef pair<Point, Point> seg;
bool segCrossSeg(seg a, seg b, bool includeEnd)
{
  Vec ver = b.X-b.Y, v1 = a.X-b.X, v2 = a.Y-b.X;
  int tmp1 = dcmp((ver^v1)*(ver^v2));
  ver = a.X-a.Y, v1 = b.X-a.X, v2 = b.Y-a.X;
  int tmp2 = dcmp((ver^v1)*(ver^v2));
  if (includeEnd)
    return tmp1 <= 0 && tmp2 <= 0;
  else
    return tmp1 < 0 && tmp2 < 0;
}

double areaPoly(vector<Point> &P) {
  double area = 0.0;
  for (int i = 1, n = P.size(); i+1 < n; i++) {
    area += (P[i+1]-P[0])^(P[i]-P[0]);
  }
  return area / 2.0;
}

