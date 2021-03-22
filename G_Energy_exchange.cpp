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
double eps = 1e-7;
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

int n , k , a[10009] ;


int can(double m){
    double dif = 0 , over = 0;
    // if((a[n-1] - a[0]) < eps )
    //     return true;

    for(int i = 0 ; i <n;i++){
        if(a[i] < m)
            dif += (m- a[i]);   
        else
            over += (a[i] - m);
    }
    // cout<<m<<" "<< over<<" "<<dif / ((double)(100-k)/100)<<" ";
    // cout<<abs( over - dif / ((double)(100.0-k)/100.0))<<endl;
    if(abs( over - dif / ((double)(100.0-k)/100.0)) <= eps )
        return 0;
    else if (over  - dif / ((double)(100-k)/100) > 0 ){
        return -1;
    }
    return 1;
}
int main(){
    fast_cin();
    cin>>n>>k;
    for(int i = 0 ; i < n ; i++)cin>>a[i];
    if(n == 1){
        cout<<a[0];
        return 0;
    }
    sort(a , a+n);
    double l = a[0] , r = a[n-1] , mid;

    for(int i =0;i<200;i++){
        mid =(r+l) / 2;
        int st = can(mid);
        if(st == 0){
            cout.precision(17);
            cout<<mid<<endl;
            break;
        }else if(st == 1){
            r = mid;
        }else{
            l = mid;
        }

    }
    
    return 0;
}