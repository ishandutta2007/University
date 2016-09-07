#include <bits/stdc++.h>

#define x1 x1z
#define y1 y1z

using namespace std;  
const double eps = 1e-10;  
const int maxn = 20;  
  
int tail, head, it;  
struct Point {  
    double x, y;  
    Point(double x, double y):x(x),y(y){}
    Point(){}
} P[maxn], tp[5];  
typedef Point point;

struct Line {  
    Point a, b;  
    double angle;  
    void getAngle() {angle = atan2(b.y-a.y, b.x-a.x);}  
} L[maxn], deq[maxn];  
  
int dcmp(double x) {  
    return x < -eps ? -1 : x > eps;  
}  
int operator * (point a, point b)
{
  return a.x*b.x + a.y*b.y;
}

int operator ^ (point a, point b)
{
  return a.x*b.y - a.y*b.x;
}

point operator + (point a, point b)
{
  return point (a.x+b.x, a.y+b.y);
}

point operator - (point a, point b)
{
  return point (a.x-b.x, a.y-b.y);
}
double xmult(Point a, Point b, Point c) {  
    return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);  
}  
bool cmp(Line u, Line v) {  
    int d = dcmp(u.angle-v.angle);  
    if(d) return d > 0;  
    return dcmp(xmult(u.a, v.a, v.b)) > 0;  
    ///Clockwise:大于0取向量左半部分为半平面，小于0，取右半部分  
}  
Point intersection(Line u, Line v)  
{  
    Point ret = u.a;  
    double t = ((u.a.x-v.a.x)*(v.a.y-v.b.y)  
               -(u.a.y-v.a.y)*(v.a.x-v.b.x))  
             / ((u.a.x-u.b.x)*(v.a.y-v.b.y)  
               -(u.a.y-u.b.y)*(v.a.x-v.b.x));  
    ret.x += (u.b.x-u.a.x)*t, ret.y += (u.b.y-u.a.y)*t;  
    return ret;  
}  
bool judge(Line l1, Line l2, Line l3) {  
    Point p = intersection(l2, l3);  
    return dcmp(xmult(p, l1.a, l1.b)) < 0;  
    ///Clockwise:大于小于符号与上面cmp（）中注释处相反  
}  
void HPI(Line L[], int n){  
    sort(L, L+n, cmp);  
    int tmp = 1;  
    for(int i = 1; i < n; ++i) {  
        if(dcmp(L[i].angle-L[tmp-1].angle) != 0) {  
            L[tmp++] = L[i];  
        }  
    }  
    n = tmp;  
    deq[0] = L[0], deq[1] = L[1];  
    head = 0, tail = 1;  
    for(int i = 2; i < n; ++i) {  
        while(head < tail && judge(L[i], deq[tail-1], deq[tail]))  
            tail--;  
        while(head < tail && judge(L[i], deq[head+1], deq[head]))  
            head++;  
        deq[++tail] = L[i];  
    }  
    while(head < tail && judge(deq[head], deq[tail-1], deq[tail]))  
        tail--;  
    while(head < tail && judge(deq[tail], deq[head+1], deq[head]))  
        head++;  
    if(head == tail) return ;  
    it = 0;  
    for(int i = head; i < tail; ++i) {  
        P[it++] = intersection(deq[i], deq[i+1]);  
    }  
    if(tail > head+1) {  
        P[it++] = intersection(deq[head], deq[tail]);  
    }  
}  

void show(Point x)
{
  printf("%.2f %.2f\n", x.x, x.y);
}

double getArea(Point p[], int n) {  
  /*
  printf("hull = %d\n", n);
  for (int i = 0; i < n; i++)
  {
    show(p[i]);
  }
  */
  double area = 0;  
  for(int i = 1; i < n-1; ++i) {  
    area += xmult(P[0], P[i], P[i+1]);  
  }  
  return fabs(area)/2.0;  
}  
bool cmpxy(point a, point b)
{
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}

int main()  
{  
  double x1, y1, x2, y2;
  double x3, y3, x4, y4; 
  point v1, v2, v3;
  while(scanf("%lf%lf%lf%lf", &x1,&y1,&x2,&y2) == 4)
  {
    scanf("%lf%lf%lf%lf", &x3,&y3,&x4,&y4);
    if ((x2 > x1 && y2 > y1) || (x2 < x1 && y2 < y1))
    {
      L[0] = (Line){(Point){x1, y2}, (Point){x1, y1}};
      L[1] = (Line){(Point){x2, y1}, (Point){x1, y2}};
      L[2] = (Line){(Point){x1, y1}, (Point){x2, y1}};
    }
    else
    {
      L[0] = (Line){(Point){x1, y1}, (Point){x1, y2}};
      L[1] = (Line){(Point){x1, y2}, (Point){x2, y1}};
      L[2] = (Line){(Point){x2, y1}, (Point){x1, y1}};
    }
    L[3] = (Line){(Point){x3, y3}, (Point){x4, y3}};
    L[4] = (Line){(Point){x4, y3}, (Point){x4, y4}};
    L[5] = (Line){(Point){x4, y4}, (Point){x3, y4}};
    L[6] = (Line){(Point){x3, y4}, (Point){x3, y3}};
    int n = 7;
    /*
    for (int i = 0; i < n; i++)
    {
      show(L[i].a);
      show(L[i].b);
    }
    */
    for (int i = 0; i < n; i++)
      L[i].getAngle();
    HPI(L, n);  
    printf("%.9f\n", getArea(P, it));  
  }  
  return 0;  
}

