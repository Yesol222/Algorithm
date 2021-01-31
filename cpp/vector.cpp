#include <iostream>
#include <vector>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);

    vector<int> a;
    a.push_back(6);
    a.push_back(8);
    a.push_back(11);
    cout<<a.size()<<endl;
    cout<<a[1]<<endl;
}