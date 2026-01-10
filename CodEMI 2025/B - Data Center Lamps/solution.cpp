#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)


using ll = long long ;  
using ld = long double ;
using vi = vector<int> ; 
using vvi = vector<vi> ; 

int mod = 1'000'000'007 ;

void flipRow( vvi &grid , int i , int m ){
    for( int j=0 ; j<m ; ++j ){
        grid[i][j] ^= 1 ; 
    }
}

void flipCol( vvi &grid , int i , int n ){
    for( int j=0 ; j<n ; ++j ){
        grid[j][i] ^= 1 ; 
    }
}

bool isGood( vvi &arr , int n , int m ){
    for( int i=0 ; i<n ; ++i ){
        for( int j=0 ; j<m ; ++j ){
            if( arr[i][j] == 0 ) return false ;
        }
    }
    return true ; 
}

void solve(){
  int n ; cin >> n ; 
  int m ; cin >> m ; 
  vvi grid( n , vi(m) ) ; 
  for( int i=0 ; i<n ; ++i ){
      for( int j=0 ; j<m ; ++j ){
          cin >> grid[i][j] ; 
      }
  }
  
  int ans = INT_MAX ;  
  
  if( grid[0][0] == 0 ){
        vvi copy1( grid ) ; 
        flipRow( copy1 , 0 , m ) ; 
        int curr=1; 
        for( int i=1 ; i<n ; ++i ){
            if( copy1[i][0] == 0 ){
                flipRow( copy1 , i , m ) ; 
                curr++ ; 
            }
        }
        for( int i=1 ; i<m ; ++i ){
            if( copy1[0][i] == 0 ){
                flipCol( copy1 , i , n ) ; 
                curr++ ; 
            }
        }
        if( isGood( copy1 , n , m ) ){
            ans = min( ans , curr ) ; 
        }
        
        vvi copy2( grid ) ; 
        flipCol( copy2 , 0 , n ) ; 
        curr=1; 
        for( int i=1 ; i<n ; ++i ){
            if( copy2[i][0] == 0 ){
                flipRow( copy2 , i , m ) ; 
                curr++ ; 
            }
        }
        for( int i=1 ; i<m ; ++i ){
            if( copy2[0][i] == 0 ){
                flipCol( copy2 , i , n ) ; 
                curr++ ; 
            }
        }
        if( isGood( copy2 , n , m ) ){
            ans = min( ans , curr ) ; 
        }
        
  }else {
      vvi copy1( grid ) ; 
      int curr = 0 ; 
      for( int i=1 ; i<n ; ++i ){
          if( copy1[i][0] == 0 ){
              flipRow( copy1 , i , m ) ; 
              curr++ ;
          }
      }
      for( int i=1 ; i<m ; ++i ){
          if( copy1[0][i] == 0 ){
              flipCol( copy1 , i , n ) ; 
              curr++ ; 
          }
      }
      if( isGood( copy1 , n , m ) ){
          ans = min( ans , curr ) ; 
      }
      
      
      vvi copy2( grid ) ; 
      flipRow( copy2 , 0 , m ) ; 
      flipCol( copy2 , 0 , n ) ; 
      curr = 2 ; 
      for( int i=1 ; i<n ; ++i ){
          if( copy2[i][0] == 0 ){
              flipRow( copy2 , i , m ) ; 
              curr++ ;
          }
      }
      for( int i=1 ; i<m ; ++i ){
          if( copy2[0][i] == 0 ){
              flipCol( copy2 , i , n ) ; 
              curr++ ; 
          }
      }
      if( isGood( copy2 , n , m ) ){
          ans = min( ans , curr ) ; 
      }
  }
  
  cout << ( ans == INT_MAX ? -1 : ans ) << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ; 
    while( t-- ){
       solve() ; 
    }
}
