#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n,m;
int a,b,c;
int arr[13][13]={0,};
vector <int> v[13];
bool visit[13];

int result=-1;
vector <int> result_arr;

void solve(int idx,int start,int cnt,vector<int> vec){
    
    if (cnt==n){          //다 방문한 경우 다시 시작점으로
        if (arr[idx][start]==0)         //순회가 아닌 경우
            return;
        
        vec.push_back(start);
        int temp=0;
        for (int i=0;i<vec.size()-1;i++){
            temp=max(temp,arr[vec[i]][vec[i+1]]);
        }
        if (result == -1 || temp<result){
            result=temp;
            result_arr=vec;
        }
        return;
    }
    
    for (int i=0;v[idx].size();i++){
        if (v[idx][i]==start)
            continue;
        
        if (!visit[v[idx][i]]){
            visit[v[idx][i]]=true;
            vec.push_back(v[idx][i]);
            solve(v[idx][i],start,cnt+1,vec);
            vec.pop_back();
            visit[v[idx][i]]=false;
        }
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n>>m;
    for (int i=0;i<m;i++){
        cin>>a>>b>>c;
        arr[a][b]=c;
        v[a].push_back(b);
    }
    
    for (int i=1;i<=n;i++){
        vector <int> vec;
        visit[i]=true;
        vec.push_back(i);
        solve(i,i,1,vec);
        visit[i]=false;
    }
    
    if (result==-1)
        cout<<"-1";
    
    else{
        cout<<result<<"\n";
        for (int i=0;i<result_arr.size();i++)
            cout<<result_arr[i]<<" ";
    }
}

