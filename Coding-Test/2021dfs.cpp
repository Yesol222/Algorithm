#include <string.h>
#include <vector>
#include <iostream>
using namespace std;
int n=0;
//vector<string> combination[n+1];
//1. dfs로 조합찾기
//2. 투포인트로 같은거 비교하기.
//조합의 카운트를 어떻게 세느냐?????? hashmap??
vector<string> combination(1001);
vector<int> counts(1001);

//2 이상으로 붙이기

int compare(string str){
    int res=0;
    int size = sizeof(combination)/sizeof(string);
    for(int i=0;i<size;i++){
        if(str==combination[i]){
            res = i;
            break;
        }
    }
    return res;
}

string Combine(string str1, string str2){
    string tmp;
    if(str1>str2) tmp=str2+str1;
    else tmp=str1+str2;
    return tmp;
}

void Put(string str, int idx){
    int size = sizeof(str)/sizeof(string);
    if(size<=10){
        if(idx == 0) combination.push_back(str);
        else combination[idx]=str;
    }
}

//for loop를 돌리면 combination 배열이 계속 갱신됨;;;
//for loop 말고 idx로 돌려야 함
void combi(int L, string S){
    int size = sizeof(S);
    cout<<size<<endl;
    if(L>=size){
        return;
    }else
    {
        int ch;
        int mod = L%2;
        string str1(S[L],1);
        string str2(S[L+1],1);
        string newString = Combine(str1,str2);
        if(L==1){
            combination.push_back(newString);
            counts[L] += 1;
            combi(L+1,S);
        }else
        {
            combi(L+1,S);
            ch = compare(newString);
            if(ch!=0){
                counts[ch] += 1;
            }
            else {
                counts[L] +=1;
                Put(newString,L+11);
            }
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    n = orders.size();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<orders[i].size();j++){
            cout << orders[i][j] << endl;
        }
    }
    return answer;
}




#include <string.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int n=0;

vector<string> combination;
vector<int> counts;

//2 이상으로 붙이기

int compare(string str){
    int res=0;

    for(int i=0;i<combination.size();i++){
        if(str==combination[i] && str.length()==combination[i].length()){
            res = i;
            break;
        }
    }
    return res;
}

string Combine(string str1, string str2){
    string tmp;
    if(str1>str2) tmp=str2+str1;
    else tmp=str1+str2;
    return tmp;
}

void Put(string str, int idx){
    int size = sizeof(str)/sizeof(string);
    if(size<=10){
        if(idx == 0) combination.push_back(str);
        else combination[idx]=str;
    }
}

void bfs(string str){
    queue<string> Q;
    int n = str.size();

    for(int i=0;i<n;i++){
        string s1=str.substr(i,1);
        Q.push(s1);
    }

    while(!Q.empty()){
        string s = Q.front();
        Q.pop();
        string s2 = s.substr(s.length()-1,1);
        int pos = str.find(s2);   
        
        for(int i=pos+1;i<n;i++){
            string str2 = s+str[i];
            if(compare(str2)>0){
                int m = compare(str2);
                combination[m] =str2;
                counts[m] = counts[m]+1;
                Q.push(str2);
            }
            else{
                combination.push_back(str2);
                counts.push_back(1);
                Q.push(str2);
            }
        }
    
   }
}

vector<string> Find(int x){
    vector< pair<int,string> > maxs;
    vector<string> res;

    for(int i=0;i<=combination.size();i++){
        if(combination[i].size()==x){
            maxs.push_back(make_pair(i,combination[i]));
        } 
    }
    if(maxs.empty()) return res;
    int max = 2;
    int size = maxs.size()/2;
    cout << size<<endl;
    for(int i=0;i<maxs.size()/2;i++){
        cout<<maxs[i].first<<maxs[i].second;
    }
    
    int c=0; 
    int pos=maxs[0].first;
    while(c!=size){
        if(counts[pos]>=max) max=counts[pos];
        c++;
        pos=maxs[c].first;
    }
    c=0;
    pos=maxs[0].first;
    while(c!=size){
        if(counts[pos]==max) res.push_back(combination[pos]);
    }
    return res;
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    n = orders.size();
    
    for(int i=0;i<orders.size();i++){
        bfs(orders[i]);
    }
    // for(int i=0;i<combination.size();i++){
    //     cout<<combination[i]<<endl;
    // }
    for(int i=0;i<course.size();i++){
        int number = course[i];
        vector<string> tmp = Find(number);
        answer.insert(answer.end(),tmp.begin(),tmp.end());
    }

    
    return answer;
}