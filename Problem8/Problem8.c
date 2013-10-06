// --------------------------------------------------------------
// ASSIGNMENT: Find the greatest product of five consecutive 
// 			   digits in the 1000-digit number, located in 
//			   Thousand_Digit_Number.txt and below
//
// 			   73167176531330624919225119674426574742355349194934
// 			   96983520312774506326239578318016984801869478851843
// 			   85861560789112949495459501737958331952853208805511
// 			   12540698747158523863050715693290963295227443043557
// 			   66896648950445244523161731856403098711121722383113
// 			   62229893423380308135336276614282806444486645238749
// 			   30358907296290491560440772390713810515859307960866
// 			   70172427121883998797908792274921901699720888093776
// 			   65727333001053367881220235421809751254540594752243
// 			   52584907711670556013604839586446706324415722155397
// 			   53697817977846174064955149290862569321978468622482
// 			   83972241375657056057490261407972968652414535100474
// 			   82166370484403199890008895243450658541227588666881
// 			   16427171479924442928230863465674813919123162824586
// 			   17866458359124566529476545682848912883142607690042
// 			   24219022671055626321111109370544217506941658960408
// 			   07198403850962455444362981230987879927244284909188
// 			   84580156166097919133875499200524063689912560717606
// 			   05886116467109405077541002256983155200055935729725
// 			   71636269561882670428252483600823257530420752963450
// --------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUMBER_ARRAY_SIZE 1000+1 // +1 for the null character
#define FIVE_ELEMENTS 5

FILE *filePointer; // file pointer to input text file

int main (void)
{
	int bufferOfDigits[NUMBER_ARRAY_SIZE] = {0};
	int bufferIndex                       = 0; // used to count through buffer array
	int fiveIndex                         = 0;
	int candidateProduct                  = 1;
	int largestProduct                    = 0;

	// checks for successful file opening
	filePointer = fopen("/Users/conoroshaughnessy/Desktop/Kaggle/Proj_Euler/Problem8/Thousand_Digit_Number.txt", "r");
	if (filePointer == NULL)
	{
		printf("Could not open Thousand_Digit_Number.txt for reading\n");
		exit(1);
	}
	else
		printf("Opened Thousand_Digit_Number.txt successfully\n");

	// reads in character 1 by 1 and converts it to its integer value, stopping when it hits a tab at the end of the file
	while ((bufferOfDigits[bufferIndex] = (int)fgetc(filePointer)-48) != -39)
	{
		bufferIndex++;
	}
	
	// closes file THOUSAND_DIGIT_NUMBER
	fclose(filePointer);
	
	for (bufferIndex = 0; bufferIndex <= (NUMBER_ARRAY_SIZE-5-1); bufferIndex++)
	{
		for (fiveIndex = bufferIndex; fiveIndex < (bufferIndex + FIVE_ELEMENTS); fiveIndex++)
			candidateProduct *= bufferOfDigits[fiveIndex];

		if (candidateProduct > largestProduct)
			largestProduct = candidateProduct;

		candidateProduct = 1; //re-assigning to value of 1 so products dont aggregate
	}
	printf("The largest product of 5 consecutive numbers in the thousand digit number is: %d\n", largestProduct);
	
	return 0;
}




