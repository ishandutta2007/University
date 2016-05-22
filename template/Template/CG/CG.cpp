// undone !!
const double EPS = 1e-10;
// #define MAXN = 1000000.0
const double PI = acos(-1.0);
int dcmp(double x){if(fabs(x) < EPS) return 0; return x<0.0?-1:1;}
int dcmp(double x, double y){return dcmp(x-y);}
struct Point
{
  double x, y;
  Point(double x=0.0,double y=0.0):x(x),y(y){}
  double len(){return hypot(x, y);}//向量的模
  double len2(){return x*x+y*y;}//向量模的平方
  double distance(Point p){return hypot(x-p.x, y-p.y);}//两点之间的距离
  Point turnc(double r)//化为长度为r的向量,如果为0向量，返回本身
  {
    double l = len();
    if(!dcmp(l)) return *this;
    r /= l;
    return Point(x*r, y*r);
  }
  Point rotv(double rad) //逆时针旋转rad的角度
  {
    return Point(x*cos(rad)-y*sin(rad),x*sin(rad)+y*cos(rad));
  }
};
typedef Point Vec;
double isint(double x){return fabs(x - (int)(x+0.5))<EPS;}
Vec operator + (Vec a, Vec b){return Vec(a.x+b.x,a.y+b.y);}
Vec operator - (Vec a, Vec b){return Vec(a.x-b.x,a.y-b.y);}
double operator * (Vec a, Vec b){return a.x*b.y-a.y*b.x;}//向量叉乘
Vec operator * (Vec a, double b){return Vec(a.x*b,a.y*b);}
Vec operator / (Vec a, double b){return Vec(a.x/b,a.y/b);}
bool operator == (Vec a, Vec b){return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;}
double operator ^ (Vec a, Vec b){return a.x*b.x+a.y*b.y;}//向量点乘
bool operator < (Vec a, Vec b){ return dcmp(a.x, b.x)==0? dcmp(a.y,b.y)<0:a.x<b.x;}// 水平序
double operator % (Vec a, double b){return sqrt(a^a)/b;}
bool operator == (Vec a, double b){return dcmp((a%1.0), b)==0;}
double ang(Vec v){return atan2(v.y, v.x);}//angle between v and x+ range 0 ~ 2*PI
double ang(Vec a,Vec b){return acos((a^b)/(a%1.0)/(b%1.0));}
//Vec rotv(Vec A,double rad){return Vec(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));} //逆时针旋转rad的角度
Vec getvn(Vec A){double L = A%1.0;return Vec(-A.y/L,A.x/L);}//求 A 逆时针旋转90°的单位法向量
double area2(Point A,Point B,Point C){return (B-A)*(C-A);}//ABC的三角形有向面积的两倍
double area2(Vec A, Vec B){return A*B;}//AB为邻边的三角形有向面积的两倍
/*************************************
basic operations of Vectors and Points
*************************************/
struct Seg
{
  Point s, e;
  Seg(){}
  Seg(Point s, Point e):s(s),e(e){}
  bool operator == (Seg v)const{return (s==v.s)&&(e==v.e);}
  void adjust() //调整为起点在终点的左下方
  {
    if(e<s) swap(e, s);
  }
  bool pointonseg(Point p) //点在线段上的判定
  {
    //包含在端点上 <=
    //不包含在端点上 <
    return dcmp((p-s)*(e-s))==0 && dcmp((p-s)^(p-e)) <= 0;
  }
  //两线段相交判断
  //2 规范相交
  //1 非规范相交
  //0 不相交
  int segcrossseg(Seg v)
  {
    int d1=dcmp((e-s)*(v.s-s));
    int d2=dcmp((e-s)*(v.e-s));
    int d3=dcmp((v.e-v.s)*(s-v.s));
    int d4=dcmp((v.e-v.s)*(e-v.s));
    if((d1^d2)==-2 && (d3^d4)==-2) return 2;
    return (d1==0 && dcmp((v.s-s)^(v.s-e))<=0) ||
      (d2==0 && dcmp((v.e-s)^(v.e-e))<=0) ||
      (d3==0 && dcmp((s-v.s)^(s-v.e))<=0) ||
      (d4==0 && dcmp((e-v.s)^(e-v.e))<=0);
  }
};


struct Line
{
  Point p;Vec v;double ang;
  Line(){}
  Line(Point p,Vec v):p(p),v(v){/*if(dcmp(ang, 0.0)<0||dcmp(ang, PI)>=0) ang=atan2(-v.y,-v.x);*/}
  Line(Point p, double angle)//根据一个点和倾斜角 angle 确定直线， 0 <= angle < pi;
  {
    (*this).p = p;
    if(dcmp(angle, PI/2) == 0)
    {
      v = Point(0,1);
    }else{
      v = Point(1,tan(angle));
    }
  }
  Line(double a, double b, double c)//根据ax+by+c=0
  {
    if(dcmp(a)==0)
    {
      p=Point(0,-c/b);
      v=Point(1,-c/b);
    }
    else if(dcmp(b)==0)
    {
      p=Point(-c/a,0);
      v=Point(-c/a,1);
    }
    else
    {
      p=Point(0,-c/b);
      v=Point(1,(-c-a)/b);
    }
    v = v - p;
  }
  bool parallel(Line l)//直线平行或重合
  {
    return dcmp(v*l.v)==0;
  }
  //点和直线关系
  //1 在左侧
  //2 在右侧
  //3 在直线上
  int relation(Point x)
  {
    int c = dcmp((x-p)*v);
    if(c<0) return 1;
    else if(c>0) return 2;
    else return 3;
  }
  //直线和线段相交判断
  //*this line
  //v seg
  //2 规范相交
  //1 非规范相交
  //0 不相交
  int linecrossseg(Seg sg)
  {
    int d1 = dcmp(v*(sg.s-p));
    int d2 = dcmp(v*(sg.e-p));
    if((d1^d2)==-2) return 2;
    return (d1==0||d2==0);
  }
  //两直线平行
  //0 平行
  //1 重合
  //2 相交
  int linecrossline(Line l)
  {
    if((*this).parallel(l)) return l.relation(p)==3;
    return 2;
  }
  void calang(){ang=atan2(v.y,v.x);};
  bool operator < (const Line& L) const {return ang < L.ang;}
  Point point(double t){return p+v*t;}//根据参数t求得直线上一点,t由求交点的函数计算得出
  Point intersection_point(Line b)//P+tv和Q+tw两条直线的交点,确保有唯一交点
  {
    Point q=b.p;Vec w=b.v,u=p-q;
    double t=(w*u)/(v*w);
    return point(t);
  }
  //返回点 p 在直线上的投影
  //点在直线上的投影
  Point lineprog(Point P)
  {
    return p + v*((v^(P-p))/(v^v));
  }
  //返回点 p 关于直线的对称点
  Point symmetrypoint(Point p)
  {
    Point q = lineprog(p);
    return Point(2*q.x-p.x,2*q.y-p.y);
  }
};

Point intersection_point(Line a,Line b)
//P+tv和Q+tw两条直线的交点,确保有唯一交点
{
  Point p=a.p,q=b.p;Vec v=a.v,w=b.v,u=p-q;
  double t=(w*u)/(v*w);
  return a.point(t);
}
double distance_p_l(Point P,Line a)
{
  Vec v1 = a.v,v2 = P-a.p;
  return fabs((v1*v2)/(v1%1.0));//不取绝对值那么得到的是有向距离
}

double distace_p_seg(Point P,Point A,Point B)
//点到线段的距离
//需要考虑点和线段的位置关系
{
  if(A == B) return (P-A)%1.0;
  Vec v1=B-A,v2=P-A,v3=P-B;
  if(dcmp(v1^v2)<0) return v2%1.0;
  else if(dcmp(v1^v3)>0) return v3%1.0;
  else return fabs(v1*v2)/(v1%1.0);
}
//返回线段到线段的距离
//前提是两线段不相交， 相交距离为0
double dissegtoseg(Seg v, Seg u)
{
  return min(min(distace_p_seg(v.s,u.s,u.e), distace_p_seg(v.e,u.s,u.e)),min(distace_p_seg(u.s,v.s,v.e),distace_p_seg(u.e,v.s,v.e)));
}
//点在直线上的投影
Point projection_p_l(Point P,Line a){return a.p + a.v*((a.v^(P-a.p))/(a.v^a.v));}
//判断两条线段是否相交 此处必须为规范相交
bool intersection_seg_seg(Point a1,Point a2,Point b1,Point b2){
  double c1 = (a2-a1)*(b1-a1),c2 = (a2-a1)*(b2-a1);
  double c3 = (b2-b1)*(a1-b1),c4 = (b2-b1)*(a2-b1);
  return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
//如果允许端点相交，则用以下代码，判断一个点是否在一条线段上s
bool onsegment_p(Point p,Point s,Point e){return dcmp((s-p)*(e-p)) == 0 && dcmp((s-p)^(e-p))<0;}


/*********************************
多边形有关的计算
**********************************/

typedef vector<Point> Polygon;

int inpolygon_p(Point p, const Polygon& poly)
//判断点和多边形位置关系
// -1 表示在边界上
//  1 表示在多边形内部
//  0 表示在多边形外部
{
  int w = 0;
  for(int i=0,n=poly.size();i<n;i++){
    if(onsegment_p(p,poly[i],poly[(i+1)%n]))return -1;
    int k = dcmp((poly[(i+1)%n]-poly[i])*(p-poly[i]));
    int d1 = dcmp(poly[i].y - p.y);
    int d2 = dcmp(poly[(i+1)%n].y - p.y);
    if(k > 0 && d1 <= 0 && d2 > 0)w++;
    if(k < 0 && d2 <= 0 && d1 > 0)w--;
  }
  if(w != 0)return 1;
  return 0;
}
double cals_polygon(const Polygon p)
//多边形有向面积,点需要极角排序
//返回多边形的有向面积
{
  double area = 0;
  for(int i=1,n=p.size();i<n-1;i++)
    area+=(p[i]-p[0])*(p[i+1]-p[0]);
  return area/2.0;
}

double calc_polygon(const Polygon p)
//多边形周长,点需要极角排序
{
  double ans = 0;
  for(int i=0,n = p.size();i<n-1;i++)
    ans+= (p[i+1]-p[i])%1.0;
  ans+=(p[0]-p[p.size()-1])%1.0;
  return ans;
}
//如果线上的点不算就改成>
bool onleft(Line L,Point P){return (L.v)*(P - L.p)>=0;}

Polygon halfplane_intersection(vector<Line> L)
//半平面交所需函数及主过程
{
  int first,last,n=L.size();Polygon Poly;Point *p = new Point[n];Line *q = new Line[n];
  sort(L.begin(), L.end());
  q[first = last = 0] = L[0];
  for(int i=1;i<n;i++){
    while(first<last && !onleft(L[i],p[last-1]))last--;
    while(first<last && !onleft(L[i],p[first]))first++;
    q[++last] = L[i];
    if(fabs((q[last].v)*(q[last-1].v))<EPS){
      last--;
      if(onleft(q[last],L[i].p))q[last] = L[i];
    }
    if(first<last) p[last-1] = intersection_point(q[last-1],q[last]);
  }
  while(first<last && !onleft(q[first],p[last-1]))last--;
  if(last-first<=1) return Poly;
  p[last] = intersection_point(q[last],q[first]);
  for(int i=first;i<=last;i++)Poly.push_back(p[i]);
  return Poly;
}

Polygon ConvexHull(Polygon p)
{
  sort(p.begin(),p.end());
  //删除重复点
  p.erase(unique(p.begin(),p.end()),p.end());
  int n = p.size();
  Polygon ch(n+1);
  int m = 0;
  for(int i=0;i<n;i++){
    while(m>1 && dcmp((ch[m-1]-ch[m-2])*(p[i]-ch[m-2])) <= 0) m--;//若需要把边线上的点也算上，把等号去掉
    ch[m++] = p[i];
  }
  int k = m;
  for(int i = n-2;i>=0;i--){
    while(m > k && dcmp((ch[m-1] - ch[m-2])*(p[i]-ch[m-2] )) <= 0)m--;
    ch[m++] = p[i];
  }
  if(n > 1)m--;
  ch.resize(m);
  return ch;
}
double RotatingCalipers(const Polygon& p)
{
  int n = p.size(), cur=1;double ans = 0;Point v;
  for(int i=0;i<n;i++)
  {
    v = p[i]-p[(i+1)%n];
    while(dcmp((v)*(p[(cur+1)%n]-p[cur]))<0)
      cur = (cur+1)%n;
    ans = max(ans,max((p[i]-p[cur])%1.0,(p[(i+1)%n]-p[(cur+1)%n])%1.0));
  }
  return ans;
}//求凸包上两点间最远距离
//得到多边形的重心
Point getbarycenter(const Polygon p)
{
  int n = p.size();
  Point ret (0,0);
  double area = 0;
  for(int i = 1; i < n-1;i++)
  {
    double tmp = (p[i]-p[0])*(p[i+1]-p[0]);
    if(dcmp(tmp) == 0) continue;
    area += tmp;
    ret.x += (p[0].x + p[i].x+p[i+1].x)/3*tmp;
    ret.y += (p[0].x + p[i].y+p[i+1].y)/3*tmp;
  }
  if(dcmp(area)) ret = ret/area;
  return ret;
}


/*=============以上为凸包==========*/



double earthdis(Point a,Point b)
//给出经纬度，算出球体上两点之间的角度
//纬度作为纵坐标，经度作为横坐标
//以度为单位，返回弧度值
{
  double x1=PI*a.x/180.0;
  double y1=PI*a.y/180.0;
  double x2=PI*b.x/180.0;
  double y2=PI*b.y/180.0;
  return acos(cos(x1-x2)*cos(y1)*cos(y2)+sin(y1)*sin(y2));
}

struct Circle
{
  Point c;
  double r;
  Circle(Point c,double r):c(c),r(r){}
  Point point(double a)//通过角度求圆上一点
  {
    return Point(c.x+cos(a)*r,c.y + sin(a)*r);
  }
  //三角形的外接圆
  //需要Point 的 + / rotate() 以及 Line 的 crosspoint()
  //利用两条边的中垂线得到圆心
  //测试：UVA12304
  Circle(Point a, Point b, Point c)
  {
    Line u = Line((a+b)/2,((b-a).rotv(PI/2)));
    Line v = Line((b+c)/2,((c-b).rotv(PI/2)));
    c = u.intersection_point(v);
    r = c.distance(a);
  }
  //三角形的内切圆
  //参数 bool t 无作用， 表示内切圆
  //测试：UVA12304
  Circle(Point a, Point b, Point c, bool t)
  {
    Line u, v;
    double m = atan2(b.y-a.y,b.x-a.x),n=atan2(c.y-a.y, c.x-a.x);
    u.p = a;
    u.v = Point(cos((n+m)/2), sin((n+m)/2));
    v.p = b;
    m = atan2(a.y-b.y, a.x - b.x), n = atan2(c.y-b.y,c.x-b.x);
    v.p = Point(cos((n+m)/2), sin((n+m)/2));
    c = u.intersection_point(v);
    r = distace_p_seg(c, a, b);
  }
  bool operator == (const Circle v)const
  {
    return (c==v.c) && dcmp(r, v.r)==0;
  }
  //越坐下 越小
  //半径越小 越小
  bool operator < (const Circle v)const
  {
    return ((c<v.c) || ((c==v.c)&&dcmp(r,v.r)<0));
  }
  double area()
  {
    return PI*r*r;
  }
  //周长
  double circumference()
  {
    return 2*PI*r;
  }
  //点和圆的关系
  //0 圆外
  //1 圆上
  //2 圆内
  int relation(Point b)
  {
    double dst = b.distance(c);
    if(dcmp(dst, r) < 0) return 2;
    else if(dcmp(dst, r) == 0) return 1;
    return 0;
  }
  //线段和圆的关系
  //比较的是圆心到线段的距离和半径的关系
  int relationseg(Seg v)
  {
    double dst = distace_p_seg(c, v.s, v.e);
    if(dcmp(dst, r)<0) return 2;
    else if(dcmp(dst, r) == 0) return 1;
    return 0;
  }
  //直线和圆的关系
  //比较的是圆心到直线的距离和半径的关系
  int relationline(Line v)
  {
    double dst = distance_p_l(c, v);
    if(dcmp(dst, r)<0) return 2;
    else if(dcmp(dst, r) == 0) return 1;
    return 0;
  }
  //两圆的关系
  //5 相离
  //4 外切
  //3 相交
  //2 内切
  //1 内含
  //需要Point的distance
  //测试：UVA12304
  int relationcircle(Circle v)
  {
    double d = c.distance(v.c);
    if(dcmp(d-r-v.r) > 0) return 5;
    if(dcmp(d-r-v.r) == 0) return 4;
    double l = fabs(r-v.r);
    if(dcmp(d-r-v.r)<0 && dcmp(d-l)>0) return 3;
    if(dcmp(d-l)==0) return 2;
    else return 1;
  }
  //求两个圆的交点 返回交点个数
  //需要 relationcircle()
  //测试：UVA12304
  int pointcrosscircle(Circle v, Point &p1, Point &p2)
  {
    int rel = relationcircle(v);
    if(rel == 1 || rel == 5) return 0;
    double d = c.distance(v.c);
    double l = (d*d+r*r-v.r*v.r)/(2*d);
    double h = sqrt(r*r-l*l);
    Point tmp = c+(v.c-c).turnc(l);
    p1 = tmp + ((v.c-c).rotv(PI/2).turnc(h));
    p2 = tmp + ((v.c-c).rotv(-PI/2).turnc(h));
    if(rel == 2 || rel == 4)
    {
      return 1;
    }
    else
    {
      return 2;
    }
  }
  //求直线和圆的交点
  int pointcrossline(Line v, Point &p1, Point &p2)
  {
    if(!(*this).relationline(v)) return 0;
    Point a = v.lineprog(c);
    double d = distance_p_l(c, v);
    d = sqrt(r*r-d*d);
    if(dcmp(d) == 0)
    {
      p1 = a;
      p2 = a;
      return 1;
    }
    p1 = a + (v.v).turnc(d);
    p2 = a - (v.v).turnc(d);
    return 2;
  }
  //得到过a, b 两点， 半径为r1 的两个圆
  int gercircle(Point a, Point b, double r1, Circle &c1, Circle &c2)
  {
    Circle x(a, r1), y(b,r1);
    int t = x.pointcrosscircle(y,c1.c,c2.c);
    if(!t) return 0;
    c1.r = c2.r = r;
    return t;
  }
  //得到与直线 u 相切， 过点 q， 半径为r1 的圆
  //测试 ： UVA12304
  int getcircle(Line u, Point q, double r1, Circle &c1, Circle &c2)
  {
    double dis = distance_p_l(q, u);
    if(dcmp(dis-r1*2)>0)return 0;
    if(dcmp(dis)==0)
    {
      c1.c = q + (u.v.rotv(PI/2).turnc(r1));
      c2.c = q + (u.v.rotv(-PI/2).turnc(r1));
      c1.r = c2.r = r1;
      return 2;
    }
    Line u1 = Line((u.p+u.v.rotv(PI/2).turnc(r1)),(u.p+u.v+u.v.rotv(PI/2).turnc(r1)));
    Line u2 = Line((u.p+u.v.rotv(-PI/2).turnc(r1)),(u.p+u.v+u.v.rotv(-PI/2).turnc(r1)));
    Circle cc = Circle(q, r1);
    Point p1, p2;
    if(!cc.pointcrossline(u1, p1, p2))
      cc.pointcrossline(u2, p1, p2);
    c1 = Circle(p1, r1);
    if(p1 == p2)
    {
      c2 = c1;
      return 1;
    }
    c2 = Circle(p2,r1);
    return 2;
  }
  //同时与直线 u,v 相切， 半径为 r 的元
  //测试: UVA12304
  int getcircle(Line u, Line v, double r1, Circle &c1, Circle &c2, Circle &c3, Circle &c4)
  {
    if(u.parallel(v))return 0;//两直线平行
    Line u1 = Line(u.p+u.v.rotv(PI/2).turnc(r1),u.p+u.v+u.v.rotv(PI/2).turnc(r1));
    Line u2 = Line(u.p+u.v.rotv(-PI/2).turnc(r1),u.p+u.v+u.v.rotv(-PI/2).turnc(r1));
    Line v1 = Line(v.p+v.v.rotv(PI/2).turnc(r1),v.p+v.v+v.v.rotv(PI/2).turnc(r1));
    Line v2 = Line(v.p+v.v.rotv(-PI/2).turnc(r1),v.p+v.v+v.v.rotv(-PI/2).turnc(r1));
    c1.r = c2.r = c3.r = c4.r = r1;
    c1.c = u1.intersection_point(v1);
    c2.c = u1.intersection_point(v2);
    c3.c = u2.intersection_point(v1);
    c4.c = u2.intersection_point(v2);
    return 4;
  }
  //同时与不相交圆 cx, cy 相切， 半径为 r1 的圆
  //测试:UVA 12304
  int getcircle(Circle cx, Circle cy, double r1, Circle &c1, Circle &c2)
  {
    Circle x(cx.c,r1+cx.r),y(cy.c,r1+cy.r);
    int t = x.pointcrosscircle(y, c1.c, c2.c);
    if(!t) return 0;
    c1.r = c2.r = r1;
    return t;
  }
  //过一点作圆的切线
  //测试 : UVA12304
  int tangentline(Point q, Line &u, Line &v)
  {
    int x = relation(q);
    if(x == 2) return 0;
    if(x == 1)
    {
      u = Line(q, (q-c).rotv(PI/2));
      v = u;
      return 1;
    }
    double d = c.distance(q);
    double l = r*r/d;
    double h = sqrt(r*r-l*l);
    u = Line(q, c+(q-c).turnc(l)+(q-c).rotv(PI/2).turnc(h)-q);
    v = Line(q, c+(q-c).turnc(l)+(q-c).rotv(-PI/2).turnc(h)-q);
    return 2;
  }
  //求两圆相交的面积
  double areacircle(Circle v)
  {
    int rel = relationcircle(v);
    if(rel >= 4) return 0.0;
    if(rel <= 2) return min(area(), v.area());
    double d = c.distance(v.c);
    double hf = (r+v.r+d)/2.0;
    double ss = 2*sqrt(hf*(hf-r)*(hf-v.r)*(hf-d));
    double a1 = acos((r*r+d*d-v.r*v.r)/(2.0*r*d));
    a1 = a1*r*r;
    double a2 = acos((v.r*v.r+d*d-r*r)/(2.0*v.r*d));
    a2 = a2*v.r*v.r;
    return a1+a2-ss;
  }
  //求圆和三角形pab的相交面积
  //测试 ： POJ3675 HDU3982 HDU2892
  double areatriangle(Point a, Point b)
  {
    if(dcmp((c-a)*(c-b)) == 0) return 0.0;
    Point q[5];
    int len = 0;
    q[len++] = a;
    Line l(a, b-a);
    Point p1, p2;
    if(pointcrossline(l, q[1], q[2])==2)
    {
      if(dcmp((a-q[1])^(b-q[1]))<0) q[len++] = q[1];
      if(dcmp((a-q[2])^(b-q[2]))<0) q[len++] = q[2];
    }
    q[len++] = b;
    if(len == 4 && dcmp((q[0]-q[1])^(q[2]-q[1])) > 0) swap(q[1],q[2]);
    double res = 0;
    for(int i = 0; i < len-1;i++)
    {
      if(relation(q[i])==0 || relation(q[i+1])==0)
      {
        double arg = ang(q[i]-c, q[i+1]-c);
        res += r*r*arg/2.0;
      }
      else
        res += fabs((q[i]-c)*(q[i+1]-c))/2.0;
    }
    return res;
  }
};

int getLineCircleIntersection(Line L, Circle C, double& t1,double& t2,vector<Point>& sol)
//圆和直线交点方程法
//返回交点个数
//sol 为交点的数组
{
  double a=L.v.x,b=L.p.x-C.c.x,c=L.v.y,d=L.p.y-C.c.y,e=a*a+c*c,f=2*(a*b+c*d),g=b*b-C.r*C.r,delta=f*f-4*e*g;
  //相离
  if(dcmp(delta)<0)return 0;              
  //相切
  if(dcmp(delta)==0){t1 = t2 = -f/(2*e);sol.push_back(L.point(t1));return 1;}
  //相交
  t1 = (-f - sqrt(delta)) / (2*e); sol.push_back(L.point(t1));
  t2 = (-f + sqrt(delta)) / (2*e); sol.push_back(L.point(t2));
  return 2;
}
int getLineCircleIntersection(Line L, Circle C,vector<Point>& sol)
//圆和直线交点几何法
//返回交点个数
{
  double d = distance_p_l(C.c, L);
  //相离
  if(dcmp(d - C.r)>0)return 0;
  Point ans = intersection_point(L, Line(C.c,getvn(L.v)));
  //相切
  if(dcmp(d - C.r) == 0){sol.push_back(ans);return 1;}
  //相交
  double len = sqrt(C.r*C.r-d*d);
  Vec v = L.v / (L.v%1.0);
  sol.push_back(ans + v * len),sol.push_back(ans - v * len);
  return 2;
}
//判断两圆相交
int getCircleCircleIntersection(Circle C1, Circle C2, vector<Point>& sol){
  double d = (C1.c-C2.c)%1.0;
  if( dcmp(C1.r - C2.r)>0)
    swap(C1,C2);
  if(dcmp(d)==0){
    if(dcmp(C1.r-C2.r)==0)return -1;//重合
    return 0;
  }
  if(dcmp(C1.r + C2.r -d) < 0) return 0;//外离
  if(dcmp(fabs(C1.r-C2.r)-d)>0)return 0;//内含
  if(dcmp(C1.r + C2.r - d) == 0 || dcmp(fabs(C1.r - C2.r)-d) == 0){
    Vec p = C1.c-C2.c;
    sol.push_back(C2.c + p / (p%1.0) * C2.r);
    return 1;
  }//外切或内切
  double a = ang(C2.c - C1.c);
  double da = acos((C1.r * C1.r+d*d-C2.r*C2.r)/(2*C1.r*d));
  Point p1 = C1.point(a-da),p2 = C1.point(a+da);
  sol.push_back(p1);
  sol.push_back(p2);
  return 2;//相交
}
//过点p到圆C的切线
int getTangents(Point p,Circle C,vector<Line>& L){
  Vec u = C.c - p , temp;
  double dist = (u%1.0);
  if(dist < C.r) return 0;
  else if(dcmp(dist - C.r) == 0){
    temp = getvn(u);
    L.push_back(Line(p,temp));
    return 1;
  }else{
    double ang = asin(C.r/dist);
    temp = u.rotv(-ang),L.push_back(Line(p,temp));
    temp = u.rotv(+ang),L.push_back(Line(p,temp));
    return 2;
  }
}
//两圆公切线,返回切线条数，-1表示无穷多条
//注意,当两圆内切或者外切的时候,切点相同,均为p.
//sol里存的是切线，p为a上切点,p+v为b上切点
int getTangents(Circle A,Circle B,vector<Line>& sol)
{
  int cnt = 0;
  Point a,b;
  if(dcmp(A.r - B.r) < 0)swap(A,B);
  double d2 = (A.c.x - B.c.x) * (A.c.x - B.c.x) + (A.c.y - B.c.y) * (A.c.y -B.c.y);
  double rdiff = A.r - B.r;
  double rsum = A.r + B.r;
  if(dcmp(d2 - rdiff * rdiff) < 0) return 0;//内含

  double base = atan2(B.c.y - A.c.y, B.c.x - A.c.x);
  if(dcmp(d2)==0 && A.r == B.r)return -1;//重合,切线无限多
  if(dcmp(d2-rdiff * rdiff)==0){//内切，一条切线
    a = A.point(base),b = B.point(base);
    sol.push_back(Line(a,getvn(A.c-B.c)));
    return 1;
  }
  //有外切线
  double ang = acos((A.r-B.r) / sqrt(d2));
  a = A.point(base+ang),b = B.point(base+ang),sol.push_back(Line(a,b-a)),cnt++;
  a = A.point(base-ang),b = B.point(base-ang),sol.push_back(Line(a,b-a)),cnt++;
  if(dcmp(d2 - rsum * rsum)==0){
    a = A.point(base),b = B.point(PI + base),sol.push_back(Line(a,getvn(A.r-B.r))),cnt++;
  }else if(dcmp(d2 - rsum * rsum)>0){
    double ang2 = acos((A.r + B.r) / sqrt(d2));
    a = A.point(base+ang),b = B.point(PI+base+ang2),sol.push_back(Line(a,b-a)),cnt++;
    a = A.point(base-ang),b = B.point(PI+base-ang2),sol.push_back(Line(a,b-a)),cnt++;
  }
  return cnt;
}
/*==========以上为圆的常用函数及计算==========*/
//多边形和圆交的面积
//测试 : POJ3675 HDU3982 HDU2892
double areacircle(Circle c,Polygon p)
{
  int n = p.size();
  double ans = 0;
  for(int i = 0; i < n; i++)
  {
    int j = (i+1)%n;
    if(dcmp((p[j]-c.c)*(p[i]-c.c))>=0)
      ans += c.areatriangle(p[i],p[j]);
    else
      ans -= c.areatriangle(p[i], p[j]);
  }
  return fabs(ans);
}
//判断点和任意多边形的关系
//3 点上
//2 边上
//1 内部
//0 外部
int relationpoint(Point q, Polygon p)
{
  int n = p.size();
  for(int i = 0; i < n;i++)
    if(p[i]==q)return 3;
  vector<Seg> l;
  for(int i = 0; i < n; i++)
    l.push_back(Seg(p[i],p[(i+1)%n]));
  for(int i =0; i < n;i++)
    if(l[i].pointonseg(q)) return 2;
  int cnt = 0;
  for(int i = 0; i < n; i++)
  {
    int j = (i+1)%n;
    int k = dcmp((q-p[j])*(p[i]-p[j]));
    int u = dcmp(p[i].y-q.y);
    int v = dcmp(p[j].y-q.y);
    if(k > 0 && u < 0 && v >= 0) cnt++;
    if(k < 0 && v < 0 && u >= 0) cnt--;
  }
  return cnt != 0;
}
//多边形和圆的关系
//2 圆完全在多边形内
//1 圆在多边形里面，碰到了多边形边界
//0 其他

int relationcircle(Circle c, Polygon p)
{
  int n = sizeof(p);
  vector<Seg> l;
  for(int i = 0; i < n; i++)
    l.push_back(Seg(p[i],p[(i+1)%n]));
  int x = 2;
  if(relationpoint(c.c, p) != 1) return 0;
  for(int i = 0; i < n; i++)
  {
    if(c.relationseg(l[i])==2) return 0;
    if(c.relationseg(l[i])==1) return 1;
  }
  return x;
}




int main(int argc, char const *argv[])
{
  // Point p = Point(0,0), p1 = Point(2,0);
  // Line l = Line(p, Vec(1,1));
  // p = GetLineProjection(p1, l);
  // cout << p.x << "    " << p.y << endl;
  // system("pause");
  return 0;
}
