import math
a = float(input())
b = int(input())

a%=(math.pi*2)
res = a
c = a
for i in range(1, b+1):
	c = -(c*a*a)/((2*i)*(2*i+1))
	res += c
print(res)