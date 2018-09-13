
common = {}
common["f"] = 15
common["e"] = 14
common["d"] = 13
common["c"] = 12
common["b"] = 11
common["a"] = 10
common["9"] = 9
common["8"] = 8
common["7"] = 7
common["6"] = 6
common["5"] = 5
common["4"] = 4
common["3"] = 3
common["2"] = 2
common["1"] = 1
common["0"] = 0

common1 = {}
common1[15] = "f"
common1[14] = "e"
common1[13] = "d"
common1[12] = "c"
common1[11] = "b"
common1[10] = "a"
common1[9] = "9"
common1[8] = "8"
common1[7] = "7"
common1[6] = "6"
common1[5] = "5"
common1[4] = "4"
common1[3] = "3"
common1[2] = "2"
common1[1] = "1"
common1[0] = "0"
def solution(line):

    inputs = line.split(" ")
    
    A = (inputs[0])
    B = (inputs[1])
    C = (inputs[2])

    N = 0
    if (B != "10"):
        i = len(A)
        A1 = A[::-1]
        delta = 1
        for index in range(i):
            N = N + common[A1[index]] * delta
            delta = delta * int(B)
    else:
        N = int(A)

    res = ""
    while(N / int(C)):
        res = res + common1[(N % int(C))]
        N = N / int(C)
    if (N % int(C) != 0) :
        res = res + common1[(N % int(C))]

    res = res[::-1]

    return res
    
print solution("131c 16 15")