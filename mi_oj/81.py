def solution(line):
    
    A = line.split(",")[0]
    B = line.split(",")[1]

    if len(A) != len(B):
        return 0

    a_len = len(A)
    my_dict = {}
    for i in range(a_len):
        if my_dict.has_key(A[i]):
            if (B[i] != my_dict[A[i]]):
                return 0
        else:
            my_dict[A[i]] = B[i]

    return 1


print solution("aaa,aba")