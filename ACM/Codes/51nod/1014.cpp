#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll a, p;
vector<ll> ans;

int main()
{
    cin >> p >> a;
    for (int i = 0; i <= p; i++)
    {
//        cout << i << endl;
        ll tmp = a + p*i;
        ll tmp1 = sqrt(tmp);
        if (tmp <= p*p && tmp1*tmp1 == tmp)
            ans.push_back(tmp1);
    }

//    cout << "!!!" << endl;

    if (ans.size() == 0)
    {
        printf("No Solution\n");
    }
    else
    {
      for (int i = 0, len = ans.size(); i < len; i++)
        printf("%I64d%c", ans[i], i == len-1? '\n' : ' ');
    }
    return 0;
}
