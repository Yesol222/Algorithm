#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int a[1501];

int main(){
    int n, i, p2, p3, p5, min=2147000000;
    scanf("%d",&n);
    a[1]=1;
    p2=p3=p5=1;
    for(i=2;i<=n;i++){
        if(a[p2]*2<a[p3]*3) min=a[p2]*2;
        else min = a[p3]*3;
        if(a[p3]*5<min) a[p3]*5;

        if(a[p2]*2==min) p2++;
        if(a[p3]*3==min) p3++;
        if(a[p5]*5==min) p5++;
        a[i]=min;
    }
    printf("%d",&a[n]);

    return 0;
}




int main(){
    int n, i=1, p2=1, p3=1, p5=1;
    vector<int> a(n+1);
    a[1]=1;
    while(a.size()<=n){
        int tmp = min(a[p2]*2,a[p3]*3,a[p5]*5);
        a.push_back(tmp);
        if(tmp==a[p2]*2) p2++;
        if(tmp==a[p3]*3) p3++;
        if(tmp==a[p5]*5) p5++;
    }
    printf("%d",&a[n]);
    return 0;
}




//밑의 코드로는 절대 답이 나올 수가 없다 왜냐면 i가 계속 증가하기 때문에,,
//투 포인트의 핵심을 이해 못한듯?? 인덱스로서 역할을 하면서 값을 수정해야 함

// int main(){
//     int n, i=1, p2=1, p3=1, p5=1;
//     vector<int> a(n+1);
//     a[1]=1;
//     p2 = p2*2;
//     p3 = p3*3;
//     p5 = p5*5;
//     while(a.size()<=n){
//         int tmp = min(a[i]*p2,a[i]*p3,a[i]*p5);
//         a.push_back(tmp);
//         if(tmp==a[i]*p2) p2=p2*2;
//         else if(tmp==a[i]*p3) p3=p3*3;
//         else p5=p5*5;
//         i++;
//     }

//     printf("%d",&a[n]);
//     return 0;
// }