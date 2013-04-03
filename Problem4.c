// --------------------------------------------------------------
// ASSIGNMENT: A palindromic number reads the same both ways.
// 			   The largest palindrome made from the product 
// 			   of two 2-digit numbers is 9009 = 91 × 99. Find
// 			   the largest palindrome made from the product 
// 			   of two 3-digit numbers.
// --------------------------------------------------------------

#include <stdio.h>
#define UPPER_LIMIT 999
#define LOWER_LIMIT 100
#define TRUE 1
#define FALSE 0

// prototype for evaluatePalindrome, returns integer 1 if true, 0 if false.
int evaluatePalindrome(int palindromeCandidate);

int main (void)
{
	int palindromeCandidate=0;
	int largestPalindrome=0;
	int outsideCounter;
	int insideCounter;

	// counts up from LOWER_LIMIT to UPPER_LIMIT
	for (outsideCounter=LOWER_LIMIT; outsideCounter<=UPPER_LIMIT; outsideCounter++)
	{
 		// counts up from LOWER_LIMIT to UPPER_LIMIT
 		for (insideCounter=LOWER_LIMIT; insideCounter<=UPPER_LIMIT; insideCounter++)
 		{
 			// takes current value for inside and outside counter and finds product
 			palindromeCandidate = insideCounter * outsideCounter;

 			// function call inside an if statement to see if current value computed above is a palindrome
 			if (evaluatePalindrome(palindromeCandidate)&&(palindromeCandidate>largestPalindrome))
 			{
 					largestPalindrome = palindromeCandidate;
 			}
 		}
 	}
 
 	printf("The largest palindrome produced by the product of two 3 digit numbers is: %d\n", largestPalindrome);
 	return 0;
}

// ----------------------evaluatePalindrome----------------------
// Purpose: returns a 1 or 0 depending on if argument is a
// 			palindrome
// Parameters: int palindromeCandidate
// --------------------------------------------------------------
int evaluatePalindrome(int palindromeCandidate)
{
	int digit;
	int temporaryPalindromeCandidate = palindromeCandidate;
	int reversedNumber=0;

	while (temporaryPalindromeCandidate)// aka not equal to zero, true
	{
		// takes digits off palindromeCandidate from right to left
		digit = (temporaryPalindromeCandidate%10);
	
		// pushes right-hand-side digits to the left while adding most current digit into ones place
		reversedNumber = (reversedNumber*10) + digit;
	
		// takes off the right-most digit each iteration, ones place is removed
		temporaryPalindromeCandidate /= 10;
	}
	if (palindromeCandidate==reversedNumber)
		return TRUE;
	else
		return FALSE;
}
