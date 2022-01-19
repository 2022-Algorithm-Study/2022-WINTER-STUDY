#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    using namespace std;
    
    ll n,a;
    vector <ll> arr1;
    vector <ll> arr2;
    ll sum=0;
    
    cin>>n;
    while (n--){
        cin>>a;
        if (a<0)
            arr1.push_back(a);
        
        else{
            arr2.push_back(a);
            sum+=a;
        }
    }
    
    sort(arr1.begin(),arr1.end(),greater<>());
    sort(arr2.begin(),arr2.end());
    
    ll size=arr2.size();
    ll result = sum*size;
    
    for (int i=0;i<arr1.size();i++){
        if ((sum*size)+arr1[i] > (sum+arr1[i])*(size+1)){
            result+=arr1[i];
        }
        
        else{
            result=result-(sum*size)+(sum+arr1[i])*(size+1);
            sum+=arr1[i];
            size+=1;
        }
    }
    cout<<result;
}
