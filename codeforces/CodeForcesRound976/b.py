import math
n = int(input())
for _ in range(n):
	a = int(input())
	i = 0
	f = 2e18
	while(i<f):
		m = (i+f)//2
		t = m-math.floor(m**0.5)
		if(t>=a):
			f = m
		else:
			i = m+1
	print(int((i+f)//2))