#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n,a,x,y;
    vector <int> v;
    
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    cin>>x>>y;
    sort(v.begin(),v.end());
    
    cout<<(n*x)/100<<" ";
    
    cout<<v.size()-(lower_bound(v.begin(), v.end(), y)-v.begin());
}
