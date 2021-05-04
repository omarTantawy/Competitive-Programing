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
// ll MOD = 998244353;
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
int MOD = 100000000;

int k1 , k2;
int v[111][111][2];
int dp[111][111][2];

int solve(int n1 , int n2 , bool q ){

    if(n1 ==0 && n2 ==0)return 1;
    if(v[n1][n2][q])return dp[n1][n2][q];
    v[n1][n2][q] =1;
    int ans = 0;
    if(q){
        for(int i = 1; i <=n1 && i<= k1 ; i ++){
            ans += solve(n1 -i , n2 , !q);
            if(ans >= MOD) ans -= MOD;
        }
    }else{
        for(int i = 1 ; i <=n2 && i<=k2 ; i++){
            ans+= solve(n1 , n2-i , !q);
            if(ans >= MOD) ans -= MOD;
        }
    }
return dp[n1][n2][q]= ans;
}

int main(){
    fast_cin();
    int n1 , n2;
    cin>>n1>>n2>>k1>>k2;
    int ans = solve(n1 , n2 , 0) + solve(n1,n2 , 1);
    if( ans >=MOD) ans -=MOD;
    cout<<ans;

    
    return 0;
}