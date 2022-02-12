 #include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    map<int,int> map;
    int result=0;
    
    cin>>n;
    vector <int> A(n);
    vector <int> B(n);
    
    
    for (int i=0;i<n;i++)
        cin>>A[i];
    
    for (int i=0;i<n;i++)
        cin>>B[i];
    
    sort(A.begin(),A.end(),greater<>());
    sort(B.begin(),B.end());
    
    for (int i=0;i<n;i++){
        result += (A[i]*B[i]);
    }
    
    cout<<result;
}
