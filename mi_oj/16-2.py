def solution(line):

    inputs = line.split(",")

    A = inputs[0]
    B = inputs[1]

    A = sorted(A)
    B = sorted(B)

    if (len(A) != len(B)):
        return "NO"

    dictA = {}
    dictB = {}

    for i in range(len(A)):
        if dictA.has_key(A[i]):
            dictA[A[i]] = dictA[A[i]] + 1
        else:
            dictA[A[i]] = 1

        if dictB.has_key(B[i]):
            dictB[B[i]] = dictB[B[i]] + 1
        else:
            dictB[B[i]] = 1
    if len(dictA) != len(dictB):
        return "NO"

    countA = []
    countB = []
    for k in dictA:
        countA.append(dictA[k]);
    for k in dictB:
        countB.append(dictB[k]);

    countA.sort()
    countB.sort()

    for i in range(len(countA)):
        if (countA[i] != countB[i]):
            return "NO"

    return "YES"


print solution("GUJYETEEQHGOTCZSSCFIBQYVRWQQJCVPTRBEAKKUIYXMPNRIZJBJKQXDDWWZGVRWLABIUINAUOGTUMRF,GTGRVGAANILHIJCMFNUHIASQUVKTTZOQJMMTPFYXEQCHIWLVPAPRRPHVLZXKRZOGDDNIVYFRXBOEAWNM")