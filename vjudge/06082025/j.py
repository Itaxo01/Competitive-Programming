n = int(input())
d = {}

maior = 0
for _ in range(n):
	s = input().split()
	s = [int(e) for e in s[1:len(s)]]
	k = 0
	for i in s:
		if(i not in d):
			k+=1
			d[i] = 1
	maior = max(maior, k)
print(maior)