

def MyFunc(A, a, b):
	B = A[a:b+1]
	while (len(B) > 1):
		C = []
		for i in range(0, len(B)-1):
			C.append(B[i]^B[i+1])
		print C
		B = C
	return B[0]


A = [1 ,2 ,4 ,8 ,16 ,32]


print MyFunc(A, 0, 5)