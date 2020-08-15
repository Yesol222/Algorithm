
def solution(n, times):
    left = 1
    right = max(times)*n
    answer = right
    

    while(left <= right):
        mid = (right+left) //2
        people = 0

        for time in times:
            people += mid // time

        if people >= n:
            if answer >= mid :
                answer = mid
            right = mid - 1
        else:
            left = mid+1

    return answer

    #이진 탐색의 논리 -> mid 값으로 범위를 좁혀가며 타겟을 찾아가는 것인데
    #이 문제에서는 answer를 최악의 값인 max(times)*n으로 정해놓고
    #범위를 줄여가면서 최적의 해를 찾는 것
    #직관적인 연결이 안 됨 ㅠ 이해가 안된다 ㅠㅠ