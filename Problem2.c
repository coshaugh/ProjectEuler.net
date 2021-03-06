// --------------------------------------------------------------
// ASSIGNMENT: Each new term in the Fibonacci sequence is 
// 			   generated by addingthe previous two terms. By
// 			   starting with 1 and 2, the first 10 terms will be:
// 			   1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
// 			   By considering the terms in the Fibonacci sequence 
// 			   whose values do not exceed four million, find the 
// 			   sum of the even-valued terms.
// --------------------------------------------------------------

#include <stdio.h>
#define UPPER_LIMIT 4000000

int main(void)
{
	int leadingSequence=1;
	int trailingSequence=0;
	int sum=0;
	printf("This program computes the sum of even valued integers within the Fibonacci sequence that do not exceed 4 million.\n");
	while (leadingSequence<UPPER_LIMIT)
	{
		leadingSequence += trailingSequence;
		if (leadingSequence%2==0)
		{
			sum+=leadingSequence;
		}
		if (trailingSequence%2==0)
		{
			sum+=trailingSequence;
		}
		trailingSequence += leadingSequence;
	}
	printf("The sum of even integers contained within the Fibonacci sequence that are less than 4 million is: %d\n", sum);
	return 0;
}