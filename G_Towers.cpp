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

int n , k  , ko ,arr[110];
multiset<pair<int , int>> mset;
vector<pair<int,int>> vec;
int main(){
    fast_cin();
    cin>>n>>k;
    ko=k;
    for(int i = 1 ; i <= n ; i ++){
        cin>>arr[i];
        mset.insert(make_pair(arr[i], i ));
    }

    while(k--){
        if((*mset.begin()).first == (*--mset.end()).first || abs((*mset.begin()).first - (*--mset.end()).first) == 1){
            break;
        }
        vec.push_back(make_pair( (*--mset.end()).second , (*mset.begin()).second ));
        pair<int,int> f = (*mset.begin());
        pair<int,int> s = (*--mset.end());
        f.first++;
        s.first--;
        mset.erase(mset.begin());
        mset.erase(--mset.end());
        mset.insert(f);
        mset.insert(s);
    }

    cout<<(*--mset.end()).first-(*mset.begin()).first<<" "<<vec.size()<<endl;
    for(auto it:vec){
        cout<<it.first<<" "<<it.second<<endl;
    }

    


    return 0;
}