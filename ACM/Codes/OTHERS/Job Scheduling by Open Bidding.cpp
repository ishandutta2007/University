/*This Code is Submitted by py for Problem 2196 at 2015-01-18 15:44:47*/
#include"cstdio"
#include"iostream"
#include"cstring"


using namespace std;

int c[520];
double v[520];
int _time;
double dp[2020];



int main(){
        int T,n;
        int tt;
        scanf("%d",&T);
        tt = T;
        while(T--){
                scanf("%d",&n);
//            printf("n = %d\n",n);
                for(int i = 1; i <= n; i++)
                        scanf("%d%lf",&c[i],&v[i]);
                
                scanf("%d",&_time);
                memset(dp, 0, sizeof(dp));
                
                for(int i = 1; i <= n; i++)
                        for(int j = _time; j >= c[i]; j--)
                        dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
//                            if(dp[j]<dp[j-c[i]] + v[i])   
//			                {  
//			                    dp[j] = dp[j-c[i]] + v[i];  
//			                }  
                
            while(dp[_time] == dp[_time-1]) _time--;
            
            printf("Problem %d: %d seconds scheduled for $%.2f\n",tt- T,_time,dp[_time]);     
        }
        
        
        
        
        return 0;
}
