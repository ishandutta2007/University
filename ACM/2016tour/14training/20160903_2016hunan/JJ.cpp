#include <bits/stdc++.h>

using namespace std;  
  
const double eps = 1e-8;  
int n, pn, dq[20005], top, bot;  
struct Point {  
    double x, y;  
} p[20005];  
  
struct Line {  
    Point a, b;  
    double angle;  
    Line& operator= (Line l) {  
       a.x = l.a.x; a.y = l.a.y;  
       b.x = l.b.x; b.y = l.b.y;  
       angle = l.angle;  
       return *this;  
    }  
} l[20005];  
  
int dblcmp(double k) {  
    if (fabs(k) < eps) return 0;  
    return k > 0 ? 1 : -1;  
}  
  
double multi(Point p0, Point p1, Point p2) {  
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);  
}  
  
bool cmp(const Line& l1, const Line& l2) {  
    int d = dblcmp(l1.angle-l2.angle);  
    if (!d) return dblcmp(multi(l1.a, l2.a, l2.b)) > 0; //极角相同时，将更靠半平面里面的放在前面  
    return d < 0;  
}  
  
void addLine(Line& l, double x1, double y1, double x2, double y2) {  
    l.a.x = x1; l.a.y = y1;  
    l.b.x = x2; l.b.y = y2;  
    /*atan2(y,x)返回值的取值范围为-PI到PI，实际上就是根据向量（x,y）确定极角， 
      若向量在1，2象限，则值大于0；3，4象限，则值小于0 
      所以atan2（1，1）与atan（-1，-1）值不同 
    */  
    l.angle = atan2(y2-y1, x2-x1);  
}  
  
//求交点，写得略复杂  
 void getIntersect(Line l1, Line l2, Point& p) {  
    double A1 = l1.b.y - l1.a.y;  
    double B1 = l1.a.x - l1.b.x;  
    double C1 = (l1.b.x - l1.a.x) * l1.a.y - (l1.b.y - l1.a.y) * l1.a.x;  
    double A2 = l2.b.y - l2.a.y;  
    double B2 = l2.a.x - l2.b.x;  
    double C2 = (l2.b.x - l2.a.x) * l2.a.y - (l2.b.y - l2.a.y) * l2.a.x;  
    p.x = (C2 * B1 - C1 * B2) / (A1 * B2 - A2 * B1);  
    p.y = (C1 * A2 - C2 * A1) / (A1 * B2 - A2 * B1);  
}  
  
bool judge(Line l0, Line l1, Line l2) {  
     Point p;  
     getIntersect(l1, l2, p);  
     return dblcmp(multi(p, l0.a, l0.b)) < 0;  
}  
  
void HalfPlaneIntersect( ){  
    int i, j;  
    /*排序是在满足所有半平面A*x+B*y+C>0或（<,<=,>=）, 
      也就是所有半平面的符号均相同的情况下对极角进行排序， 
      此题中题目对半平面的定义就等价于这个条件 
 */  
    sort(l, l+n, cmp);  
    for (i = 0, j = 0; i < n; i++)  
        if (dblcmp(l[i].angle-l[j].angle) > 0) //极角相同时，只保留最靠里面的那条  
            l[++j] = l[i];  
    n = j + 1;  
    dq[0] = 0; //双端队列  
    dq[1] = 1;  
    top = 1;   //顶部和底部  
    bot = 0;  
    for (i = 2; i < n; i++) {  
        //当栈顶的两条直线交点在当前半平面外部时，弹栈  
        while (top > bot && judge(l[i], l[dq[top]], l[dq[top-1]])) top--;  
        /*由于求的是一个凸多边形，所以当半平面转过接近一圈时，某个半平面满足上一个while的条件后， 
          它又会影响到底部的两条直线，当底部的两条直线的交点，在当前的半平面外部时，底部弹栈 
        */  
        while (top > bot && judge(l[i], l[dq[bot]], l[dq[bot+1]])) bot++;  
        dq[++top] = i; //当前半平面入栈  
    }  
    //当最顶部的两条直线的交点不在最底部的半平面内时，顶部的那个半平面是多余的，顶部弹栈  
    while (top > bot && judge(l[dq[bot]], l[dq[top]], l[dq[top-1]])) top--;  
    //当最底部的两条直线的交点不在最顶部的半平面内时，底部的那个半平面是多余的，底部弹栈  
    while (top > bot && judge(l[dq[top]], l[dq[bot]], l[dq[bot+1]])) bot++;  
    dq[++top] = dq[bot]; //将最底部的半平面放到最顶部来，方便下面求顶点  
    for (pn = 0, i = bot; i < top; i++, pn++)  
        getIntersect(l[dq[i+1]], l[dq[i]], p[pn]);  
}  
  
double getArea() { //叉积求面积  
    if (pn < 3) return 0;  
    double area = 0;  
    for (int i = 1; i < pn-1; i++)  
        area += multi(p[0], p[i], p[i+1]);  
    if (area < 0) area = -area;  
    return area/2;  
}  

int main()  
{  
  int i;  
  double x1, y1, x2, y2;
  double x3, y3, x4, y4; 

  while (scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2) != EOF)
  { 
    scanf("%lf%lf%lf%lf", &x3, &y3, &x4, &y4);
    n = 0;
    if ((x2 > x1 && y2 > y1) || (x2 < x1 && y2 < y1))
    {
      addLine(l[n++], x1, y2, x1, y1);  
      addLine(l[n++], x2, y1, x1, y2);  
      addLine(l[n++], x1, y1, x2, y1);  
    }
    else
    {
      addLine(l[n++], x1, y1, x1, y2);  
      addLine(l[n++], x1, y2, x2, y1);  
      addLine(l[n++], x2, y1, x1, y1);  
    }
    
    addLine(l[n++], x3, y3, x4, y3);  
    addLine(l[n++], x4, y3, x4, y4);  
    addLine(l[n++], x4, y4, x3, y4);  
    addLine(l[n++], x3, y4, x3, y3);  

    HalfPlaneIntersect();  
    printf ("%.9lf\n", getArea());  
  }  
  return 0;  
}  
