
def Whatever(array,target,start,end):
    mid = (start+end) //2

    if sum([e-mid for e in array]) == target :
        return mid
    elif sum([e-mid for e in array]) > target:
        return Whatever(array,target,mid+1,end)
    elif sum([e-mid for e in array]) < target:
        return start

def notMyAnswer(array,n,m):
    start = 0 
    end = max(array)
    
    result = 0
    while(start <= end):
        total = 0
        mid = (start+end) // 2
        for x in array:
            if x > mid:
                total += x - mid
        if total < m :
            end = mid -1
        else:
            result = mid
            start = mid+1

def main():
    
    # N, M = map(int,input().split())
    N = input("number of T: ")
    M = input("Max of T: ")

    Ts = [input("insert heights of Ttecks: ") for i in range(N)]
    Ts.sort(reverse=True)

    print(Whatever(Ts,M,0,Ts[0]))
    print(notMyAnswer(Ts,N,M))


if __name__ == '__main__':
    main()