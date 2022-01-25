#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll n;
ll arr[202020];

ll gcd(ll x, ll y){
    if (!y)
        return x;
    return gcd(y, x % y);
}

ll solve(ll s,ll e){
    
    if (s==e){
        return arr[s];
    }
    ll mid_f,mid_b;
    ll front_gcd,back_gcd;
    ll front_result,back_result;
    
    if ((e-s+1)%2 ==0 ){
        mid_f = mid_b = (e-s+1)/2;
    }
    else{
        mid_f = (e-s+1)/2;
        mid_b = (e-s+1)/2+1;
    }
    
    front_gcd = arr[s];
    for (int i=0;i<mid_f;i++){
        front_gcd = gcd(front_gcd,arr[s+i]);
    }
    
    back_gcd = arr[e];
    for (int i=0;i<mid_b;i++){
        back_gcd = gcd(back_gcd,arr[e-i]);
    }
    
    front_result = front_gcd + solve(s+mid_f,e);
    back_result = back_gcd + solve(s,e-mid_b);
    
    if (front_result>back_result)
        return front_result;
    else
        return back_result;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>arr[i];
    
    cout<<solve(1,n);
}
