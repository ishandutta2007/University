#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

char table[8][8];
char operations[1000];

void above_move(int x, int y){
	table[x][y] = table[x - 1][y];
	table[x - 1][y] = ' ';
	printf("AAA\n");
}

void below_move(int x, int y){
	table[x][y] = table[x + 1][y];
	table[x + 1][y] = ' ';
	printf("BBB\n");
}


void right_move(int x, int y){
	table[x][y] = table[x][y + 1];
	table[x][y + 1] = ' ';
	printf("RRR\n");
}



void left_move(int x, int y){
	table[x][y] = table[x][y - 1];
	table[x][y - 1] = ' ';
	printf("LLL\n");
}

bool puzzle(int x,int y){
	for(int i = 0; i < strlen(operations) - 1; i++)
	{
		//Above;
		if(operations[i] == 'A'){
			above_move(x, y);
			x--;
		}
		else if(operations[i] == 'B'){
			below_move(x, y);
			x++;
		}
		else if(operations[i] == 'R'){
			right_move(x, y);
			y++;
		}
		else if(operations[i] == 'L'){
			if(y == 0)
				return 0;
			left_move(x, y);
			y--;
		}
		if(x < 1 || x > 5 || y < 0 || y > 4)
			return 0;
	}
	printf("finished\n");
	return 1;
}



int main(){
	int r = 1;
	while(r){
		for(int i = 1; i <= 5; i++)
		{
			gets(table[i]);
			if(strcmp(table[1], "Z") == 0)
				return 0;
		}
		
		int x,y;
		scanf("%s",operations);
		for(int i = 1; i <= 5; i++)
			for(int j = 1; j <= 5; j++)
				if(table[i][j] == ' ')
				{
					x = i;
					y = j;
				}
		printf("x:%d y:%d\n",x,y);
		bool ans = puzzle(x, y);
		
		
		printf("Puzzle #%d:\n",r++);
		
		if(ans == 0)
			printf("impossible\n");
		else{
			for(int i = 1; i <= 5; i++){
				for(int j = 1; j <= 5; j++)
					printf("%c ",table[i][j]);
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}

