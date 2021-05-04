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
#include <cstring>
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
 
 
int main(){
    fast_cin();
    int n , q ,l,r , cp =0, dp = 1 ,last_idx = -1, arr[10];
    string str;
    char last = '!';
    cin>>n>>q>>str;
    while(q--){
        string s = str;
        memset(arr , 0, sizeof(arr));
        cin>>l>>r;
        l--;
        r--;
        cp = l;
        dp = 1;
        last = s[l];
        last_idx = 0;
        while(true){
            bool finished = true;
            for(int i = l;i<=r;i++)
                if(s[i] <= '9' && s[i] >= '0')
                    finished = false;
            if (finished || cp < l || cp > r)
                break;
            
            if(s[cp] == '<'){
                dp = -1;
                if(last == '<' || last == '>'){
                        s[last_idx] = '#';
                }
            }else if ( s[cp] == '>'){
                dp = 1;
                if(last == '<' || last == '>'){
                        s[last_idx] = '#';
                }
            }else if(s[cp] <= '9' && s[cp] >= '0'){
                arr[s[cp]-'0'] ++;
                s[cp] --;
                if(s[cp] == ('0'-1))
                    s[cp] = '#';
            }
 
            last_idx = cp;
            last = s[cp];
 
            while(true){
                cp += dp;
                if(cp > r || cp < l )
                    break;
                if((s[cp] <= '9' && s[cp] >= '0')|| s[cp] == '<' || s[cp] == '>'){
                    break;
                }else
                    continue;
            }
        }
        for(int i = 0 ; i < 10 ; i ++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}