#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>


// using namespace std;

typedef long long LL;

int a[100020];
int left[100020], right[100020];
LL ans;



void merge(int l1, int r1, int l2, int r2)
{

	int n1 = r1 - l1 + 1, n2 = r2 - l2 + 1;


	for(int i = 0; i < n1; i++)
	{
		left[i] = a[i + l1];
	}
	for(int i = 0; i < n2; i++)
	{
		right[i] = a[i + l2];
	}

	left[n1] = 0x7f7f7f7f;
	right[n2] = 0x7f7f7f7f;

	int i ,j, k;
	i = j = 0;
    for (k=l1; k<=r2; k++)  
    {  
        if (left[i] <= right[j])  
        {  
            a[k] = left[i];  
            i++;  
        }  
        else  
        {  
            a[k] = right[j];  
            j++;  
            ans += n1-i;
        }  
    }  
    return;


}


void mergesort(int l, int r)
{

	int mid = (l+r)>>1;

	if(mid > l) mergesort(l, mid);
	if(mid < r) mergesort(mid+1, r);
	merge(l, mid, mid +1, r);

}


int main()
{
	int n, k;
	while(scanf("%d%d", &n,&k) != EOF)
	{
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);

		ans = 0;

		mergesort(1, n);
		// printf("%d %d\n", n, k);
		printf("%I64d\n", std::max(ans - k, 0LL));

	}




	return 0;
}