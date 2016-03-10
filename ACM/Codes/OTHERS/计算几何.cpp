#include"cstdio"
#include"iostream"
#include"cmath"
#define pi 3.141592653589793
using namespace std;

struct point{
	double x,y;
}p1,p2,p3,x1,x2,x3;
//
//struct xl{
//	struct point p1,p2;
//}x1,x2;

double d,theta;


int main(){
	
	while(scanf("%lf%lf%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y) == 6){
		x1.x = p2.x - p1.x;
		x1.y = p2.y - p1.y;
		x2.x = p3.x - p1.x;
		x2.y = p3.y - p1.y;
		x3.x = p3.x - p2.x;
		x3.y = p3.y - p2.y;
		
//		printf("%lf,%lf,%lf,%lf,%lf,%lf\n",x1.x,x1.y,x2.x,x2.y,x3.x,x3.y);
		
		double A = sqrt(x1.x*x1.x+x1.y*x1.y);
		double B = sqrt(x2.x*x2.x+x2.y*x2.y);
		double C = sqrt(x3.x*x3.x+x3.y*x3.y);
		double P = (A+B+C)/2;
		
//		printf("A=%lf,B=%lf,C=%lf\n",A,B,C);
		
//		theta = acos( ( (x1.x*x2.x) + (x1.y*x2.y) ) / (A*B) );
//		theta = acos((B*B+C*C-A*A) / (2*B*C));
//		double costheta = (B*B+C*C-A*A) / (2*B*C);
//		double sintheta = sqrt(1-costheta*costheta);
		
//		printf("sin theta = %lf\n",sin(theta));
		
//		d = A / sintheta;
		
		double s = sqrt(P*(P-A)*(P-B)*(P-C));
		double d = A*B*C/(2*s);
		
		
		printf("%.2lf\n",pi*d);
	}
	
	
	
	return 0;
}
