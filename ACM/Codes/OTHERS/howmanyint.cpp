#include"stdio.h"
#include"stdlib.h"


int find_int(){
	printf("in find\n");
	int _state=0;
	int _count=0;
	int c;
	while(1){
		scanf("%c",&c);
		printf("c:[%c]\n",c);
		if(c=='a'){
			printf("do break\n");
			break;}
		switch (_state){
			case 0: if(c=='i') 
						_state=1;
					break;
			case 1: if(c=='n')
						_state=2;
					else if(c!='i')
						_state=0;
					break;
			case 2: if(c=='t'){
						_state=0;
						_count++;
					}
					else if(c=='i')
						_state=1;
					break;
		}
	printf("in while\n");
	}
	return _count;
}



int main(){
	printf("Now ,neter you words:\n");
	int _count=find_int();
	switch(_count){
	case 0: printf("Are you kidding me ? !  There's anything but 'int'\n");
			break;
	case 1: printf("Luckily , at list there is one.\n");
			break;
	default:printf("Wow ! There are %ds int hidden in your input!!\n",_count);
			break;
	
	
	}
	system("pause");
	return 0;
}