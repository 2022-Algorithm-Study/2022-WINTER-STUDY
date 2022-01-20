#include <iostream>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    double n,t;
    cin>>n;
    
    double time=30.0;
    int cnt=0;
    
    for (int i=0;i<n;i++){
        cin>>t;
        if (t>=time){
            if (time >= t/2){
                cnt++;
            }
            time=30;
        }
        else{
            cnt++;
            time-=t;
        }
    }
    cout<<cnt;
}
