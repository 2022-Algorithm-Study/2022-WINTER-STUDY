#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll n,m;
    char x;
    ll arr[3030][3030];        //0: black , 1: white
    ll dp[3030][3030];
    ll result=0;
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>x;
            if (x=='B')
                arr[i][j] = 0;
            else
                arr[i][j] = 1;
            
            if (i==1 || j==1)
                dp[i][j]=0;
        }
    }
    
    for (int i=2;i<=n;i++){
        for (int j=2;j<=m;j++){
            ll xmin = 54321;
            if (arr[i][j]==arr[i-1][j-1] && arr[i-1][j]==arr[i][j-1] && arr[i][j]!=arr[i-1][j]){
                xmin = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                dp[i][j]=xmin+1;
                result+=dp[i][j];
            }
            
            else
                dp[i][j]=0;
        }
    }
    
    result+=(n*m);
    cout<<result;
}

//bwbw
//wbww
//bwbw
//bbwb

