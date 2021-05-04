#include<iostream>
#include <math.h>
using namespace std;


int unsignedBitLength(unsigned int number) {
        int length;
        
        length = 0;
        while (number != 0) {
            ++length;
            number >>= 1;
        }

        return length;
    }
    int divide(int dividend, int divisor) {
        bool minus;
        unsigned int unsigned_dividend, unsigned_divisor;
        unsigned int d;
        unsigned int quotient;
        int offset;

        minus = (divisor < 0 && dividend > 0) || ( dividend <0 && divisor >0) ? true :false;
        
        unsigned_divisor = abs(divisor);
        unsigned_dividend = abs(dividend);

        if(unsigned_dividend <unsigned_divisor  || dividend ==0)
            return 0;

        offset = unsignedBitLength(unsigned_dividend) - unsignedBitLength(unsigned_divisor);

        quotient =0;
        while(offset>=0){
            d = unsigned_divisor << offset;
            if(unsigned_dividend >= d){
                unsigned_dividend -= d;
                quotient += 1<<offset;
            }
            --offset;
        }

        if(!minus && quotient > INT_MAX)
            return INT_MAX;
        
        return minus ? ~quotient +1 : quotient;
    }


int main(){
    int dividend , divisor;
    // cin>>dividend>>divisor;
    cout<<divide(51 , 5);


    return 0;
}