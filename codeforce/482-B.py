

str = raw_input();

N = int(str)

str1 = raw_input();
str2 = raw_input();
str3 = raw_input();

S = len(str1);

if N >= S and S < 52:
	print "Draw"
else:

	max1 = 0
	max2 = 0
	max3 = 0


	MyMap1 = {}
	for i in range(S):
		if MyMap1.has_key(str1[i]) :
			MyMap1[str1[i]] = MyMap1[str1[i]] + 1
		else :
			MyMap1[str1[i]] = 1
	for k,v in MyMap1.iteritems():
		if v + N < S:
			if max1 < v+N:
				max1 = v+N
		else:
			if max1 < 2*S -N -v:
				max1 =  2*S -N -v

	MyMap2 = {}
	for i in range(S):
		if MyMap2.has_key(str2[i]) :
			MyMap2[str2[i]] = MyMap2[str2[i]] + 1
		else :
			MyMap2[str2[i]] = 1
	for k,v in MyMap2.iteritems():
		if v + N < S:
			if max2 < v+N:
				max2 = v+N
		else:
			if max2 < 2*S -N -v:
				max2 =  2*S -N -v

	MyMap3 = {}
	for i in range(S):
		if MyMap3.has_key(str3[i]) :
			MyMap3[str3[i]] = MyMap3[str3[i]] + 1
		else :
			MyMap3[str3[i]] = 1

	for k,v in MyMap3.iteritems():
		if v + N < S:
			if max3 < v+N:
				max3 = v+N
		else:
			if max3 < 2*S -N -v:
				max3 =  2*S -N -v

	print max1
	print max2
	print max3

	if (max1 > max2 and max1 > max3 ) :
		print "Kuro"

	elif (max2 > max1 and max2 > max3 ) :
		print "Shiro"
	elif (max3 > max2 and max3 > max1) :
		print "Katie"
	else :
		print "Draw"