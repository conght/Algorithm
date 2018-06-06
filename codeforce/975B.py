

arr = map(int, (raw_input()).split(" "))

ans = 0

for i in range(14):
	item = arr[i]

	n = item/14
	c = item%14

	sum_ = 0
	for j in range(14):
		temp = 0
		if j != i:
			temp = temp + arr[j]
		temp = temp + n
		if i+c<14 and j<=(i+c) and j>i:
			temp = temp + 1
		elif i+c >= 14 and (j > i or j <= (i+c)%14):
			temp = temp + 1
		if temp %2 == 0:
			sum_ = sum_ + temp

	if sum_ > ans:
		ans = sum_

print ans