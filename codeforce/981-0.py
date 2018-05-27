

def ishuiwen(str1):
	L = len(str1);

	ishuiwen = True;


	if (L%2 == 0):
		for i in range(L/2):
			if str1[i] != str1[L-i-1]:
				return False;
		return True;

	else:
		for i in range(L/2):
			if str1[i] != str1[L-i-1]:
				return False;
		return True;

str1 = raw_input();

L = len(str1);

ans = 0;
for i in range(L):
	#print str1[i:], ishuiwen(str1[i:])
	if not ishuiwen(str1[i:]):
		ans = L-i;
		break;

ans2 = 0;
str1 = str1[::-1]
for i in range(L):
	if not ishuiwen(str1[i:]):
		ans2 = L-i;
		break;

if (ans2 > ans):
	ans = ans2;
print ans;
