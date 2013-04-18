// A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,
// a^2 + b^2 = c^2
// For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.
#include <stdio.h>

int main(void)
{
	int counterA;
	int counterB;
	int counterC;
	for (counterA = 1; counterA < 1000; counterA++)
	{
		for (counterB = 1; counterB <= 1000-counterA; counterB++)
		{
			counterC = 1000 - (counterA+counterB);
			if (counterA*counterA + counterB*counterB == counterC*counterC)
			{
				// prints twice since there are two instances where 'counterA' and 'counterB' satisfy condition
				printf("Product of Pythagorean triplet that sums to 1000 is: %d\n", counterA * counterB * counterC);
			}
		}
	}
	return 0;
}