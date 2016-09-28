// s 为保存有序的凸包点的下标的栈
// 此处的凸包点为顺时针的顺序
int rotatingCaliper(Point *p, int top) {
  int q = 1;
  int ans = 0;
  s[top] = 0;
  for (int i = 0; i < top; i++) {
    while( ((p[s[i+1]]-p[s[i]])^(p[s[q+1]]-p[s[i]])) > 
           ((p[s[i+1]]-p[s[i]])^(p[s[q]]  -p[s[i]])) )
      q = (q+1)%top;
    ans = max(ans, (p[s[i]]-p[s[q]])*(p[s[i]]-p[s[q]]));
    // 处理两条边平行的情况
    ans = max(ans, (p[s[i+1]]-p[s[q+1]])*(p[s[i+1]]-p[s[q+1]]));
  }
  return ans;
}

