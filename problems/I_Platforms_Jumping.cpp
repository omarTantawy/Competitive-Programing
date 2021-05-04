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


int n , m , d , total = 0,start = 0 , arr[1009] , ans[1009];

int main(){
    fast_cin();
    cin>>n>>m>>d;
    for(int i = 1 ; i <= m ; i++){
        cin>>arr[i];
        total += arr[i];
    }

    if((m+1)*d + (total-m) <= n){
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    int cur = n;
    int pos = 1;
    int ans_pos = 0;
    int last_pos = 0;
    while(cur > total){
        if(pos==1 && n-cur < d-1){
            cur --;
            ans_pos ++;
            continue;
        }
        if(arr[pos] > 0 ){
            ans[ans_pos] = pos;
            ans_pos ++;
            arr[pos]--;
            total--;
            cur--;
            last_pos = ans_pos;
        }else{
            if(ans_pos -last_pos >=d-1){
                pos++;
                continue;
            }
            ans_pos ++;
            cur--;
            
        }
    }

    for(int i = 0; i < ans_pos ; i ++){
        cout<<ans[i]<<" ";
    }
    for(int i = pos ; i <= m ; i ++){
        while(arr[i]){
            cout<<i<<" ";
            arr[i]--;
        }
    }

    return 0;
}