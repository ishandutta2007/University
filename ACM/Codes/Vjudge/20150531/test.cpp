#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>

using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int main(){
    for(int i=0;i<10;i++)
        q.push(i);
    while(!q.empty()){
        cout<<q.top()<< endl;
        q.pop();
    }
    return 0;
}
