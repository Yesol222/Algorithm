import re

def first(new_id):
    alphabet = " ".join(re.split("[^a-zA-Z]*", new_id))
    if alphabet.islower == True:
        print("1단계 변화 없습니다.")
    else:
        after = new_id.lower()
        print("1단계",new_id,"->",after)
        new_id = after
    return after
    
def second(new_id):
    after = new_id
    after = re.sub('[=§!@#$%^&*+/?,\']','',after)
    if new_id == after:
        print("2단계 변화 없습니다")
    else:
        print("2단계",new_id,"->",after)
    return after

def third(new_id):
    S = ".."
    after = new_id
    while S:
        if S not in after:
            print("3단계 변화 없습니다")
            return after
        else:
            after = after.replace(S,'.')
    print("3단계",new_id,'->',after)
    return after

def fourth(new_id):
    if new_id.startswith('.'):
        after = new_id[1:]
        print("4단계",new_id,'->',after)
        return after
    elif new_id.endswith('.'):
        after = new_id[:-1]
        print("4단계",new_id,'->',after)
        return after
    elif new_id.startswith('.') and new_id.endswith('.'):
        after = new_id[1:-1]
        print("4단계",new_id,'->',after)
        return after
    else:
        print("4단계 변화 없습니다")
        return new_id
    
def fifth(new_id):
    if len(new_id) == 0:
        after = "aaa"
        print("5단계",new_id,'->',after)
        return after
    else:
        print("5단계 변화 없습니다")
        return new_id

def sixth(new_id):
    if len(new_id) >= 16:
        after = new_id[:15]
        if after.endswith('.') == True:
            after = after[:14]
        print("6단계",new_id,"->",after)
        return after
    else:
        print("6단계 변화 없습니다")
        return new_id

def seventh(new_id):
    if len(new_id) >2:
        print("7단계 변화 없습니다")
        return new_id
        
    final = new_id[-1]
    after = new_id
    while len(after) < 3:
        after = after+final
    print("7단계",new_id,'->',after)
    return after
        
            
def solution(new_id):
    answer = ''
    
    new_id= first(new_id)
    new_id = second(new_id)
    new_id = third(new_id)
    new_id = fourth(new_id)
    new_id = fifth(new_id)
    new_id = sixth(new_id)
    new_id = seventh(new_id)
    
    answer = new_id
    return answer