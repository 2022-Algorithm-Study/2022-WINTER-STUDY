#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
#define mod 1505

ll solve(string s){
    ll hash=0;
    for(int i = 0; i < s.length(); i++){
        hash+=pow(26,(s[i]-'a'));
        hash%=mod;
    }
    return hash;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    string n,m;

    cin>>n>>m;
    
    ll l=0;
    ll r,k;
    ll result=0;
    
    if (n.size()<=m.size()){
        r=n.size();
        k=0;
    }
    
    else{
        r=m.size();
        k=1;
    }
    
    while (l<=r){
        set<ll> s;
        ll mid = ceil((double)(l+r)/2);
        
        bool flag=false;
        if (k==0){
            for (int i=0;i+mid-1<n.size();i++){
                string s1 = n.substr(i,mid);
                ll temp=solve(s1);
                s.insert(temp);
//                cout<<temp<<"*\n";
            }
            
            for (int i=0;i+mid-1<m.size();i++){
                ll temp = solve(m.substr(i,mid));
                if (s.find(temp)!=s.end()){
//                    cout<<temp<<"** ";
                    flag=true;
                    break;
                }
            }
        }
        
        else{
            for (int i=0;i+mid-1<m.size();i++){
                string s1 = m.substr(i,mid);
                ll temp=solve(s1);
                s.insert(temp);
//                cout<<temp<<"*\n";
            }
            
            for (int i=0;i+mid-1<n.size();i++){
                ll temp = solve(n.substr(i,mid));
                if (s.find(temp)!=s.end()){
//                    cout<<temp<<"** ";
                    flag=true;
                    break;
                }
            }
        }
        if (flag){
            result=mid;
            l=mid+1;
        }
        else
            r=mid-1;
        
    }
    cout<<result;
}

