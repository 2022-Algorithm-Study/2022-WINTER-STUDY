#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n,a,b,u,v;
    int arr[1000001];
    unordered_map <int,int> map;          //나라별 섬 개수
    
    arr[0]=0;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a>>b;
        arr[i]=arr[i-1]+a;
        for (int j=0;j<b;j++){
            cin>>u>>v;
        }
        map.insert({i,a-b});
    }
        
    int q;
    int x,y,z;
    
    cin>>q;
    while (q--){
        cin>>x;
        if (x==1){
            cin>>y;
            cout<<map[y]<<'\n';
        }
        
        else if (x==2){
            cin>>y>>z;
            for (int i=1;i<=n;i++){
                if (arr[i-1]+1<=y && y<= arr[i]){
                    map[i]++;
                    break;
                }
            }
        }
        
        else if (x==3){
            cin>>y>>z;
            for (int i=1;i<=n;i++){
                if (arr[i-1]+1<=y && y<= arr[i]){
                    map[i]--;
                    break;
                }
            }
        }
    }
}
