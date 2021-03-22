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


int n , m ,arr[29][3];
vector<int> v;

bool valid(){
    int a , b;
    for(int i = 0 ; i < m ; ++i){
        for(int j =0;j<n;j++){
            if(v[j] == arr[i][0])
                a = j;
            else if (v[j] == arr[i][1])
                b = j;
        }

        if (arr[i][2]<0){
            if(abs(a-b) < (-1 * arr[i][2]))
                return false;
        }else{
            if(abs(a-b) >arr[i][2])
                return false;
        }
    }
    return true;
}

int main(){
    fast_cin();

    while(1){
        int ans = 0;
        v.clear();
        cin>>n>>m;
        if(n == 0) return 0;
        for(int i = 0 ; i < m ; i ++)
            cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        
        for(int i = 0 ;i<n;i++)
            v.push_back(i);
        
        do{
            if (valid())
                ans++;

        }while(next_permutation(v.begin() , v.end()));
        
        cout<<ans<<endl;
    }
    return 0;
}