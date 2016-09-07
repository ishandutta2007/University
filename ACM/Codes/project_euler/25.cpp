#include <bits/stdc++.h>

using namespace std;



double cal(double x)
{
  double g5 = sqrt(5);
  double tmp = (pow((1.0+g5)/2.0, x) - pow((1.0-g5)/2.0, x)) / g5;
  return log10(tmp);
}



int main()
{
  

  for (int i = 1;; i++)
  {
    if (cal((double)i) >= 1000.0)
    {
      cout << i << endl;
      return 0;
    }
  }



  return 0;
}
