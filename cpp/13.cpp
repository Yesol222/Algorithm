#include <stdio.h>

using namespace std;
int ch[10];//각각의 자릿수 몇개 사용했는지 카운팅
int main(){
    int i, digit, max=-2147000000,res;
    char a[101];
    scanf("%s",&a);//문자열로 받으면 하나씩 들어감..
    for(i=0;i<a[i]!='\0';i++){
        digit=a[i]-48;
        ch[digit]++;
    }
    for(i=0;i<9;i++){
        if(ch[i]>=max){
            max=ch[i];
            res=i;
        }
        // else if(ch[i]==max){
        //     if(i>res) res=i;
        // }
    }

    printf("%d",res);
    return 0;
}