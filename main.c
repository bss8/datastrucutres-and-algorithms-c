#include <stdlib.h>
#include <stdio.h>

/**
 * x becomes 5 at the end of call stack and stays 5 because it's static
 * So it is ((((0+5)+5)+5)+5)+5
 * so bottom call for n = 1 returns 5 for the function
 * When it returns to the second to last it's 5 for static_recursive(1) plus x = 5. 
 * So that would return 10 for the 2nd to last level. the static_recursive(2) would be 5 + 5 = 10 returned 
 * static_recursive(3) would be 10 + 5 = 15. next would be 15 + 5 = 20. Last is 20 + 5 = 25, which is the result. 
 */ 
int static_recursive(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return static_recursive(n-1) + x;
    }
    return 0;
}

int sum_formula(int n)
{
    return n*(n+1)/2;
}

int sum_loop(int n)
{
    int i, s = 0;
    for (i = 1; i <= n; i++)
        s += i;

    return s;
}

int sum_recursive(int n)
{
    if (n == 0)
        return 0;
    else 
        return sum_recursive(n-1) + n;
}

int main(int argc, char* argv[]) 
{
    printf("Hello world!\n");
    int* p = (int*) malloc(5 * sizeof(int));

    // trace recursion, simple example
    printf("Tracing recursion, result should be 25: %d\n", static_recursive(5));

    // sum of natural numbers employing different means
    printf("Sum of numbers via formula: %d\n", sum_formula(6));
    printf("Sum of numbers via loop: %d\n", sum_loop(6));
    printf("Sum of numbers via recursion: %d\n", sum_recursive(6));

}


