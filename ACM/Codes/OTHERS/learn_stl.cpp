#include <iostream>
#include <stdlib.h>    // Need random(), srandom()
#include <time.h>      // Need time()
#include <algorithm>   // Need random_shuffle()
#include <vector>      // Need vector
#include <functional>  // Need ptr_fun()
 
using namespace std;
 
// Data to randomize
int iarray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
vector<int> v(iarray, iarray + 10);
 
// Function prototypes
unsigned int RandInt(const unsigned int n);
 
int main()
{
  srand( time(NULL) );  // Seed random generator
 
  pointer_to_unary_function<unsigned int, unsigned int> ptr_RandInt = ptr_fun(RandInt);  // Pointer to RandInt()//????
  random_shuffle(v.begin(), v.end(), ptr_RandInt);
 
  return 0;
}

unsigned int RandInt(const unsigned int n)
{
  return rand() % n;
}

