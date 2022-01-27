#include <iostream>
#include <cstring>
using namespace std;

bool solve(string str){
    if (str.size()==1)
        return true;

    int mid = str.size()/2;
    string s,e;
    for (int i=0;i<mid;i++)
        s+=str[i];
    
    if (str.size()%2 == 0)
        e = str.substr(mid);
    else
        e = str.substr(mid+1);

    if (s==e && solve(s) && solve(e))
        return true;
    return false;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    string str;
    cin>>str;
    
    if (solve(str))
        cout<<"AKARAKA";
    else
        cout<<"IPSELENTI";
}
