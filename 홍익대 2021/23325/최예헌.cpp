#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    string s;
    int arr[200001];
    int dp[200001];
    
    cin>>s;
    for (int i=0;i<s.size();i++){
        if (s[i]=='+'){
            arr[i+1]=10;
        }
        else if (s[i]=='-'){
            arr[i+1]=1;
        }
    }
    for (int i=0;i<200001;i++)
        dp[i]=-20000000;
    
    dp[0]=0;
    dp[1]=arr[1];
    
    if (arr[1]==10 && arr[2]==1)
        dp[2]=11;
    else
        dp[2]=-20000000;
    
    if (arr[2]==10)
        dp[3]=arr[1]+arr[3];
    else
        dp[3]=arr[1]-arr[3];
    
    
    for (int i=4;i<=s.size();i++){
        if (arr[i-1]==10 && arr[i]==1){
            if (arr[i-2]==10)
                dp[i]=max(dp[i-3]+11,dp[i]);
            else
                dp[i]=max(dp[i-3]-11,dp[i]);
        }
        
        
        if (arr[i-1]==10)       //더하기
            dp[i]=max(dp[i-2]+arr[i],dp[i]);
        else                    //빼기
            dp[i]=max(dp[i-2]-arr[i],dp[i]);
    }
    cout<<dp[s.size()];
}
