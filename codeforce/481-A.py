

str = raw_input();

N = int(str)

str = raw_input();

NumbersStrArray = str.split(" ")

result = []

MyMap = {}
for i in range(len(NumbersStrArray)) :
	if MyMap.has_key(NumbersStrArray[len(NumbersStrArray) - i - 1]) :
		continue
	else :
		MyMap[NumbersStrArray[len(NumbersStrArray) - i - 1]] = 1
		result.append(NumbersStrArray[len(NumbersStrArray) - i - 1])
	#MyMap.add(NumbersStrArray[len(NumbersStrArray) - i - 1])

result_str = ""
for i in range(len(result)) : 
	result_str = result_str + result[len(result) - i - 1] + " "
result_str = result_str[:-1]

print len(result)
print result_str
