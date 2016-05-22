#include <bits/stdc++.h>

using namespace std;


typedef vector<int> VI;


void buble_sort(VI &v)
{
	int len = v.size();
	
	for(int i = len-1; i >= 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			if(v[j] > v[j+1])
				swap(v[j], v[j+1]);
		}
	}
}


void select_sort(VI &v)
{
	int len = v.size();
	
	for(int i = len-1; i >= 0; i--)
	{
		int pos = i;
		for(int j = 0; j < i; j++)if(v[j] > v[pos])
			pos = j;
		swap(v[pos], v[i]);
	}
}

void insert_sort(VI &v)
{
	int len = v.size();
	for(int i = 1; i < len; i++)
	{
		int tmp = v[i];
		int pos = i;
		
		while(tmp < v[pos-1] && pos > 0)
		{
			v[pos] = v[pos-1];
			pos--;
		}
		v[pos] = tmp;
	}
}


void quick_sort(VI &v, int l, int r)
{
	if(l >= r) return ;
	int i = l-1;
	int mid = v[r];
	for(int j = l; j < r; j++)
		if(v[j] < mid)
		{
			i++;
			swap(v[i], v[j]);
		}
	swap(v[i+1], v[r]);
	quick_sort(v, l, i);
	quick_sort(v, i+2, r);
}


int main()
{
	VI v;
	v.clear();
	for(int i = 0; i < 40000; i++)
		v.push_back(rand());
    clock_t start,finish; 
	start=clock();
	// buble_sort(v);	//Ã°ÅÝÅÅÐò
	// select_sort(v); 	//Ñ¡ÔñÅÅÐò
	//insert_sort(v); 	//²åÈëÅÅÐò
	quick_sort(v, 0, 39999);	//¿ìËÙÅÅÐò
	//sort(v.begin(), v.end());	//stl ¿ìËÙÅÅÐò
    finish=clock();
    cout << finish-start   << "/" << CLOCKS_PER_SEC  << " (s) "<< endl;

	
	return 0;
}

