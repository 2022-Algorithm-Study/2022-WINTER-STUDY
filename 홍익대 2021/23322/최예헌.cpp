#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll n,k;
    ll arr[2002];
    ll cnt=0,day=0;
    
    cin>>n>>k;
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);

    for (ll temp=1;temp<n;temp++){
        if (arr[temp]!=arr[0])
            day++;
        cnt+=(arr[temp]-arr[0]);
        arr[temp]=arr[0];
    }
    cout<<cnt<<" "<<day;
}
