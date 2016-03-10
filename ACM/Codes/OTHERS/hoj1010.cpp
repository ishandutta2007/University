#include"cstdio"
#include"iostream"
#include"cmath"
using namespace std;

int main(){
	int h,m;
	float angh,angm;
	float ang;
	while(1){
		scanf("%d%d",&h,&m);
		if(h==0 && m==0)
			break;
//		printf("%f\n",float(m/60.0));
		angh = float(h + float(m/60.0))*30;
		angm = float(6*m);
//		printf("%.1f\n",angh);
//		printf("%.1f\n",angm);
		ang = fabs(angm - angh);
		if(ang > 180)
			ang = 360 - ang;
		printf("At %d:%02d the angle is %.1f degrees.\n", h, m, ang);
		
	}
	
	return 0;
	
	
}
