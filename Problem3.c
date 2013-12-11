// -----------------------------------------------------------
// ASSIGNMENT: The prime factors of 13195 are 5, 7, 13 and 29.
// 			   What is the largest prime factor of the number 
// 			   600851475143 ?
// 			   FOLLOW NUMBERS IN COMMENTS FOR CLARITY :)
// -----------------------------------------------------------

#include <stdio.h>
#define NUMBER_BEING_EVALUATED 600851475143

int determineIfPrime(long int mainLoopCounter);

int main(void)
{
	long int mainLoopCounter;
	int currentPrime=0;

	// 1) this for loop counts up, ultimately the counter is the value tested whether it is a prime multiple
	for (mainLoopCounter=2; mainLoopCounter <= (NUMBER_BEING_EVALUATED/2); mainLoopCounter++)
	{
		// 2) checks to see if current mainLoopCounter value is prime, with a function
		if (determineIfPrime(mainLoopCounter))
		{
			// 6) now that it has found a prime, time to see if its a multiple
			if (NUMBER_BEING_EVALUATED % mainLoopCounter==0)
			{
				// 7) the following is carried out if the above statement is true, overwriting value 'currentPrime' each iteration
				currentPrime=mainLoopCounter;
				printf("prime number inside for loop inside inner nested if: %d\n", currentPrime);
			}
		}
	}
	// 8) once above looping has executed, this print statement should print out the most currently updated prime multiple
	printf("Largest prime number that is a multiple of 600851475143 is: %d \n", currentPrime);
	return 0;
}

// 3) function that determines if number passed is prime, and returns a true or false accordingly to be used in an if
int determineIfPrime(long int mainLoopCounter)
{
	long int primeLoopCounter;
	// 4) starting at 2, loop checks to see if anything divides into the number currently being evaluated
	for (primeLoopCounter=2; primeLoopCounter < mainLoopCounter; primeLoopCounter++)
	{
		// 5) if a number between 2 and less than number being evaluated, returns a false or a not prime
		if (mainLoopCounter%primeLoopCounter==0)
		{
			return 0;
		}
	}
	// 5) this return is only reached it excapes above loop, returning a true to the function call
	return 1;
}