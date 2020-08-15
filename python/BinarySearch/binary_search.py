
# 이 binary search는 sorted array에서 target의 index를 찾는 알고리즘임
# 반으로 분할한 후에 타겟 기준으로 점점 좁혀가는 알고리즘

def binary_search(array, target, start, end):
    if start > end:
        return None
    mid = (start+end) // 2

    if array[mid] == target:
        return mid
    elif array[mid] > target:
        return binary_search(array,target,start,mid-1)
    else:
        return binary_search(array,target,mid+1,end)

n, target = list(map(int, input().split()))

array = list(map(int,input().split()))

result = binary_search(array,target,0,n-1)
if result == None:
    print("Element doesnt exist")
else:
    print(result+1)


