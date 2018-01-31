/*- -*- mode: c; c-basic-offset: 8; -*-
 *
 * The first line of this file configures the behavior of the "Tab" key in
 * emacs.  Emacs has a rudimentary understanding of C syntax and style.  In
 * particular, depressing the "Tab" key once at the start of a new line will
 * insert as many tabs and/or spaces as are needed for proper indentation.
 */

#include <stdio.h>

#define MAXITER 100

int memo[MAXITER]; 

const int NOMEMO = -1;

/*
 * Requires:
 *  Nothing.
 *
 * Effects:
 *  Initializes each element in the array "memo" to NOMEMO.
 */
void
memo_init(void)
{
	int i;

	for (i = 0; i < MAXITER; i += 1)
		memo[i] = NOMEMO;
}

/* 
 * Requires:
 *  "x" should be less than 100 and "y" should be a valid integer.
 *
 * Effects:
 *  Stores "y" within the array "memo" at the location indexed by "x". 
 */
void 
memo_put(int x, int y)
{

	memo[x] = y;
}

/* 
 * Requires:
 *  "x" should be less than 100.
 *
 * Effects:
 *  Returns the value stored within the array "memo" at the location indexed
 *  by "x". 
 */
int 
memo_get(int x)
{

	return (memo[x]);
}

/* 
 * Requires:
 *  "n" should be a valid integer.
 *
 * Effects:
 *  Returns the "n"th number in the fibonacci series.
 */
int 
fib(int n)
{
	/*
	 * Check if the "n"th fibonacci number is already stored in the array
	 * "memo".
	 */
	int result = memo_get(n);

	/*
	 * If the result is already calculated, just retrieve and return it.
	 */
	if (result == NOMEMO) {
		if (n == 0 || n == 1)
			result = 1;
		else {
			/*
			 * Calculate the "n"th number in the fibonacci series
			 * by recursively finding the "n - 1"th and "n - 2"nd
			 * numbers and adding them. 
			 */
			result = fib(n - 1) + fib(n - 2);
		}
		/* Store the result in the array "memo". */
		memo_put(n, result);
	}
	return (result);
}

/*
 * Requires:
 *  Nothing.
 *
 * Effects:
 *  Gets input "n" from user.  If "n" is negative the program exits.
 *  Otherwise, it calculates the "n"th number in the fibonacci series and
 *  prints the result.
 */
int 
main(void)
{
	int n;

	memo_init();

	while (1) {
		/* Get input "n". */
		printf("Enter a number (negative to quit): ");
		scanf("%d", &n);

		/* If "n" is negative, quit. */
		if (n < 0)
			break;

		/*
		 * Otherwise, calculate the "n"th number in the fibonacci
		 * series and print it.
		 */
		printf("The %d-th Fibonacci number is %d.\n", n, fib(n));
	}
	return (0);
}