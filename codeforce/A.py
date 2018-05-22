

str = raw_input();  


M = 0;
N = 0;

for i in range(len(str)):
	if str[i] == '-':
		M = M + 1;
	if str[i] == 'o':
		N = N + 1;

if N == 0:
	print "YES"
elif (M >= N and M%N == 0):
	print "YES"
elif M == 0:
	print "YES"
else :
	print "NO"