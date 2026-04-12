#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;


int helper( string &s , int n , string patt ){
    int ans = n ; 
    int a = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( s[i] != patt[i%3] ){
            a++; 
        }
    }
    ans = min( ans , a ) ; 
    int b = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( s[i] != patt[(i+1)%3] ){
            b++; 
        }
    }
    ans = min( ans , b ) ; 
    int c = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( s[i] != patt[(i+2)%3] ){
            c++; 
        }
    }
    ans = min( ans , c ) ; 
    return ans ; 
}

void solve(){
    int n ; cin >> n ; 
    string s ; cin >> s ; 

    int x = helper( s , n , "mit" ) ; 
    int y = helper( s , n , "mti" ) ; 


    if( x == y ){
        cout << "FAKE\n" ;
    }else if( x < y ){
        cout << "mit " << x << '\n' ; 
    }else {
        cout << "mti " << y << '\n';  
    }


}

int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}