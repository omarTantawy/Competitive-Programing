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

ll t , n, a [300009], b[300009];
int main(){
    fast_cin();
    cin>>t;
    while(t--){
        cin>>n;

        for(int i = 0 ; i < n ; i ++){
            cin>>a[i]>>b[i];
        }

        ll min_dif = 9e13, min_idx = -1 , ans = 0;

        for(int i = 1 ; i < n ; i ++){
            if( a[i]  - max(0* 1LL ,(a[i] - b[i-1])) < min_dif ){
                min_dif = a[i]  - max(0* 1LL ,(a[i] - b[i-1]));
                min_idx = i;
            }
        }
         if( a[0]  - max(0* 1LL ,(a[0] - b[n-1])) < min_dif ){
                min_dif = a[0]  - max(0* 1LL ,(a[0] - b[n-1]));
                min_idx = 0;
            }
        
        for(int i = 1 ; i < n ; i ++){
            if(i == min_idx){
                ans += a[i];
            }else{
                ans += max(0*1LL , a[i]- b[i-1]);
            }
        }
        if(min_idx == 0 )
            ans += a[0];
        else
            ans+=  max(0*1LL , a[0]- b[n-1]);
        cout<<ans<<endl;
    }
    




    return 0;
}