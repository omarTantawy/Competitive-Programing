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
 
const ll N = 5e6+9;
ll t ,a ,b;
// vector<vector<ll>> factor;
ll factor[N];
vector<ll> primes;
bool is_prime[N];
 
void sieve(){
    memset(is_prime , 1 , sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    primes.push_back(2);
    for(ll i = 2 ; i < N ; i ++){
        if(is_prime[i] ){
            primes.push_back(i);
            for(ll j = i* i ; j < N ; j += i)
                is_prime[j] = false;
        }
    }
}
 
void prime_fac(){
 
    factor[0] = factor[1] = 0;
    factor[2] = 1;
    factor[3] = 1;
    for(ll i = 4 ; i < N ; i++){
        ll n = i;
        for(ll j = 0 ; j< primes.size() ; j++){
            ll k = primes[j]; 
            if( k*k > n || is_prime[i]){
                // cout<<i<<" "<<k<<endl;
                break;
            }else if(n % k ==0){
                factor[i] = factor[n/k]+1;
                n--;
                break;
            }
        }
        if (n==i)
            factor[i] = 1;
    }
}
 
int main(){
    fast_cin();
    cin>>t;
    
    sieve();
    prime_fac();
    for(int i = 1; i < N; ++i)
        factor[i] += factor[i - 1];
    while(t--){
        cin>>a>>b;
        cout<<factor[a]-factor[b]<<endl;
        
    }
    
    return 0;
}