#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef tuple<int,int,int> tll;

int n,m;
int vi1_i,vi1_j,vi2_i,vi2_j;
int arr[1010][1010];
int check[1010][1010];

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

//struct city{
//    int y;
//    int x;
//    int vir;
//
//    city(int y, int x, int vir) {
//            this->y = y;
//            this->x = x;
//            this->vir = vir;
//    }
//
//};

void solve(void){
    priority_queue< pair<int,tll>, vector<pair<int,tll>>,greater<pair<int,tll>> > q;         //시간,바이러스,i,j
    
    q.push({0,{vi1_i,vi1_j,1}});
    q.push({0,{vi2_i,vi2_j,2}});
    
    while (!q.empty()){
        int now_time=q.top().first;
        int now_y=get<0>(q.top().second);
        int now_x=get<1>(q.top().second);
        int now_vir=get<2>(q.top().second);
        q.pop();
        
        if (arr[now_y][now_x] == 3)
            continue;

        
        for (int k=0;k<4;k++){
            int nexty=now_y+dy[k];
            int nextx=now_x+dx[k];
            
            if (nexty<0 || nexty>=n || nextx<0 || nextx>=m )
                continue;
            
            if (arr[nexty][nextx] == -1)
                continue;
            
            if (arr[nexty][nextx]!=0){          // 이미 그 마을에 바이러스가 존재할 때
                if (check[nexty][nextx]!=now_time+1)          //바이러스에 완전히 감염된 경우
                    continue;
                
                if (arr[nexty][nextx]==3)
                    continue;
                
                if (arr[nexty][nextx] != now_vir){          //현재 바이러스랑 같지 않으면
                    arr[nexty][nextx]=3;
                }
            }
            
            else{                       //바이러스가 존재하지 않는 경우
                arr[nexty][nextx]=now_vir;
                check[nexty][nextx]=now_time+1;
                q.push({now_time+1,{nexty,nextx,now_vir}});
            }
        }
        
//        for (int i=0;i<n;i++){
//            for (int j=0;j<m;j++){
//                cout<<arr[i][j]<<" ";
//            }
//            cout<<"\n";
//        }
//        cout<<"\n";
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n>>m;
    
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>arr[i][j];
            if (arr[i][j]==1)
                vi1_i=i, vi1_j=j;
            else if (arr[i][j]==2)
                vi2_i=i, vi2_j=j;
            
        }
    }
    solve();
    
    int result1=0,result2=0,result3=0;
    
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
//            cout<<arr[i][j]<<" ";
            if (arr[i][j]==1)
                result1++;
            else if (arr[i][j]==2)
                result2++;
            else if (arr[i][j]==3)
                result3++;
        }
//        cout<<"\n";
    }
    cout<<result1<<" "<<result2<<" "<<result3;
}
