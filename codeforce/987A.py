
mdict = {}

mdict['purple'] = 'Power'
mdict['green'] = 'Time'
mdict['blue'] = 'Space'
mdict['orange'] = 'Soul'
mdict['red'] = 'Reality'
mdict['yellow'] = 'Mind'

N = int(raw_input())

for i in range(N):
	key = raw_input();
	mdict[key] = '';

print (6 - N);
for key in mdict:
	if (mdict[key] != ''):
		print mdict[key]