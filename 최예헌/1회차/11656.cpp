#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    vector <string> v;
    string str;
    
    cin>>str;
    
    for (int i=0;i<str.size();i++){
        v.push_back(str.substr(i));
    }
    
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();i++)
        cout<<v[i]<<"\n";    
}
