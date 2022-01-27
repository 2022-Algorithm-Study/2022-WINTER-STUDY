#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

// == main ==
class Node
{
public:
    int x,y,c,d;
    Node(int x, int y,int c,int d){
        this->x=x;
        this->y=y;
        this->c=c;
        this->d=d;
    }
};

vector <Node> arr;     //구슬 발사기의 위치, 비용, 방향
ll n,s,e;
ll x,y,c;
string d;
vector <string> dir = {"N","NE","E","SE","S","SW","W","NW"};
int direction[8][2] = {0,1, 1,1, 1,0, 1,-1, 0,-1, -1,-1, -1,0, -1,1};

// == init 함수 ==
//key: int
//value: vector <tuple <int,int,int> >      x좌표, y좌표, 발사기 번호
unordered_map<ll,vector<tuple<ll,ll,ll>>> mp;

// == dijk 함수 ==
vector <pair<ll,ll>> v[100001];             //도착 이동가능 발사기, 비용
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;   //비용, 번호 (오름차순)
bool visit[100001];
ll dist[100001][2];                         //0: 비용 , 1: 부모번호


//연결 발사기와 이동 비용 구하기
void make_edge(ll i,ll j,ll d){
    ll w = (((8+d-arr[i-1].d)%8) * arr[i-1].c);
    v[i].push_back({j,w});
}

//발사기 사이 방향
void init(ll d){
    mp.clear();
    for (int i=0;i<arr.size();i++){
        mp[arr[i].x * direction[d][1] - arr[i].y * direction[d][0]].push_back({arr[i].x,arr[i].y,i+1});
    }
    
    for (auto iter = mp.begin(); iter!=mp.end(); iter++){
        vector v = iter->second;
        sort(v.begin(),v.end());        //정렬 꼭 필요. 없을 시 틀렸습니다.
        for (int i=1;i<v.size();i++){
//            cout<<".1."<<get<2>(v[i-1])<<" "<<get<2>(v[i])<<" "<<d<<'\n';
//            cout<<".2."<<get<2>(v[i])<<" "<<get<2>(v[i-1])<<" "<<(d+4)%8<<'\n';
            
            make_edge(get<2>(v[i-1]), get<2>(v[i]), d);
            make_edge(get<2>(v[i]), get<2>(v[i-1]), (d+4)%8);
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
            return;
        }
        
        for (int i=0;i<v[now_num].size();i++){
            ll next_num = v[now_num][i].first;
            ll next_cost = v[now_num][i].second;
            if (visit[next_num])
                continue;
            
            if (now_cost + next_cost < dist[next_num][0] || dist[next_num][0]==-1){
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
        arr.push_back(Node(x,y,c,find(dir.begin(),dir.end(),d)-dir.begin()));
    }
    
    for (int k=0;k<4;k++)
        init(k);
    
//    for (int i=1;i<=n;i++){
//        for (int j=0;j<v[i].size();j++){
//            cout<<v[i][j].first<<" "<<v[i][j].second<<'\n';
//        }
//        cout<<'\n';
//    }
    memset(visit,false,sizeof(false));
    for (int i=0;i<100001;i++){
        dist[i][0]=-1;
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

    cout<<dist[e][0]<<'\n';
    for (int i=result.size()-1;i>=0;i--)
        cout<<result[i]<<' ';
}
