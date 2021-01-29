#include<stdio.h>
#include<stack>

using namespace std;

int main(){
    stack<char> s;
    char a[50];
    int i;
    scanf("%s",&a);
    for(i=0;a[i]!='\0';i++){
        if(a[i]=='(') s.push(a[i]);
        else{
            if(s.empty()) break;
            else s.pop();
        }
    }
    if(s.empty()) printf("YES");
    else printf("NO");
    return 0;
}
// int main(){
//     int i,cnt,j=0;
//     char a[31];
//     stack<int> s;
//     scanf("%s",&a);
    
//     while(a[j]!='\0'){
//         s.push(a[j]);
//         j++;
//     }

//     while(!s.empty()){
//         if(s.top()==')'){
//             cnt++;
//             s.pop();
//         }
//         else if(s.top()=='('){
//             cnt--;
//             s.pop();
//         }

//         if(cnt==-1){
//             printf("NO");
//             break;
//         }
//     }

//     printf("YES");
//     return 0;
// }