// --------------------------------------------------------------
// ASSIGNMENT: By listing the first six prime numbers: 
// 			   2, 3, 5, 7, 11, and 13, we can see that the 6th 
// 			   prime is 13.
// 			   What is the 10,001st prime number?
// --------------------------------------------------------------

#include <stdio.h>
#define TARGET_PRIME 10001

int main(void)
{
	int arrayOfPrimes[TARGET_PRIME] = {1,2};
	int n = 1; // keeps track of total primes found, starting at 1 since we don't iterate through even values, thus skipping the even prime 2
	int p = 1; // surrogate prime value
	while(n != TARGET_PRIME)
	{
		p+=2; // no primes are even, no need to iterate through even values
		int i;
		for(i = 1; i <= n; i++)
		{
			if(p % arrayOfPrimes[i] == 0) // p is not primes, no need to continue
				break;
		}
		if(i > n) // counter reached end of final iteration, a unique prime has been found
		{
			arrayOfPrimes[n+1] = p;
			n++;
		}
	}

	printf("%d\n", arrayOfPrimes[TARGET_PRIME]);
	return 0;
}