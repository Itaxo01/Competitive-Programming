max_x = 0
min_x = 0
max_y = 0
min_y = 0
max_xc = 0
min_xc = 0
max_yc = 0
min_yc = 0

for i in range(10):
	x, y = map(float, input().split())
	if(i == 0):
		max_x = x
		min_x = x
		max_y = y
		min_y = y
		max_xc = 1
		min_xc = 1
		max_yc = 1
		min_yc = 1
	if(x < min_x):
		min_x = x
		min_xc = 1
	elif(x == min_x):
		min_xc+=1

	if(x > max_x):
		max_x = x
		max_xc = 1
	elif(x == max_x):
		max_xc+=1

	if(y < min_y):
		min_y = y
		min_yc = 1
	elif(y == min_y):
		min_yc+=1

	if(y > max_y):
		max_y = y
		max_yc = 1
	elif(y == max_y):
		max_yc+=1

if(max_xc <= 2 and min_xc <= 2 and max_yc <= 2 and min_yc <= 2):
	print("VINYL")
else:
	print("CASSETTE")
	

