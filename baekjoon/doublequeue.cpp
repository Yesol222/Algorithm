#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

priority_queue<int> pQ;
priority_queue<int> pQ2;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<string> x;
    string stringBuffer;
    int i, max=-2147000000, min=2147000000;
    
    for(i=0;i<operations.size();i++){
        istringstream ss(operations[i]);
        while(getline(ss, stringBuffer, ' ')){
            x.push_back(stringBuffer);
        }
        if(x[0]=="I"){
            string s = x[1];
            int n = stoi(s);
            if(n>max) {
                max = n;
                pQ.push(n);
            }
            else if(n<min) {
                min = n;
                pQ2.push(-n);
            }
        }
        else if(x[1]=="-1"){
            if(!pQ2.empty()){
                pQ2.pop();
            }
        }
        else if(x[1]=="1"){
            if(!pQ.empty()){
                pQ.pop();
            }
        }
        x.clear();
    }
    
    if(pQ.empty() && pQ2.empty()){
        answer={0,0};
    }

    else answer={pQ.top(),-pQ2.top()};
    
    return answer;
}




#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

priority_queue<int> pQ;
priority_queue<int> pQ2;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<string> x;
    string stringBuffer;
    int i, max=-2147000000, min=2147000000;
    
    for(i=0;i<operations.size();i++){
        istringstream ss(operations[i]);
        while(getline(ss, stringBuffer, ' ')){
            x.push_back(stringBuffer);
        }
        if(x[0]=="I"){
            string s = x[1];
            int n = stoi(s);
            pQ.push(n);
            pQ2.push(-n);
        }
        else if(x[1]=="-1"){
            if(!pQ2.empty()){
                pQ2.pop();
            }
        }
        else if(x[1]=="1"){
            if(!pQ.empty()){
                pQ.pop();
            }
        }
        x.clear();
    }
    
//     if(pQ.empty() && pQ2.empty()){
//         answer={0,0};
//     }

//     else answer={pQ.top(),-pQ2.top()};