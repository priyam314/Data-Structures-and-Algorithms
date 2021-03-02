from sys import argv
def candiesDistribute(candyType,n):
	return min(len(set(candyType)),n//2)
print(candiesDistribute(argv[1:],len(argv[1:])))
