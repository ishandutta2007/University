#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#define INF 0x7f7f7f7f

using namespace std;

// const int N = int(2e5) + 9;
// int pi[N];
 
// class Solution 
// {
// public:
//     string shortestPalindrome(string ss) 
//     {
//         string rr = ss; int nn = ss.size();
//         reverse(rr.begin(), rr.end());
//         string s = ss + '$' + rr;
//         int n = s.size();
//         for (int i = 1, j = pi[0] = -1; i < n; ++i)
//         {
//             while (j >= 0 && s[i] != s[j+1])
//             	j = pi[j];
//             if (s[i] == s[j+1]) ++j;
//             pi[i] = j;
//         }
//         return rr.substr(0, nn-1-pi[n-1]) + ss;
//     }
// };

#define maxn 200009

int next[maxn];

class Solution
{
public:
    string shortestPalindrome(string s)
    {
    	string r = s;
    	int n = s.size();
    	reverse(r.begin(), r.end());
    	string ss = s + '$' + r;
    	int nn = ss.size();
    	for(int i = 1,j = next[0] = -1; i < nn; i++)
    	{
    		while(j >= 0 && ss[i] != ss[j + 1])
    			j = next[j];

    		if(ss[i] == ss[j+1]) j++;
    		next[i] = j;
    	}
    	return r.substr(0, n - 1 - next[nn - 1]) + s;
    }
};


string s;
int main()
{


	Solution So;

	while(cin >> s)
	{
		cout << So.shortestPalindrome(s) << endl;
	}

	return 0;
}


