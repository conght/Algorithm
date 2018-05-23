def solution(line):

    input_str = line.split(" ")
    number_str = input_str[0]
    d = int(input_str[1])
    a = number_str.split(",")

    a = map(int, a)

    start = 0
    a_len = len(a)
    end = a_len - 1

    while end > start:
        middle = start + ((end-start+1) >> 1)
        if d == a[middle]:
            return middle

        if d > a[start] and d < a[middle]:
            end = middle - 1
        else:
            start = middle + 1

    if d == a[end]:
        return end
    else:
        return -1

print solution("4,5,6,7,0,1,2 8")