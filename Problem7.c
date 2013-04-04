// --------------------------------------------------------------
// ASSIGNMENT: By listing the first six prime numbers: 
// 			   2, 3, 5, 7, 11, and 13, we can see that the 6th 
// 			   prime is 13.
// 			   What is the 10,001st prime number?
// --------------------------------------------------------------

#include <stdio.h>
#define ROWS 10 // 105 for real problem
#define COLUMNS 10 // 10000 for real problem
#define TARGET_PRIME 10001

// Function Prototypes
void fill_2D_ArrayOfIntegers(int filledArray[][COLUMNS]);
void seiveOfEratosthenes(int arrayToPrint[][COLUMNS]);
void setNonPrimesToZero(int filledArray[][COLUMNS], int row, int column);
void countPrimeNumbers(int arrayToPrint[][COLUMNS]);
void print_2D_ArrayOfIntegers(int arrayToPrint[][COLUMNS]);

int main (void)
{
	int targetPrimeNumber;
	int targetCounter=1;// this will count up to 10,001
	int arrayOfIntegers[ROWS][COLUMNS] = {0};
	fill_2D_ArrayOfIntegers(arrayOfIntegers);// fills newley created array
	/*
	WARNING: IF YOU HAVE A MASSIVE ARRAY YOU MAY WANT TO RECONSIDER PRINTING,
			 ONLY FORMATTED TO HANDLE UP TO 3 DIGITS(999).
	print_2D_ArrayOfIntegers(arrayOfIntegers);
	*/
	seiveOfEratosthenes(arrayOfIntegers);
	countPrimeNumbers(arrayOfIntegers);

	return 0;
}// end main

// ----- fill_2D_ArrayOfIntegers --------------------------------
// fill_2D_ArrayOfIntegers function
// Purpose: to fill the elements of a 2-d array declared in main,
// 			and return a pointer to that array
// Parameters: int *filledArray
// --------------------------------------------------------------
void fill_2D_ArrayOfIntegers(int filledArray[][COLUMNS])
{
	int arrayElementFiller = 1;
	int rowCounter;
	int columnCounter;

	// counts through designated number of rows
	for (rowCounter = 0; rowCounter < ROWS; rowCounter++)
	{
		// counts through designated number of columns
		for (columnCounter = 0; columnCounter < COLUMNS; columnCounter++)
		{
			filledArray[rowCounter][columnCounter] = arrayElementFiller;
			arrayElementFiller++;
		}
	}
	filledArray[0][0]=0; // assigns first element in array from one to zero, avoids problems with seive fcn.
}

// ----- seiveOfEratosthenes ------------------------------------
// seiveOfEratosthenes function
// Purpose: to set all non-prime numbers in 2-d array to zero by
//			going through and marking all increments of variable
//			seiveNumber: 2*seiveNumber, 3*seiveNumber, etc.
//			https://en.wikipedia.org/wiki/File:Sieve_of_Eratosthenes_animation.gif
// Parameters: int *filledArray
// --------------------------------------------------------------
void seiveOfEratosthenes(int filledArray[][COLUMNS])
{	
	int rowCounter;
	int columnCounter;

	// counts through designated number of rows
	for (rowCounter = 0; rowCounter < ROWS; rowCounter++)
	{
		// counts through designated number of columns, starting at 2
		for (columnCounter = 0; columnCounter < COLUMNS; columnCounter++)
		{
			// if slot in 2-d array NOT empty
			if (filledArray[rowCounter][columnCounter] != 0)
			{
				setNonPrimesToZero(filledArray, rowCounter, columnCounter);
			}
		}
	}
}

// ----- setNonPrimesToZero -------------------------------------
// setNonPrimesToZero function
// Purpose: to set all non primes to 0
// Parameters: int *filledArray, int row, int column
// --------------------------------------------------------------
void setNonPrimesToZero(int filledArray[][COLUMNS], int row, int column)
{
	int primeNumber = filledArray[row][column];
	int rowCounter;
	int columnCounter;

	// counts through designated number of rows, starts at 'rows' to lower runtime
	for (rowCounter = row; rowCounter < ROWS; rowCounter++)
	{
		// counts through designated number of columns, cant start at 'column' like above loop starts at rows since will
		// never include full column after one iteration of outside loop
		for (columnCounter = 0; columnCounter < COLUMNS; columnCounter++)
		{
			//test to see if element is divisible by primeNumber
			if ((filledArray[rowCounter][columnCounter] % primeNumber) == 0
					&& (filledArray[rowCounter][columnCounter] != primeNumber))
			{
				filledArray[rowCounter][columnCounter] = 0;
			}
		}
	}
}

// ----- countPrimeNumbers -------------------------------------
// countPrimeNumbers function
// Purpose: to count prime numbers in designated array, and to
//			print a designated prime'th number from within that
//			specified by macro TARGET_PRIME
// Parameters: int *arrayOfPrimes
// --------------------------------------------------------------
void countPrimeNumbers(int arrayOfPrimes[][COLUMNS])
{
	int numberOfPrimes=0;
	int rowCounter;
	int columnCounter;

	// counts through designated number of rows
	for (rowCounter = 0; rowCounter < ROWS; rowCounter++)
	{
		// counts through designated number of columns, starting at 2
		for (columnCounter = 0; columnCounter < COLUMNS; columnCounter++)
		{
			// if slot in 2-d array NOT empty
			if (arrayOfPrimes[rowCounter][columnCounter] != 0)
			{
				numberOfPrimes++;
				if (numberOfPrimes==TARGET_PRIME)
				{
					printf("The %d'st prime number is: %d\n", TARGET_PRIME, arrayOfPrimes[rowCounter][columnCounter]);	
				}
			}
		}
	}
	printf("The number of primes in the array is: %d\n", numberOfPrimes);
}

// ----- print_2D_ArrayOfIntegers -------------------------------
// print_2D_ArrayOfIntegers function
// Purpose: to print the elements of a 2-d array declared in main
//			and filled by fill_2D_ArrayOfIntegers in formatted
//			manner
// Parameters: int *arrayToPrint
// --------------------------------------------------------------
void print_2D_ArrayOfIntegers(int arrayToPrint[][COLUMNS])
{
	int rowCounter;
	int columnCounter;	

	// counts through designated number of rows
	for (rowCounter = 0; rowCounter < ROWS; rowCounter++)
	{
		// counts through designated number of columns
		for (columnCounter = 0; columnCounter < COLUMNS; columnCounter++)
		{
			// here to deal with the first row where numbers 1-9 are 1 digit and 10 is 2 digit
			if (arrayToPrint[rowCounter][columnCounter]<10)
			{
				printf(" %d  ", arrayToPrint[rowCounter][columnCounter]);
			}
			else if (arrayToPrint[rowCounter][columnCounter]<100)
			{
				printf("%d  ", arrayToPrint[rowCounter][columnCounter]);
			}
			else
				printf("%d ", arrayToPrint[rowCounter][columnCounter]);
		}
		printf("\n");
	}
}