import re
def solution(info, query):
    answer = []
    applicants = {}
    
    for person in info:
        att = person.split(" ")
        applicants[att[-1]] = att[:-1]
    a = 0
    for wants in query:
        want = wants.split("and")
        if '-' in want:
            want = re.sub('[-]','',want)
            print(want)
        for key in applicants.keys():
            if key >= want[-1] and applicants[key] == want[:-1] :
                answer[a] += 1
            elif key >= want[-1] and want in applicants[key]:
                answer[a] += 1
        a += 1
    return answer
    


def solution(info, query):
    answer = [0]*len(query)
    applicants = {}
    a = 0
    for person in info:
        att = person.split(" ")
        applicants[att[-1]] = att[:-1]

    for wants in query:
        want = wants.split(" ")
        criteria = want[-1]
        want = set(want)
        want.remove("and")
        want.remove(criteria)        
        if '-' in want:
            want.remove('-')
        for key in applicants.keys():
            if key >= criteria:
                diff = set(applicants[key])^want
                if diff == set():
                    answer[a] = answer[a] + 1
                if diff | set(applicants[key]) == set(applicants[key]):
                    answer[a] = answer[a] + 1
        a += 1
    return answer