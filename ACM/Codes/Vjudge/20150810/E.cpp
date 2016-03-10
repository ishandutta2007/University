#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;


char s[1020];
int divs[40];
bool appe[40];
int fa[40];

int root(int i){
    if(fa[i] == i)
        return i;

    fa[i] = root(fa[i]);
    return fa[i];
}

void unionset(int a, int b){
    int ra = root(a);
    int rb = root(b);

    if(ra == rb) return ;

    fa[ra] = rb;

}



int main(){


    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        memset(divs, 0, sizeof(divs));
        memset(appe, 0, sizeof(appe));
        for(int i = 0; i < 26; i++)
            fa[i] = i;

        for(int i = 0; i < n; i++){
            scanf("%s", s);
            divs[s[0] - 'a']--;
            appe[s[0] - 'a'] = true;
            divs[s[strlen(s) - 1] - 'a'] ++;
            appe[s[strlen(s) - 1] - 'a'] = true;
            unionset(s[0] - 'a', s[strlen(s) - 1] - 'a');
        }

//        for(int i = 0; i < 26; i++){
//            if(appe[i])
//                printf("%c %d\n", i + 'a', root(i));
//        }
        int p = 0;
        while(appe[p] == false) p++;
        int rot = root(p);
//        printf("rot : %d\n", rot);
        bool flag = true;
        for(; p < 26; p++)if(appe[p] && root(p) != rot) flag = false;

//        printf("%d\n", flag);
        int one = 0, minone = 0, zero = 0;
        for(int i = 0; i < 26; i++){
            if(divs[i] == 0) zero++;
            if(divs[i] == -1) minone++;
            if(divs[i] == 1) one++;
        }


        if(!((one == 1 && minone == 1 && zero == 24) || (one == 0 && minone == 0 && zero == 26))){
            flag = false;
        }
//        printf("%d\n", flag);

        if(flag)
            printf("Ordering is possible.\n");
        else
            printf("The door cannot be opened.\n");

    }
    return 0;
}
