#include <vector>
//segmentation fault 나왔음 ㅜ
bool answer;
vector<vector<int> > map;
int ok;
int xs, ys;

bool next(int a, int b){

}

void Search(int a, int b, int L){
    if(L==ok){
        answer = true;
        return;
    }
    else{
        if(next(a,b)==false) return false;
        else{
            a=(a+1)%xs;
            b=(b+1)%ys;
            Search(a,b,L+1);
        }
    }
} 




bool Solution(int x, int y){
    xs = x;
    ys = y;

    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            answer=false;
            map.clear();
            map[i][j]=1;
            Search(i,j,1);
        }
    }

    return answer;
}