a, b = map(int, input().split())
m = []
for _ in range(a):
    m+= [0]
for _ in range(b):
    c, d = map(int, input().split())
    m[c-1] = 1
    for i in range(c, 0, -d):
        m[i-1] = 1
    for i in range(c, a+1, d):
        m[i-1] = 1
for i in m:
	print(i)