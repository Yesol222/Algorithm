#include <stdio.h>
#include <stack>

using namespace std;
//empty, size, back, push, pop 사용 가능
int main(){
    stack<int> a;
    stack<char> b;

    a.push(1);
    a.push(2);
    a.push(3);

    a.pop();

    a.size();
    a.empty();
    
}