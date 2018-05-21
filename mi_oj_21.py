def find(a,b,k):
    if k==0:
        return ''
    la=len(a)
    lb=len(b)
    ra=la-max(0,k-lb-1)
    rb=lb-max(0,k-la-1)
    nowa=-1
    pa=-1
    nowb=-1
    pb=-1
    for i in range(ra):
        if a[i]>nowa:
            nowa=a[i]
            pa=i
    for i in range(rb):
        if b[i]>nowb:
            nowb=b[i]
            pb=i
    print ra, rb, nowa, nowb
    if nowa>nowb:
        return str(nowa)+find(a[pa+1:],b,k-1)
    elif nowa<nowb:
        return str(nowb)+find(a,b[pb+1:],k-1)
    else:
        return str(nowa)+max(find(a[pa+1:],b,k-1),find(a,b[pb+1:],k-1))
def solution(line):
    a=[int(x) for x in line.split(' ')[0].split(',')]
    b=[int(x) for x in line.split(' ')[1].split(',')]
    c=int(line.split(' ')[2])
    return find(a,b,c)

#print range(3)
print solution("6,3,8,9,4,6,0 3,5,7 6")