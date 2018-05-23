

def solution2(n):

    my_map = {}
    res = n + 1;
    i = 1;
    while (i * i <= n):
        if (n % i == 0):
            my_map[n / i] = True;
        i = i+1;


    k = 2
    while(k<=n):
        q = 1;
        m = 1;
        while(m<32):
            q = q * k + 1;
            if (my_map.has_key(q) and n/q<k):
                return k;
            if (q > n):
                break;
            m = m + 1
        k = k+1


    return res;


def solution4(M):
    k = 2
    while (k<M+1):
        if (M%k == 0):
            k = k + 1
            continue
        if ((2*M) % (M%k) != 0):
            k = k+1
            continue
        r = M/(M%k)
        n = log(r*k)/log(k)
        l1 = pow(k, n)
        l = (1-l1)/(1-k)
        while l > r:
            n = n + 1
            l1 = l1*k
            l = (1-l1)/(1-k)
        if l == r:
            return k
        k = k + 1
    return k

def solution3(M):
    k = 2
    while (k<M+1):
        if (M%k == 0):
            k = k + 1
            continue
        if (M % (M%k) != 0):
            k = k+1
            continue
        r = M/(M%k)
        l1 = k
        l = (1-l1)/(1-k)
        while l < r:
            #n = n + 1
            l1 = l1*k
            l = (1-l1)/(1-k)
        if l == r:
            return k
        k = k + 1
    return k

from math import log
from math import e

def solution5(M):
    k = 2
    while (k<M+1):
        if (M%k == 0):
            k = k + 1
            continue
        if (M % (M%k) != 0):
            k = k+1
            continue
        r = M/(M%k)
        n = int(log(r)/log(k)+1)
        #print k, n
        l1 = pow(k, n)
        l = (1-l1)/(1-k)
        while l > r:
            #n = n + 1
            l1 = l1/k
            l = (1-l1)/(1-k)
        if l == r:
            return k
        k = k + 1
    return k

factors = [0]*100000

def FindK(leftlimit,target,m):
    left = leftlimit
    right = target;
    while (left <= right):
        k = (left + right) / 2;
    
        mul = pow(k, m);
        if (mul == -1):
            right = k - 1;
            continue;
        div = (mul - 1 )/ (k - 1);
        if (target == div):
            return k;
        elif (target < div):
            right = k - 1;
        else:
            left = k + 1;
    return -1;

def MinPureNum(n):
    res = n + 1
    cnt=0
    i = 1;
    while (i * i <= n):
        if (n % i == 0):
            factors[cnt] = n / i;
            cnt = cnt + 1;
        i = i + 1;

    i=0;
    while i < cnt:
        curfactor = factors[i];
        m = 1
        while m < 32:
            tempK = FindK(n/curfactor+1,curfactor, m);
            if (tempK != -1 and tempK < res):
                res = tempK;
            m = m + 1
        i = i + 1

    return res;

def solution(line):
    N = int(line)
    return str(MinPureNum(N))

#300print solution(45642466)
#print factors



def check(n, i):
    last_x = n % i
    n /= i
    while n > 0:
        x = n % i
        if x != last_x:
            return False
        last_x = x
        n /= i
    return True

def solution(line):
    n = int(line)
    ans = n - 1 if n > 2 else n + 1
    for i in range(2, int(n ** 0.5)+1):
        if n % i == 0:
            ans = n / i - 1
        if check(n, i):
            return str(i)
    return str(ans)