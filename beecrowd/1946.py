while(True):
	try:
		n = int(input());
		n-=1;
		p = n;
		div = 1;
		total = 1.0;
		increment = 0;
		while(n>div):
			total = (total*n)/div;
			div+=1;
			n-=1;
			if(increment<=p):
				increment+=1;
				total/=2;
			
		print(total);
	except EOFError:
		break