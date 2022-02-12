#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    int arr[1010];
    int dp[1010]={0,};
    int result=0;
    
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>arr[i];
        
        if (i==0){
            dp[0]=arr[0];
            result=max(result,dp[i]);
            continue;
        }
        dp[i]=arr[i];
        for (int j=0;j<i;j++){
            if (arr[i] > arr[j])
                dp[i]=max(dp[i],dp[j]+arr[i]);
        }
        result=max(result,dp[i]);
    }
    cout<<result;
}
