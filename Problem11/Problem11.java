// -------------------------------------------------------------------------------------------------
// ASSIGNMENT: In the 20×20 grid in Product_Grid.txt, what is the greatest product of four adjacent
// 			   numbers in the same direction (up, down, left, right, or diagonally)?
// -------------------------------------------------------------------------------------------------
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.File;
import java.util.Scanner;

/**
* @author Conor O'Shaughnessy, coshaugh1@gmail.com
* @version v1.0
* @since 12/13/13
*/
public class Problem11
{
	private int[][] grid;
	
	/**
	* main runs the program execution
	* @param String
	* @throws IOException
	*/
	public static void main(String args[]) throws IOException
	{
		Problem11 run = new Problem11();
		run.readFile();
		int max = run.findMaxProd();
		System.out.println(max);
	}

	/**
	* Problem11 constructor, initializes 2d array
	*/
	public Problem11()
	{
		grid = new int[20][20];
	}

	/**
	* readFile fills 2d array from file "Product_Grid.txt"
	* @throws IOException
	*/
	public void readFile() throws IOException
	{
		Scanner inputStream = null;
		int lineCounter = 0;

		try
		{
			inputStream = new Scanner(new File("Product_Grid.txt"));
		}
		catch(FileNotFoundException e)
		{
			System.out.println("ERROR: " + e);
		}

		while(inputStream.hasNextLine())
		{
			String line = inputStream.nextLine();
			String[] lineElements = line.split("[ ]+");
			for(int i = 0; i < 20; i++)
				grid[lineCounter][i] = Integer.parseInt(lineElements[i]);
			lineCounter++;
		}
		inputStream.close();
	}

	/**
	* findMaxProd returns the max product(horizontal, vertical, and left/right diagonals) of 4 adjacent array elements
	* @return int
	*/
	public int findMaxProd()
	{
		int prod_M  = 0;
		int prod_H  = 0;
		int prod_V  = 0;
		int prod_RD = 0;
		int prod_LD = 0;
		for(int p = 0; p < 16; p++)
		{
			for(int j = 0; j < 16; j++)
			{
				prod_H  = grid[p][j]   * grid[p][j+1]   * grid[p][j+2]   * grid[p][j+3]; // horizontal product
				prod_V  = grid[p][j]   * grid[p+1][j]   * grid[p+2][j]   * grid[p+3][j]; // vertical product
				prod_RD = grid[p][j]   * grid[p+1][j+1] * grid[p+2][j+2] * grid[p+3][j+3]; // right diagonal product
				prod_LD = grid[p][j+3] * grid[p+1][j+2] * grid[p+2][j+1] * grid[p+3][j]; // left diagonal product
				if(prod_M < prod_H)
					prod_M = prod_H;
				if(prod_M < prod_V)
					prod_M = prod_V;
				if(prod_M < prod_RD)
					prod_M = prod_RD;
				if(prod_M < prod_LD)
					prod_M = prod_LD;
			}	
		}
		return prod_M;
	}
}