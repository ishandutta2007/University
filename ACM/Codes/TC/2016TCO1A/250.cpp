#include <bits/stdc++.h>
using namespace std;


char ret[20];

class EllysTimeMachine
{
public:
		string getTime(string Time)
		{
			int H,M;
			sscanf(Time.c_str(), "%d:%d", &H,&M);
			H*=5;
			M/=5;
			sprintf(ret, "%02d:%02d",M==0? 12:M,H==60?0:H);
			return ret;
		}
};
