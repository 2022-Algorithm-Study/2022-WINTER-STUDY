#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n,t;
ll a;
vector <pair<ll,ll>> arr;   //원래 자리, 현재 위치
long double result=0;

void solve(ll idx,vector <pair<ll,ll>> v){
    if (idx == n-1){
        sort(v.begin(),v.end());
        
        for (int i=0;i<v.size();i++){
            cout<<v[i].first<<" "<<v[i].second<<"\n";
        }
        cout<<'\n';
        for (int i=0;i<v.size()-1;i++){
            for (int j=i+1;j<v.size();j++){
                if (v[i].second>=v[j].second)
                    result++;
            }
        }
        return;
    }
    
    v[idx+1].second -= t;      // 왼쪽으로
    solve(idx+1,v);
    v[idx+1].second += t*2;      // 오른쪽으로
    solve(idx+1,v);
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a;
        arr.push_back({a,a});
    }
    cin>>t;
    sort(arr.begin(),arr.end());
    
    arr[0].second -= t;
    solve(0,arr);
    
    arr[0].second += t*2;
    solve(0,arr);
    
    long double temp=1;
    while (n--){
        temp*=2;
    }
    cout<<result/temp;
}
