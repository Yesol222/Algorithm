#include <iostream>
#include <vector>
using namespace std;
//  구조체를 이용해서 벡터를 정렬하는 방법
struct Loc{
    int x, y, z;
    Loc(int a, int b, int c){
        x=a;
        y=b;
        z=c;
    }//constructor
    bool operator<(const Loc &b)const{ //상수 멤버함수. x,y,z 값을 바꿀 수가 없음
        return x<b.x; //오름차순으로 정렬
    }//연산자 오버로딩
};
int main(){
    vector<Loc> XY;
    XY.push_back(Loc(2,3,5));
    XY.push_back(Loc(3,6,7));
    XY.push_back(Loc(2,3,1));
    XY.push_back(Loc(5,2,3));
    XY.push_back(Loc(3,1,6));
    for(auto pos: XY) cout<<pos.x<<" "<<pos.y<<" "<<pos.z<<endl;
    return 0;
}