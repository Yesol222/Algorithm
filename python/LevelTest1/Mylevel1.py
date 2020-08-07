def solution(n):

    numbers = list()
    l = len(str(n)) -1
    for i in range(l,0,-1):
        if i == 1 :
            numbers.append(n//(i*10))
            numbers.append(n%(i*10))
            break
        a = n//(i*10)
        b = n%(i*10)
        
        numbers.append(a)
        n = b
        numbers.sort(reverse==True)

    for i in numbers:
        answer += str(i) 
    return answer