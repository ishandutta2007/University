#include <bits/stdc++.h>

using namespace std;

int main()
{
  int h1, m1, s1, h2, m2, s2;
  int T;
  cin >> T;
  while(T--)
  {
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    if (h1 > h2) {cout << "Player2" << endl;continue;}
    if (h1 < h2) {cout << "Player1" << endl;continue;}
    if (m1 > m2) {cout << "Player2" << endl;continue;}
    if (m1 < m2) {cout << "Player1" << endl;continue;}
    if (s1 > s2) {cout << "Player2" << endl;continue;}
    if (s1 < s2) {cout << "Player1" << endl;continue;}
    cout << "Tie" <<endl;
  }



  return 0;
}
