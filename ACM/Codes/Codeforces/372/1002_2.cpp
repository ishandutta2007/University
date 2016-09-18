/*
 *******************************
 * author :   poore            *
 * mail   :   py100c@gmail.com *
 * from   :   Chongqing, China *
 *******************************
 */

#include <bits/stdc++.h>

#define inf 999999999
#define mo 1000000007
#define LL long long 
using namespace std;
const int maxn=100000;
char s[maxn];
int sum[maxn];
bool check()
{
	int tmp=0;
	for (int i=1;i<=26;i++) {
		if (sum[i]==0) tmp++;
	}
	if (tmp==sum[0]) return 1;
	else return 0;
}
int main() {
	int l,x,flag;
	scanf("%s",s);
	l=strlen(s);
	if (l<26) {
		cout<<"-1"<<endl;
		return 0;
	}

	for (int i=0;i<25;i++) {
		if (s[i]=='?') x=0;
		else x=s[i]-'A'+1;
		sum[x]++;
	}
	flag=0;
	for (int i=25;i<l;i++)
	{
		if (s[i]=='?') x=0;
		else x=s[i]-'A'+1;
		sum[x]++;

		if (check()) {
			for (int j=i-25;j<=i;j++) {
				if (s[j]=='?') {
					for (int k=1;k<=26;k++) {
						if (sum[k]==0) {s[j]='A'+k-1;sum[k]++;break;}
					}
				}
			}
			flag=1;
			break;
		}
		if (s[i-25]=='?') x=0;
		else x=s[i-25]-'A'+1;
		sum[x]--;
	}
	if (flag) {
		for (int i=0;i<l;i++) {
			if (s[i]=='?') printf("A");
			else printf("%c",s[i]);
		}
	}
	else
		cout<<"-1"<<endl;
  return 0;
}

