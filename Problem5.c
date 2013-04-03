// --------------------------------------------------------------
// ASSIGNMENT:
// 2520 is the smallest number that can be divided by each
// of the numbers from 1 to 10 without any remainder.
//
// What is the smallest positive number that is evenly 
// divisible by all of the numbers from 1 to 20?
// --------------------------------------------------------------

#include <stdio.h>

int main(void)
{
	int targetNumber = 20; // starts at 20 but will count up until is divisible by numbers 1-20
	int evaluatingCounter = 20; // counter that counts down from 20 to test if targetNumber divisible
	int numberNotYetFound = 1;

	while (numberNotYetFound)
	{
		if (targetNumber%evaluatingCounter == 0)
		{
			if (evaluatingCounter==11) // only checking down till 11, since if #'s 20-11 go in evenly, so will 1-10
			{
				printf("The smallest number divisible by all the numbers from 1-20 is: %d\n", targetNumber);
				numberNotYetFound = 0; // breaks out of while loop, number found!
			}
			evaluatingCounter--;
		}
		else // if targetNumber not divisible by current counter, resets counter to 20 and increments targetNumber
		{
			evaluatingCounter = 20;
			targetNumber++;
		}
	}
	return 0;
} // end main







