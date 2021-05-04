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

int t , n , h,first = 0;
set<string> mset;
int ones(string s){
    int counter = 0;
    for(int i = 0 ; i < n;i++)
        if(s[i] == '1')
            counter++;
    return counter;            
}

void solve(int idx , string s){
    if(ones(s) == h){
        mset.insert(s);
        return;
    }
    if(idx == n)
        return;

    string old = s;
    s[idx] = '1';
    solve(idx+1, s);
    s = old;
    solve(idx+1 , s);
    
}


int main(){
    fast_cin();
    cin>>t;
    while(t--){
        if(first )cout<<endl;
        first = 1;
        mset.clear();
        cin>>n>>h;
        string s = string(n,'0');
        // cout<<s<<endl;
        solve(0,s);
        for(auto it : mset)
            cout<<it<<endl;
    }


    return 0;
}