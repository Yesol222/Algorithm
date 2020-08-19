#Timeover error :(
def solution():

    A,B,V = map(int,input().split(" "))

    left = 1
    right = (A-B)*V

    answer = right
    while(left<=right):
        mid = (left+right) // 2
        h = 0
        for i in range(0,mid):
            h += A
            if h >= V :
                break
            else :
                h -= B
        if h >= V:
            if answer >= mid :
                answer = mid
            right -= 1
        else:
            left += 1
    return answer
            
print(solution())