#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

ll t,n,m,a,b,c;
ll dp[1010]={0,};
vector<pair<ll,ll>> v[1010];        //연결 정점, 가중치

ll solve(ll idx, ll par){
    if (v[idx].size()==1 && v[idx][0].first==par){
        return dp[idx];
    }

    ll temp=0;
    for (int i=0;i<v[idx].size();i++){
        ll next = v[idx][i].first;
        if (next==par)
            continue;
        
        dp[next]=v[idx][i].second;
        temp+=solve(next,idx);
    }
//    cout<<idx<<" "<<par<<": "<<temp<<" "<<dp[idx]<<"*\n";
    
    if (temp<dp[idx])
        dp[idx]=temp;
    
    return dp[idx];
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>t;
    while (t--){
        cin>>n>>m;
        
        for (int i=1;i<=n;i++)
            v[i].clear();
        
        for (int i=1;i<=n;i++)
            dp[i]=0;
        
        for (int i=0;i<m;i++){
            cin>>a>>b>>c;
            v[a].push_back({b,c});
            v[b].push_back({a,c});
        }
        
        dp[1]=987654321;
        cout<<solve(1,0)<<'\n';
    }
}
