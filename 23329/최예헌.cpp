#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;

ll n,s,e;
vector <pair<ll,ll>> arr;     //좌표
ll cost[100001];               //비용
int dir[100001];                //방향
ll x,y,c;
string d;
vector <pair<ll,ll>> v[100001];       //이동가능 발사기, 비용

priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;   //비용, 번호 (오름차순)
bool visit[100001];
ll dist[100001][2];        //0: 비용 , 1: 부모번호

int numDir(string d){       //방향을 정수로 변환
    if (d=="N")
        return 0;
    else if (d=="NE")
        return 1;
    else if (d=="E")
        return 2;
    else if (d=="SE")
        return 3;
    else if (d=="S")
        return 4;
    else if (d=="SW")
        return 5;
    else if (d=="W")
        return 6;
    else if (d=="NW")
        return 7;
    return -1;
}

int check(int a,int b){     //현재 방향, 갈 수 있는 방향
    if (a<=b)
        return b-a;
    
    return (8-a)+b;
}

void solve(int i,int j){
    
    if (arr[i].first == arr[j].first){              //x축 좌표 같은 경우
        if (arr[i].second < arr[j].second){
            v[i+1].push_back({j+1,cost[i+1]*check(dir[i+1],0)});
            v[j+1].push_back({i+1,cost[j+1]*check(dir[j+1],4)});
        }
        
        else if (arr[i].second > arr[j].second){
            v[i+1].push_back({j+1,cost[i+1]*check(dir[i+1],4)});
            v[j+1].push_back({i+1,cost[j+1]*check(dir[j+1],0)});
        }
    }
    
    else if (arr[i].second == arr[j].second){       //y축 좌표 같은 경우
        if (arr[i].first < arr[j].first){
            v[i+1].push_back({j+1,cost[i+1]*check(dir[i+1],2)});
            v[j+1].push_back({i+1,cost[j+1]*check(dir[j+1],6)});
        }
        
        else if (arr[i].first > arr[j].first){
            v[i+1].push_back({j+1,cost[i+1]*check(dir[i+1],6)});
            v[j+1].push_back({i+1,cost[j+1]*check(dir[j+1],2)});
        }
    }
    
    else if (abs(arr[i].first-arr[j].first)==abs(arr[i].second-arr[j].second)){     //대각선 위치
        if (arr[i].first > arr[j].first){
            if (arr[i].second > arr[j].second){
                v[i+1].push_back({j+1,cost[i+1]*check(dir[i+1],5)});
                v[j+1].push_back({i+1,cost[j+1]*check(dir[j+1],1)});
            }
            else{
                v[i+1].push_back({j+1,cost[i+1]*check(dir[i+1],7)});
                v[j+1].push_back({i+1,cost[j+1]*check(dir[j+1],3)});
            }
        }
        else{
            if (arr[i].second > arr[j].second){
                v[i+1].push_back({j+1,cost[i+1]*check(dir[i+1],3)});
                v[j+1].push_back({i+1,cost[j+1]*check(dir[j+1],7)});
            }
            else{                              
                v[i+1].push_back({j+1,cost[i+1]*check(dir[i+1],1)});
                v[j+1].push_back({i+1,cost[j+1]*check(dir[j+1],5)});
            }
        }
    }
}

void dijk(){
    
    q.push({0,s});
    visit[s]=true;
    dist[s][0]=0;
    dist[s][1]=s;
    
    while (!q.empty()){
        ll now_cost = q.top().first;
        ll now_num = q.top().second;
        q.pop();
        visit[now_num]=true;

        if (now_num == e){
            cout<<now_cost<<'\n';
            return;
        }
        
        for (int i=0;i<v[now_num].size();i++){
            ll next_num = v[now_num][i].first;
            ll next_cost = v[now_num][i].second;
            if (visit[next_num])
                continue;
            
            if (now_cost + next_cost < dist[next_num][0]){
                dist[next_num][0]=now_cost+next_cost;
                dist[next_num][1]=now_num;
                q.push({now_cost+next_cost,next_num});
            }
        }
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n>>s>>e;
    for (int i=1;i<=n;i++){
        cin>>x>>y>>c>>d;
        arr.push_back({x,y});
        cost[i]=c;
        dir[i]=numDir(d);
    }
    
    for (int i=1;i<arr.size();i++){
        for (int j=0;j<i;j++){
            solve(i,j);
        }
    }
//    for (int i=1;i<=n;i++){
//        for (int j=0;j<v[i].size();j++){
//            cout<<v[i][j].first<<" "<<v[i][j].second<<'\n';
//        }
//        cout<<'\n';
//    }

    memset(visit,false,sizeof(false));
    for (int i=0;i<100001;i++){
        dist[i][0]=10000000;
    }
    dijk();
    if (!visit[e]){
        cout<<"-1";
        return 0;
    }

    ll temp=e;
    vector <ll> result;
    while(1){
        result.push_back(temp);
        if (temp==s)
            break;
        temp=dist[temp][1];
    }

    for (int i=result.size()-1;i>=0;i--)
        cout<<result[i]<<' ';
}
