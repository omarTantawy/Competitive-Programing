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

int t ,n, k , first = 0;
string s_orig , all = "ACGT";
set<string> mset;

void solve(int idx , int diff , string s){

    if(idx == n || diff == k){
        mset.insert(s);
        return;
    }


    for(int i = 0 ; i < 4; i ++){
        if(s[idx] == all[i]){
            solve(idx+1 , diff , s);
        }else{
            char orig = s[idx];
            s[idx] = all[i];
            solve(idx+1 , diff+1 , s);
            s[idx]= orig;
        }
    }


}

int main(){
    fast_cin();
    cin>>t;
    while(t--){
        cin>>n>>k;
        cin>>s_orig;
        solve(0 , 0 , s_orig);
        cout<<mset.size()<<endl;
        for(auto it:mset){
            cout<<it<<endl;
        }
        mset.clear();
    }
    

    return 0;
}