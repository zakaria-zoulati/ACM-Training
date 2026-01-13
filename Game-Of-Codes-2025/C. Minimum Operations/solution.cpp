#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

using vi = vector<int> ; 
using vvi = vector<vi> ;
using edge = pair<int,int> ; 
using ve = vector<edge> ; 
using vve = vector<ve> ; 


int mod = 1'000'000'007 ;

ll modE( ll p ){
    if( p == 0 ){
        return  1; 
    }
    if( p == 1 ){
        return 2 ; 
    }
    ll ans = modE( p/2 ) ; 
    ans = ( ans * ans ) % mod; 
    if( p % 2 == 1 ){
        ans = ( ans * 2  ) % mod ; 
    }
    return ans ; 
}

void solve(){
  string s ; cin >> s;  
  string t ; cin >> t ; 
  
  int n = s.size() ; 
  
  if( s[0] == '1' ){
    for( int i=1 ; i<n ; ++i ){
        if( s[i] == '1' ) {
            cout << "-1\n" ; 
            return ; 
        }
    }  
    cout << "0\n" ; 
    return ; 
  }
  
  int pos = -1 ; 
  int count = 0 ; 
  for( int i=0 ; i<n ; ++i ){
      if( s[i] == '1' ){
          count++ ; 
          if( pos == -1 ){
              pos = i ; 
          }
      }
  }
  
  if( count == 0 ){
      cout << n << '\n' ; 
  }else if( count == 1  ){
      cout << pos << '\n' ; 
  }else {
      ll ans = 0 ;
      for( int i=n-1 ; i>=pos ; --i ){
        if( s[i] == '1' ){
            int ind = i ; 
            int count = 1 ; 
            while( s[i-1] == '1' ){
                count++ ; 
                i-- ; 
            }
            ans = ( ans + modE( n-1 - ind ) ) % mod ; 
            s[i-1] = '1' ; 
        }
      }
      ans = ( ans + pos - 1 ) % mod ; 
      cout << ans << '\n'; 
  }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
       solve() ; 
    }
}
