#include <stdio.h>

using namespace std;

int main(){
    freopen("input.txt","rt",stdin);
    char a[101], b[101];

    int i, p =0;

    gets(a);
    //space 무시하고 입력값을 배열로 받음

    for(i=0;a[i]!='\0';i++){
        if(a[i]!=' '){
            if(a[i]>= 65 && a[i]<=90){//대문자라면
                b[p++]=a[i]+32; // 소문자로 변환
            }
            else b[p++]=a[i];
        }
    }

    b[p]='\0';
    printf("%s",b);
    return 0;
}