// --------------------------------------------------------------
// ASSIGNMENT: If we list all the natural numbers below 10 that 
// 			   are multiples of 3 or 5, we get 3, 5, 6 and 9. The 
// 			   sum of these multiples is 23. Find the sum of all 
// 			   the multiples of 3 or 5 below 1000.
// --------------------------------------------------------------

#include <stdio.h>

#define UPPER_LIMIT 1000

int main(void)
{
	int multipleOfThreeCounter = 0;
	int multipleOfFiveCounter = 0;
	int counter3;
	int counter5;
	int sum=0;

	printf("This program computes the sum of the natural numbers that are multiples of 3 and 5."
		   "\nThe values are taken from 0 to 1000.\n");
	for (counter3 = 1; multipleOfThreeCounter < (UPPER_LIMIT-3); counter3++)
	{
		multipleOfThreeCounter = counter3*3;
		sum += multipleOfThreeCounter;
		if (multipleOfThreeCounter%5==0)
		{
			sum -= multipleOfThreeCounter;
		}
	}
	for (counter5 = 1; multipleOfFiveCounter < (UPPER_LIMIT-5); counter5++)
	{
		multipleOfFiveCounter = counter5*5;
		sum += multipleOfFiveCounter;
	}
	printf("The sum of the natural numbers that are multiples of 3 and 5 from 0 to 1000 is: %d\n", sum);
	return 0;
}