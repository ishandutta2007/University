#include<map>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#define LL long long


using namespace std;

int main(){


    map<string, int>cnt, low;
    for(int i = 0; i < 6; i++){
        string name, dev;
        int p;
        cin >> name >> dev >> p;
        if(!cnt[dev]){ cnt[dev] = 0; low[dev] = p;}
        cnt[dev] ++;
        low[dev] = min(low[dev], p);

//        cout << dev << ' ' << cnt[dev] << ' ' << low[dev] << endl;
    }

    int tmpcnt = 0;
    int tmplow = 0;
    string tmpname;
    for(map<string, int> :: iterator it = cnt.begin(); it != cnt.end(); it ++){
        if(it->second > tmpcnt){
            tmpcnt = it->second;
            tmplow = low[it->first];
            tmpname = it->first;
        }
        else if(it->second == tmpcnt && low[it->first] < tmplow){
            tmpcnt = it->second;
            tmplow = low[it->first];
            tmpname = it->first;
        }
    }
//    cout << cnt["nexus4"] << endl;
//    cout << tmpcnt <<endl;
//    cout << tmplow <<endl;
    cout << tmpname << endl;
    return 0;
}
