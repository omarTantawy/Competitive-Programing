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

const int N = 3e5+99;
int n , k , arr[N];
int main(){
    fast_cin();
    cin>>n>>k;
    for(int i = 0 ; i < n ; i ++)cin>>arr[i];

    int l , r ,j = 0, left = k , ans = -1;
    for(int i = 0 ; i < n ; i ++){
        if(i > 0 ){
            if(arr[i-1] == 0) left++;
        }
        while(true){
            if(j ==n)
                break;
            if(arr[j] == 1){
                j++;
            }else{
                if(left >0){
                    left--;
                    j++;
                }else{
                    break;
                }
            }
        }
        
        if(j-i > ans){
            l = i , r = j , ans = j-i;
        }

    }
    r--;
    cout<<ans<<endl;
    for(int i = 0 ; i < n ; i ++){
        if(i<= r && i >= l)
            cout<<1<<" ";
        else
            cout<<arr[i]<<" ";
    }
    return 0;
}