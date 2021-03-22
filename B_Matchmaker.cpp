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

int n , m ,temp,temp2,ans = 0 , beu = 0 ,arr[1009][1009],arr2[1009];
vector<int> le;
int main(){
    fast_cin();
    cin>>n>>m;
    for(int i = 0 ; i < n ; i ++){
        cin>>temp>>temp2;
        arr[temp][temp2]++;
        arr2[temp2]++;
    }
    for(int i = 0 ; i < m ; i ++){
        cin>>temp>>temp2;
        if(arr[temp][temp2] > 0 && arr2[temp2] > 0 ){
            ans++;
            beu++;
            arr[temp][temp2]--;
            arr2[temp2]--;
        }else{
            le.push_back(temp2);
        }
    }
    for(auto it : le){
        if(arr2[it] > 0){
            arr2[it]--;
            ans++;
        }
    }
    cout<<ans<<" "<<beu;
    return 0;
}