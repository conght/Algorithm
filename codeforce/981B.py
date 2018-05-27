

valuemap = {}

N = int(raw_input());
while(N>0):
	str1 = raw_input();
	index = int(str1.split(" ")[0])
	value = int(str1.split(" ")[1])

	if not valuemap.has_key(index):
		valuemap[index] = value;
	else:
		if value > valuemap[index]:
			valuemap[index] = value;
	N = N -1;

M = int(raw_input());

while(M>0):
	str1 = raw_input();
	index = int(str1.split(" ")[0])
	value = int(str1.split(" ")[1])

	if not valuemap.has_key(index):
		valuemap[index] = value;
	else:
		if value > valuemap[index]:
			valuemap[index] = value;
	M = M -1;

ans = 0;
for key in valuemap:
	ans = ans + valuemap[key];

print ans;