from collections import deque

a, b, c = map(int, input().split())

M1 = deque(range(1, a+1))
M2 = deque(range(a, 0, -1))
contratados = []
while(len(M1)>2):
	M1.rotate(b)
	M2.rotate(c)
	if(M1[0] == M2[0]):
		contratados.append(M1[0])
		M1.popleft()
		M2.popleft()
	else:
		v1 = M1[0]
		v2 = M2[0]
		M1.popleft()
		M1.remove(v2)
		M2.popleft()
		M2.remove(v1)
for e in M1:
	contratados.append(e)
contratados.sort()
print(*contratados)