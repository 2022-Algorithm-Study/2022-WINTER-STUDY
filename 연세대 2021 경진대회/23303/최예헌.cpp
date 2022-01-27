//cin getline : 공백 포함 입력 문자열
#include <iostream>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    string str;
    bool flag = false;
    
    getline(cin,str);
    for (int i=0;i<str.size();i++){
        if (str[i]=='d' || str[i]=='D'){
            if (str[i+1]=='2'){
                flag=true;
                break;
            }
        }
    }
    if (flag)
        cout<<"D2";
    else
        cout<<"unrated";
}
