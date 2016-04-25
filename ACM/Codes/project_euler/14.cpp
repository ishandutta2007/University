#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstdlib>

using namespace std;

// int dist[100000200];
// deque<int> que;

// int main()
// {
//     que.push_back(1);
//     dist[1] = 1;
//     int now, to;
//     while(!que.empty())
//     {
//       now = que.front();
//       que.pop_front();

//       // cout << now << endl;
//       // system("pause");


//       to = now * 2;
//       if (to < 100000000 && dist[to] <= dist[now])
//       {
//         que.push_back(to);
//         dist[to] = dist[now] + 1; 
//       }
//       if ((now-1) % 3 == 0)
//       {
//         to = (now-1)/3;
//         if(to > 0 && to < 100000000 && dist[to] <= dist[now] && to % 2 == 1 && to != 1)
//         {
//           que.push_back(to);
//           dist[to] = dist[now] + 1;
//         }
//       }

//     }

//     int ans = 1;
//     int m = dist[1];
//     for (int i = 1; i <= 1000000; i++)
//       if(dist[i] > m)
//       {
//         m = dist[i];
//         ans = i;
//       }
//     cout << ans << endl;
//     return 0;
// }


int main()
{
    long long cnt = 0;
    long long now = 837799;
    while(true)
    {
      // cout << now << endl;

      // if(now > 100000000)
      //   system("pause");
      cnt ++;
      if(now == 1) break;

      if(now % 2 == 0) now /= 2;
      else now = now*3 + 1;
    }
    cout << cnt << endl;
}
