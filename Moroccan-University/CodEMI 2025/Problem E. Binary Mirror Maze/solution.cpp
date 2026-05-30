#include <iostream>
using namespace std;
using ll = long long;

ll solve( ll k ){
    if( k == 1 ){
        return 0 ; 
    }else if( ( k &( k - 1 ) ) == 0 ){
        return 0 ; 
    }
    int in = 0 ; 
    while( ( 1 << (in+1) ) - 1 < k ) in++ ; 
    int ele = k - ( (1 << in)  ) ; 
    int rev = ( (1 << in)  ) - ele ; 
    
    return 1 - solve( rev ) ; 
}


int main() {
    int t ; cin >> t ; 
    while( t-- ){
        ll k ; cin >> k ; 
        
        cout << solve(k) << endl ; 
    }
    return 0;
}
