#include <stdio.h>

using namespace std;

int main(){
    freopen("input.txt","rt",stdin);
    //scanf, printf가 대용량 입출력에 빨라서 문제풀이에 이것을 사용하는게 나음
    char a[20];
    int year , age;
    scanf("%s",a);
    //ASCII 0-9 = 48-57
    if(a[7]=='1' || a[7] == '2') year = 1900+((a[0]-48)*10+(a[1]-48));
    else year = 2000+((a[0]-48)*10+(a[1]-48));

    age = 2019-year+1;
    printf("%d",age);

    if(a[7]=='1' || a[7] == '3') printf("M\n");
    else printf("W\n");

    return 0;
}