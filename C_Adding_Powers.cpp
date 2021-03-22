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

ll t , n, k , temp , arr[35];
stack<ll> pws;
bool ans;
int main(){
    fast_cin();
    cin>>t;
    while(t--){
        while(!pws.empty())pws.pop();
        ans = true;
        cin>>n>>k;
        temp = k;
        for(int i = 0 ; i < n ; i++)cin>>arr[i];
        sort(arr, arr+n , greater<ll>());
        pws.push(1);
        while(temp <= (1e16 * 1LL)){
            pws.push(temp);
            temp *= k ;
        }
        
        while(!pws.empty()){
            for(int i = 0 ; i < n ; i ++){
                if(arr[i] >= pws.top()){
                    arr[i] -= pws.top();
                    break;
                }
            }
            pws.pop();
        }
        for(int i = 0 ; i < n ; i++){
            if(arr[i] != 0 )ans=false;
        }
        if(ans)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}