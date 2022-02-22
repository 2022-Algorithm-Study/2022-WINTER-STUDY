//
#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
#define mod 1000000007

ll p[26];
void clearp() {
    p[0] = 1;
    for (int i = 1; i < 26; i++) p[i] = p[i - 1] * 1501;
}

ll solve(string s){
    ll hash=0;
    for(int i = 0; i < s.length(); i++){
        hash += p[s[i]-'a'];
    }
    return hash;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    string n,m;
    cin>>n>>m;
    
    ll k;
    ll result;
    
    if (n.size()<= m.size()){
        result=n.size();
        k=0;
    }
    
    else{
        result=m.size();
        k=1;
    }
    
    while (result){
        clearp();
        set<ll> s;
        bool flag=false;
        if (k==0){
            for (int i=0;i+result-1<n.size();i++){
                string s1 = n.substr(i,result);
                ll temp=solve(s1);
                s.insert(temp);
//                cout<<temp<<"*\n";
            }
            
            for (int i=0;i+result-1<m.size();i++){
                ll temp = solve(m.substr(i,result));
                if (s.find(temp)!=s.end()){
//                    cout<<temp<<"** ";
                    flag=true;
                    break;
                }
            }
        }
        
        else{
            for (int i=0;i+result-1<m.size();i++){
                string s1 = m.substr(i,result);
                ll temp=solve(s1);
                s.insert(temp);
//                cout<<temp<<"*\n";
            }
            
            for (int i=0;i+result-1<n.size();i++){
                ll temp = solve(n.substr(i,result));
                if (s.find(temp)!=s.end()){
//                    cout<<temp<<"** ";
                    flag=true;
                    break;
                }
            }
        }
        if (flag){
            break;
        }
        result--;
    }
    if (result<0)
        cout<<"0";
    else
        cout<<result;
}
