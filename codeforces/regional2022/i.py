def solve(a):
	for i in a:
		if(i == 9):
			return False
	return True


a = map(int, input().split())
if(solve(a)):
	print("S")
else:
	print("F")