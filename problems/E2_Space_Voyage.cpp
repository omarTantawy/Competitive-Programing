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

const ll N = 10009;
ll n , c ;
ll a[N] , b [N];
long double arr[N];
ll valid(ll x){
    ll days = 0;
    for(int i = 0 ;i<n;i++){

        if (1.*x*a[i] > 1LL*b[i]*c+1LL*b[i]*100) return c+1000LL;
        days += arr[i]*x +1;
        // if(days > c)
        //     return days;
    }
    return days;
}
int main(){
    fast_cin();
    cin>>n>>c;
    for(int i = 0 ; i < n ; i ++){
        cin>>a[i]>>b[i];
        arr[i] = (long double)a[i] / b[i];
    }

    ll lo = 1 , hi = 3e18 , mid , st = -1 , end = -1;
    while(lo <= hi){
        mid = (lo + hi)/2;
        if(valid(mid) == c){
            st =mid;
            hi = mid-1;
        }else if (valid(mid) < c){
            lo = mid +1;
        }else{
            hi = mid-1;
        }
    }

    lo = 1 , hi = 3e18 ;
    while(lo <= hi){
        mid = (lo + hi)/2;
        if(valid(mid) == c){
            end =mid;
            lo = mid+1;
        }else if (valid(mid) < c){
            lo = mid +1;
        }else{
            hi = mid-1;
        }
    }

    if(end == -1 || st == -1)
        cout<< 0;
    else if (end-st+1 >= 1000000000000000000)
        cout<<-1;
    else
        cout<<end - st +1;

    return 0;
}