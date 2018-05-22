from math import log
from math import e

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


def solution3(M):
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
def solution(line):
    N = int(line)
    return str(solution3(N))

print solution(45642466)