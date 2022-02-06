#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    long double n,x,c;
    vector <long double> v;
    bool check[101010];
    ll result=0;

    cin>>n>>x;
    for (int i=0;i<n;i++){
        cin>>c;

        if (c==x)
            result++;

        else
            v.push_back(c);
    }

    if (v.empty() || v.size()==1){
        cout<<result;
        return 0;
    }

    sort(v.begin(),v.end());

    ll s = 0;
    ll e = v.size()-1;

    while (s<e){
        if (v[s]+v[e] >= (x/2)){
            result++;
            check[s]=check[e]=true;
            s++;
            e--;
        }

        else{
            s++;
        }
    }

    int cnt=0;
    for (int i=0;i<v.size();i++){
        if (!check[i]){
//            cout<<i<<" ";
            cnt++;
        }
    }
    cout<<result + (cnt/3);
}
