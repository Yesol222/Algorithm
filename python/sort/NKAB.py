
def quickSort(array):
    if len(array) <= 1:
        return array
    pivot = array[0]
    tail = array[1:]
    
    left_side = [x for x in tail if x >= pivot]
    right_side = [x for x in tail if x < pivot]

    return quickSort(left_side) + [pivot] + quickSort(right_side)


def betterAnswer(a,b,n,k):
    # n, k = map(int, input().split())
    # a = list(map(int, input().split))
    # b = list(map(int, input().split))

    a.sort()
    b.sort(reverse=True)

    for i in range(k):
        if a[i] < b[i]:
            a[i],b[i] = b[i],a[i]
        else:
            break
    print("right answer : "+str(sum(a)))
    


def main():
    N = input("insert length of arrays :")
    A = [input("element of A:") for i in range(N)]
    B = [input("element of B:") for i in range(N)]

    sorted_A = quickSort(A)
    sorted_B = quickSort(B)

    K = input("you can swap numbers K times, insert K: ")
    a = 0
    b = N-1

    while(K>=1):
        if a >= b :
            break
        if sorted_A[b] < sorted_B[a]:
            sorted_A[b] = sorted_B[a]
            K -= 1
        a += 1
        b -= 1
    
    print("my answer:"+str(sum(sorted_A)))
    betterAnswer(A,B,N,K)



if __name__ == "__main__":
    main()
    