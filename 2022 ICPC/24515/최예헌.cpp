#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
typedef long long ll;

ll n,cnt;
char area[1005][1005];        //영역
ll arr[1005][1005];          //영역을 숫자로
bool visit[1005][1005];
ll check[1005][1005];
ll dist[1005][1005];
ll m[1000005];

ll result=10000;

int dy[8]={-1,1,0,0,-1,-1,1,1};
int dx[8]={0,0,-1,1,-1,1,-1,1};

void dfs(ll i,ll j,ll num){
    visit[i][j]=true;
    arr[i][j]=num;
    
    for (int k=0;k<4;k++){
        ll nexty=i+dy[k];
        ll nextx=j+dx[k];
        
        if (nexty<0 || nexty>=n || nextx<0 || nextx>=n)
            continue;
        
        if (area[i][j] != area[nexty][nextx])
            continue;
        
        if (!visit[nexty][nextx]){
            dfs(nexty,nextx,num);
            cnt++;
        }
    }
}


void solve(ll i,ll j){
    priority_queue<tuple<ll,ll,ll>> q;
    //가중치값,i,j
    
//    for (int i=0;i<n;i++){
//        for (int j=0;j<n;j++){
//            dist[i][j]=10000;
//            visit[i][j]=false;
//        }
//    }
//    memset(visit,false,sizeof(visit));
    
    dist[i][j]=m[arr[i][j]];
    q.push({-dist[i][j],i,j});
    
    while (!q.empty()){
        ll weight=-get<0>(q.top());
        ll nowy=get<1>(q.top());
        ll nowx=get<2>(q.top());
//        visit[nowy][nowx]=true;
        q.pop();
        
        if (weight>result)
            return;
//        cout<<weight<<" "<<nowy<<" "<<nowx<<"\n";
        
        if (nowy==n-1 || nowx==0){
            result=min(result,weight);
            return;
        }
        
        for (int k=0;k<8;k++){
            ll nexty=nowy+dy[k];
            ll nextx=nowx+dx[k];
            
            if (nexty<0 || nexty>=n || nextx<0 || nextx>=n)
                continue;
            
            if (arr[nexty][nextx]==0){
//                visit[nexty][nextx]=true;
                continue;
            }
            
//            if (!visit[nexty][nextx]){
                if (arr[nowy][nowx] == arr[nexty][nextx]){
                    if (dist[nexty][nextx] > weight){
                        dist[nexty][nextx] = weight;
//                        cout<<nexty<<" "<<nextx<<" "<<dist[nexty][nextx]<<"**\n";
                        if (dist[nexty][nextx]<result)
                            q.push({-dist[nexty][nextx],nexty,nextx});
                    }
                }
                
                else{
                    if (dist[nexty][nextx] > weight+m[arr[nexty][nextx]]){
                        dist[nexty][nextx]=weight+m[arr[nexty][nextx]];
//                        cout<<nexty<<" "<<nextx<<" "<<dist[nexty][nextx]<<"**\n";
                        if (dist[nexty][nextx]<result)
                            q.push({-dist[nexty][nextx],nexty,nextx});
                    }
                }
//            }
        }
    }
    
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)
            cin>>area[i][j];
    }
    
    int temp=1;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (area[i][j]=='.'){
                arr[i][j]=0;
                continue;
            }
            
            if (!visit[i][j]){
                cnt=1;
                dfs(i,j,temp);
                m[temp]=cnt;
                temp++;
//                cout<<cnt<<" ";
            }
        }
    }
    
//    for (int i=0;i<n;i++){
//        for (int j=0;j<n;j++)
//            cout<<arr[i][j]<<" ";
//        cout<<"\n";
//    }
//
//    for (auto iter=m.begin();iter!=m.end();iter++)
//        cout<<iter->first<<" : "<<iter->second<<"\n";
    
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            dist[i][j]=10000;
        }
    }
    
    for (int i=1;i<n;i++){
        solve(0,i);

        if (i!=n-1)
            solve(i,n-1);
    }
//    solve(0,n-1);
    cout<<result;
}
