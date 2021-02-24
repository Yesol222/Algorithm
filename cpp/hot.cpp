// #include <string>
// #include <vector>
// #include <queue>

// using namespace std;

// int solution(vector<int> scoville, int K) {
//     int answer=0;
//     priority_queue<int> pQ;
//     int i=0, t1, t2, newfood;
//     while(i!=scoville.size()){
//         pQ.push(-scoville[i]);
//         i++;
//     }
    
//     while(!pQ.empty()){
//         t1=-pQ.top();
//         pQ.pop();
//         if(t1>=K) break;
//         if(pQ.empty()){
//             if(t1<K) answer=-1;
//             break;
//         }
//         t2=-pQ.top();
//         pQ.pop();
//         newfood = t1+(2*t2);
//         if(pQ.empty()){
//             if(newfood<K) answer=-1;
//         }
//         else if(newfood<K){
//             pQ.push(-newfood);
//             answer+=1;
//         }
//         else if(newfood>=K){
//             answer+=1;
//         }
//     }
//     return answer;
// }
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> sco;

    for(int i = 0 ; i < scoville.size() ; ++i)
        sco.push(-scoville[i]);

    while(sco.size() >= 2 && -sco.top() < K)
    {
        int mix1 = sco.top();
        sco.pop();
        int mix2 = sco.top()*2;
        sco.pop();

        sco.push(mix1+mix2);
        ++answer;
    }

    if(-sco.top() < K)
        answer = -1;

    return answer;
}