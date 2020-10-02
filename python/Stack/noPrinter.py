def solution(priorities, location):
    answer = 0

    sample = [0] * len(priorities)
    sample[location] = 1

    while max(sample) == 1:
        if priorities[0] == max(priorities):
            priorities.pop(0)
            sample.pop(0)
            answer += 1

        else:
            priorities.append(priorities.pop(0))
            sample.append(sample.pop(0))

    return answer



def comparision(priorities,one):
    for so in priorities:
        if one < so:
            return True
    return False
        
def Mysolution(priorities, location):
    answer = 0
    bigger = list()
    smaller = list()
    
    friends = [i for i in range(0,len(priorities))]
    
    while priorities:
        one = priorities.pop(0)
        so = friends.pop(0)
        if len(priorities) == 1 :
            bigger.append(so)
        elif comparision(priorities,one) == True :
            smaller.append(so)
        else:
            bigger.append(so)
        
    printer = bigger+smaller
    answer = printer.index(location)+1
    return answer



    def comparision(priorities,one):
    if len(priorities) == 0:
        return False
    for so in priorities:
        if one < so:
            return True
    return False
        
def solution(priorities, location):
    answer = 0
    bigger = list()
    smaller = list()
    
    friends = [i for i in range(0,len(priorities))]
    
    while priorities:
        one = priorities.pop(0)
        so = friends.pop(0)
        if len(priorities) == 1 :
            bigger.append(so)
        elif comparision(priorities,one) == True :
            smaller.append(so)
        else:
            bigger.append(so)
        
    printer = bigger+smaller
    answer = printer.index(location)+1
    return answer