#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n,q,a,x,y;
    int cnt=0;
    int location=1;
    set <int> s;
    
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        cin>>a;
        if (a==1){
            cnt++;
            s.insert(i);
        }
    }
    
//    for (auto iter=s.begin();iter!=s.end();iter++){
//        cout<<*iter<<" ";
//    }
//    cout<<'\n';
    
    while (q--){
        cin>>x;
        if (x==1){
            cin>>y;
            if (s.find(y) != s.end()){
                s.erase(y);
                cnt--;
            }
            else{
                s.insert(y);
                cnt++;
            }
        }
        
        else if (x==2){
            cin>>y;
            y%=n;
            location+=y;
            if (location>n)
                location-=n;
        }
        
        else{
            if (cnt<=0)
                cout<<"-1"<<'\n';
            
            else{
                auto iter = s.lower_bound(location);
                if (iter!=s.end())
                    cout<< *iter-location <<'\n';
                else
                    cout<<n-location+(*s.begin())<<'\n';
            }
        }
    }
}
