#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
#define MAX 1000000007

ll parent[200002];
ll height[200002];
ll root[200002];

ll Find(ll u){
    if (parent[u] == u)
        return u;
        
    return parent[u]=Find(parent[u]);    //find 하면서 만난 모든 부모노드 값을 root로
}

void Union(ll u,ll v){
    u=Find(u);
    v=Find(v);
    
    if (u==v)                //root 노드가 같은 경우 즉, 같은 트리인 경우
        return;
    
    //높이가 낮은 트리를 높이가 큰 트리 밑에 붙임. 즉, 높이가 큰 트리의 root 값을 가지도록 설정
    if (height[u]<height[v])
        swap(u,v);
    parent[v]=u;
    root[u]+=root[v];
    
    if (height[u]==height[v])
        height[u]++;
    return;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    ll a,b;
    ll result=1;
    map<ll,ll> mm;
    
    for (int i=0;i < 200002;i++){
        parent[i]=i;
    }
    for (int i=0;i < 200002;i++){
        root[i]=1;
    }
    
    cin>>n>>m;
    while (m--){
        cin>>a>>b;
        Union(a,b);
    }
    
//    for (int i=1;i<=n;i++)
//        cout<<parent[i]<<" ";
//    cout<<"\n";
    
    for (int i=1;i<=n;i++){
        if (Find(i)==i){
//            cout<<i<<" "<<root[i]<<"*\n";
            result*=root[i];
            result%=MAX;
        }
    }
    
//    for (int i=1;i<=n;i++)
//        cout<<root[i]<<" ";
    cout<<result%MAX;
    
}

//15 10
//1 4
//4 8
//8 9
//5 6
//5 7
//10 11
//12 13
//13 15
//12 14
//1 5

