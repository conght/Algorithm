def MyMax(a, b):
	if (a > b ):
		return a
	return b

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

for d in range(1,S+1):
	for i in range(0, S-d+1):
		#print d, i
		if (d == 1):
			D[i][i+d-1] = A[i]
		else:
			for j in range(i+1,i+d):
				
				temp = MyMax(D[i][j-1], D[j][i+d-1])
				D[i][i+d-1] = MyMax(temp, D[i][i+d-1])
			D[i][i+d-1] = MyMax(MyFunc(A, i, d+i), D[i][i+d-1])
				
#print D

str1 = raw_input();
Q = int(str1)

for i in range(Q):
	str1 = raw_input();
 	a = int(str1.split(" ")[0])
 	b = int(str1.split(" ")[1]) 
 	print D[a-1][b-1]