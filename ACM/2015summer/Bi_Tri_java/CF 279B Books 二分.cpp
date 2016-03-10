/*

题目：
    给出a1,a2,...,an，现在从中选出起始点i，从i开始能够往后连续选择多少
    个数，使得和值不操作t
分析：
    我们先求出前缀和，然后二分出能够到达的最后位置

*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define debug puts("here")
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define foreach(i,vec) for(unsigned i=0;i<vec.size();i++)
#define pb push_back
#define RD(n) scanf("%d",&n)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define RD3(x,y,z) scanf("%d%d%d",&x,&y,&z)

const int MAXN = 1e5+5;

int sum[MAXN],n,t;
int a[MAXN];

int bin(int x){
    int l = 0,r = n-1;
    int ans = 0;
    while(l<=r){
        int mid = (l+r)>>1;
        if(sum[mid]==x)
            return mid;
        else if(sum[mid]>x)
            r = mid-1;
        else{
            ans = mid;
            l = mid+1;
        }
    }
    return ans;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("sum.in","r",stdin);
	//freopen("sum.out","w",stdout);
#endif

    while(cin>>n>>t){

        rep(i,n){
            RD(a[i]);
            if(i)   sum[i] = sum[i-1]+a[i];
            else    sum[i] = a[0];
        }

        int ans = 0;
        for(int i=0;i<n;i++)
            if(a[i]<=t){
                int tmp = bin(sum[i]+t-a[i]);
                ans = max(tmp-i+1,ans);
            }
        cout<<ans<<endl;

    }

	return 0;
}
