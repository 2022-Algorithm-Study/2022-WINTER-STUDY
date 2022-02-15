// 멀티셋, 내장 함수 lower_bound
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll n,m,a,b;
    vector <pair<ll,ll>> stop;
    vector <pair<ll,ll>> bus;
    ll result=0;
    
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>a>>b;
        stop.push_back({a,b});
    }
    
    for (int i=0;i<m;i++){
        cin>>a>>b;
        bus.push_back({a,b});
    }
    sort(stop.begin(),stop.end());
    sort(bus.begin(),bus.end());
    
    int k=0;        //배차
    
    multiset<ll> s;
    for (int i=0;i<bus.size();i++){
        
        while (stop[k].first <= bus[i].first){
            if (k>=n)
                break;
            
            s.insert(stop[k].second);
            k++;
        }
        
        if (s.empty())
            continue;
        
        auto iter = s.lower_bound(bus[i].second);
        if (iter != s.end()){
            result++;
            s.erase(iter);
        }
    }
    cout<<result;
}

