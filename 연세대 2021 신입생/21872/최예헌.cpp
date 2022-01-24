#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
    int g,k,l;
    int n,m;
    string s,t;
    
    cin>>g>>k>>l;
    while(g--){
        cin>>n>>s>>m>>t;
        
        if (k==1||n==m){
            cout<<"YS"<<'\n';
        }
        else if (n<m){
            cout<<"Y"<<'\n';
        }
        else if (n>m){
            cout<<"S"<<'\n';
        }
    }
}
