#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll n,x;
    
    cin>>n;
    vector <ll> arr(n);
    
    while (n--){
        cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end(),greater<>());
    
    for (int i=0;i<arr.size()-2;i++){
        if (arr[i] < arr[i+1]+arr[i+2]){
            cout<<arr[i]+arr[i+1]+arr[i+2];
            return 0;
        }
    }
    cout<<"-1";
}
