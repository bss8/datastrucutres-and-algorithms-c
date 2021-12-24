#include <stdio.h>

void fun(int n)
{
   if (n>0)
   {
      printf("%d ", n); // ascending section
      fun(n-1);         // recursive call
      // descending section
   }
}


void fun1(int n)
{
   if (n>0)
   {
      // ascending section
      fun1(n-1);         // recursive call
      printf("%d ", n); // descending section
   }
}

/**
 * @brief The "Tower of Hanoi" recursive function is O(2^n) 
 * exponential run time function. 
 * 
 * @param n how many "disks" need to be moved
 * @param A source tower
 * @param B "using" or auxiliary tower
 * @param C destination tower
 */
void towerOfHanoi(int n, int A, int B, int C) {
   if (n > 0) 
   {
      towerOfHanoi(n-1, A, C, B);
      printf("from tower %d to %d \n", A, C);
      towerOfHanoi(n-1, B, A, C);
   }
}

int main() 
{
   int x = 3; 
   fun1(x);
   printf("\n");

   printf("Now running Tower of Hanoi recursive function...\n");
   towerOfHanoi(3, 1, 2, 3);

   return 0;
}