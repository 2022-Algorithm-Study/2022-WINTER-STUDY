#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    char b,x,s;
    int p=0,q=0;
    vector <char> v1;        //폭탄/쉴드 포함 안된 문자
    vector <char> v2;        //결과
    
    cin>>n>>b;
    s=b+32;
    while (n--){
        cin>>x;
        if (x==b){          //폭탄
            p++;
        }
        else if (x==s){     //쉴드
            q++;
        }
        else{
            v1.push_back(x);
        }
    }
    sort(v1.begin(),v1.end());
    
    if (v1.empty()){        //폭탄, 쉴드만 존재하는 경우
        for (int i=0;i<p;i++)
            v2.push_back(b);
        for (int i=0;i<q;i++)
            v2.push_back(s);
    }
    
    else if (q<2){          //쉴드 1개 이하
        
        if (s<v1.front() || (b<v1.front() && 'A'<=v1.front()<='Z')){    //앞에 넣는 경우
            while (p--){
                v2.push_back(b);
            }
            while (q--){
                v2.push_back(s);
            }
            for (int i=0;i<v1.size();i++)
                v2.push_back(v1[i]);
        }
        
        else{               //뒤에 넣는 경우
            for (int i=0;i<v1.size();i++)
                v2.push_back(v1[i]);
            while (q--){
                v2.push_back(s);
            }
            while (p--){
                v2.push_back(b);
            }
        }
    }
    
    else{               //쉴드 2개 이상
        int i=0;
        while (1){
            if (s<v1[i] || i==v1.size())
                break;
            
            v2.push_back(v1[i]);
            i++;
        }
        //쉴드|폭탄..|쉴드..
        v2.push_back(s);
        q--;
        while (p--){
            v2.push_back(b);
        }
        while (q--){
            v2.push_back(s);
        }
        
        //나머지 집
        if (i!=v1.size()){
            for (int j=i;j<v1.size();j++){
                v2.push_back(v1[j]);
            }
        }
    }

    for (int i=0;i<v2.size();i++){
        cout<<v2[i];
    }
}
