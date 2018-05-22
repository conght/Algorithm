
def MyMax(a, b ,c):
	if (a > b and a > c):
		return a
	if (b > a and b > c):
		return b
	return c

def MyFunc(A, a, b):
	B = A[a:b]
	#print B, a, b
	while (len(B) > 1):
		C = []
		for i in range(0, len(B)-1):
			C.append(B[i]^B[i+1])
		B = C
	return B[0]

str1 = raw_input();


N = int(str1)

str1 = raw_input();
A = str1.split(" ")

for i in range(len(A)):
	A[i] = int(A[i])

S = len(A)
D = []
for i in range(S):
	DD = []
	for j in range(S):
		DD.append(0)
	D.append(DD)

#for i in range(S):
#	D[i][0] = A[i]

for d in range(1,S+1):
	for i in range(0, S-d+1):
		#print d, i
		if (d == 1):
			D[i][i+d-1] = A[i]
		else:
			for j in range(i+1,i+d-1):
				D[i][i+d-1] = MyMax(D[i][j-1], MyFunc(A, i, d+i), D[j][i+d-1])
		#for j in range(i, i+d):
		#	print d, i, j
	#for j in range(1, S):
	#	D[i][j] = MyMax(D[i][j-1], MyFunc(A, i, j), A[j])

print D
str1 = raw_input();
Q = int(str1)

for i in range(Q):
	str1 = raw_input();
 	a = int(str1.split(" ")[0])
 	b = int(str1.split(" ")[1]) 
 	print D[a-1][b-1]
