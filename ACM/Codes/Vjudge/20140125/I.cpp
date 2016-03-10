#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;


char s[20];

int digit_check(int n){
	while(1){
		if(s[n] >= '0' && s[n] <= '9')
			n++;
		else
			return n;
	}
}

bool case1(int start, int end){
	if(end < start)
		return false;
	for(int i = start; i <= end; i++)
		if(s[i] > '9' || s[i] < '0')
			return false;
	return true;
}

bool case2(int start, int end){
	if(end < start)
		return false;
	if(s[start] == '.' && case1(start + 1, end))
		return true;
	return false;
}

bool case3(int start, int end){
	if(end < start)
		return false;
	if(case1(start, end - 1) && s[end] == '.')
		return true;
	return false;
}

bool case4(int start, int end){
	int i;
	if(end < start)
		return false;
	for(i = start; i <= end; i++)
		if(s[i] == '.')
			break;
	if(case1(start,i - 1) && case1(i + 1, end))
		return true;
	return false;
}

bool case5(int start, int end){
	int i;
	if(end < start)
		return false;
	for(i = start; i <= end; i++)
		if(s[i] == 'e' || s[i] == 'E')
			break;
	if(case1(start, i - 1) && case1(i + 1, end))
		return true;
	return false;
}

bool case6(int start, int end){
	int i;
	if(end < start)
		return false;
	for(i = start; i <= end; i++)
		if(s[i] == 'e' || s[i] == 'E')
			break;
	if(s[i+1] == '+' || s[i+1] == '-')
		if(case1(start, i - 1) && case1(i + 2, end))
			return true;
	return false;
}

bool case7(int start, int end){
	if(end < start)
		return false;
	if(s[start] == '.' && case5(start + 1, end))
		return true;
	return false;
}

bool case8(int start, int end){
	if(end < start)
		return false;
	if(s[start] == '.' && case6(start + 1, end))
		return true;
	return false;
}

bool case9(int start, int end){
	int i;
	if(end < start)
		return false;
	for(i = start; i <= end; i++)
		if(s[i] == '.')
			break;
	if(s[i + 1] == 'e' || s[i + 1] == 'E')
		if(case1(start, i - 1) && case1(i + 2, end))
			return true;
	return false;
}
bool case10(int start, int end){
	int i;
	if(end < start)
		return false;
	for(i = start; i <= end; i++)
		if(s[i] == '.')
			break;
	if(s[i + 1] == 'e' || s[i + 1] == 'E')
		if(s[i + 2] == '+' || s[i + 2] == '-')
			if(case1(start, i - 1) && case1(i + 3, end))
				return true;
	return false;
}

bool case11(int start, int end){
	int i;
	if(end < start)
		return false;
	for(i = start; i <= end; i++)
		if(s[i] == 'e' || s[i] == 'E')
			break;
	if(case4(start, i - 1) && case1(i + 1, end))
		return true;
	return false;
}

bool case12(int start, int end){
	int i;
	if(end < start)
		return true;
	for(i = start; i <= end; i++)
		if(s[i] == 'e' || s[i] == 'E')
			if(s[i + 1] == '+' || s[i + 1] == '-')
				break;
	if(case4(start, i - 1) && case1(i + 2, end))
		return true;
	return false;
}

int main(){
	int t;
	int now;
	int len;
	int tmp;
	scanf("%d",&t);
	getchar();
	while(t--){
		memset(s,0,sizeof(s));
		scanf("%s",s);
		len = strlen(s) - 1;
		if(case1(0, len))
			printf("%s\n",s);
		else if(case2(0, len))
			printf("%s\n",s);
		else if(case3(0, len))
			printf("%s\n",s);
		else if(case4(0, len))
			printf("%s\n",s);
		else if(case5(0, len))
			printf("%s\n",s);
		else if(case6(0, len))
			printf("%s\n",s);
		else if(case7(0, len))
			printf("%s\n",s);
		else if(case8(0, len))
			printf("%s\n",s);
		else if(case9(0, len))
			printf("%s\n",s);
		else if(case10(0, len))
			printf("%s\n",s);
		else if(case11(0, len))
			printf("%s\n",s);
		else if(case12(0, len))
			printf("%s\n",s);
	}
	return 0;
}

