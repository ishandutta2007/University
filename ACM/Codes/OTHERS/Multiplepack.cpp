#include"cstdio"
#include"iostream"

int main(){
	
	for(i=1;i<=n;i++){
		if(num[i]*w[i]>=m)
			for(j=w[i],j<=m;j++)
				ans[j]=max(ans[j],ans[j-w[i]]+v[i]);
		
		else{
			int k=1;
			while(k<num[i]){
				for(j=m;j>=k*w[i];j--)
					ans[j]=max(ans[j],ans[j-k*w[i]]+k*v[i]);
				num-=k;
				k*=2;
			}
			for(j=m;j>=num[i]*w[i];j--)
				ans[j]=max(ans[j],ans[j-num[i]*w[i]]+num[i]*v[i]);
		}
	}
	
}
