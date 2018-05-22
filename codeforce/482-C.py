str = raw_input();

N = int(str.split(" ")[0])
X = int(str.split(" ")[1])
Y = int(str.split(" ")[2])


router = []
for i in range(N+1) :
	router.append([])
for i in range(N-1) :
	path = raw_input();
	a = int(path.split(" ")[0])
	b = int(path.split(" ")[1])
	if not (a == X and b == Y):
		router[a].append(b)
	if not (a == X and b == Y):
		router[b].append(a)

print router