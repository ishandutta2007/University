#include <iostream>
using namespace std;
//編號從0開始，也就是說如果編號從1開始結果要加1
int josephus(int n, int k) { //非遞回版本
  int s = 0;
  for (int i = 2; i <= n; i++)
    s = (s + k) % i;
  return s;
}
int josephus_recursion(int n, int k) { //遞回版本
  return n > 1 ? (josephus_recursion(n - 1, k) + k) % n : 0;
}
int main() {
  for (int i = 1; i <= 100; i++)
    cout << i << ' ' << josephus(i, 5) << endl;
  return 0;
}
