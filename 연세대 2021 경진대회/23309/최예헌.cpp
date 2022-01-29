#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;

typedef struct Node{
    int llink;
    int rlink;
};

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n,m;
    int arr[1005];
    Node station[1005];
    string str;
    int a,b;
    
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    for (int i=0;i<n;i++){
        if (i==0){
            station[arr[i]].llink = arr[n-1];
            station[arr[i]].rlink = arr[i+1];
        }
        else if (i==n-1){
            station[arr[i]].llink = arr[i-1];
            station[arr[i]].rlink = arr[0];
        }
        else{
            station[arr[i]].llink = arr[i-1];
            station[arr[i]].rlink = arr[i+1];
        }
    }
    
    while (m--){
        cin>>str>>a;
        if (str == "BN"){
            cin>>b;
            int next = station[a].rlink;
            cout<<next<<'\n';
            station[a].rlink = b;
            station[next].llink = b;
            station[b].llink = a;
            station[b].rlink = next;
            
        }
        else if (str == "BP"){
            cin>>b;
            int pre = station[a].llink;
            cout<<pre<<'\n';
            station[a].llink = b;
            station[pre].rlink = b;
            station[b].llink = pre;
            station[b].rlink = a;
        }
        else if (str == "CN"){
            int next = station[a].rlink;
            cout<<next<<'\n';
            station[a].rlink = station[next].rlink;
            station[station[next].rlink].llink = a;
        }
        else if (str == "CP"){
            int pre = station[a].llink;
            cout<<pre<<'\n';
            station[a].llink = station[pre].llink;
            station[station[pre].llink].rlink = a;
        }
    }
}

