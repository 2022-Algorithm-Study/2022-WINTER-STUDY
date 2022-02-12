#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    int arr[505][505];
    int dp[505][505];
    
    cin>>n;
    vector<int> v(n);
    
    dp[0][0]=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            cin>>dp[i][j];
            
            if (j==1){
                dp[i][j] = dp[i-1][1]+dp[i][j];
            }
            
            else if (j==i){
                dp[i][j] = dp[i-1][j-1]+dp[i][j];
            }
            
            else{
                dp[i][j]=max(dp[i-1][j-1]+dp[i][j] , dp[i-1][j]+dp[i][j]);
            }
        }
    }
    int result=0;
    for (int i=1;i<=n;i++){
        result = max(result,dp[n][i]);
    }
    cout<<result;
}
