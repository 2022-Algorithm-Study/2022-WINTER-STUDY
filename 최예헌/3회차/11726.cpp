#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    int dp[1010];
    
    dp[1]=1;
    dp[2]=2;
    
    cin>>n;
    if (n<=2){
        cout<<dp[n];
        return 0;
    }
    
    for (int i=3;i<=n;i++){
        dp[i] = (dp[i-1]+dp[i-2])%10007;
    }
    cout<<dp[n];
}
