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

ll n1 , n2 , n3 , temp;
vector<ll> a , b, c;


int main(){
    fast_cin();
    cin>>n1>>n2>>n3;
    for(int i = 0 ; i < n1 ; i ++){
        cin>>temp;
        a.push_back(temp);
    }
    for(int i = 0 ; i < n2 ; i ++){
        cin>>temp;
        b.push_back(temp);
    }
    for(int i = 0 ; i < n3; i++){
        cin>>temp;
        c.push_back(temp);
    }

    sort(a.begin() , a.end());
    sort(b.begin() , b.end());
    sort(c.begin() , c.end());
    
    if(a[0] <= b[0] && a[0] <= c[0]){
        while(n1>1){
            
        }
        while(n2>0){
            a[0] -= b[n2-1];
            n2--;
        }
        while(n3>0){
            a[0] -= c[n3-1];
            n3--;
        }
    }
    
    for(int i = 0 ; i < n1 ; i ++)cout<<a[i]<<" ";
    cout<<endl;
    for(int i = 0 ; i < n2 ; i ++)cout<<b[i]<<" ";
    cout<<endl;
    for(int i = 0 ; i < n3 ; i ++)cout<<c[i]<<" ";

    // if(*a.begin() - *b.end())
    return 0;
}