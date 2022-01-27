#include <iostream>
#include <cstring>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n,x;
    int num[1000005];
    int cnt=0;
    
    cin>>n;
    
    memset(num,0,sizeof(num));
    for (int i=0;i<n;i++){
        cin>>x;
        num[x]++;
    }
    
    for (int i=0;i<n;i++){
        cin>>x;
        if (num[x]==0)
            cnt++;
        else
            num[x]--;

    }
    cout<<cnt;
}
