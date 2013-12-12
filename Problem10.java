// ----------------------------------------------------------------
// ASSIGNMENT: The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17
// 			   Find the sum of all the primes below two million
// ----------------------------------------------------------------
import java.lang.Math;

public class Problem10
{
	public static void main(String[] args)
	{
		int approxPrimeNumbs = (int) ( 2500000/Math.log(2500000) ); // approximation so values are padded to avoid array out of bounds
		int[] arrayOfPrimes = new int[approxPrimeNumbs];

		arrayOfPrimes[0] = 1;
		arrayOfPrimes[1] = 2;

		int n = 1; // keeps track of total primes found, starting at 1 since we don't iterate through even values, thus skipping the even prime 2
		int p = 1; // surrogate prime value
		long sum = 2; // start at 2 since never iterate over singular even prime number '2'
		while(p < 2000000)
		{
			p+=2; // no primes are even, no need to iterate through even values
			int i;
			for(i = 2; i <= n; i++)
			{
				if((p % arrayOfPrimes[i]) == 0) // p is not primes, no need to continue
					break;
			}
			if(i > n && p < 2000000) // counter reached end of final iteration, a unique prime has been found
			{
				arrayOfPrimes[n+1] = p;
				n++;
				sum = sum + p;
			}
		}
		System.out.println(sum);
	}
}