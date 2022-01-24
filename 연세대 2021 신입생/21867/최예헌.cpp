#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    string str;
    string s;
    int n;
    
    cin>>n>>str;
    
    for (int i=0;i<str.size();i++){
        if (str[i]=='J' || str[i]=='A' || str[i]=='V')
            continue;
        s+=str[i];
    }
    if (s.empty())
        cout<<"nojava";
    else
        cout<<s;
}
