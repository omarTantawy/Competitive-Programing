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
#include <string.h>
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

int t , n , k ,ans = -1, temp,a[200009],cnt[200009],mx[200009];

int main(){
    fast_cin();
    cin>>t;
    while(t--){
        ans = 0;
        memset(a , 0 ,sizeof(a));
        memset(cnt , 0 ,sizeof(cnt));
        memset(mx , 0 ,sizeof(mx));
        cin>>n>>k;
        for(int i = 0 ; i < n ; i ++)cin>>a[i];
        for(int i = 0 ; i < n ; i ++)cin>>temp;
        sort(a, a + n );
        // if(n<=2 || (a[n-1] - a[0]) <= 2*k){
        if(n<=2){
            cout<<n<<endl;
            continue;
        }
        
        for(int i = 0 ; i <n ; i ++){
            int idx = lower_bound(a , a+n, a[i]+k+1)-a;
            cnt[i] = idx-i;
            // cout<<a[i]<<" "<<a[idx-1]<<" "<<cnt[i]<<endl;
        }
        temp = -1;
        for(int i = n-1 ; i >=0 ; i--){
            if(temp > cnt[i]){
                mx[i] = temp;
            }else{
                mx[i] = cnt[i];
                temp = cnt[i];
            }
            // cout<<mx[i]<<endl;
        }

        for(int i = 0 ; i <n ; i ++){
            int idx = lower_bound(a , a+n, a[i]+k+1)-a;
            temp = idx-i;
            ans = max(ans , (temp+ mx[idx]));
        }
        cout<<ans<<endl;
    }
    
    return 0;
}