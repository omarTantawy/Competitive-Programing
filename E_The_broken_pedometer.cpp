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

int t , p , n, ans , first = 0;
char temp;
string temp_s;
vector<string> v ;


bool check(){

    // sort(v.begin() , v.end());
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ;j <n; j ++)
            if(v[i] == v[j] && i != j )
                return false;
    }
    return true;
}

void solve(int idx , int useless){
    ans = max(ans , useless);
    if(idx == p )
        return;
    
    vector<string> v2=v;
    for(int i = 0 ; i <n;i++)
        v[i][idx] = '#';
    if(check())
        solve(idx+1 , useless +1);

    v=v2;
    solve(idx+1 , useless);
}

int main(){
    fast_cin();
    cin>>t;

    while(t--){
        if(first) cout<<endl;
        first = 1;
        ans = 0;
        v.clear();
        // v2.clear();
        cin>>p>>n;
        for(int i = 0 ; i < n;i++){
            temp_s = "";
            for(int i = 0 ; i <p ; i ++){
                cin>>temp;
                temp_s+=temp;
            }
            v.push_back(temp_s);
        }
        solve(0 , 0);
        cout<<p-ans;
    }
    
    return 0;
}