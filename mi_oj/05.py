
def solution(line):

    inputs = line.split(",")
    inputs_len = len(inputs)

    inputs = map(int, inputs)

    if inputs_len == 1:
        print inputs[0]
        return

    flag = True
    for index in range(inputs_len):
        if index == 0 :
            continue
        if inputs[index-1] > inputs[index]:
            flag = False

    if (flag):
        print str(inputs[inputs_len/2])
        return

    flag = True
    for index in range(inputs_len):
        if index == 0 :
            continue
        if inputs[index-1] < inputs[index]:
            flag = False
    if (flag):
        print str(inputs[inputs_len/2])
        return

    left = True

    if inputs[0] > inputs[1]:
        for index in range(inputs_len):
            if index == 0:
                continue
            if inputs[index] > inputs[index-1]:
                print str(inputs[(index+inputs_len/2)%inputs_len])
                return

    if inputs[0] < inputs[1]:
        for index in range(inputs_len):

            if index == 0:
                continue
            if inputs[index] < inputs[index-1]:
                print str(inputs[(index+inputs_len/2)%inputs_len])
                return


#solution("12,13,14,5,6,7,8,9,10")
solution("1,2,3")