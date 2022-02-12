#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    string str;
    cin>>str;
    
    int size = str.size();
    for (int i=0;i<(size/2-1);i++){
        if (str[i] != str[size-1-i]){
            cout<<"false";
            return 0;
        }
    }
    
    if (size%2 == 0){
        if (str[size/2] != str[size-1-(size/2)]){
            cout<<"false";
            return 0;
        }
    }
    cout<<"true";

}
