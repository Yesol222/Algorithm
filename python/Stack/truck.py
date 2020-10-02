from collections import deque
def solution(bridge_length, weight, truck_weights):
    answer = 0
    wait_list = deque(truck_weights)
    passing = list()

    while wait_list:
        truck = wait_list.popleft()
        if wait_list == False:
            answer += (bridge_length) + len(passing)
            break
        if (sum(passing) + truck) <= weight:
            passing.append(truck)
            print(passing)
        else:
            answer += (bridge_length+ len(passing))
            print(passing,answer)
            passing.clear()
            passing.append(truck)
            print(passing)

    return answer

def betterSolution(bridge_length, weight, truck_weights):
    q=[0]*bridge_length
    sec=0
    while q:
        sec+=1
        q.pop(0)
        if truck_weights: # truck_weight에 아무것도 없으면 q.pop만 하다가 와일문 끝남.
            if sum(q)+truck_weights[0]<=weight:
                q.append(truck_weights.pop(0))
            else:
                q.append(0)
    return sec

# q = bridge_length 길이의 배열이고, 그 만큼 시간동안 동시에 올라갈 수 있기 때문에 0으로 채워두고 트럭들을 push 한 것.
# q + 들어갈 트럭 합이 weight 보다 작으면 q에 집어넣고 아니면 안넣음, q는 bridge 길이만큼 도니까 시간 계산 +
