a = input()
b = input()
if(not a.lstrip('-').isnumeric() or not b.lstrip('-').isnumeric()):
	 print("Entrada inválida")
else:
	a = int(a)
	b = int(b)
	print("Início do intervalo:", a)
	print("Fim do intervalo:", b)
	print("Somatório do intervalo:", sum([i for i in range(min(a, b), max(a, b)+1)]))
	print("Metade do intervalo:", str((a+b)//2)+" e "+str((a+b+1)//2) if (b-a)%2 == 1 else str((a+b)//2))