#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n,lt,cwr,rt,k=1,res;
    scanf("%d",&n);

    while(lt!=0){
        lt=n/(k*10);
        cwr=(n/k)%10;
        rt=n%k;

        if(cwr>3){
            res=res+(lt+1)*k;
        }
        else if(cwr<3){
            res=res+(lt*k);
        }
        else{
            res=res+(lt*k)+rt+1;
        }
        k=k*10;
    }

    return 0;   
}