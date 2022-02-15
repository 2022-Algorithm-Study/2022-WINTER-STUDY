//시작점에서 시작해서 처음과 두번째의 방향 고려
//길이 체크

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

int dy[4]={-1,0,1,0};       //i
int dx[4]={0,-1,0,1};       //j
string dir[4]={"D","R","U","L"};

ll n;
char x;
ll arr[1255][1255];
vector <pair<tuple<ll,ll,ll>,string>> result;        //좌표, 길이, 타입


bool cmp(pair<tuple<ll,ll,ll>,string> a,pair<tuple<ll,ll,ll>,string> b){
    if (get<0>(a.first) == get<0>(b.first))
        return get<1>(a.first) < get<1>(b.first);
    return get<0>(a.first) < get<0>(b.first);
}

bool check(int i,int j){        // 혼자 있는지 체크
    int cnt=0;
    for (int k=0;k<4;k++){
        ll nexty = i+dy[k];
        ll nextx = j+dx[k];
        
        if (nexty<=0 || nextx<=0 || nexty>n || nextx>n )
            continue;
        
        if (arr[nexty][nextx] == 1){
//            cout<<"**"<<nexty<<" "<<nextx<<"**\n\n";
            cnt++;
        }
    }
    if (cnt==1)
        return true;
    
    return false;
}

int getDir(int i,int j,int d){
    for (int k=0;k<4;k++){
        if ((k+d)%2 == 0)
            continue;
        
        ll nexty = i+dy[k];
        ll nextx = j+dx[k];
        
        if ( nexty<=0 || nextx<=0 || nexty>n || nextx>n )
            continue;
        
        if (arr[nexty][nextx])
            return k;
    }
    return -1;
}

void solve(int i,int j){
    int temp,length;
    
    int k;
    for (k=0;k<4;k++){
        ll nexty = i+dy[k];
        ll nextx = j+dx[k];
        
        if ( nexty<=0 || nextx<=0 || nexty>n || nextx>n )
            continue;
        
        if (arr[nexty][nextx]){
            temp=0;
            length=1;
            
            while (arr[nexty+(dy[k]*temp)][nextx+(dx[k])*temp]){
                length++;
                temp++;
            }
            break;
        }
    }
    
    if (length==3)
        return;
    
    ll ii = i+(length-1)*dy[k];     //두 번째 방향 시작점
    ll jj = j+(length-1)*dx[k];
    
    ll k1 = k;                      //첫 번째 방향
    ll k2 = getDir(ii,jj,k);        //두 번째 방향
    
    ll midLen = (length-1)/2+1;     //중점 길이
    ll midi,midj;
    
    if (k1==0 || k1==2){
        midi = i+dy[k1]*(midLen-1);
        midj = j+dx[k2]*(midLen-1);
    }
    
    else{
        midi = i+dy[k2]*(midLen-1);
        midj = j+dx[k1]*(midLen-1);
    }
    
    result.push_back({{midi,midj,length},dir[k1]+dir[k2]});
    return;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>x;
            if (x=='#')
                arr[i][j]=1;
            else
                arr[i][j]=0;
        }
    }
    
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (!arr[i][j])
                continue;
            
            if (check(i,j)){        //주변에 # 하나인 경우
                solve(i,j);
            }
        }
    }
    sort(result.begin(),result.end());
    
    cout<<result.size()<<"\n";
    for (int i=0;i<result.size();i++){
        cout<<get<0>(result[i].first)<<" "<<get<1>(result[i].first)<<" "<<get<2>(result[i].first)<<" "<<result[i].second<<'\n';
    }
    
}




/*
17
#.###.###.#.#.###
#.#.#.#.#.#.#.#.#
#.#.#.#.#.#.#.#.#
#...#.#...#.#...#
#####.#####.#####
.................
#.###.###.#.#.###
#.#.#.#.#.#.#.#.#
#.#.#.#.#.#.#.#.#
#...#.#...#.#...#
#####.#####.#####
.................
#.###.###.#.#.###
#.#.#.#.#.#.#.#.#
#.#.#.#.#.#.#.#.#
#...#.#...#.#...#
#####.#####.#####
*/

/*
 15
 #.#######.###.#
 #.#.....#.#.#.#
 #.#.###.#.#.#.#
 #.#.#.#.#.#...#
 #.#.#.#.#.#####
 #.#...#.#......
 #.#####.#......
 #.......#......
 #########......
 ...............
 .###.#....###.#
 .#.#.#....#.#.#
 .#.#.#....#.#.#
 .#...#....#...#
 .#####....#####
 */

/*
5
#####
#...#
#.#.#
#.#.#
#.###
*/

/*

 25
 ..........#####..........
 ..........#...#..........
 ..........#.#.#..........
 ..........#.#.#..........
 ..........###.#..........
 .........................
 #######.#.......#.#######
 #.....#.#.......#.#.....#
 #.###.#.#.......#.#.###.#
 #.#.#.#.#.......#.#.#.#.#
 #.#.#.#.#.......#.#.#.#.#
 #.#...#.#.......#.#...#.#
 #.#####.#.......#.#####.#
 #.......#.......#.......#
 #########.......#########
 .........................
 .........................
 .........................
 .........................
 .........................
 .........................
 .........................
 .........................
 .........................
 .........................
 
 */
