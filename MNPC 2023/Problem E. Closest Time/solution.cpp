#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
using ll = long long;

string rs = "__:__" ; 
int diff = -1 ; 

bool isValid( string &s ){
    int a = ( s[0] - '0' )*10 + ( s[1] - '0' )  ; 
    int b = (s[3] - '0' )*10 + ( s[4] - '0' ) ; 
    return ( a <= 23 && b <= 59 ) ; 
}

int getSeconds( string &s ){
    int a = ( ( s[0] - '0' )*10 + ( s[1] - '0' ) )*60 ; 
    int b = (( s[3] - '0' )*10 + ( s[4] - '0' )) ; 
    return a+b ; 
}

void backtrack( string &s , string &t , int in ){
    if( in == 5 ){
        if( !isValid(s) ) return ; 
        int a = getSeconds( s ) ; 
        int b = getSeconds( t ) ; 
        int curr = min( abs(a-b) , 24*60 - abs(a-b) ) ; 
        if( curr < diff ){
            diff = curr ; 
            rs = s; 
        }
        return ; 
    }
    if( s[in] != '?' ) {
        backtrack( s, t , in+1 ) ; 
    }else {
        for (char c = '0'; c <= '9'; c += 1 ){
            s[in] = c;
            backtrack(s, t, in + 1);
            s[in] = '?' ; 
        }        
    }
}

void solve() {
    rs = "__:__" ; 
    diff = INT_MAX ; 
    string s ; cin >> s ; 
    string t ; cin >> t ;
    backtrack( s , t , 0 ) ; 
    cout << rs << '\n' ; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1 ; cin >> t ; 
    while (t--) {
        solve();
    }
    
    return 0;
}