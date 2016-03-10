#include"cstdio"
#include"iostream"
#include"cmath"

using namespace std;

typedef struct{  
    int x, y;  
}Point;  
  
typedef struct{  
    Point s,e;  
}Line;


double crossmultiply(Point v1, Point v2){
	return (v1.x * v2.y - v2.x * v1.y); 
}



