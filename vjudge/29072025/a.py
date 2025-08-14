n = int(input())
b = "o-----------------------o"
c1 = "|           ><>         |"
c2 = "|                       |"

print(b)
c = 0
for i in range(13):
	if(c < n):
		c+=1
		print(c1)
	else:
		print(c2)
print(b)