def SelectSort(number):
    for i in range(len(number)) :
        min_index = i
        for j in range(i+1,len(number)) :
            if number[min_index] > number[j] : 
                min_index = j
        number[i], number[min_index] = number[min_index],number[i]
    print(number)


def main():
    print("--------------\n")
    print("put 5 numbers and will sort it in ascending order")

    number = [input("numbers : ") for n in range(5)]

    print("--------------\n")
    print("select sort : 1")
    print("insert sort : 2")

    choice = input("your choice: ")
    if choice == 1 :
        SelectSort(number)
    # elif choice == 2:
    #     InsertSort(number)


if __name__ == "__main__":
    main()
    