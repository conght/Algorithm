

str = raw_input();

N = int(str)

str = raw_input();

if (len(str) < 3) :
	print 0

count = 0
result = 0
for i in range(2, len(str)) :
	if (str[i] == 'x') and str[i-1 - count] == 'x' and str[i-2 - count] == 'x':
		count = count + 1
		result = result + 1
	else:
		count = 0

print result
