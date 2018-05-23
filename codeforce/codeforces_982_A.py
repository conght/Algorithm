

# contest http://codeforces.com/contest/982/problem/A

def f(seats):
    if len(seats) == 1:
        if seats == "1":
            return "Yes"
        else:
            return "No"

    if seats[0] == '1' and seats[-1] == '1':
        return f(seats[2:])
    else:
        return "No"

def solution(line1, line2):
    N = int(line1)
    seats = line2

    if (N%2 == 0):
        if seats[0] == '1' and seats[-1] == '0':
            return f(seats[0:-1])
        elif seats[0] == '0' and seats[-1] == '1':
            return f(seats[1:])
        else:
            return "No"

    else:
        return f(seats)

def solution2(line2):

    if line2 == '0':
        return "No"
    if line2[-2:] == "00":
        return "No"
    first_one_index = 0
    for i in range(len(line2)):
        if line2[i] == '1':
            first_one_index = i
            break
    if first_one_index > 1:
        return "No"

    line2 = line2[first_one_index+1:]

    last_is_zero = False
    zero_count = 0
    one_count = 1
    for i in range(len(line2)):
        c = line2[i]
        if c == '0':
            if last_is_zero == False:
                zero_count = 1
                one_count = 0
                last_is_zero = True
            elif zero_count > 1:
                return "No"
            else:
                zero_count = zero_count + 1
        elif c == '1':
            if last_is_zero == True:
                zero_count = 0
                one_count = 1
                last_is_zero = False
            else:
                return "No"
    return "Yes"

line1 = raw_input();
line2 = raw_input();

print solution2(line2)