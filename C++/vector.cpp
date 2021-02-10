#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> c[3]; //c라는 이름을 가진 벡터가 3개 생기는 것임
    // 벡터 객체 배열 생성이라고 생각하면 된다.
    c[0].push_back(1);
    c[0].push_back(3);
    c[0].push_back(5);
    c[1].push_back(2);
    c[2].push_back(7);
    cout<<c[1][1]<<endl;
    cout<<c[2][0]<<endl;

    vector<pair<int,int> > graph[3];
    graph[1].push_back({3,5});
    graph[1].push_back({4,7});
    graph[2].push_back(make_pair(7,7));

}