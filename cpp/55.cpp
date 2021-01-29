#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;

// a도 필요없고 str 벡터도 필요 없음
//다만 내 코드에서는 stack = empty일 때 Push하는 부분이 없음
//또 a 배열에 넣어서 스택에 다시 저장했는데, 걍 읽어서 바로 처리해도 됨 
// 하지만 배열에 넣어서 스택에 저장하면 n, 이중루프 사용하면 n 제곱인걸..?
int main(){
    stack<int> s;
    int n, i, j=1,m;
    int a[40];

    // for(i=1;i<=n;i++){
    //     scanf("%d",&a[i]);
    // }

    for(i=1;i<=n;i++){
        a[i]=i;
    }
    vector<char> str;
    for(i=1;i<=n;i++){
        scanf("d",&m);
        s.push(m);
        str.push_back('P');
        while(1){
            if(s.empty()) break;
            if(a[j]==s.top()){
                s.pop();
                j++;
                str.push_back('O');
            }
            else break;
        }
    }
    // while(a[j]!='\0'){
    //     if(s.top()==j){
    //         s.pop();
    //         printf("O");
    //     }
    //     else{
    //         s.push(a[j]);
    //         printf("P");
    //     }
    //     j++;
    // }

    // if(!s.empty()) printf("possible");
    // else printf("impossible");

    if(!s.empty()) printf("impossible");
    else {
        for(i=0;i<str.size();i++) printf("%c",&str[i]);
    }
    return 0;
}