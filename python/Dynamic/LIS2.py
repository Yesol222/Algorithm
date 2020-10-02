import math
#assign -inf on 0th index, so that stop function when 0th is the biggest 
def lis(arr):
    arr = [-math.inf] + arr
    N = len(arr)
    cache = [-1]*N
    
    def find(start):
        if cache[start] != -1:
            return cache[start]
        ret = 0
        for nxt in range(start+1,N):
            if arr[start] < arr[nxt] :
                ret = max(ret,find(nxt)+1)
        cache[start] = ret
        return ret
    return find(0)