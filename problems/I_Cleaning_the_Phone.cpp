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

int t , n , m ,ans  ,sum,temp,a[200009];
vector<int> tws , ons;


int main(){
    fast_cin();
    cin>>t;
    while(t--){
        tws.clear();
        ons.clear();
        sum = 0;
        ans = 0;
        cin>>n>>m;
        for(int i = 0 ; i<n;i++)cin>>a[i];
        for(int i = 0 ; i<n;i++){
            cin>>temp;
            if(temp == 1)
                ons.push_back(a[i]);
            else
                tws.push_back(a[i]);
            sum+=a[i];
        }
        if(sum < m){
            cout<<-1<<endl;
            continue;
        }
        ons.push_back(0);
        tws.push_back(0);
        sort(ons.begin() , ons.end() );
        sort(tws.begin() , tws.end() ); 
        if(ons.back() != 0 && ons.back() >= m){
            cout<<1<<endl;
            continue;
        }else if(ons.back() != 0 && ons.back()+*(ons.rbegin()+1) >= m || tws.back() >= m){
            cout<<2<<endl;
            continue;
        }else if(tws.back() + ons.back() >=m){
            cout<<3<<endl;
            continue;
        }
        sum = 0;
        while(sum<m){
            if(ons.back() >= tws.back() || (m-sum) <= ons.back()  || tws.back() == 0 && ons.back() != 0){
                sum+=ons.back();
                ons.pop_back();
                ans++;
                }else if (ons.back() != 0 && (m-sum) <= ons.back()+*(ons.rbegin()+1)){
                sum+=ons.back();
                ons.pop_back();
                sum+=ons.back();
                ons.pop_back();
                ans+=2;
                }else{
                sum+=tws.back();
                tws.pop_back();
                ans+=2;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}