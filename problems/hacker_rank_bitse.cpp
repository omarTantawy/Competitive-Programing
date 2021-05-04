#include <iostream>
#include <bitset>
#include<vector>
#include<set>
using namespace std;


const unsigned m = 1 << 31;
const unsigned m2 = m-1;
int vis[m / 32];

#define setBit(k)     ( vis[(k >> 5)] |= (1 << (k & 31)) )
#define checkBit(k)    ( vis[(k>> 5)] & (1 << (k& 31)) )

int main() {
 
    unsigned  N, S, P, Q, mu, nu ,cur , last , ans =1;
 
    cin >> N >> S >> P >> Q;
 
    last = S;
    setBit(last);
    for (int i = 1; i < N; ++i) {
        cur = (last * P + Q) & m2;
         if(!checkBit(cur)){
            ++ans;
           setBit(cur);
            }else{
                break;
            }
        last = cur;
    }
    cout<<ans;
    
    return 0;
}
 
