n, m = map(int, input().split())

strings = []
for _ in range(n):
	s = input()
	strings.append(s)


t = 0
for _ in range(m):
	k = int(input())
	t = (t+k)%len(strings)
	print(strings[t])
	t = (t+1)%len(strings)