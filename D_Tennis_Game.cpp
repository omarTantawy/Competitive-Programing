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


int n , temp,ones_cnt , twos_cnt , cur , osets , tsets , winner;
vector<int> ones , twos;
vector<pair<int,int>> ans;
int main(){
    fast_cin();

    cin>>n;

    ones.push_back(0);
    twos.push_back(0);
    for(int i = 1 ; i <=n ; i ++){
        cin>>temp;
        if(temp == 1)ones_cnt++;
        else twos_cnt ++;
        ones.push_back(ones_cnt);
        twos.push_back(twos_cnt);
        if(i ==n)winner = temp;
    }

    for(int i = 1 ; i <= n ; i ++){
        ones_cnt = 0 , twos_cnt = 0 , cur = 0,osets = 0 , tsets=0;
        while(true){
            vector<int>::iterator first_one = lower_bound(ones.begin() , ones.end(), ones[cur]+i);
            vector<int>::iterator first_two = lower_bound(twos.begin() , twos.end(), twos[cur]+i);
            
            if(first_one == ones.end() && first_two == twos.end()){
                if(cur == n && osets != tsets && (winner == 1 && osets > tsets || winner ==2 && tsets > osets))
                    ans.push_back(make_pair(max(osets , tsets) , i));
                break;
            }

            if(first_one-ones.begin()< first_two- twos.begin()){
                ones_cnt ++;
                osets++;
                cur = first_one-ones.begin();
            }else{
                twos_cnt ++;
                tsets++;
                cur = first_two-twos.begin();
            }
            
          
                           
        }
    }

    sort(ans.begin() , ans.end());
    cout<<ans.size()<<endl;
    for(int i = 0 ; i < ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
   
    return 0;
}