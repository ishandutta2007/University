#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#define inf 999999999
using namespace std;
char c;
int t,len,po,n,in,ca,cb,co,cc,l,num;
char si[15000];
vector <char> s;
vector <char> sc;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		scanf("%s",si);

		s.clear();
		len=0;po=0;in=0;
		ca=0;cb=0;co=0;
		num=0;
		l=strlen(si);
		for (int i=0;i<l;i++)
		{
			c=si[i];
			if (c=='S') {in^=1;continue;}

			if (c=='C' && !co) {ca=po;cb=po;co=1;sc.clear();continue;}
			if (c=='C' && co)
			{
				cb=max(po-1,0);
				for (int j=min(ca,cb);j<=max(ca,cb);j++)
				{
					sc.push_back(s[j]);
				}
				continue;

			}


			if (c=='V' && sc.size()!=0 && !in)
			{
				for (int j=0;j<sc.size();j++)
				{
					c=sc[j];
					if (!in || po==len)
					{
						s.insert(s.begin()+po,c);
						po++;
						len++;
					}
					else
					{

						s[po]=c;
						po++;
					}
				}
				co=0;
				sc.clear();
				continue;
			}

			if (c=='V' && sc.size()!=0 && !in)
			{
				for (int j=0;j<sc.size();j++)
				{
					c=sc[j];
					s[po]=c;
					po++;
				}
				co=0;
				sc.clear();
				continue;
			}

			if ('a'<=c && c<='z')
			{
				if (num==n) continue;
				num++;
				//cout<<num<<' '<<c<<endl;
				if (co) co=0;
				if (!in || po==len)
				{
					s.insert(s.begin()+po,c);
					po++;
					len++;
				}
				else
				{

					s[po]=c;
					po++;
				}
				continue;
			}

			if (c=='L' && po>0 ) 
			{
				po--;
				if (co) cb--;
				continue;
			}

			if (c=='R' && (s[po]>='a' && s[po]<='z')) 
			{
				po++;
				if (co) cb++;
				continue;
			}

			if (c=='D' && !co)
			{

				if (po==len) continue; 
				s.erase(s.begin()+po);
				len--;
				continue;
			}

			if (c=='D' && co)
			{
				co=0;
				if (cb<ca) {cc=cb;cb=ca;ca=cc;}
				cout<<ca<<' '<<cb<<endl;
				s.erase(s.begin()+ca,s.begin()+cb);
				len-=(cb-ca);
			}

			if (c=='B')
			{
				if (po==0) continue;
				s.erase(s.begin()+po-1);
				po--;
				len--;
				continue;
			}
		}
		if (len==0) cout<<"NOTHING"<<endl;
		else 
		{
			for (int i=0;i<len;i++)
		{
			printf("%c",s[i]);
		}
		}
		
		printf("\n");
	}
}