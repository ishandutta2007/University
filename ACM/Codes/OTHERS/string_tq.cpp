#include <stdio.h>
#include <string.h>
#define MAX1 5
#define MAX2 20
int delestr(char a[MAX1][MAX2],int);
int main (){
    char a[MAX1][MAX2];
    int i;
    int count=0;
    
    printf("Input the strings:\n");
    for(i=0;i<MAX1;i++){
        scanf("%s",a[i]);
    }
    
    count=delestr(a,count);
    
    printf("The deleted strins:\n");
    for(i=0;i<MAX1-count;i++){
        printf("%s\n",a[i]);
    }
    return 0;
}
int delestr(char a[][MAX2],int count){
    int k,i,j,r;
    for(k=0;k<MAX1-count-1;k++)
        for(i=k+1;i<MAX1-count;i++){
            r=strcmp(a[k],a[i]);
            if(r==0){
                count++;
                for(j=i;j<MAX1-1;j++)
                   strcpy(a[j],a[j+1]) ;
                i--;
            }
        }
    
    return count;
    
}
