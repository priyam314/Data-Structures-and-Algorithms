import sys
def reversed(a):
	a.reverse()
	return " ".join(a)
print(reversed(sys.argv[1:]))
