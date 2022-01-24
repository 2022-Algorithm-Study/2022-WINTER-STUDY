#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int arr[9]={100,100,200,200,300,300,400,400,500};
    int sum=0;
    int x;
    
    for (int i=0;i<9;i++){
        cin>>x;
        if (x>arr[i]){
            cout<<"hacker";
            return 0;
        }
        
        else
            sum+=x;
    }
    if (sum>=100)
        cout<<"draw";
    else
        cout<<"none";
}
