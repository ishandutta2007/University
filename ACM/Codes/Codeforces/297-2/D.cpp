#include<bits/stdc++.h>

using namespace std;

int n,m;
char ss[2020][2020];
int mx[8] = {0,0,-1,1,1,1,-1,-1};
int my[8] = {-1,1,0,0,-1,1,-1,1};


int left_up(int x, int y){
    if(ss[x][y] == '.')
        return 0;
    if(x - 1 < 0 || y - 1 < 0)
        return 0;

    if(ss[x - 1][y - 1] =='.' && ss[x - 1][y] == '.' && ss[x][y - 1] == '.'){
        ss[x][y] = '.';
        return 1;
    }
    return 0;
}

int left_bot(int x, int y){
    if(ss[x][y] == '.')
        return 0;
    if(x + 1 >= n || y - 1 < 0)
        return 0;

    if(ss[x + 1][y - 1] == '.' && ss[x + 1][y] == '.' && ss[x][y - 1] == '.'){
        ss[x][y] = '.';
        return 1;
    }
    return 0;
}

int right_up(int x, int y){
    if(ss[x][y] == '.')
        return 0;
    if(x - 1 < 0 || y + 1 >= m)
        return 0;

    if(ss[x - 1][y + 1] == '.' && ss[x - 1][y] == '.' && ss[x][y + 1] == '.'){
        ss[x][y] = '.';
        return 1;
    }
    return 0;
}


int right_bot(int x, int y){
    if(ss[x][y] == '.')
        return 0;
    if(x + 1 >= n || y + 1 >= m)
        return 0;

    if(ss[x + 1][y + 1] == '.' && ss[x + 1][y] == '.' && ss[x][y + 1] == '.'){
        ss[x][y] = '.';
        return 1;
    }
    return 0;
}



void movewall(int x, int y){
    int flag = left_up(x,y) + left_bot(x,y) + right_up(x,y) + right_bot(x,y);

//    printf("flag : %d\n", flag);
    if(flag)for(int i = 0; i < 8; i++){
        int tx = x + mx[i];
        int ty = y + my[i];
        if(0 <= tx && tx < n && 0 <= ty && ty < m && ss[tx][ty] == '*')
            movewall(tx, ty);
    }
}





int main(){

    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%s", ss[i]);

    for(int i = 0 ; i < n; i++)
        for(int j = 0; j < m; j++)
            if(ss[i][j] == '*')
                movewall(i, j);

    for(int i = 0 ; i < n; i++)
        printf("%s\n", ss[i]);

    return 0;
}
