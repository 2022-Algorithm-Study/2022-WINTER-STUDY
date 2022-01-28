//endl: \n과 같은 역할을 하나, 추가로 버퍼 비워주는 flush 역할 함
#include <iostream>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n,a,b;
    cin>>n;
    cout<<"? 1"<<endl;
    cin>>a;
    cout<<"? "<<n<<endl;
    cin>>b;
    
    if (a<b)
        cout<<"! 1"<<endl;
    else if (a==b)
        cout<<"! 0"<<endl;
    else
        cout<<"! -1"<<endl;
    return 0;
}
