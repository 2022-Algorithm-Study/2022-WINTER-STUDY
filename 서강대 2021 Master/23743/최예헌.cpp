#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n,m;
vector <pair <ll,ll>> v[202020];      //연결된 정점, 시간
vector <pair<ll,ll>> arr;             //시간, 정점번호
ll sum;
bool visit[202020];
ll result=0;

bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    return a.second<b.second;
}

void dfs(ll n){
    visit[n]=true;
    sort(v[n].begin(),v[n].end(),cmp);
    
    for (int i=0;i<v[n].size();i++){
        if (!visit[v[n][i].first]){
            sum+=v[n][i].second;
            dfs(v[n][i].first);
        }
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int a,b,c,t;
    
    cin>>n>>m;
    for (int i=0;i<m;i++){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    
    for (int i=1;i<=n;i++){
        cin>>t;
        arr.push_back({t,i});
    }
    sort(arr.begin(),arr.end());
    
    for (int i=0;i<arr.size();i++){
        if (!visit[arr[i].second]){
            sum=0;
            dfs(arr[i].second);
            
            result+=(sum+arr[i].first);
        }
    }
    cout<<result;

}
