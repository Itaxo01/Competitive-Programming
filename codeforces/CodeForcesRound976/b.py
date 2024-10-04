n = int(input())
for _ in range(n):
	a = int(input())
	k = a
	c = int((((1+4*a)**0.5)-1.01)//2)
	print(k+c+1)