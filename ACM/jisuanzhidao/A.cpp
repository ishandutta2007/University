#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 100020;
const ll mod = 1e9 + 7;


double l1, l2, theta;
double pi = 3.141592653;


int main()
{
  
  cin >> l1 >> l2 >> theta;
  
  l1 /= 2;
  l2 /= 2;
  double r1 = l1, r2 = l2;
  theta = theta / 180 * pi;
  double l = sqrt(l1*l1+l2*l2 - 2*l1*l2*cos(theta));

  l = l/2.0 + max(r1, r2);


  
  printf("%.9f\n", 3.141592653 * l * l);

  return 0;
}
