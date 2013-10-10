import math

def binomialExpansion(nDimension):
	outerEdgeTot = 2*nDimension
	numerator = math.factorial(outerEdgeTot)
	denominator = math.factorial(nDimension)
	denominator *= denominator

	return numerator/denominator

def main():
	latticePaths = binomialExpansion(input("Enter the N-Dimension of your NxN matrix: "))
	print("Number of lattice paths: " + repr(latticePaths))

main()