#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll t,n,m;
    ll cnt;
    
    cin>>t;
    while (t--){
        cin>>n>>m;
        cnt=0;
        
        while (n>0){
            n/=2;
            cnt++;
        }
        cout<<m+cnt<<'\n';
    }
}
