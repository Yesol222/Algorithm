#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    
    map<string, int> ch;
    map<string, int> ::iterator it;
    char a[100];
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a;
        ch[a]++;
    }

    int max = 0;
    string res;

    for(it=ch.begin();it!=ch.end();it++){
        cout << it->first <<' '<< it->second <<endl;
        if(it->second>max){
            max=it->second;
            res =it->first;
        } 
    }
    cout << res << " : " << max << endl;
    
    return 0;
}