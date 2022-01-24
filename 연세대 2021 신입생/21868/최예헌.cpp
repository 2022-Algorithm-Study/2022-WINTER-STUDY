#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int e1,e2;
    int a,b;
    int x;
    
    cin>>e1>>e2>>a>>b>>x;
    cout<<a*x+b<<'\n';
    
    if (a==0){
        cout<<"0 0";
        return 0;
    }
    cout<<e1<<" "<<abs(a)*e2;

}
