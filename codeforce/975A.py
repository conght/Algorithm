# contest http://codeforces.com/contest/975/problem/A

N = int(raw_input())

str1 = raw_input()

arr = str1.split(" ")

root = {}

for item in arr:
    s = set()
    for c in item:
        s.add(c)
    li = list(s)
    li.sort()
    key = ''.join(li)
    if root.has_key(key):
        continue
    else:
        root[key] = 1

print len(root)