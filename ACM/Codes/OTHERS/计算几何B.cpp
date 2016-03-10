#include"cstdio"
#include"iostream"
#include"cmath"

using namespace std;


struct line{
	
	int nx,ny;
	int px,py;
}line1,line2;


int main(){
	
	int n;
	int a,b,c,d;
	scanf("%d",&n);
	
	printf("INTERSECTING LINES OUTPUT\n");
	for(int i = 1; i<=5; i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		line1.px = a;
		line1.py = b;
		line1.nx = c-a;
		line1.ny = d-b;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		line2.px = a;
		line2.py = b;
		line2.nx = c-a;
		line2.ny = d-b;
		
		
		if(line1.nx*line2.ny-line1.ny*line2.nx == 0){
			int nx = line2.px-line1.px;
			int ny = line2.py-line1.py;
			
			if(((nx*line1.ny-ny*line1.nx) == 0) && ((nx*line2.ny-ny*line2.nx) == 0))
				printf("LINE\n");
			
			else
				printf("NONE\n");
			
		}
		
		else if(line1.nx!=0 && line2.nx!=0)
		{
			
			double k1 = double(line1.ny)/double(line1.nx);
			double c1 = double(line1.py - k1*double(line1.px));
			
			double k2 = double(line2.ny)/double(line2.nx);
			double c2 = double(line2.py - k2*double(line2.px));
			
			double x = (c2-c1)/(k1-k2);
			double y = k1*x + c1;
			
			
			printf("PONIT %.2lf %.2lf\n",x,y);
		}
		
		else{
			double x,y;
			if(line1.nx == 0){
				double k2 = double(line2.ny)/double(line2.nx);
				double c2 = double(line2.py - k2*double(line2.px));
				
				x = line1.px;
				y = k2*x + c2;
				
			}
			else{
				double k1 = double(line1.ny)/double(line1.nx);
				double c1 = double(line1.py - k1*double(line1.px));
				x = line2.px;
				y = k1*x +c1;
				
				
			}
			printf("PONIT %.2lf %.2lf\n",x,y);
			
		}
		
		
		
	}
	printf("END OUT PUT\n");
	
	return 0;
}
