import itertools

def solution(orders, course):
    answer = []
    combi = {}
    for order in orders:
        for i in order:
            if i in combi.keys():
                combi[i] = combi[i] + 1
            else:
                combi[i] = 1
    a = 0
    print(combi)
    while a < 3:
        newCombi = {}
        newKey =  list(map(''.join, itertools.combinations(combi.keys(), course[a])))
        for order in orders:
            for key in newKey:
                if key in order:
                    if key in newCombi.keys():
                        newCombi[key] = newCombi[key]+1
                    else:
                        newCombi[key] = 1

        print(newCombi.values())
        max_keys = max(newCombi.keys(), key=lambda k : newCombi[k])
        answer.append(max_keys)
        a += 1

    return answer