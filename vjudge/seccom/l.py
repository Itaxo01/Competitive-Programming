def gcd(a, b):
	if(a == 0):
		return b
	return gcd(b%a, a)


t = int(input())
cases = 1
for _ in range(t):
	a, b, c = map(int, input().split())
	if(c%gcd(a, b) == 0):
		print(f"Cases {cases}: Yes")
	else:
		print(f"Cases {cases}: No")
	cases+=1;	