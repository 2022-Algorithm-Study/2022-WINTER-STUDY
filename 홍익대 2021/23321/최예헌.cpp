#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    string str[5];
    string a="owln.";
    string b=".omln";
    
    for (int i=0;i<5;i++){
        cin>>str[i];
    }
    
    for (int i=0;i<str[1].size();i++){
        if (str[1][i]=='o'){
            for (int j=0;j<5;j++){
                str[j][i]=a[j];
            }
        }
        
        else if (str[1][i]=='w'){
            for (int j=0;j<5;j++){
                str[j][i]=b[j];
            }
        }
        
    }
    
    for (int i=0;i<5;i++){
        cout<<str[i]<<'\n';
    }
}

