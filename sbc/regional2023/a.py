n, h = map(int, input().split())
v = map(int, input().split())
c = 0
for e in v:
	if(h >= e):
		c+=1

print(c)