#include <iostream>
#include <map>

using namespace std;

int main(){
    
    map<char, int> ch;
    map<char, int> ::iterator it;
    char a[100];
    cin >> a;

    for(int i=0;a[i]!='\0';i++){
        ch[a[i]]++;
    }
    for(it=ch.begin();it!=ch.end();it++){
        cout<< it->first <<' '<< it->second <<endl;
    }
    
    
    return 0;
}