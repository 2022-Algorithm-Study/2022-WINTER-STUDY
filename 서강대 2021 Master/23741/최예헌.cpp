#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n,m,x,y;
    int a,b;
    vector <int> arr[1001];
    int dp[1001][1001];
    vector <int> v;
    memset(dp,0,sizeof(dp));
    
    cin>>n>>m>>x>>y;
    for (int i=0;i<m;i++){
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dp[0][x]=1;
    for (int i=0;i<y;i++){
        for (int j=1;j<=n;j++){
            if (!dp[i][j])
                continue;
            
            for (int k=0;k<arr[j].size();k++){
                dp[i+1][arr[j][k]]=1;
                if (i==y-1)
                    v.push_back(arr[j][k]);
            }
        }
    }
    
    if (v.empty())
        cout<<"-1";
    
    else{
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        
        for (int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
    }
}
