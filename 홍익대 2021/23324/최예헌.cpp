#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll n,m,k;
ll u,v;
vector <ll> arr[202020];
bool visit[202020];
ll a,b;
ll cnt,cnt1,cnt2;

void dfs(ll x){
    visit[x]=true;
    cnt++;
    for (int i=0;i<arr[x].size();i++){
        if (!visit[arr[x][i]])
            dfs(arr[x][i]);
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n>>m>>k;
    
    for (int i=1;i<=m;i++){
        cin>>u>>v;
        if (i==k){
            a=u;
            b=v;
        }
        else {
            arr[u].push_back(v);
            arr[v].push_back(u);
        }
    }
    cnt=0;
    dfs(a);
    cnt1=cnt;

    if (visit[b])
        cout<<"0";
    else{
        cnt=0;
        dfs(b);
        cnt2=cnt;
        
        cout<<cnt1*cnt2;
    }
    
//    dfs로 순환 확인
//    비순환이면 양 노드 간선+1의 곱으로 값 구함
}
