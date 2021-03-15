#include <string.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int n=0;

vector<pair<string, int> > combination;

//2 이상으로 붙이기

int compare(string str){
    int res=0;

    for(int i=0;i<combination.size();i++){
        if(str==combination[i].first && str.length()==combination[i].first.length()){
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

void bfs(string str){
    queue<string> Q;
    int n = str.size();

    for(int i=0;i<n;i++){
        string s1=str.substr(i,i+1);
        Q.push(s1);
    }

    while(!Q.empty()){
        string s = Q.front();
        Q.pop();
        string s2 = s.substr(s.length()-1,s.length());
        int pos = str.find(s2);   

        for(int i=pos+1;i<n;i++){
            string str2 = s+str[i];
            if(compare(str2)>0){
                int m = compare(str2);
                combination[m].second++;
                Q.push(str2);
            }
            else{
                combination.push_back(make_pair(str2,0));

                Q.push(str2);
            }
        }
    
   }
}

vector<string> Find(int x){
    vector< pair<string,int> > maxs;
    vector<string> res;

    for(int i=0;i<=combination.size();i++){
        if(combination[i].first.size()==x){
            maxs.push_back(make_pair(combination[i].first,combination[i].second));
        } 
    }
    if(maxs.empty()) return res;

    int max =2;
    for(int i=0;i<maxs.size();i++){
        if(maxs[i].second>=max) max=maxs[i].second;
    }
    for(int i=0;i<maxs.size();i++){
        if(maxs[i].second==max) res.push_back(maxs[i].first);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    n = orders.size();
    
    for(int i=0;i<orders.size();i++){
        bfs(orders[i]);
    }
    
    for(int i=0;i<course.size();i++){
        int number = course[i];
        vector<string> tmp = Find(number);
        answer.insert(answer.end(),tmp.begin(),tmp.end());
    }

    
    return answer;
}