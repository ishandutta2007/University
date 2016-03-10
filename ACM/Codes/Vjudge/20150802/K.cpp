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


set<string>st;

int main(){


    string str, line;

    while(getline(cin, line)){
        if(line[0] == '#') return 0;

        stringstream sin(line);
        st.clear();
        while(sin >> str){
            st.insert(str);
        }
        cout << st.size() << endl;
    }

    return 0;
}


