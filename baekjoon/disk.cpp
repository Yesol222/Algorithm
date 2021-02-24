#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Disk{
    int arrival;
    int task;
    Disk(int a, int b){
        arrival = a;
        task = b;
    }
    bool operator<(Disk &d){
        return task<d.task;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int i, w, pos=0, time=0, res;
    priority_queue<int> pQ;
    vector<Disk> d;
    
    pos = jobs[0][1];
    time += pos;
    answer += pos;
    for(i=1;i<jobs.size();i++){
        d.push_back(Disk(jobs[i][0],jobs[i][1]));
    }
    sort(d.begin(),d.end());

    for(i=1;i<d.size();i++){
        time += d[i].task;
        pos+=d[i].task;
        res = time-d[i].arrival;
        pQ.push(-res);
    }
    while(!pQ.empty()){
        answer+= (-pQ.top());
        pQ.pop();
    }
    
    answer = answer/jobs.size();
    return answer;
}

class compare1{
public:
    bool operator<(vector<int> &com1, const vector<int> &com2){
        return com1[1]<com[2] ? false:true;
    }
}; //queue 에서 쓸 수 있게 하려고 클래스로 만드는 건가봄...

priority_queue<vector<int>, vector<int> > compare1> qu;
int solution(vector<vector<int>> jobs){
    int answer=0;
    sort(jobs.begine(),jobs.end());
    int lastTime = jobs[0][0], i =1;
    qu.push(jobs[0]);

    while(!qu.empty()){
        vector<int> cur=qu.top(); qu.pop();
        answer += cur[1] + (lastTime-cur[0]);
        lastTime = cur[1]+lastTime;
        for(; i< jobs.size() && jobs[i][0] <= lastTime; i++){
            qu.push(jobs[i]);
        }
        if(qu.empty()&& i<jobs.size()){
            lastTime=jobs[i][0];
            qu.push(jobs[i++]);
        }
    }

    return answer / jobs.size();
}