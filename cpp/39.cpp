#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int a[101],b[101],c[300];
int main(){
    int n,m,i,p1=1,p2=1,p3=1;
    scanf("%d",n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",m);
    for(i=1;i<=m;i++){
        scanf("%d",&b[i]);
    }

    while (p1<=n && p2<=m)
    {
        if(a[p1]<b[p2]){
            c[p3++]=a[p1++]; //후치 연산이므로 루프 끝난 후에 인덱스 증가.
        }
        else{
            c[p3++]=b[p2++];
        }
    }
    while(p1<=n) c[p3++] = a[p1++];
    while(p2<=m) c[p3++] = b[p2++];
    
    return 0;
}


// #include<stdio.h>
// #include<stdlib.h>

// int main() {
// 	int* p1, * p2, * p3;
// 	int* a, * b, * c;
// 	int N, M;
// 	scanf("%d", &N);
// 	a = (int*)malloc(sizeof(int) * (N+1));
// 	for (int i = 0; i < N; i++) { scanf("%d", &a[i]); }
// 	a[N]=2147483647;
	
// 	scanf("%d", &M);
// 	b = (int*)malloc(sizeof(int) * (M+1));
	
// 	for (int i = 0; i < M; i++) { scanf("%d", &b[i]); }
// 	b[M]=2147483647;

// 	c = (int*)malloc(sizeof(int) * (N + M+1));

// 	p1 = a, p2 = b, p3 = c;
	
// 	while (*p1!=2147483647 || *p2!=2147483647) {
// 		if (*(p1) < *(p2)) { *(p3) = *(p1); p3++; p1++;}
// 		else { *(p3) = *(p2);p3++; p2++;}
// 	}

// 	for (int i = 0; i < N+M; i++) { printf("%d ", c[i]); }
// 	return 0;

// }