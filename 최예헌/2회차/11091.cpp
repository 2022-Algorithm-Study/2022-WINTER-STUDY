#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    bool check[26];
    
    
    cin>>n;
    cin.ignore();
    while (n--){
        string str;
        memset(check,false,sizeof(check));
        vector <char> result;
        
        getline(cin,str);
        for (int i=0;i<str.size();i++){
            if ('a'<= str[i] && str[i]<='z'){
                check[str[i]-'a']=true;
            }
                    
            else if ('A'<= str[i] && str[i]<='Z'){
                check[str[i]-'A']=true;
            }
        }
                
        bool flag=true;
        for (int i=0;i<26;i++){
            if (!check[i]){
                flag=false;
                result.push_back(i+'a');
            }
        }
                
        if (flag)
            cout<<"pangram\n";

        else{
            cout<<"missing ";
            for (int i=0;i<result.size();i++)
                cout<<result[i];
            cout<<'\n';
        }
    }
}
