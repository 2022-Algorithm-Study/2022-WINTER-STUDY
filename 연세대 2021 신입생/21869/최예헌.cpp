#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    
    if (n==1){
        cout<<"1"<<'\n'<<"1 1";
        return 0;
    }
    
    cout<<2*n-2<<'\n';
    for (int i=1;i<=n;i++){
        cout<<"1 "<<i<<'\n';
    }
    for (int i=2;i<n;i++){
        cout<<n<<" "<<i<<'\n';
    }
}
