#include <bits/stdc++.h> 

#define all(x) begin(x) , end(x)

using namespace std  ;

using vi = vector<long long> ; 

using ll = long long ; 
using ld = long double ;

bool check( vi &pages , int n , int d , int h , ll tar ){
    int days = 0 ; 
    int l = 0 ; 
    int r = n-1 ; 
    while( l <= r ){
        if( l == r ){
            if( pages[l] <= tar * h ){
                days++ ; 
                break ; 
            }
        }
        if( pages[r] > tar * h ){
            return false ; 
        }
        if( pages[r] + pages[l] <= tar * h ){ 
            l++ ;
        }
        r-- ; 
        days++ ; 
    }
    
    return days <= d ; 
}


void solve(){
   int n ; cin >> n ; 
   int d ; cin >> d ; 
   int h ; cin >> h ; 
   
   vector<ll> pages(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> pages[i] ; 
   }
   
   sort( all(pages) ) ; 
   
   if( n > 2 * d ){
       cout << -1 << '\n' ; 
       return ; 
   }
   
   ll l = 1 ; 
   ll r = 2e9 ; 
   while( l < r ){
        ll mid = l + ( r - l )/2 ; 
        if( check( pages , n , d , h , mid ) ){
            r = mid ; 
        }else {
            l = mid + 1 ; 
        }
   }
   cout << l << '\n' ; 
}

int main(){
    int t ; cin >> t ; 
    while( t-- ){
        solve() ; 
    }
}
