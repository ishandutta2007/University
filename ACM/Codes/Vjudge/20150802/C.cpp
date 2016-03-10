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

#define ll long long

using namespace std;


char str[20];




bool cmp(char ch1, char ch2){

    bool isup1 = false, isup2 = false;

    if(ch1 >= 'A' && ch1 <= 'Z')
    {
        isup1 = true;
        ch1 += 32;
    }

    if(ch2 >= 'A' && ch2 <= 'Z')
    {

        isup2 = true;
        ch2 += 32;
    }

    if(ch1 == ch2) return isup1 > isup2;
    return ch1 < ch2;

}


int main(){


    int T;
    scanf("%d", &T);

    while(T--){
        scanf("%s", str);
        int len = strlen(str);
        sort(str, str + len, cmp);

//        cout << str << endl;

        do{
            cout << str << endl;
        }while(next_permutation(str, str + len, cmp));

    }

    return 0;
}
