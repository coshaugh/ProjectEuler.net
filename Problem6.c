// --------------------------------------------------------------
// ASSIGNMENT: The sum of the squares of the first ten natural 
// 			   numbers is:  1^2 + 2^2 + ... + 10^2 = 385
// 			   The square of the sum of the first ten natural 
// 			   numbers is:  (1 + 2 + ... + 10)^2 = 55^2 = 3025
// 			   Hence the difference between the sum of the squares 
// 			   of the first ten natural numbers and the square of 
// 			   the sum is: 3025 − 385 = 2640. 
// 			   Find the difference between the sum of the squares 
// 			   of the first one hundred natural numbers and the 
//			   square of the sum.
// --------------------------------------------------------------

#include <stdio.h>

int main (void)
{
	int sumOfSquares=0;
	int sum=0;

	for (int naturalNumberCounter = 1; naturalNumberCounter <= 100; naturalNumberCounter++)
	{
		sumOfSquares += (naturalNumberCounter*naturalNumberCounter);
		sum += naturalNumberCounter;
	}

	printf("The difference between the sum of squares and square of sum of first 100 natural numbers is: %d\n", 
		((sum*sum)-sumOfSquares));

	return 0;
}


