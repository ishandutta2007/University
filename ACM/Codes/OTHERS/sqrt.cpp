#include <stdio.h>
#include"cmath"  
//#include"cmath" ��#include"math.h" һ�����õ�
//�õ������fabs() 


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
  	return 0;//�����˵��仰�� 
}

double sqrt(double x){
	double sub,r2;
    double r1=1.0;
//����������㲻��Ҫ֮ǰ��ֵ��������ֱ����r1�������µ�ֵ����Ӱ��
 	do
	 {
   		r2=(r1+x/r1)/2;
      	sub=r1-r2;
      	r1=r2;
 	}while(fabs(sub)>1e-6/*0.000001*/);  //д��0.0000001̫�����ˣ�ֱ��д��1e-6 
    
	
	return r1;
}
