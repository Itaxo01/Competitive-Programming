n = int(input())
x = []
y = []
for _ in range(n):
	a, b = map(int, input().split())
	x.append(a)
	y.append(b)

sum = 0
j = n-1
for i in range(n):
	sum+= (x[j]+x[i])*(y[j]-y[i])
	j = i
print(abs(sum))