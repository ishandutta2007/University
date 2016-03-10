#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
#include<string>

using namespace std;


map<string, int>from, dest;


int main(){


    int n;
    while(scanf("%d", &n) != EOF){
        if(n == 0) return 0;
        from.clear();
        dest.clear();
        int ans = 0;
        string loser, winner;
        for(int i = 0; i < n; i++){
            cin >> winner >> loser;

            if(dest.find(winner) == dest.end()){
                dest[winner] = 0;
                ans++;
            }
            if(dest.find(loser) == dest.end()){
                dest[loser] = 0;
                ans++;
            }
            dest[loser]++;
            if(dest[loser] == 1) ans--;
        }

        if(ans == 1) printf("Yes\n");
        else printf("No\n");

    }

    return 0;
}
