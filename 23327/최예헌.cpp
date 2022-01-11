#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll n,q;
    ll l,r;
    ll arr[100001];     //팀 인기
    ll num[100001];     //인기 누적합
    ll dp[100001];      //디비전의 재미
    
    cin>>n>>q;
    arr[0]=num[0]=dp[0]=0;
    for (int i=1;i<=n;i++){
        cin>>arr[i];
        num[i]=num[i-1]+arr[i];
        dp[i]=dp[i-1]+num[i-1]*arr[i];
    }
    
    while (q--){
        cin>>l>>r;
        cout<<dp[r]-dp[l-1]-(num[l-1]*(num[r]-num[l-1]))<<'\n';
    }
}
