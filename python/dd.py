def solution(n, products):
    answer = 0
    mySum = 0
    
    while n > 0 :
        for i in range(len(products)):
            if products[i][0] > 2*products[i][2]:
                mySum += products[i][1]*products[i][2]
                products[i][0] -= products[i][2]
        for i in range(len(products)):
            if products[i][0] > 2*products[i][2]:
                answer = max(answer,mySum+products[i][1]*products[i][2])
        n -= 1
        
    return answer


    def solution(num, cards):
    answer = 0
    Sum = 0
    
    for i in range(len(cards)-1,0,-1):
        if num < min(cards):
            return -1
        if (num%cards[i]) not in cards:
            continue
        else:
            Sum += cards[i]
            num = num%cards[i]
            answer += 1

    if Sum == num:
        return answer
    else:
        solution(num,cards)