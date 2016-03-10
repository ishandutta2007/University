#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<sstream>

#define ll long long

using namespace std;

map<string, string>mp;
map<string, int>cnt;
int main(){


    int n;
    scanf("%d", &n);
    getchar();
    string name, party;
    for(int i = 0; i < n; i++)
    {
        getline(cin, name);
//        cout << name <<endl;
        getline(cin, party);

//        cout << party << endl;


        mp[name] = party;
        cnt[name] = 0;
    }


    scanf("%d", &n);
    getchar();
    int m = 0;
    bool hasmax = false;
    string maxname = "";
    for(int i = 0; i < n; i++){
        getline(cin, name);
//        cout << name <<endl;
        if(mp.find(name) == mp.end()) continue;
        cnt[name] ++;
        if(cnt[name] > m){
            hasmax = true;
            m = cnt[name];
            maxname = name;
        }
        else if(cnt[name] == m){
            hasmax = false;
        }
    }


    if(hasmax){
        cout << mp[maxname] <<endl;
    }
    else printf("tie\n");


    return 0;
}



