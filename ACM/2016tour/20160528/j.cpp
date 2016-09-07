#include <bits/stdc++.h>

using namespace std;

typedef vector<Point> Polygon;
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
