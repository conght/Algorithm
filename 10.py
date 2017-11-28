
def solution(line):

    if line == None:
        return None

    n = int(line)

    step = []

    for i in range(n+1):
        if i == 0:
            step.append(0)
            continue
        if i == 1:
            step.append(1)
            continue
        if i == 2:
            step.append(2)
            continue

        step.append(step[i-2]+step[i-1])

    return step[n]

print solution(1)