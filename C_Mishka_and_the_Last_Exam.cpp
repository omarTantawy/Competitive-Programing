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


const int N = 2e5+99;
long long int arr[N] , arrb[N];
long long int n , mini, maxi ,f , l;

int main(){
    fast_cin();
    cin>>n;
    f=1;
    l=n;
    for(int i = 1 ; i <= (int)n/2 ; i ++){
        cin>>arrb[i];
        if(i == 1){
            arr[f] = 0;
            arr[l]= arrb[i];
        }else{
            if(arrb[i] == arrb[i-1]){
                arr[f] = mini;
                arr[l] = maxi;
            }else if(arrb[i] > arrb[i-1]){
                arr[l] = maxi;
                arr[f] = arrb[i] - arr[l];
            }else{
                arr[f] = mini;
                arr[l] = arrb[i] - arr[f];
            }
        }
        maxi = arr[l];
        mini = arr[f];
        f++;
        l--;     
    }

    for(int i = 1 ; i <= n ; i ++){
        cout<<arr[i]<<" ";
    }

    
    return 0;
}