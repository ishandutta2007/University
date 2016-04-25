#include <bits/stdc++.h>
using namespace std;
int arr[1000200], tarr[1000200];
int cnt;
void merge(int low, int mid, int high)
{
	int i, j, k;
	for (i = low, j = mid + 1, k = 0; i <= mid && j <= high;)
	{
		if(arr[i] < arr[j])
			tarr[k++] = arr[i++];
		else
		{
			tarr[k++] = arr[j++];
			cnt += mid - i + 1;
		}
	}
	while(i <= mid) tarr[k++] = arr[i++];
	while(j <= high) tarr[k++] = arr[j++];

	for (k = 0; low <= high; low++, k++)
		arr[low] = tarr[k];
}
void mergesort(int low, int high)
{
	if(low == high) return;
	int mid = (low + high) / 2;
	mergesort(low, mid);
	mergesort(mid + 1, high);
	merge(low, mid, high);
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	cnt = 0;
	mergesort(0, n-1);
	printf("%d\n", cnt);
	return 0;
}