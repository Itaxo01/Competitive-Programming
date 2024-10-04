n = int(input())
for _ in range(n):
	s = [*input()]
	new_s = ""
	anterior = ""
	if(s[0]!=s[1]):
		new_s += s[0]+s[0]
	else:
		new_s += s[0]
	for e in range(1, len(s)-2):
		if(s[e]!=s[e-1] and s[e]!=s[e+1]):
			new_s += s[e]+s[e]
		else:
			new_s += s[e]
	if(s[len(s)-2]!=s[len(s)-3]):
		new_s += s[len(s)-2]+s[len(s)-2]
	else:
		new_s += s[len(s)-2]
	print(new_s)
