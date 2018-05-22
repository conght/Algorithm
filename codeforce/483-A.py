str = raw_input();

N = int(str)

str = raw_input();

AStr = str.split(" ")

A = []
for i in AStr:
	A.append(int(i))

A.sort()
A.reverse()

S = len(A)

#print A
if (S%2 == 0):
	print A[S/2]
else:
	print A[S/2]