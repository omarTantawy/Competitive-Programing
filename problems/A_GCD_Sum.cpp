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
#include <numeric>
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


// int gcd(long long int a,long long int b){
//     if(b==0)return a;
//     else return gcd(b,a%b);
// }

long long int  t, n , x;
int main(){
    fast_cin();
    cin>>t;

    while(t--){
        cin>>x;
        while(true){
            long long int x2 =x ,digits = 0;
            while(x2>0){
                long long int d = x2%10;
                x2/=10;
                digits += d;
            }
            if(digits%2 == 0 &&  x %2 == 0){
                cout<<x<<endl;
                break;
            }
            else if(__gcd(digits, x) > 1){
                cout<<x<<endl;
                break;
            }
            x++;
        }

    }

    
    return 0;
}