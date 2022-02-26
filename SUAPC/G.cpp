#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll n;
    string str;
    ll dp[100005][5]={0,};     //T,G,F,P , 값
    
    cin>>n>>str;
    ll result=0;
    
    for (ll i=1;i<=str.size();i++){
        for (int k=0;k<4;k++)
            dp[i][k]=dp[i-1][k];
        
        if (str[i-1]=='T')
            dp[i][0]++;
        
        else if (str[i-1]=='G')
            dp[i][1]++;
        
        else if (str[i-1]=='F')
            dp[i][2]++;
        
        else if (str[i-1]=='P')
            dp[i][3]++;
        
        
        if (i>=3){
            ll idx=-1;
            for (ll j=3;i-j>=0;j+=3){
                
                bool check=true;        //3의 배수인지 확인
                for (int k=0;k<4;k++){
                    if ((dp[i][k]-dp[i-j][k])%3!=0 && dp[i][k]-dp[i-j][k]!=0){
                        check=false;
                        break;
                    }
                }
                if (check){
                    idx=i-j;
                    break;
                }
            }
            
            if (idx!=-1){
                dp[i][4]+=(dp[idx][4]+1);
            }
        }
    }
    
    for (ll i=1;i<=str.size();i++){
//        cout<<i<<" "<<dp[i][4]<<"*\n";
        result+=dp[i][4];
    }
        
    cout<<result;
}

