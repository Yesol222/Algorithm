def solution(n, times):
    left = 1
    ## 최대 시간 = 모든 사람이 심사시간이 제일 긴 심사관에게 입국심사를 보는 경우
    right = max(times) * n
    answer = right

    ## 이분탐색 시작
    while(left <= right):
        mid = (right + left) // 2
        people = 0

        ## 현재 탐색하는 소요시간 // 각 심사관 별 소요시간
        ## 이를 통하여 각 심사관이 해당 시간 내에 해결할 수 있는 심사의 수를 구해 더한다.
        for time in times:
            people += mid // time

        ## 해결 가능한 총 심사 수가 구하고자 하던 것보다 많거나 같은 경우
        if people >= n:
            ## 기존 탐색했던 값보다 더 작다면 이를 저장한다.
            if answer >= mid:
                answer = mid
            ## 혹시나 더 최소인 경우가 있을 수 있으므로 탐색을 계속한다.
            right = mid - 1
        ## 해결한 총 심사 수가 기존에 구하려던 것보다 적은 경우
        else:
            ## 해당 시간보다 더 많은 시간이 필요한 것이 명확하므로 탐색을 계속한다.
            left = mid + 1

    return answer