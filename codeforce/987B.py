
import math

str1 = (raw_input())

X = int(str1.split(" ")[0])
Y = int(str1.split(" ")[1])

x = math.log(X)*Y
y = math.log(Y)*X
if (x > y ):
	print '>'
elif (x < y):
	print '<'
else:
	print '='
