
#http://codeforces.com/contest/983/submission/38313655

str1 = raw_input();
N = int(str1)

str1 = raw_input();
A = map(int, str1.split(" "))

D = [[0 for i in range(N+1)] for i in range(N+1)]

for i in range(N):
	D[0][i] = A[i]

for i in range(1, N):
	for j in range(N-i):
		D[i][j] = D[i-1][j]^D[i-1][j+1]

for i in range(1, N):
	for j in range(N-i):
		D[i][j] = max(D[i][j], max(D[i-1][j],D[i-1][j+1]))

str1 = raw_input();
Q = int(str1)

#print D
for i in range(Q):
	str1 = raw_input();
 	l = int(str1.split(" ")[0])
 	r = int(str1.split(" ")[1]) 
 	print D[r-l][l-1]