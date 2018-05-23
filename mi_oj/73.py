
def solution(line):
    lists = line.split(",")

    if len(lists) == 0:
        return 0

    A = map(int, lists)

    bits = []
    for i in range(32):
        bits.append(0)

    for item in A:
        for i in range(32):
            cb = item & 1
            if cb == 1:
                bits[i] = bits[i] + 1
            item = item >> 1

    result = 0
    for i in range(32):

        if not bits[i]%3 == 0:
            result = result + (1<<i)

    return result

print solution("2,3,2,2")
