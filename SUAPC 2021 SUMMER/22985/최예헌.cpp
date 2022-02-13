#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll n,m;
    string str;
//    ll dp[303][26]={0,};
    ll dp[303][75][2]={0,};     // 문자 , 횟수, z 존재 여부
    ll sumx=0;
    
    cin>>n>>m;
    cin>>str;
    
    
    for (int i=0;i<str.size();i++){
        int x = 'z'-str[i];
        sumx+=x;
        
        if (i==0){
            if (x>m){
                for (int k=0;k<=m;k++)
                    dp[i][k][0]=1;
            }
            
            else{
                for (int k=0;k<x;k++)
                    dp[i][k][0]=1;
                
                for (int k=x;k<=m;k++){
                    if (k>7503)
                        break;
                    
                    dp[i][k][1]=1;
                }
            }
            continue;
        }
        
        for (int j=0;j<=m;j++){
            if (j>7503)
                break;
            
            if (j==0){
                if (str[i]=='z')
                    dp[i][j][1]=1;
                else{
                    dp[i][j][0]=dp[i-1][j][0];
                    dp[i][j][1]=dp[i-1][j][1];
                }
            }
            
            else{
                dp[i][j][0] = dp[i-1][j][0]+dp[i][j-1][0];
                dp[i][j][1] = dp[i-1][j][1];
                
                if (j>=x){
                    dp[i][j][0]-=dp[i-1][j-x][0];
                    dp[i][j][1]+=dp[i-1][j-x][0];
                    
                    if (x!=0)
                        dp[i][j][1]+=dp[i-1][j-x][1];
                }
            }
        }
    }
    
//    for (int i=0;i<str.size();i++){
//        for (int j=0;j<=m;j++){
//            cout<<dp[i][j][0]<<" "<<dp[i][j][1]<<'\n';
//        }
//        cout<<'\n';
//    }
    
    ll result=0;
    if (sumx < m){
        for (int j=0;j<=sumx;j++){
            result+=dp[n-1][j][1];
            result%=1000000007;
        }
    }
    
    else{
        result = dp[n-1][m][0] % 1000000007;
        
        for (int j=0;j<=m;j++){
            result+=dp[n-1][j][1];
            result %= 1000000007;
        }
    }
    cout<<result;
}


// 2 2
// z a
// => 3
