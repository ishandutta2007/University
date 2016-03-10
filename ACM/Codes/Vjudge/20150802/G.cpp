#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<string>
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<sstream>
#define ll long long

using namespace std;


stack<string>fw,bc;
string now = "http://www.acm.org/";

void ignore(){
    cout<< "Ignored" << endl;
}


void show(){
    cout << now << endl;
}


int main(){


    string cmd;

    while(cin >> cmd){

        if(cmd == "BACK"){
            if(bc.empty()){
                ignore();
            }
            else{
                fw.push(now);
                now = bc.top();
                bc.pop();
                show();
            }

        }

        else if(cmd == "FORWARD"){
            if(fw.empty()){
                ignore();
            }
            else{
                bc.push(now);
                now = fw.top();
                fw.pop();
                show();
            }

        }
        else if(cmd == "VISIT"){
            bc.push(now);
            cin >> now;
            show();
            while(!fw.empty()) fw.pop();
        }
        if(cmd == "QUIT") return 0;
    }

    return 0;
}



