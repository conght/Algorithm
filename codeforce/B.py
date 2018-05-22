

str = raw_input();  

N = int(str.split(" ")[0])
K = int(str.split(" ")[1])

possible = False

if (K % 2 == 0):
	if N-2 >= K/2:
		possible = True
		print "YES"
		print '.'*N;
		print '.'+'#'*(K/2)+'.'*(N-K/2-1)
		print '.'+'#'*(K/2)+'.'*(N-K/2-1)
		print '.'*N;
	else:
		print "NO"
else:
	if K <= N - 2:
		possible = True
		print "YES"
		print '.'*N;
		print '.'+'#'*(K)+'.'*(N-K-1)
		print '.'*N;
		print '.'*N;
	else:
		print "YES"
		print '.'*N;
		print '.'+'#'*(N-2)+'.'
		print '.'+'#'*((K-N+2)/2)+'.'*(N-2-(K-N+2))+'#'*((K-N+2)/2)+'.';
		print '.'*N;

		