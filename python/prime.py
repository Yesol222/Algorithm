import itertools 

def solution(numbers):
    answer = 0
    maxNum = 10*7
    Num = [numbers[i] for i in range(len(numbers))]
    S = Num + list(map(''.join, itertools.permutations(Num)))
    
    for i in S:
        if i[0] == 0:
            i.remove(i[0])

    S = set(S)

    if 0 in S:
        S -= set(0)
    elif 1 in S:
        S -= set(1)
    elif 0 in S and 1 in S:
        S -= set(0,1)
    print(S)

    # S = list(S)
    # print(S)

    # for i in range(0,len(S)):
    #     for j in range(2,maxNum+1):
    #         if int(S[i])%j == 0 :
    #             S.remove(S[i])
    
    # answer = len(S)
    # print(answer)
    # return answer


def solution2(n):
    a = set()
    for i in range(len(n)):
        a |= set(map(int, map("".join, itertools.permutations(list(n), i + 1))))
    a -= set(range(0, 2))
    for i in range(2, int(max(a) ** 0.5) + 1):
        a -= set(range(i * 2, max(a) + 1, i))
    return len(a)
    



print(solution2("17"))
print(solution2("011"))



def solution3(brown, yellow):
    answer = []
    a =int(brown) + int(yellow)
    mini = list()
    for  i in range(1,a+1):
        if a%i == 0:
            mini.append(i)

    middle = len(mini)//2
    if mini[middle]*mini[(middle+1)] == a:
        answer.append(mini[middle])
        answer.append(mini[middle+1])
    elif mini[(middle-1)]*mini[middle] == a:
        answer.append(mini[middle])
        answer.append(mini[middle-1])
    elif mini[middle]*mini[middle] == a:
        answer.append(mini[middle])
        answer.append(mini[middle])
    
    answer.sort(reverse=True)
    return answer