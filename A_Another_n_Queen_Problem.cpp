#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int t ,pos[16] ,col[16],left[16],rigt[16], first = 0 , sum  = 0, N;
char arr[16][16];



bool is_valid(int x , int y){
    for(int i=1;i<=N;i++){
        if (pos[i] == -1)continue;
        if(i == y || pos[i] == x || abs(i - y) == abs(pos[i] - x) ){
            return false;
        }
    }
    return true;
}


int calc_sum(){
    int s= 0;
    for(int i = 1 ; i <=N ; i ++){
        s += arr[pos[i]][i];
    }
    return s;
}

void solve(int x){
    if(x == N+1){
        sum ++;
        return;
    }

    for(int i = 1;i <=N;i++){
        if(is_valid(i , x) && arr[i][x] != '*'){
            pos[x] = i;
            solve(x+1);
            pos[x] = -1;
        }
    }
}

int main(){
    fast_cin();
    int k =1;
    while(true){
        cin>>N;
        if(N == 0) break;
        memset(pos, -1, sizeof pos);
        sum = 0;
        for(int i = 1 ; i <=N ; i ++)
            for(int j = 1 ; j <=N ; j ++)
                cin>>arr[i][j];
        if(first) cout<<endl;
        first = 1;
        solve(1);
        cout<<"Case "<<k++<<": "<<sum;
    }
    
    return 0;
}