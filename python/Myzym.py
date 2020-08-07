def checkLost(num, lost):
    if num in lost :
        return True
    return False

def checkReserve(num, reserve):
    if num in reserve:
        return True
    return False

def solution(n, lost, reserve):
    answer = 0
    for i in range(1,n+1,1): 
        if checkLost(i,lost) == True and checkReserve(i,reserve) == True:
            lost.remove(i)
            reserve.remove(i)
    for i in range(1,n+1,1) :
        j = i+1
        if checkLost(j,lost) == True and checkReserve(i,reserve) ==True :
            lost.remove(j)
            reserve.remove(i)
        if checkLost(i,lost) == True and checkReserve(j,reserve) == True:
            lost.remove(i)
            reserve.remove(j)
        if checkLost(i,lost) == False :
            answer = answer+1
    return answer