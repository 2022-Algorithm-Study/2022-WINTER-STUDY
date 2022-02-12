#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    string s,t;
    
    while (cin>>s>>t){      // 여기에 !cin.eof()를 넣으면 틀림.... 끝나는 단축키뭘까..  control+D
        int num=0;
        
        for (int i=0;i<t.size();i++){
            if (num>=s.size())
                break;
            
            if (t[i] == s[num])
                num++;
        }
        if (num>=s.size())
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}
