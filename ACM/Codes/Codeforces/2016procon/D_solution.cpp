#include<bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define eps 1e-9

const int MOD = 1e9+7;

typedef long long ll;
typedef pair<int,int> pii;

ll POWER[65];
ll power(ll a, ll b) {ll ret=1;while(b) {if(b&1) ret*=a;a*=a;if(ret>=MOD) ret%=MOD;if(a>=MOD) a%=MOD;b>>=1;}return ret;}
ll inv(ll x) {return power(x,MOD-2);}

void precompute() {
	POWER[0]=1;
	for(int i=1;i<63;i++) POWER[i]=POWER[i-1]<<1LL;
}
#define int long long

const int MAXN = 1e5+5;
int A[MAXN],B[MAXN];
ll answer[MAXN];
int BIT[2][MAXN];
int fre[2][MAXN];
int BLOCK;
struct node {
	int idx,l,r,k;
	node(){}
	node(int a, int b, int c, int d) {
		idx=a;
		l=b;
		r=c;
		k=d;
	}
};
struct node Q[MAXN];

bool cmp(const struct node &A, const struct node &B) {
	int bl1=A.l/BLOCK;
	int bl2=B.l/BLOCK;
	if(bl1!=bl2) return bl1<bl2;
	return A.r<B.r;
}
const int MAXK = 1e5+1;
void update(int id, int idx, int v) {
	while(idx<MAXK) {
		BIT[id][idx]+=v;
		idx+=(idx&-idx);
	}
}
int query(int id, int idx) {
	int ret=0;
	while(idx) {
		ret+=BIT[id][idx];
		idx-=(idx&-idx);
	}
	return ret;
}
void add(int id) {
	int v = A[id];
	if(v<MAXK) {
		fre[0][v]++;
		update(0,v,1);
	}
	v = B[id];
	if(v<MAXK) {
		fre[1][v]++;
		update(1,v,1);
	}
}
void remove(int id) {
	int v = A[id];
	if(v<MAXK) {
		fre[0][v]--;
		update(0,v,-1);
	}
	v = B[id];
	if(v<MAXK) {
		fre[1][v]--;
		update(1,v,-1);
	}
}
ll f(int x) {
	ll lo=0,hi=x,ret=-1;
	while(lo<=hi) {
		ll mid=lo+(hi-lo+1)/2;
		if(mid*mid<=x) ret=mid,lo=mid+1;
		else hi=mid-1;
	}
	return ret;
}
ll go(int k) {
	int root = f(k);
	ll ans=0;
	int v;
	for(int i=1;i<=root;i++) {
		if(fre[0][i]) {
			v = k/i;
			ans+=1LL*fre[0][i]*1LL*query(1,v);
		}
		if(fre[1][i]) {
			v = k/i;
			ans+=1LL*fre[1][i]*1LL*query(0,v);
		}
	}
	ll temp = query(0,root);
	temp*=1LL*query(1,root);
	ans-=temp;
	return ans;
}
#undef int
int main() {
	// freopen("TASK.in","r",stdin);freopen("TASK.out","w",stdout);
	// precompute();
	#define int long long
	int n,q;
	cin>>n>>q;
	BLOCK = sqrt(n);
	for(int i=1;i<=n;i++) scanf("%lld",&A[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&B[i]);
	for(int i=0;i<q;i++) {
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		struct node P(i,x,y,z);
		Q[i]=P;
	}
	sort(Q,Q+q,cmp);
	int ML=1,MR=0;
	for(int i=0;i<q;i++) {
		int l=Q[i].l;
		int r=Q[i].r;
		int idx=Q[i].idx;
		int k=Q[i].k;
		while(MR<r) {
			++MR;
			add(MR);
		}
		while(MR>r) {
			remove(MR);
			--MR;
		}
		while(ML>l) {
			--ML;
			add(ML);
		}
		while(ML<l) {
			remove(ML);
			++ML;
		}
		answer[idx]=go(k);
	}
	for(int i=0;i<q;i++) printf("%lld\n",answer[i]);
	return 0;
}
