str1 = raw_input();


N = int(str1.split(" ")[0])
M = int(str1.split(" ")[1])

A = []
for i in range(N):
	str1 = raw_input();
	AA = []
	for v in str1:
		AA.append(v)
	A.append(AA)

B = []

for i in range(N):
	BB = []
	for j in range(M):
		if (A[i][j] == "*"):
			BB.append("*")
		else:
			BB.append(".")
	B.append(BB)


for i in range(N):
 	for j in range(M):
 		if (B[i][j] == "*"):
 			if(i-1 >= 0 and j - 1 >= 0):
 				if(B[i-1][j-1] == "."):
 					B[i-1][j-1] = 1
 				elif (B[i-1][j-1] != "*"):
 					B[i-1][j-1] = B[i-1][j-1] + 1
 			if(i-1 >= 0):
 				if(B[i-1][j] == "."):
 					B[i-1][j] = 1
 				elif (B[i-1][j] != "*"):
 					B[i-1][j] = B[i-1][j] + 1
 			if(i-1 >= 0 and j + 1 < M):
 				if(B[i-1][j+1] == "."):
 					B[i-1][j+1] = 1
 				elif (B[i-1][j+1] != "*"):
 					B[i-1][j+1] = B[i-1][j+1] + 1
 			if(j + 1 < M):
 				if(B[i][j+1] == "."):
 					B[i][j+1] = 1
 				elif (B[i][j+1] != "*"):
 					B[i][j+1] = B[i][j+1] + 1
 			if(i + 1 < N and j + 1 < M):
 				if(B[i+1][j+1] == "."):
 					B[i+1][j+1] = 1
 				elif (B[i+1][j+1] != "*"):
 					B[i+1][j+1] = B[i+1][j+1] + 1
 			if(i + 1 < N):
 				if(B[i+1][j] == "."):
 					B[i+1][j] = 1
 				elif (B[i+1][j] != "*"):
 					B[i+1][j] = B[i+1][j] + 1
 			if(i + 1 < N and j - 1 >=0):
 				if(B[i+1][j-1] == "."):
 					B[i+1][j-1] = 1
 				elif (B[i+1][j-1] != "*"):
 					B[i+1][j-1] = B[i+1][j-1] + 1
 			if(j -1 >=0):
 				if(B[i][j-1] == "."):
 					B[i][j-1] = 1
 				elif (B[i][j-1] != "*"):
 					B[i][j-1] = B[i][j-1] + 1

for i in range(N):
 	for j in range(M):
 		if (B[i][j] != "*" and B[i][j] != "."):
 			B[i][j] = str(B[i][j])

flag = True
for i in range(N):
 	for j in range(M):
 		if (A[i][j] != B[i][j]):
 			flag = False
 			break

if (flag):
	print "YES"
else:
	print "NO"
