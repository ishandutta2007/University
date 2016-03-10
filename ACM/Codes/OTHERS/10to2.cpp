#include <stdio.h>
void binary(int a ,int i ,int *out);
void _output(int *out);
int main(){
    int a, m, k, j, c;
    int i = 31;
    int out[32] = {0};
    
    printf("Input the integer to be transferred:");
    scanf("%d",&a);
    
//    if(a < 0)
//        c = -a-1;
    binary(a, i, out);
    
//    for(k=0; k<(32-m); k++){
//        out[k] = out[m];
//        m++;
//    }
//    for(j = 31; j>k; j--)
//        out[j] =0;
//    if(a < 0){
//        for(j=31; j>=0; j--)
//            out[j] = (!out[j]||0);
//    }
//    for(j=31; j>=0; j--)
//        printf("%d",out[j]);
	
	for(i=0 ;i<32 ;i++)
		printf("%d ",out[i]);
	printf("\n");
	_output( out );   
    return 0;
}

void _output(int *out )
{
	int i = 0;
	while(out[i] ==0 )
		i++;
	for(; i<32; i++)
		printf("%d ",out[i]);
	return;
	
	
}


void binary(int a, int i, int *out){
    
	
	int b;
    b = a%2;
    a = a/2;
    out[i] = b;
    if(a != 0)
    	binary(a, i-1, out);
//    if(a == 0){
//        out[i] = 0;
//        return;
//    }
//    else{
//        out[i] = b;
//        binary(a, i-1, out);
//        return;
//    }
}
