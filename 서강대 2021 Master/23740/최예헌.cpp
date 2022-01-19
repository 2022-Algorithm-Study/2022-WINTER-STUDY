#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
typedef long long ll;

bool cmp(tuple<ll,ll,ll> a,tuple<ll,ll,ll> b){
    if (get<0>(a)==get<0>(b)){
        if (get<1>(a)==get<1>(b)){
            return get<2>(a) < get<2>(b);
        }
        return get<1>(a) < get<1>(b);
    }
    return get<0>(a) < get<0>(b);
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll n,s,e,c;
    vector <tuple<ll,ll,ll>> v;
    vector <tuple<ll,ll,ll>> result;
    
    cin>>n;
    while (n--){
        cin>>s>>e>>c;
        v.push_back({s,e,c});
    }
    sort(v.begin(),v.end(),cmp);
    
    ll start = get<0>(v[0]);
    ll end = get<1>(v[0]);
    ll cost = get<2>(v[0]);
    
    for (int i=1;i<v.size();i++){
        if (get<0>(v[i]) > end){
            result.push_back({start,end,cost});
            start=get<0>(v[i]);
            end=get<1>(v[i]);
            cost=get<2>(v[i]);
        }
        
        else{
            end = get<1>(v[i]);
            if (get<2>(v[i]) < cost)
                cost=get<2>(v[i]);
        }
    }
    result.push_back({start,end,cost});
    cout<<result.size()<<'\n';
    for (int i=0;i<result.size();i++){
        cout<<get<0>(result[i])<<" "<<get<1>(result[i])<<" "<<get<2>(result[i])<<'\n';
    }
    
}
