def SelectSort(number):
    for i in range(len(number)) :
        min_index = i
        for j in range(i+1,len(number)) :
            if number[min_index] > number[j] : 
                min_index = j
        number[i], number[min_index] = number[min_index],number[i]
    print(number)

def InsertSort(number):
    for i in range(1,len(number)):
        for j in range(i,0,-1):
            if number[j] < number[j-1] :
                number[j],number[j-1] = number[j-1], number[j]
            else:
                break
    print(number)

def QuickSort(number,start,end):
    if start>=end:
        return
    pivot = start
    left = start+1
    right = end
    
    while(left<=right) :
        while(left <= end and number[left] <= number[pivot]):
            left += 1
        while(right > start and number[right] >= number[pivot]):
            right -=1
        if(left > right):
            number[right], number[pivot] = number[pivot], number[right]
        else :
            number[left], number[right] = number[right], number[left]
        QuickSort(number,start,right-1)
        QuickSort(number,right+1,end)

    return number

def quickSort(number):
    if len(number) <= 1 :
        return number
    pivot = number[0]
    tail = number[1:]

    left_side = [x for x in tail if x <= pivot]
    right_side = [x for x in tail if x> pivot]

    return quickSort(left_side) + [pivot] + quickSort(right_side)


def main():
    print("--------------\n")
    print("put 5 numbers and will sort it in ascending order")

    number = [input("numbers : ") for n in range(5)]

    print("--------------\n")
    print("select sort : 1")
    print("insert sort : 2")
    print("quick sort : 3")    
    print("better quick sort : 4")

    choice = input("your choice: ")
    if choice == 1 :
        SelectSort(number)
    elif choice == 2:
        InsertSort(number)
    elif choice == 3:
        start, end = 0,4
        print(QuickSort(number,start,end))
    elif choice == 4 :
        print(quickSort(number))

if __name__ == "__main__":
    main()
    