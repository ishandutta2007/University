#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int cmp(const void *a, const void *b){
  return strcmp((char *)a, (char *)b);
}

char p[200][200];
int main()
{
  int t;
  while (scanf("%d",&t) != EOF){
     memset(p,0,sizeof(p));
     int l=0;
    for (int i = 0; i < t; i++) {
      scanf("%s",p[i]);
      int len = strlen (p[i]);
      l=l>len?l:len;
    }
    qsort(p,t,sizeof(p[0]),cmp);
    int col = 62 / (l + 2);
    int row = (t % col == 0) ? (t / col) : (t / col + 1);
    for (int i =0; i<60; i++) {
      printf("-");
    }
    printf("\n");

    for (int i =0; i < row; i++) {
      for (int j = 0; j<col && (j*row+i) < t; j++) {
        int n = j*row + i;
        printf("%s",p[n]);

        if (j < col - 1 && ((j+1) * row + i < t)) {
          for (int k =0; k<l-strlen(p[n])+2; k++) {
            printf(" ");
          }
        }
      }
      printf("\n");
    }
  }
  return 0;
}
