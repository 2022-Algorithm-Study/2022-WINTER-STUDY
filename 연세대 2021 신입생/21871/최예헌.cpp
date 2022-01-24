#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll n,k;
    ll sum=0;
    ll a,m;
    
    cin>>n>>k;
    
    if (k>=2*n+1){
        cout<<(2*n+1)*(2*n+1);
        return 0;
    }
    
    a=2*n-1;
    m=(2*n-k+1)/2;
    sum = m*(2*a+(m-1)*(-2));
    
    cout<<sum + (2*n+1)*k;
    
}
