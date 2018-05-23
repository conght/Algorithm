def Gcd(a, b):

    if(a < b) :
        temp = a;
        a = b;
        b = temp;
        
    while(a%b != 0) :
            temp = a%b;
            a = b;
            b = temp;
    #printf 'max : ', b;
    return b;


str1 = raw_input();

N = int(str1)

for i in range(N):
    str1 = raw_input();
    str1 = str1.strip()
    p = int(str1.split(" ")[0])
    q = int(str1.split(" ")[1])
    b = int(str1.split(" ")[2])

    if p == 0:
        print "Finite"
        continue
    d = Gcd(p, q)
    p = p/d 
    q = q/d

    p = p%q
    if (p == 0) :
        print "Finite"
    else:
        b = Gcd(q, b)
        while b != 1:
            while (q%b == 0):
                q = q/b
            b = Gcd(q, b)

        if (q != 1):
            print "Infinite"
        else:
            print "Finite"