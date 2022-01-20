#include <iostream>
#include <map>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    map <char,string> m;
    string str1,str2;
    
    m.insert({'A',"a"});
    m.insert({'B',"v"});
    m.insert({'E',"ye"});
    m.insert({'K',"k"});
    m.insert({'M',"m"});
    m.insert({'H',"n"});
    m.insert({'O',"o"});
    m.insert({'P',"r"});
    m.insert({'C',"s"});
    m.insert({'T',"t"});
    m.insert({'Y',"u"});
    m.insert({'X',"h"});
    
    cin>>str1;
    
    for (int i=0;i<str1.size();i++){
        str2+=m[str1[i]];
    }
    cout<<str2;
}
