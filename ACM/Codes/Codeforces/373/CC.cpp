#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
char s[N];

int main() {  
    int n,m;
    scanf("%d%d", &n, &m);
    scanf("%s",s);
    int l = 0;
    for(int i=0;s[i];i++) {
        if(s[i] == '.') {
            l = i+1;
            break;
        }
    }
    int r = strlen(s) - 1;
    if(l)
    for(int i=l;s[i];i++) {
        if(s[i] >= '5') {
            int tmp = i;
            while(s[tmp] >= '5' && m>0) {
                if(s[tmp-1] == '.') {
                    s[tmp-2]++;
                    tmp-=2;
                    break;
                }else {
                    s[tmp-1]++;
                    tmp--;
                    m--;
                }
            }
            r = tmp;
            break;
        } 
    }
    int t = r;
    while(s[t]>'9' && t>0) {
        s[t] = '0';
        t--;
        if(s[t] == '.') t--;
        s[t]++;
    }
    if(t==0 && s[0]>'9') s[0]='0',putchar('1');
    for(int i=0;i<=r;i++) putchar(s[i]);
        puts("");
    return 0;
}
