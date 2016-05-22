#include <stdio.h>
#include <stdlib.h>

int numbers[501] = { };

int comp(const void * a, const void * b){
  printf("%d\n", numbers[501]++);
  // system("pause");
  return numbers[501] > 1 ? 0:-1;
}

int main()
{
  qsort(numbers, 501, sizeof(int), comp);
  system("pause");
  return 0;
}
