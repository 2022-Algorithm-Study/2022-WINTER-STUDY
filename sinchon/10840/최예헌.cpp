//
#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

ll p[26];
string n,m;
ll state[1505];

void clearp() {
    p[0] = 1;
    for (int i = 1; i < 26; i++) p[i] = p[i - 1] * 1501;
}

ll solve(string s,int idx,int size){
    ll hash;
    if (idx==0){
        hash=0;
        for(int i = 0; i < size; i++){
            hash += p[s[i]-'a'];
        }
    }
    
    else{
        hash = state[idx-1];
        hash -= p[s[idx-1]-'a'];
        hash += p[s[idx+size-1]-'a'];
    }
    
    state[idx]=hash;
    return hash;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
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
    
    clearp();
    while (result){
        
        set<ll> s;
        bool flag=false;
        
        if (k==0){
            state[0]=0;
            for (int i=0;i+result-1<n.size();i++){
                s.insert(solve(n,i,result));
    //               cout<<temp<<"*\n";
            }
               
            state[0]=0;
            for (int i=0;i+result-1<m.size();i++){
                ll temp = solve(m,i,result);
                if (s.find(temp)!=s.end()){
    //                    cout<<temp<<"** ";
                    flag=true;
                    break;
                }
            }
        }
        
        else{
            state[0]=0;
            for (int i=0;i+result-1<n.size();i++){
                s.insert(solve(m,i,result));
    //               cout<<temp<<"*\n";
            }
                
            state[0]=0;
            for (int i=0;i+result-1<m.size();i++){
                ll temp = solve(n,i,result);
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


