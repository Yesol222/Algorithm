#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//벡터로만 푼 풀이
bool compare(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int start = 0; // 현재까지 작업이 진행된 시간
    int time = 0; // 각각의 작업이 진행되는데 걸린 시간들의 합
    int size = jobs.size();

    sort(jobs.begin(), jobs.end(), compare); // 소요시간으로 우선 배열

    while(!jobs.empty()){
        for(int i=0; i<jobs.size(); i++){
            if(jobs[i][0] <= start) {
                start += jobs[i][1];
                time += start - jobs[i][0];
                jobs.erase(jobs.begin() + i);
                break;
            }

            if(i == jobs.size()-1) start++;
        }
    }

    answer = time / size;
    return answer;
}

//PQ를 이용한 풀이

#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

class compare1 {
public:
    bool operator()(const vector<int> &com1, const vector<int> &com2) {
        return com1[1]< com2[1] ? false : true;
    }
};
priority_queue<vector<int>, vector<vector<int> >, compare1> qu;
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end());
    int lastTime = jobs[0][0], i = 1;
    qu.push(jobs[0]);
    while(!qu.empty()) {
        vector<int> cur = qu.top(); qu.pop();
        answer += cur[1] + (lastTime - cur[0]);
        lastTime = cur[1] + lastTime;
        for(; i < jobs.size() && jobs[i][0] <= lastTime; i++)
            qu.push(jobs[i]);
        if(qu.empty() && i < jobs.size()){
            lastTime = jobs[i][0];
            qu.push(jobs[i++]);
        }
    }

    return answer / jobs.size();
}
