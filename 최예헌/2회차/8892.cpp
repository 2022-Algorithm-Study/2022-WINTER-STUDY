#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

bool solve(string s){
    
    ll size = s.size();
    for (int i=0;i<=(size/2-1);i++){
        if (s[i] != s[size-1-i]){
            return false;
        }
    }
    
    return true;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int t,n;
    cin>>t;
    
    while (t--){
        cin>>n;
        vector <string> v(n);
        bool flag=false;
        
        for (int i=0;i<n;i++){
            cin>>v[i];
        }
        
        for (int i=0;i<n;i++){
            for (int j=0;j<i;j++){
                if (solve(v[i]+v[j])){
                    cout<<v[i]+v[j]<<"\n";
                    flag=true;
                    break;
                }
                
                if (solve(v[j]+v[i])){
                    cout<<v[j]+v[i]<<"\n";
                    flag=true;
                    break;
                }
            }
            
            if (flag)
                break;
        }
        
        if (!flag)
            cout<<"0\n";
    }
}
