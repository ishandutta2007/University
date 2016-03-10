#include <stdio.h>
#include"cmath"  
//#include"cmath" 和#include"math.h" 一样，用到
//用到里面的fabs() 


double sqrt(double);

int main(){
    double x,r;
    printf("Input x:");
    scanf("%lf",&x);
	if(x<0){
		printf("Illegal Input\n");
		return 0;
	}
	
	r=sqrt(x);
  	printf("The reuslt is %lf\n",r);
  	return 0;//不想多说这句话。 
}

double sqrt(double x){
	double sub,r2;
    double r1=1.0;
//这种情况，你不需要之前的值，所以你直接用r1来储存新的值不会影响
 	do
	 {
   		r2=(r1+x/r1)/2;
      	sub=r1-r2;
      	r1=r2;
 	}while(fabs(sub)>1e-6/*0.000001*/);  //写成0.0000001太复杂了，直接写成1e-6 
    
	
	return r1;
}
